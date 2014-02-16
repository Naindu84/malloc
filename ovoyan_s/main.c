/*
** main.c for malloc in /home/ovoyan_s/Travaux/Malloc
** 
** Made by ovoyan_s
** Login   <ovoyan_s@epitech.net>
** 
** Started on  Mon Feb 10 09:47:47 2014 ovoyan_s
** Last update Sun Feb 16 17:02:13 2014 ovoyan_s
*/

#include		<stdio.h>
#include		<unistd.h>
#include		"my_malloc.h"

int			main()
{
  char			*word;
  char			*yol;
  char			*yol_2;

  word = NULL;
  word = malloc(568);
  word[0] = '0';
  word[1] = '1';
  word[2] = '2';
  word[3] = '3';
  word[4] = '4';
  yol = malloc(42);
  free(yol);
  yol_2 = malloc(1457664);
  /*  printf("First occurence : %s\n", word);
  word = realloc(word, sizeof(*word) * 2);
  printf("Second occurence : %s\n", word);*/
  show_list_of_elems();
  printf("%d", sizeof(*g_str->list_of_elems));
  return (0);
}
