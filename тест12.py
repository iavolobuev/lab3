# 3 лабораторная , 4 задача

import numpy as np

def series_sum(x, epsilon=1e-6):
    sum_value = 0.0
    k = 1
    while True:
        term = (-1)**k / (np.sin(k*x) + 21 + k**2)
        sum_value += term
        if np.abs(term) < epsilon:
            break
        k += 1
    return sum_value

x_values = [0.1, 1.0, 10.0]
for x in x_values:
    result = series_sum(x)
    print(f"Сумма ряда для x = {x} составляет {result:.6f}")

