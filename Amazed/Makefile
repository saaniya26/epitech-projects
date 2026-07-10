##
## EPITECH PROJECT, 2024
## main
## File description:
## Makefile v5
##

## //> Project Data
## * Names

NAME = amazed

DEBUG = amazed_dbg

TNAME = unit_tests

## * Compiling - Paths (Sources)

SRC = $(wildcard *.c) $(shell find ./src -type f -name '*.c')

TOBJ = $(filter-out ./src/main.c,$(wildcard *.c)) \
	$(filter-out ./src/main.c,$(shell find ./src -type f -name '*.c'))

TSRC = $(shell find ./tests/ -type f -name '*.c')

LIBSRC := $(wildcard ./lib/*/)

## * Compiling - Paths (Objects)

OBJ = $(SRC:.c=.o)

## * Compiling - Flags

INCLPATH = include/

LIBFLGS = -L. -lmy -largparser

DBGFLGS = -Wall -Wextra -g3

CFLAGS = -Wall -Wextra -I$(INCLPATH) $(LIBFLGS)

TCFLGS = -lcriterion

## //> Scripts

## * Global Compilation

all: libs $(NAME)

dbg: dbg_libs $(DEBUG)

## * Global Compilation (Subtasks)

$(NAME): $(OBJ)
	@$(CC) $(SRC) -o $(NAME) $(CFLAGS)

$(DEBUG): $(OBJ)
	@$(CC) $(SRC) -o $(DEBUG) $(DBGFLGS) $(CFLAGS)

## * Lib Compilation

libs: $(LIBSRC)
	@for fld in $^ ; do $(MAKE) -C $$fld --no-print-directory ; done

dbg_libs: $(LIBSRC)
	@for fld in $^ ; do $(MAKE) -C $$fld CFLGS='$(DBGFLGS)' \
		--no-print-directory ; done

## * Cleaning

clean:
	@for fld in $(LIBSRC) ; do $(MAKE) clean -C $$fld \
		--no-print-directory ; done
	@$(RM) $(OBJ)
	@$(RM) unit_tests *.gc*
	@$(RM) ./tests/example_files/*.cor
	@$(RM) vgcore*

fclean: clean
	@for fld in $(LIBSRC) ; do $(MAKE) fclean -C $$fld \
		--no-print-directory ; done
	@$(RM) $(NAME)
	@$(RM) $(DEBUG)

## * Recompilation

re: fclean all

dbg_re: fclean dbg

## * Checks

style: fclean
	@../coding-style-checker/coding-style.sh ./
	@cat coding-style-reports.log
	@$(RM) -f coding-style-reports.log

## * Unit tests

tests_run: unit_tests
	@./unit_tests

unit_tests: re
	@$(CC) $(TSRC) $(TOBJ) -o $(TNAME) $(TCFLGS) $(CFLAGS)
