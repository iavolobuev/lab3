# 3 лабораторная , 2 задача
import numpy as np
from scipy.integrate import quad, simps, trapezoid

def integrand(x):
    return np.exp(-2*x) * np.sin(21*x)

a = 0
b = np.inf

quad_result, quad_error = quad(integrand, a, b)

b_finite = 10

n = 1000
x = np.linspace(a, b_finite, n)
h = (b_finite - a) / n

y = integrand(x)

rect_result = np.sum(integrand((x[:-1] + x[1:]) / 2)) * h

trap_result = trapezoid(y, x)

simp_result = simps(y, x)

print(f"Метод quad: {quad_result:.6f} (погрешность: {quad_error:.6f})")
print(f"Метод прямоугольников: {rect_result:.6f}")
print(f"Метод трапеций: {trap_result:.6f}")
print(f"Метод Симпсона: {simp_result:.6f}")
