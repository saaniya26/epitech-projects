##
## EPITECH PROJECT, 2024
## Documents
## File description:
## Makefile
##

SRC = my_str_to_word_array.c \
	  function.c \
	  settingup.c \
	  my_getnbr.c \


OBJET = $(SRC:.c=.o)

NAME = setting_up

MYH = my.h

RM = rm -f

all : $(NAME)

$(NAME) : libmy.a $(OBJET)
	gcc -g3 -o $(NAME) -L. *.c

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
