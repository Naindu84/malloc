/*
** my_gere_list.c for malloc in /home/ovoyan_s/rendu/PSU_2013_malloc/ovoyan_s
** 
** Made by ovoyan_s
** Login   <ovoyan_s@epitech.net>
** 
** Started on  Mon Feb 10 17:49:54 2014 ovoyan_s
** Last update Sun Feb 16 13:37:21 2014 ovoyan_s
*/

#include	<stdio.h>
#include	<unistd.h>
#include	"my_malloc.h"

/*
**		Fonction d'ajout d'un élément à la liste chainée
*/

int		add_elem_in_list(int elem_position)
{
  t_elem	*elem_to_add;

  elem_to_add = NULL;
  if (elem_position == 0)
    {
      if ((g_str->list_of_elems = my_sbrk(sizeof(*g_str->list_of_elems))) == (void*)-1)
	return (-1);
      g_str->list_of_elems->next = NULL;
      g_str->list_of_elems->prev = NULL;
      g_str->list_of_elems->size = 0;
      g_str->list_of_elems->nbr_of_elem = 0;
      g_str->list_of_elems->ptr_free = 0;
      g_str->nb_of_elems = 1;
    } 
  else
    {
      add_elem_in_list_with_pos(elem_to_add);
      /*      printf("%p", elem_to_add);
      if (elem_to_add == NULL)
      printf("ERROR 1\n");*/
    }
  return (0);
}

/*
**		Deuxième partie de add_elem_in_list
*/

int		add_elem_in_list_with_pos(t_elem *elem_to_add)
{
  int		counter;
  t_elem	*elem_to_use;

  counter = 0;
  if ((elem_to_use = g_str->list_of_elems) == NULL)
    return (-1);
  while (elem_to_use->next != NULL)
    {
      elem_to_use = elem_to_use->next;
      counter = counter + 1;
    }
  if ((elem_to_add = my_sbrk(sizeof(*elem_to_add))) == (void*)-1)
    return (-1);
  elem_to_add->ptr_free = 0;
  elem_to_add->nbr_of_elem = counter + 1;
  elem_to_add->next = NULL;
  elem_to_add->prev = elem_to_use;
  if (elem_to_use == g_str->list_of_elems)
    {
      g_str->list_of_elems->next = elem_to_add;
      printf("%p\n", g_str->list_of_elems->next);
    }
  else
    elem_to_use->next = elem_to_add;
  g_str->nb_of_elems = g_str->nb_of_elems + 1;
  return (0);
}

/*
**		Renvoie l'élément à telle position
*/

t_elem		*find_elem_in_list(int elem_position)
{
  int		counter;
  t_elem	*elem_to_use;

  if ((elem_to_use = g_str->list_of_elems) == NULL)
    return (NULL);
  counter = 0;
  while (elem_to_use->next != NULL && counter < elem_position)
    {
      elem_to_use = elem_to_use->next;
      counter = counter + 1;
    }
  if (elem_to_use != NULL && counter == elem_position)
    return (elem_to_use);
  return (NULL);
}

/*
**		Remplit un element de la liste des métadonnées
*/

t_elem		*fill_elem(void *ptr_of_elem_to_set,
			   t_elem *elem_to_fill, size_t size_to_set)
{
  if (ptr_of_elem_to_set == (void*)-1)
      return (NULL);

  elem_to_fill->size = size_to_set;
  elem_to_fill->ptr_free = 0;
  elem_to_fill->ptr_of_elem = ptr_of_elem_to_set;
  return (elem_to_fill);
}

int		show_list_of_elems()
{
  int		counter;
  t_elem	*elem_to_use;

  counter = 0;
  if ((elem_to_use = g_str->list_of_elems) == NULL)
    return (-1);

  while (elem_to_use != NULL && counter < g_str->nb_of_elems)
    {
      if (printf("Adresse du pointeur : %p .\nTaille du pointeur : %lu .\n",
		 elem_to_use->ptr_of_elem, elem_to_use->size) == -1
	  || printf("Si le pointeur est free : %d .\nPlace de l'element : %d .\n",
		    elem_to_use->ptr_free, elem_to_use->nbr_of_elem) == -1)
   	return (-1);
      elem_to_use = elem_to_use->next;
      counter = counter + 1;
    }

  return (0);
}
