/*
** l_free.c for malloc in /home/ovoyan_s/rendu/PSU_2013_malloc/ovoyan_s
** 
** Made by ovoyan_s
** Login   <ovoyan_s@epitech.net>
** 
** Started on  Mon Feb 10 13:31:10 2014 ovoyan_s
** Last update Sat Feb 15 16:08:48 2014 ovoyan_s
*/

#include	<stdio.h>
#include	"my_malloc.h"

void		free(void *ptr)
{
  t_elem	*elem_to_use;
 
  if (ptr != NULL)
    {
      //      printf("Zero Step : \n%p\n%p\n", ptr, g_str->list_of_elems);
      elem_to_use = ret_metadata_of_ptr(ptr);
      //      printf("Second Step : \n%p\n%p\n", elem_to_use, g_str->list_of_elems);
      fusion_of_datas(elem_to_use); 
     //      printf("Third Step : It Works\n");
    }
}

t_elem		*ret_metadata_of_ptr(void *ptr_to_use)
{
  t_elem	*elem_to_ret;

  elem_to_ret = ptr_to_use - (sizeof(*elem_to_ret));
  //  printf("Prime Step : \n%p\n%p\n\n", elem_to_ret, g_str->list_of_elems);
  elem_to_ret->ptr_free = 1;
  return (elem_to_ret);
}

void		fusion_of_datas(t_elem *elem_to_use)
{
  t_elem	*next;
  t_elem	*prev;
  
  elem_to_use->ptr_free = 1;
  next = elem_to_use->next;
  prev = elem_to_use->prev;
  if (next != NULL)
    fusion_of_ptr(elem_to_use, next);
  if (prev != NULL)
    fusion_of_ptr(prev, elem_to_use);
}

void		fusion_of_ptr(t_elem *elem_first, t_elem *elem_sec)
{
  elem_first->size = elem_first->size + sizeof(*elem_sec) + elem_sec->size;
  if (elem_sec == NULL)
    elem_first->next = NULL;
  else
      elem_first->next = elem_sec->next;
  if (elem_first != NULL && elem_first->next != NULL)
    elem_first->next->prev = elem_first;
}
