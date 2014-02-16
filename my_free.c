/*
** l_free.c for malloc in /home/ovoyan_s/rendu/PSU_2013_malloc/ovoyan_s
** 
** Made by ovoyan_s
** Login   <ovoyan_s@epitech.net>
** 
** Started on  Mon Feb 10 13:31:10 2014 ovoyan_s
** Last update Sat Feb 15 22:35:51 2014 theron
*/

#include	<stdio.h>
#include	<string.h>
#include	"my_malloc.h"

#define BLOCK_SIZE	32

void		*base = NULL;

t_elem		*get_block(void *ptr)
{
  char		*tmp;

  tmp = ptr;
  return ((t_elem*)(ptr = tmp -= BLOCK_SIZE));
}

t_elem		*ret_metadata_of_ptr(void *ptr)
{
  t_elem	*tmp;

  tmp = ptr - (sizeof(*tmp));
  return (tmp);
}

int		check_adress(void *ptr)
{
  if (get_block(ptr)->ptr_of_elem != 0)
    return (-1);
  return (0);
}

t_elem		*fusion(t_elem *in_use)
{
  if (in_use->next && in_use->next->ptr_free)
    {
      in_use->size += BLOCK_SIZE + in_use->next->size;
      if (in_use->next)
	in_use->next->prev = in_use;
    }
  return (in_use);
}

void		free(void *ptr)
{
  t_elem	*in_use;

  puts("free try");
  in_use = ret_metadata_of_ptr(ptr);
  if (check_adress(ptr) == 0)
    {
      in_use->ptr_free = 1;
      if (in_use->prev && in_use->prev->ptr_free)
	in_use = fusion(in_use->prev);
      if (in_use->next)
	fusion(in_use);
      else
	{
	  if (in_use->prev)
	    in_use->prev->next = NULL;
	  brk(in_use);
	}
    }
  puts("free success");
}
/*
void		free(void *ptr)
{
  t_elem	*elem_to_use;

  puts("il essaie de free");
  if (ptr != NULL)
    {
      //      printf("Zero Step : \n%p\n%p\n", ptr, g_str->list_of_elems);
      elem_to_use = ret_metadata_of_ptr(ptr);
      //      printf("Second Step : \n%p\n%p\n", elem_to_use, g_str->list_of_elems);
      fusion_of_datas(elem_to_use);
      //      printf("Third Step : It Works\n");
    }
  puts("free success");
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
  elem_first->next->prev = elem_first;
}
*/
