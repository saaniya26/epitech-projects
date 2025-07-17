##
## EPITECH PROJECT, 2024
## B-CPE-110
## File description:
## Makefile
##

SRC = main.c \
	  organized.c \
	  add.c \
	  delete.c \
	  mini_printf.c \
	  functions.c \
	  my_getnbr.c \

OBJET = $(SRC:.c=.o)

NAME = organized

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJET)
	gcc *.c -g3 -o $(NAME) -L./ -I./ -lshell

main: re main.c
	gcc -g3 -o main main.c

clean :
	rm -f $(OBJET)

fclean : clean
	rm -f $(NAME)

re :    fclean all
