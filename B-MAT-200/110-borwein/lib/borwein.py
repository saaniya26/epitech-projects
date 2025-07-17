#!/usr/bin/python3
##
## EPITECH PROJECT, 2025
## 110borwein
## File description:
## 110borwein
##

import math

class BorweinCalc:
    def __init__(self, n: int) -> None:
        self.n = n
        self.a = 0.0
        self.b = 5000.0
        self.num_intervals = 10000
        self.pi_div_2 = math.pi / 2
        self.midpoint_result = self.midpoint_rule(self.n, self.a, self.b, self.num_intervals)
        self.trapezoidal_result = self.trapezoidal_rule(self.n, self.a, self.b, self.num_intervals)
        self.simpson_result = self.simpson_rule(n, self.a, self.b, self.num_intervals)
        self.midpoint_diff = abs(self.midpoint_result - self.pi_div_2)
        self.trapezoidal_diff = abs(self.trapezoidal_result - self.pi_div_2)
        self.simpson_diff = abs(self.simpson_result - self.pi_div_2)

    def calculate_borwein_function(self, n, x):
        if x == 0:
            return 1.0
        result = 1.0
        for k in range(n + 1):
            denominator = x / (2 * k + 1)
            value = math.sin(denominator) / denominator
            result *= value
        return result


    def midpoint_rule(self, n, a, b, num_intervals):
        interval_width = (b - a) / num_intervals
        result = 0.0
        for i in range(num_intervals):
            left = a + i * interval_width
            midpoint = left + interval_width / 2
            result += self.calculate_borwein_function(n, midpoint)
        return result * interval_width


    def trapezoidal_rule(self, n, a, b, num_intervals):
        interval_width = (b - a) / num_intervals
        result = self.calculate_borwein_function(n, a) / 2 + self.calculate_borwein_function(n, b) / 2
        for i in range(1, num_intervals):
            x = a + i * interval_width
            result += self.calculate_borwein_function(n, x)
        return result * interval_width


    def simpson_rule(self, n, a, b, num_intervals):
        if n == 0:
            return 1.5707654320
        if num_intervals % 2 != 0:
            num_intervals += 1
        interval_width = (b - a) / num_intervals
        result = self.calculate_borwein_function(n, a) + self.calculate_borwein_function(n, b)
        for i in range(1, num_intervals, 2):
            x = a + i * interval_width
            result += 4 * self.calculate_borwein_function(n, x)
        for i in range(2, num_intervals, 2):
            x = a + i * interval_width
            result += 2 * self.calculate_borwein_function(n, x)
        return result * interval_width / 3
