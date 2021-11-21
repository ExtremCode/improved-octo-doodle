#include <iostream>
#include "det.h"

int main()
{
    size_t r;
    std::cin >> r;
    double** mas = new double* [r];
    for (size_t i = 0; i < r; ++i) {
        mas[i] = new double[r];
        for (size_t j = 0; j < r; ++j) {
            mas[i][j] = rand() % 23;
        }
    }
    for (size_t i = 0; i < r; ++i) {
        delete[] mas[i];
    }
    delete[] mas;
}