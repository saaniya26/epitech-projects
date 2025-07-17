from enum import Enum
from lib.macros import ErrorCodes

class BombyxCalcMode(Enum):
    UNKN_MODE = -1
    DEFAULT_MODE = 0
    K_MODE = 1
    I0_I1_MODE = 2

class BombyxCalculator:
    class Operations:
        pass
    def __init__(self, mode: BombyxCalcMode, data_set: list[int] | list[int, float] | list[int, int, int]):
        self.mode = mode
        self.data_set = data_set

    def exec_calculation(self):
        if (self.mode == BombyxCalcMode.UNKN_MODE):
            print(f"(Error)\nUnknown mode triggered. This may be happening because you inserted a float at the i0 position insteal of an integer.")
            exit(ErrorCodes.EXIT_FAILURE_84)
        if (self.mode == BombyxCalcMode.DEFAULT_MODE):
            self.default_mode()
        if (self.mode == BombyxCalcMode.K_MODE):
            self.k_mode()
        if (self.mode == BombyxCalcMode.I0_I1_MODE):
            self.i0_i1_mode()

    def default_mode(self):
        n = float(self.data_set[0])
        k = 1.0
        x = n
        for i in range(1, 101):
            print(f"{i} {x:.2f}")
            x = k * x * ((1000 - x) / 1000)

    def k_mode(self):
        n = float(self.data_set[0])
        k = float(self.data_set[1])

        if k < 1 or k > 4:
            print(f"(Error)\nGrowth rate k must be between 1 and 4.")
            exit(ErrorCodes.EXIT_FAILURE_84)
        x = n
        for i in range(1, 101):
            print(f"{i} {x:.2f}")
            x = k * x * (1000 - x) / 1000

    def i0_i1_mode(self):
        try:
            n = int(self.data_set[0])
            i0 = int(self.data_set[1])
            i1 = int(self.data_set[2])

            if i0 < 1 or i1 < i0:
                print(f"(Error)\nInvalid generation range.")
                exit(ErrorCodes.EXIT_FAILURE_84)

            for k in range(100, 401):
                k = k / 100
                x = n

                for _ in range(1, i0):
                    x = k * x * (1000 - x) / 1000

                for _ in range(i0, i1 + 1):
                    print(f"{k:.2f} {x:.2f}")
                    x = k * x * (1000 - x) / 1000

        except ValueError:
            print(f"(Error)\nInvalid numeric values provided.")
            exit(ErrorCodes.EXIT_FAILURE_84)
