##
## EPITECH PROJECT, 2025
## EPITECH
## File description:
## Makefile Python v2
##

NAME = 109titration

SOURCE = main.py

all:
	@cp $(SOURCE) $(NAME)
	@chmod +x $(NAME)

clean:
	@find . -name "__pycache__" -type d -exec rm -r {} +

fclean: clean
	@$(RM) $(NAME)
	@$(RM) file

re: fclean all

tests_run:
	python3 -m unittest ./tests/test_*.py -v
