##
## EPITECH PROJECT, 2025
## bssecured
## File description:
## Makefile
##

SRC = mini_printf.c \
      my_put_nbr.c \
	  my_putchar.c \
	  my_putstr.c \
	  hash.c \
	  create_hashtable.c \
	  dump.c \
	  insert.c \
	  del_hashtable.c \
	  search.c \
	  delete.c \
	  my_strdup.c \
	  my_strcmp.c \
	  my_strlen.c \

OBJET = $(SRC:.c=.o)

NAME = libhashtable.a

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJET)
	gcc -g3 -c $(SRC)
	ar rc $(NAME) $(OBJET)

clean :
	rm -f $(OBJET)

fclean : clean
	rm -f $(NAME)

re :    fclean all
