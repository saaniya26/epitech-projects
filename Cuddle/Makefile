##
## EPITECH PROJECT, 2024
## main
## File description:
## Makefile v6 (Lib)
##

## //> Project Data
## * Names

LNAME = cuddle

LNAME_F = lib$(LNAME)

NAME = $(LNAME_F).a

DEBUG = $(LNAME_F)dbg.a

ENAME = cuddle

MAINFILE = ./src/main.c

TNAME = unit_tests

## * Compiling - Paths (Sources)

SRC = $(filter-out ./src/main.c,$(shell find ./src -type f -name '*.c'))

TSRC = $(shell find ./tests/ -type f -name '*.c')

LIBSRC := $(wildcard ./lib/*/)

## * Compiling - Paths (Objects)

OBJ = $(SRC:.c=.o)

EOBJ = $(MAINFILE:.c=.o)

TOBJ = $(filter-out ./src/main.c,$(wildcard *.c)) \
	$(filter-out ./src/main.c,$(shell find ./src -type f -name '*.c'))

## * Compiling - Flags

INCLPATH = include/

LIBFLGS = -lm -L. -lmy -lstatutils -lfsutils

DLIBFLGS = -L. -l$(LNAME)dbg

DBGFLGS = -g3

CFLAGS = -Wall -Wextra -I$(INCLPATH) $(LIBFLGS)

TCFLGS = -lcriterion -l$(LNAME)

## //> Scripts

## * Global Compilation

all: libs $(NAME)

dbg: CFLAGS += $(DBGFLGS)
dbg: dbg_libs $(DEBUG) $(ENAME)

## * Global Compilation (Subtasks)

$(NAME): $(OBJ)
	@$(RM) $(NAME)
	@ar rcT $(NAME) $(OBJ) $(shell find ./ -type f -name '*.a')

$(DEBUG): $(OBJ)
	@$(RM) $(DEBUG)
	@ar rcT $(DEBUG) $(OBJ) $(shell find ./ -type f -name '*.a')

$(ENAME): $(EOBJ)
	@$(CC) $(MAINFILE) -o $(ENAME) $(CFLAGS) $(DLIBFLGS)

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
	@$(RM) ./tests/example_files/*-out.csv
	@$(RM) *-out.csv
	@$(RM) vgcore*

fclean: clean
	@for fld in $(LIBSRC) ; do $(MAKE) fclean -C $$fld \
		--no-print-directory ; done
	@$(RM) $(NAME)
	@$(RM) $(DEBUG)
	@$(RM) $(ENAME)
	@$(RM) ./src/main.o

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
	@$(CC) $(TSRC) -o $(TNAME) $(TCFLGS) $(CFLAGS)
