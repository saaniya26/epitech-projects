#!/usr/bin/python3

##
## EPITECH PROJECT, 2025
## 108trigo
## File description:
## 108trigo
##

import sys
from lib.macros import ErrorCodes
from lib.trigo import TrigoCalc

def main(argv: list[str]):
    calculator = TrigoCalc(argv)
    calculator.execute()
    calculator.display_matrix()
    exit(ErrorCodes.EXIT_SUCCESS)

if __name__ == "__main__":
    main(sys.argv)
