##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

NAME	=	corewar

SRC_DIR = src

SRC     =   $(wildcard $(SRC_DIR)/*.c)

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
