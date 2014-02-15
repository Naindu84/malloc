##
## Makefile for malloc in /home/ovoyan_s/Travaux/Malloc
## 
## Made by ovoyan_s
## Login   <ovoyan_s@epitech.net>
## 
## Started on  Mon Feb 10 09:33:41 2014 ovoyan_s
## Last update Thu Feb 13 11:17:27 2014 ovoyan_s
##

SRC	=	main.c \
		my_free.c \
		my_gere_list.c \
		my_malloc.c \
		my_realloc.c \

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-c -Wall -Werror -Wextra -fPIC

RM	=	rm -rf

NAME	=	malloc_self

LIBNAME	=	libmy_malloc_$(HOSTTYPE).so

LIBLINK	=	libmy_malloc.so

LINK	=	ln -s

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -shared -o $(LIBNAME) $(OBJ)
		# $(LINK) $(LIBNAME) $(LIBLINK)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(LIBNAME)
		$(RM) $(LIBLINK)

re:		fclean all
