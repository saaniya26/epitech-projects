from lib.macros import ErrorCodes
from sys import stderr

class Polynominial:
    def __init__(self, argv: list[str]):
        self.argv = argv
        self.execute()

    def parse_polynomial(self, line: list[str]):
        try:
          return [float(x) for x in line.split('*')]
        except ValueError:
          print(f"(Error):\nInvalid data in arguments", file = stderr)
          exit(ErrorCodes.EXIT_FAILURE_84)
        except Exception as e:
          print(f"(Error):\nUncaught error.\n{e}", file = stderr)
          exit(ErrorCodes.EXIT_FAILURE_84)

    def evaluate_polynomial(self, coefficients, x):
        result = 0
        for coeff in coefficients:
            result = result * x + coeff
        return result

    def evaluate_rational(self, numerator, denominator, x):
        num_value = self.evaluate_polynomial(numerator, x)
        denom_value = self.evaluate_polynomial(denominator, x)
        if denom_value == 0:
            return None
        return num_value / denom_value

    def execute(self):
        polynomials = []
        for i in range(0, len(self.argv), 2):
            try:
                num_str = self.argv[i]
                den_str = self.argv[i+1]
            except IndexError:
                print(f"(Error):\nMissing argument: (Denominator)", file = stderr)
                exit(ErrorCodes.EXIT_FAILURE_84)
            except Exception as e:
                print(f"(Error):\nUncaught error.\n{e}", file = stderr)
                exit(ErrorCodes.EXIT_FAILURE_84)
            num_coeffs = self.parse_polynomial(num_str)
            den_coeffs = self.parse_polynomial(den_str)
            num_coeffs.reverse()
            den_coeffs.reverse()
            polynomials.append((num_coeffs, den_coeffs))
        for i in range(1001):
            x = i / 1000
            result = 1.0
            for num_coeffs, den_coeffs in polynomials:
                value = self.evaluate_rational(num_coeffs, den_coeffs, x)
                if value is None:
                    result = None
                    break
                result *= value
            if result is None:
                print(f"(Error):\nDivision by zero", file = stderr)
                exit(ErrorCodes.EXIT_FAILURE_84)
            else:
                print(f"{x:.3f} -> {result:.5f}")