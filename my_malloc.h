/*
** malloc.h for malloc in /home/ovoyan_s/rendu/PSU_2013_malloc/ovoyan_s
** 
** Made by ovoyan_s
** Login   <ovoyan_s@epitech.net>
** 
** Started on  Mon Feb 10 13:40:04 2014 ovoyan_s
** Last update Thu Feb 13 17:21:24 2014 ovoyan_s
*/

#ifndef			L_MALLOC_H
# define		L_MALLOC_H

# include		<unistd.h>

typedef	struct	s_elem	t_elem;
typedef	struct	s_gen	t_gen;

struct			s_elem
{
  size_t		size;
  int			ptr_free;
  int			nbr_of_elem;
  void			*ptr_of_elem;
  t_elem		*next;
  t_elem		*prev;
};

struct			s_gen
{
  t_elem		*list_of_elems;
  int			nb_of_elems;
  int			nb_of_pages;
  int			pages_size;
  void			*begin_process_break_limit;
  void			*allocated_memory;
};

/*
**			Structure globale
*/

t_gen			*g_str;


/*
**			main.c
*/

int			main();

/*
**			my_free.c
*/

void			free(void *ptr);
t_elem			*ret_metadata_of_ptr(void *ptr);
void			fusion_of_datas(t_elem *elem_to_use);
void			fusion_of_ptr(t_elem *elem_first, t_elem *elem_sec);

/*
**			my_gere_list.c
*/

int			add_elem_in_list(int elem_position);
int			add_elem_in_list_with_pos(t_elem *elem_to_add, int elem_position);
t_elem			*find_elem_in_list(int elem_position);
t_elem			*fill_elem(void *ptr_of_elem_to_set, t_elem *elem_to_fill,
				   size_t size_to_set);
int			show_list_of_elems();

/*
**			my_malloc.c
*/

int			init_malloc();
void			*malloc(size_t size);
void			*my_sbrk(intptr_t increment);
t_elem			*ret_free_good_elem(size_t size);

/*
**			my_realloc.c
*/

void			*realloc(void *ptr, size_t size);

#endif			/*	L_MALLOC_H	*/
