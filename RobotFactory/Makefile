##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##
NAME	=	asm

SRC     =   $(wildcard *.c)

OBJ     =   $(SRC:.c=.o)

CFLAGS  =   -W -Wall -Wextra

all:    $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

%.o: %.c
	gcc -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
