##
## EPITECH PROJECT, 2025
## EPITECH
## File description:
## Makefile Python VirtualEnv v1
##

NAME = tardis

VENV_PATH = .venv

DATASETS = dataset.csv cleaned_dataset.csv

AI_MODELS = *.joblib

all:
	cp ./assets/gares-de-voyageurs.csv .

local:
	@python3 -m venv ./$(VENV_PATH)
	@bash -c "source ./$(VENV_PATH)/bin/activate; \
	pip install --upgrade pip; \
	pip install -r ./requirements.txt"

dataset:
	@cp ./assets/dataset.csv .

dashboard:
	@streamlit run ./tardis_dashboard.py

clean:
	@find . -name "__pycache__" -type d -exec rm -r {} +

fclean: clean
	@$(RM) $(NAME)
	@$(RM) -r $(VENV_PATH)
	@$(RM) $(DATASETS)
	@$(RM) $(AI_MODELS)

re: fclean all

tests_run: all
	python3 -m unittest ./tests/test_*.py -v
