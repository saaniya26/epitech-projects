from lib.macros import ErrorCodes
from sys import stderr, exit
import math
from io import TextIOWrapper
import csv
class TitrationCalc:
    def __init__(self, argv: list[str]) -> None:
        self.argv = argv
        self.contents: list[list[str]]
        self.data = []
        file: TextIOWrapper = None
        if ("-h" in self.argv) or ("--help" in self.argv):
            self.print_usage()
            exit(ErrorCodes.EXIT_SUCCESS)
        if (len(argv) < 2):
            print(f"ERROR: File argument missing.", file = stderr)
            exit(ErrorCodes.EXIT_FAILURE_84)
        if (len(argv) > 2):
            print(f"ERROR: Too much arguments.", file = stderr)
            exit(ErrorCodes.EXIT_FAILURE_84)
        try:
            file = open(argv[1], "r")
            reader = csv.reader(file, delimiter = ';', strict = True)
            self.contents = list(reader)
            if (self.contents == None or self.contents == []):
                raise csv.Error("No contents inside of CSV")
            for row in self.contents:
                try:
                    volume = float(row[0])
                    ph = float(row[1])
                    self.data.append((volume, ph))
                except ValueError:
                    raise csv.Error("Strings found inside of number-only CSV")
            self.data.sort()
            if len(self.data) < 3:
                raise ValueError("At least 3 data points are required")
            file.close()
        except (csv.Error, FileExistsError, FileNotFoundError) as e:
            if (file):
                file.close()
            print(f"ERROR: CSV file could not be read.\nReason: \"{e}\"", file = stderr)
            exit(ErrorCodes.EXIT_FAILURE_84)
        except Exception as e:
            if (file):
                file.close()
            print(f"ERROR: An unknown exception has occured.\nReason: \"{e}\"", file = stderr)
            exit(ErrorCodes.EXIT_FAILURE_84)

    def execute(self):
        first_derivatives = self.calculate_first_derivative()
        print("Derivative:")
        for vol, deriv in first_derivatives:
            print(f"{vol:.1f} ml -> {deriv:.2f}")
        print()
        equivalence_point = self.find_max_derivative_point(first_derivatives)
        print(f"Equivalence point at {equivalence_point:.1f} ml")
        print()
        second_derivatives = self.calculate_second_derivative(first_derivatives)
        print("Second derivative:")
        for vol, deriv in second_derivatives:
            print(f"{vol:.1f} ml -> {deriv:.2f}")
        if second_derivatives:
            start_range = equivalence_point - 0.5
            end_range = equivalence_point + 1.0
            estimated = self.estimate_second_derivative_range(second_derivatives, start_range, end_range)
            print()
            print("Second derivative estimated:")
            for vol, deriv in estimated:
                print(f"{vol:.1f} ml -> {deriv:.2f}")
            precise_equivalence = self.find_zero_crossing(estimated)
            print()
            print(f"Equivalence point at {precise_equivalence:.1f} ml")

    def rate_of_change(self, p1, p2):
        x1, y1 = p1
        x2, y2 = p2

        if x2 == x1:
            raise ValueError("Cannot calculate with same x values")
        return (y2 - y1) / (x2 - x1)

    def estimate_derivative(self, p1, p2, p3):
        x1, y1 = p1
        x2, y2 = p2
        x3, y3 = p3

        backward_rate = self.rate_of_change(p1, p2)
        forward_rate = self.rate_of_change(p2, p3)
        h1 = x2 - x1
        h2 = x3 - x2
        w1 = h2 / (h1 + h2)
        w2 = h1 / (h1 + h2)
        return w1 * backward_rate + w2 * forward_rate

    def interpolate(self, p1, p2, x):
        x1, y1 = p1
        x2, y2 = p2
        if x1 == x2:
            return (y1 + y2) / 2
        return y1 + (y2 - y1) * (x - x1) / (x2 - x1)

    def calculate_first_derivative(self):
        derivatives = []
        n = len(self.data)
        for i in range(1, n - 1):
            derivative = self.estimate_derivative(self.data[i - 1], self.data[i], self.data[i + 1])
            derivatives.append((self.data[i][0], derivative))
        return derivatives

    def calculate_second_derivative(self, derivatives):
        second_derivatives = []
        n = len(derivatives)
        for i in range(1, n - 1):
            second_deriv = self.estimate_derivative(
                derivatives[i - 1], derivatives[i], derivatives[i + 1])
            second_derivatives.append((derivatives[i][0], second_deriv))
        return second_derivatives

    def find_max_derivative_point(self, derivatives):
        max_value = derivatives[0][1]
        max_point = derivatives[0][0]
        for vol, deriv in derivatives:
            if deriv > max_value:
                max_value = deriv
                max_point = vol
        return max_point

    def estimate_second_derivative_range(self, second_derivatives, start_vol, end_vol, step=0.1):
        estimated = []
        current_vol = start_vol
        while current_vol <= end_vol + 0.001:
            current_vol = round(current_vol, 1)
            lower_point = None
            upper_point = None
            for point in second_derivatives:
                vol, val = point
                if vol <= current_vol and (lower_point is None or vol > lower_point[0]):
                    lower_point = point
                if vol >= current_vol and (upper_point is None or vol < upper_point[0]):
                    upper_point = point
            if lower_point is None:
                if upper_point is None:
                    continue
                if len(second_derivatives) >= 2:
                    estimated_value = self.interpolate(
                        second_derivatives[0], second_derivatives[1], current_vol
                    )
                else:
                    estimated_value = upper_point[1]
            elif upper_point is None:
                if len(second_derivatives) >= 2:
                    estimated_value = self.interpolate(
                        second_derivatives[-2], second_derivatives[-1], current_vol)
                else:
                    estimated_value = lower_point[1]
            else:
                estimated_value = self.interpolate(lower_point, upper_point, current_vol)
            estimated.append((current_vol, round(estimated_value, 2)))
            current_vol += step
        return estimated

    def find_zero_crossing(self, derivatives):
        for i in range(1, len(derivatives) - 1):
            prev_vol, prev_val = derivatives[i - 1]
            curr_vol, curr_val = derivatives[i]
            if prev_val >= 0 and curr_val < 0:
                if prev_val == 0:
                    return prev_vol
                zero_vol = prev_vol + (0 - prev_val) * (curr_vol - prev_vol) / (curr_val - prev_val)
                return round(zero_vol, 1)
        closest_point = derivatives[0][0]
        closest_value = abs(derivatives[0][1])
        for vol, val in derivatives:
            if abs(val) < closest_value:
                closest_value = abs(val)
                closest_point = vol
        return closest_point

    def print_usage(self) -> None:
        buff: str = ""

        with open("usage.txt", "r") as file:
            buff = file.read()
        print(buff, end = "")
