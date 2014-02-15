/*
** l_realloc.c for malloc in /home/ovoyan_s/rendu/PSU_2013_malloc/ovoyan_s
** 
** Made by ovoyan_s
** Login   <ovoyan_s@epitech.net>
** 
** Started on  Mon Feb 10 13:30:53 2014 ovoyan_s
** Last update Sat Feb 15 11:53:40 2014 ovoyan_s
*/

#include	<stdio.h>
#include	"my_malloc.h"

void		*realloc(void *ptr, size_t size)
{
  if (ptr != NULL)
    free(ptr);
  return (malloc(size));
}

