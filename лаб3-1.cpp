3 лабораторная , 1 задача

#include <iostream>
#include <cmath>
#include <iomanip>

double f(double x) {
    return std::pow(x, 4) / (21 + std::pow(x, 2));
}

double rectangle_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += f(a + i * h);
    }
    return sum * h;
}

double trapezoidal_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return sum * h;
}

double simpson_method(double a, double b, int n) {
    if (n % 2 != 0) n++;
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        if (i % 2 == 0) {
            sum += 2 * f(a + i * h);
        } else {
            sum += 4 * f(a + i * h);
        }
    }
    return sum * h / 3;
}

int main() {
    double a = 1.0;
    double b = 2.0;
    int n = 10000;

    std::cout << std::fixed << std::setprecision(6);

    double result_rectangle = rectangle_method(a, b, n);
    std::cout << "Метод прямоугольников: " << result_rectangle << std::endl;

    double result_trapezoidal = trapezoidal_method(a, b, n);
    std::cout << "Метод трапеций: " << result_trapezoidal << std::endl;

    double result_simpson = simpson_method(a, b, n);
    std::cout << "Метод Симпсона: " << result_simpson << std::endl;

    return 0;
}
