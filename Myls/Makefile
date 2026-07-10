##
## EPITECH PROJECT, 2025
## tictactoe
## File description:
## Makefile
##

SRC = main.c \
	  win.c \
	  stumper.c \
	  my_isdigit.c \

OBJET = $(SRC:.c=.o)

NAME = tictactoe

MYH = my.h

RM = rm -f

all : $(NAME)

$(NAME) : libmy.a $(OBJET)
	gcc -g3 -o my_ls -L. *.c

libmy.a:
	gcc -g3 -c $(SRC)
	ar rc $(NAME) $(OBJET)

main: re main.c
	gcc -g3 -o main main.c -lmy -L.

clean :
		rm -f $(OBJET)

fclean : clean
		rm -f $(NAME)

re : 	fclean all
