/*
** l_malloc.c for malloc in /home/ovoyan_s/rendu/PSU_2013_malloc/ovoyan_s
** 
** Made by ovoyan_s
** Login   <ovoyan_s@epitech.net>
** 
** Started on  Mon Feb 10 13:30:34 2014 ovoyan_s
** Last update Sun Feb 16 13:34:24 2014 ovoyan_s
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"my_malloc.h"

t_gen		*g_str = NULL;

int		init_malloc()
{
  g_str = sbrk(sizeof(*g_str));
  g_str->list_of_elems = NULL;
  g_str->nb_of_elems = 0;
  g_str->nb_of_pages = 0;
  g_str->pages_size = getpagesize();
  if ((g_str->begin_process_break_limit = sbrk(0)) == (void*)-1)
    return (-1);
  g_str->allocated_memory = g_str->begin_process_break_limit;
  return (0);
}

/*
**		Fonction de malloc générale
*/

void		*malloc(size_t size)
{
  void		*ptr_to_ret;

  ptr_to_ret = NULL;
  if (size == 0)
    return (NULL);
  if (g_str == NULL)
    {
      if (init_malloc() == -1)
	return (NULL);
    }

  if ((ptr_to_ret = check_add_elem_and_sbrk(ptr_to_ret, size)) == NULL)
      return (NULL);
  if (fill_elem(ptr_to_ret, find_elem_in_list(g_str->nb_of_elems - 1), size) == NULL)
      return (NULL);

  return (ptr_to_ret);
}

/*
**		Fonction agissant comme sbrk, mais faisant
**		un sbrk(getpagesize) à chaque fois.
*/

void		*my_sbrk(intptr_t increment)
{
  unsigned long local_mem_counter;
  void          *ptr_to_allocate;
  unsigned long counter;
  int		pages_counter;

  pages_counter = 0;
  g_str->allocated_memory = g_str->allocated_memory + (unsigned long)increment;
  local_mem_counter = (g_str->allocated_memory - g_str->begin_process_break_limit);
  counter = 0;
  while (counter < local_mem_counter)
    {
      counter = counter + g_str->pages_size;
      pages_counter = pages_counter + 1;
    }
  if ((pages_counter - g_str->nb_of_pages) > 0)
    {
      if ((sbrk((pages_counter - g_str->nb_of_pages) * g_str->pages_size)) == (void*)-1)
	return ((void*)-1);
    }
  g_str->nb_of_pages = pages_counter;
  ptr_to_allocate = g_str->allocated_memory - (unsigned long)increment;
  if (((unsigned long)g_str->allocated_memory % 4) != 0)
    g_str->allocated_memory = g_str->allocated_memory +
      (4 - ((unsigned long)g_str->allocated_memory % 4));
  return (ptr_to_allocate);
}

t_elem		*ret_free_good_elem(size_t size)
{
  int		counter;
  t_elem	*elem_to_use;

  elem_to_use = NULL;
  if ((elem_to_use = g_str->list_of_elems) == NULL)
    return (NULL);
  counter = 0;
  while (elem_to_use != NULL && counter < g_str->nb_of_elems)
    {
      if (elem_to_use->ptr_free == 1)
	if (size <= elem_to_use->size)
	  return (elem_to_use);
      elem_to_use = elem_to_use->next;
      counter = counter + 1;
    }
  return (NULL);
}
