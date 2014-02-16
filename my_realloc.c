/*
** l_realloc.c for malloc in /home/ovoyan_s/rendu/PSU_2013_malloc/ovoyan_s
** 
** Made by ovoyan_s
** Login   <ovoyan_s@epitech.net>
** 
** Started on  Mon Feb 10 13:30:53 2014 ovoyan_s
** Last update Sun Feb 16 17:21:39 2014 ovoyan_s
*/

#include	<stdio.h>
#include	<string.h>
#include	"my_malloc.h"

void		*realloc(void *ptr, size_t size)
{
  printf("REALLOC\n");
  if (ptr != NULL)
    {
      free(ptr);
      if (ptr != NULL)
	return (malloc_for_realloc(ptr, size));
      else if (ptr == NULL)
	return (malloc(size));
    }
  return (NULL);
}

/*
**              Fonction remplissant le pointeur de données dans le realloc 
*/

t_elem          *refill_elem(void *ptr_of_elem_to_set, void *ptr_to_use,
                             t_elem *elem_to_fill, size_t size_to_set)
{
  if (ptr_of_elem_to_set == (void*)-1)
    return (NULL);
  elem_to_fill->size = size_to_set;
  elem_to_fill->ptr_free = 0;
  if (memcpy(ptr_of_elem_to_set, ptr_to_use, sizeof(*ptr_to_use)) == NULL)
    return (NULL);
  elem_to_fill->ptr_of_elem = ptr_of_elem_to_set;
  return (elem_to_fill);
}

void		*malloc_for_realloc(void *ptr_to_use, size_t size)
{
  void		*ptr_to_ret;
  t_elem	*elem_to_use;

  ptr_to_ret = NULL;
  elem_to_use = NULL;
  if (g_str == NULL)
    {
      if (init_malloc() == -1)
	return (NULL);
    }
  ptr_to_ret = ptr_to_use;
  if ((elem_to_use = ret_free_good_elem(size)) == NULL)
    {
      if ((ptr_to_ret = check_add_elem_and_sbrk(ptr_to_ret, size)) == NULL)
	return (NULL);
      if (refill_elem(ptr_to_ret, ptr_to_use, 
		      find_elem_in_list(g_str->nb_of_elems - 1), size) == NULL)
	return (NULL);
    }
  return (ptr_to_ret);
}

void		*check_add_elem_and_sbrk(void *ptr_to_ret, size_t size)
{
  if (add_elem_in_list(g_str->nb_of_elems) == -1)
    return (NULL);
 if ((ptr_to_ret = my_sbrk(size)) == (void*)-1)
    return (NULL);
  return (ptr_to_ret);
}
