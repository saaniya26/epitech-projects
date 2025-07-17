from lib.macros import ErrorCodes
from sys import stderr, exit
import math

class TrigoCalc:
    def __init__(self, argv: list[str]) -> None:
        self.argv = argv
        if ("-h" in self.argv) or ("--help" in self.argv):
            self.print_usage()
            exit(ErrorCodes.EXIT_SUCCESS)
        self.matrix: list[list[float]] = None
        self.function_name: str = None
        self.function_name, self.matrix = self.parse_arguments()
        self.result = None

    def execute(self) -> None:
        try:
            if self.function_name == "EXP":
                self.result = self.exp_matrix(self.matrix)
            elif self.function_name == "SIN":
                self.result = self.sin_matrix(self.matrix)
            elif self.function_name == "COS":
                self.result = self.cos_matrix(self.matrix)
            elif self.function_name == "SINH":
                self.result = self.sinh_matrix(self.matrix)
            elif self.function_name == "COSH":
                self.result = self.cosh_matrix(self.matrix)
        except Exception as e:
            print("Error: Unknown Exception during execution", file = stderr)
            exit(ErrorCodes.EXIT_FAILURE_84)

    def print_usage(self) -> None:
        buff: str = ""

        with open("usage.txt", "r") as file:
            buff = file.read()
        print(buff, end = "")

    def multiply_matrix(self, matrix1: list[list[float]], matrix2: list[list[float]]) -> list[list[float]]:
        nb_rows_1 = len(matrix1)
        nb_cols_1 = len(matrix1[0])
        nb_rows_2 = len(matrix2)
        nb_cols_2 = len(matrix2[0])
        if nb_cols_1 == nb_rows_2:
            product = [[0 for _ in range(nb_cols_2)] for _ in range(nb_rows_1)]
            for i in range(nb_rows_1):
                for j in range(nb_cols_2):
                    for k in range(nb_cols_1):
                        product[i][j] += matrix1[i][k] * matrix2[k][j]
        else:
            print("Error: Cannot multiply matrices", file = stderr)
            exit(ErrorCodes.EXIT_FAILURE_84)
        return product

    def identity_matrix(self, size: int) -> list[list[float]]:
        return [[1.0 if i == j else 0.0 for j in range(size)] for i in range(size)]

    def zero_matrix(self, size: int) -> list[list[float]]:
        return [[0.0 for _ in range(size)] for _ in range(size)]

    def matrix_power(self, matrix: list[list[float]], power: int | float) -> list[list[float]]:
        size = len(matrix)
        if power == 0:
            return self.identity_matrix(size)
        if power == 1:
            return matrix
        if power % 2 == 0:
            half_power = self.matrix_power(matrix, power // 2)
            return self.multiply_matrix(half_power, half_power)
        else:
            half_power = self.matrix_power(matrix, power // 2)
            half_result = self.multiply_matrix(half_power, half_power)
            return self.multiply_matrix(half_result, matrix)

    def factorial(self, n: int | float) -> int | float:
        if n == 0 or n == 1:
            return 1
        return n * self.factorial(n - 1)

    def exp_matrix(self, matrix: list[list[float]]) -> list[list[float]]:
        size = len(matrix)
        result = self.identity_matrix(size)
        for n in range(1, 20):
            term = self.matrix_power(matrix, n)
            coeff = 1 / self.factorial(n)
            for i in range(size):
                for j in range(size):
                    result[i][j] += term[i][j] * coeff
        return result

    def sin_matrix(self, matrix: list[list[float]]) -> list[list[float]]:
        size = len(matrix)
        result = self.zero_matrix(size)
        for n in range(0, 10):
            power = 2 * n + 1
            coefficient = ((-1) ** n) / self.factorial(power)
            term = self.matrix_power(matrix, power)
            for i in range(size):
                for j in range(size):
                    result[i][j] += term[i][j] * coefficient
        return result

    def cos_matrix(self, matrix: list[list[float]]) -> list[list[float]]:
        size = len(matrix)
        result = self.identity_matrix(size)
        for n in range(1, 20):
            power = 2 * n
            coefficient = ((-1) ** n) / self.factorial(power)
            term = self.matrix_power(matrix, power)
            for i in range(size):
                for j in range(size):
                    result[i][j] += term[i][j] * coefficient
        return result

    def sinh_matrix(self, matrix: list[list[float]]) -> list[list[float]]:
        size = len(matrix)
        result = self.zero_matrix(size)
        for n in range(0, 10):
            power = 2 * n + 1
            coefficient = 1 / self.factorial(power)
            term = self.matrix_power(matrix, power)
            for i in range(size):
                for j in range(size):
                    result[i][j] += term[i][j] * coefficient
        return result

    def cosh_matrix(self, matrix: list[list[float]]) -> list[list[float]]:
        size = len(matrix)
        result = self.identity_matrix(size)
        for n in range(1, 20):
            power = 2 * n
            coefficient = 1 / self.factorial(power)
            term = self.matrix_power(matrix, power)
            for i in range(size):
                for j in range(size):
                    result[i][j] += term[i][j] * coefficient
        return result

    def display_matrix(self) -> None:
        for row in self.result:
            print("\t".join([f"{val:.2f}" for val in row]))

    def parse_arguments(self):
        try:
            function_name = self.argv[1].upper()
        except IndexError:
            print("Error: Missing operand type", file = stderr)
            exit(ErrorCodes.EXIT_FAILURE_84)
        except Exception as e:
            print(f"Error: Unknown Exception\n{e}", file = stderr)
            exit(ErrorCodes.EXIT_FAILURE_84)
        if function_name not in ["EXP", "SIN", "COS", "SINH", "COSH"]:
            print(f"Error: Unknown function '{function_name}'", file = stderr)
            exit(ErrorCodes.EXIT_FAILURE_84)
        try:
            coefficients = [float(arg) for arg in self.argv[2:]]
        except ValueError:
            print("Error: Invalid coefficients", file = stderr)
            exit(ErrorCodes.EXIT_FAILURE_84)
        n = int(math.sqrt(len(coefficients)))
        if n * n != len(coefficients):
            print("Error: Cannot create a square matrix with given coefficients", file = stderr)
            exit(ErrorCodes.EXIT_FAILURE_84)
        matrix = []
        for i in range(n):
            row = coefficients[i * n:(i + 1) * n]
            matrix.append(row)
        return function_name, matrix
