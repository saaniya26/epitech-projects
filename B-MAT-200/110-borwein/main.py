#!/usr/bin/python3

##
## EPITECH PROJECT, 2025
## 108trigo
## File description:
## 108trigo
##

import sys
import math
from lib.macros import ErrorCodes
from lib.borwein import BorweinCalc

def print_usage() -> None:
    buff: str = ""

    with open("usage.txt", "r") as file:
        buff = file.read()
    print(buff, end = "")

def main(argv: list[str]):
    if (("-h" in argv) or ("--help" in argv)):
        print_usage()
        sys.exit(ErrorCodes.EXIT_SUCCESS)
    if len(argv) != 2:
        print(f"Error: Invalid number of arguments.", file=sys.stderr)
        sys.exit(ErrorCodes.EXIT_FAILURE_84)
    try:
        n = int(argv[1])
        if n < 0:
            print(f"Error: n must be a non negative integer.", file=sys.stderr)
            sys.exit(ErrorCodes.EXIT_FAILURE_84)
    except ValueError:
        print(f"Error: n must be a non negative integer.", file=sys.stderr)
        sys.exit(ErrorCodes.EXIT_FAILURE_84)
    borwein = BorweinCalc(n)
    print("Midpoint:")
    print(f"I{n} = {borwein.midpoint_result:.10f}")
    print(f"diff = {borwein.midpoint_diff:.10f}")
    print("\nTrapezoidal:")
    print(f"I{n} = {borwein.trapezoidal_result:.10f}")
    print(f"diff = {borwein.trapezoidal_diff:.10f}")
    print("\nSimpson:")
    print(f"I{n} = {borwein.simpson_result:.10f}")
    print(f"diff = {borwein.simpson_diff:.10f}")
    exit(ErrorCodes.EXIT_SUCCESS)

if __name__ == "__main__":
    main(sys.argv)
