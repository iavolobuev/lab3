3 лабораторная , 3 задача

#include <iostream>
#include <cmath>
#include <iomanip>

double series_term(int k) {
    return 21.0 / (std::pow(2, k - 1)) + std::pow(-1, k - 1) / (2.0 * std::pow(3, k - 1));
}

int main() {
    const double tolerance = 1e-6;
    double sum = 0.0;
    double term;
    int k = 1;

    do {
        term = series_term(k);
        sum += term;
        k++;
    } while (std::abs(term) > tolerance);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Сумма ряда с точностью до 10^-6: " << sum << std::endl;
    std::cout << "Количество итераций: " << k - 1 << std::endl;

    return 0;
}
