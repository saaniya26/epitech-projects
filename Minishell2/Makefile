##
## EPITECH PROJECT, 2025
## B-PSU-200c
## File description:
## Makefile
##

SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:%.c=%.o)
NAME = mysh
CC = gcc
CFLAGS = -g3
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

main: main.c
	$(CC) $(CFLAGS) -o main main.c

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) main

re: fclean all
