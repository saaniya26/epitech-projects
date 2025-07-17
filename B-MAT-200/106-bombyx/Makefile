##
## EPITECH PROJECT, 2025
## 106bombyx
## File description:
## Makefile Python v2
##

NAME = 106bombyx

SOURCE = main.py

all:
	@cp $(SOURCE) $(NAME)
	@chmod +x $(NAME)

clean:
	@find . -name "__pycache__" -type d -exec rm -r {} +

fclean:
	@$(RM) $(NAME)

re: fclean all
