##
## EPITECH PROJECT, 2025
## B-PSU-200
## File description:
## Makefile
##

SRC = main.c \
	  minishell1.c \
	  functions.c \
	  builtin.c \
	  builtin2.c \
	  env.c \
	  my_str_to_word_array.c \
	  my_getnbr.c \
	  my_strncmp.c \
	  check_error.c \
	  my_is_alpha.c \

OBJET = $(SRC:.c=.o)

NAME = mysh

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJET)
	gcc *.c -g3 -o $(NAME)

main: re main.c
	gcc -g3 -o main main.c

clean :
	rm -f $(OBJET)

fclean : clean
	rm -f $(NAME)

re :    fclean all
