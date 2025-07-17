#!/usr/bin/python3
##
## EPITECH PROJECT, 2025
## 108trigo
## File description:
## 108trigo
##

import sys
import math

def multiply_matrix(matrix1, matrix2):
    nb_rows_1 = len(matrix1)
    nb_cols_1 = len(matrix1[0])
    nb_rows_2 = len(matrix2)
    nb_cols_2 = len(matrix2[0])
    if nb_cols_1 == nb_rows_2:
        product = [[0 for _ in range(nb_cols_2)] for _ in range(nb_rows_1)]
        for i in range(nb_rows_1):
            for j in range(nb_cols_2):
                for k in range(nb_cols_1):
                    product[i][j] += round(matrix1[i][k] * matrix2[k][j], 10)
    else:
        print("Error: Cannot multiply matrices")
        sys.exit(84)
    return product

def identity_matrix(size):
    return [[1.0 if i == j else 0.0 for j in range(size)] for i in range(size)]

def zero_matrix(size):
    return [[0.0 for _ in range(size)] for _ in range(size)]

def matrix_power(matrix, power):
    size = len(matrix)
    if power == 0:
        return identity_matrix(size)
    if power == 1:
        return matrix
    if power % 2 == 0:
        half_power = matrix_power(matrix, power // 2)
        return multiply_matrix(half_power, half_power)
    else:
        half_power = matrix_power(matrix, power // 2)
        half_result = multiply_matrix(half_power, half_power)
        return multiply_matrix(half_result, matrix)

def factorial(n):
    if n == 0 or n == 1:
        return 1
    return n * factorial(n - 1)

def exp_matrix(matrix):
    size = len(matrix)
    result = identity_matrix(size)
    for n in range(0, 50):
        term = matrix_power(matrix, n)
        coeff = 1 / factorial(n)
        for i in range(size):
            for j in range(size):
                result[i][j] += round(term[i][j] * coeff, 10)
    return result

def sin_matrix(matrix):
    size = len(matrix)
    result = zero_matrix(size)
    for n in range(0, 50):
        power = 2 * n + 1
        coefficient = ((-1) ** n) / factorial(power)
        term = matrix_power(matrix, power)
        for i in range(size):
            for j in range(size):
                result[i][j] += round(term[i][j] * coefficient, 10)
    return result

def cos_matrix(matrix):
    size = len(matrix)
    result = identity_matrix(size)
    for n in range(0, 50):
        power = 2 * n
        coefficient = ((-1) ** n) / factorial(power)
        term = matrix_power(matrix, power)
        for i in range(size):
            for j in range(size):
                result[i][j] += round(term[i][j] * coefficient, 10)
    return result

def sinh_matrix(matrix):
    size = len(matrix)
    result = zero_matrix(size)
    for n in range(0, 50):
        power = 2 * n + 1
        coefficient = 1 / factorial(power)
        term = matrix_power(matrix, power)
        for i in range(size):
            for j in range(size):
                result[i][j] += round(term[i][j] * coefficient, 10)
    return result

def cosh_matrix(matrix):
    size = len(matrix)
    result = identity_matrix(size)
    for n in range(0, 50):
        power = 2 * n
        coefficient = 1 / factorial(power)
        term = matrix_power(matrix, power)
        for i in range(size):
            for j in range(size):
                result[i][j] += round(term[i][j] * coefficient, 10)
    return result

def display_matrix(matrix):
    for row in matrix:
        print("\t".join([f"{val:.2f}" for val in row]))

def parse_arguments():
    function_name = sys.argv[1].upper()
    if function_name not in ["EXP", "SIN", "COS", "SINH", "COSH"]:
        print("Error: Unknown function")
        sys.exit(84)
    try:
        coefficients = [float(arg) for arg in sys.argv[2:]]
    except ValueError:
        print("Error: Invalid coefficients")
        sys.exit(84)
    n = int(math.sqrt(len(coefficients)))
    if n * n != len(coefficients):
        print("Error: Cannot create a square matrix with given coefficients")
        sys.exit(84)
    matrix = []
    for i in range(n):
        row = coefficients[i * n:(i + 1) * n]
        matrix.append(row)
    return function_name, matrix

def main():
    function_name, matrix = parse_arguments()
    if function_name == "EXP":
        result = exp_matrix(matrix)
    elif function_name == "SIN":
        result = sin_matrix(matrix)
    elif function_name == "COS":
        result = cos_matrix(matrix)
    elif function_name == "SINH":
        result = sinh_matrix(matrix)
    elif function_name == "COSH":
        result = cosh_matrix(matrix)
    display_matrix(result)

if __name__ == "__main__":
    main()
