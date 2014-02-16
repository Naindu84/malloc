/*
** main.c for malloc in /home/ovoyan_s/Travaux/Malloc
** 
** Made by ovoyan_s
** Login   <ovoyan_s@epitech.net>
** 
** Started on  Mon Feb 10 09:47:47 2014 ovoyan_s
** Last update Sat Feb 15 21:39:00 2014 theron
*/

#include		<stdio.h>
#include		<unistd.h>
#include		"my_malloc.h"

int			main()
{
  char			*word;

  word = malloc(6);
  word[0] = 'a';
  word[1] = 'b';
  word[2] = 'c';
  word[3] = 'd';
  word[4] = 'e';
  word[5] = '\0';

  printf("word 1 : %s\n", word);
  word = realloc(word, 2);
  printf("word 2 : %s\n", word);
  return (0);
}
