#!/usr/bin/python3
##
## EPITECH PROJECT, 2025
## B-MAT-200
## File description:
## main
##

import sys
from lib.macros import ErrorCodes
from lib.polynominial import Polynominial
from sys import stderr


def main(args: list[str]):
    if ("-h" in args) or ("--help" in args):
        try:
            file = open("usage.txt")
            print(file.read(), end = "")
            file.close()
            exit(ErrorCodes.EXIT_SUCCESS)
        except Exception as e:
            print(f"(Error):\nUncaught error.\n{e}", file = stderr)
            exit(ErrorCodes.EXIT_FAILURE_84)
    if (args == []):
        print(f"(Error):\nNo arguments supplied.", file = stderr)
        exit(ErrorCodes.EXIT_FAILURE_84)
    Polynominial(args)
    exit(ErrorCodes.EXIT_SUCCESS)

if __name__ == "__main__":
    try:
        main(sys.argv[1:])
    except Exception as e:
        print(f"(Error):\nUncaught error.\n{e}", file = stderr)
        exit(ErrorCodes.EXIT_FAILURE_84)
