#include <iostream>
#include "method.h"

int main()
{
    size_t r, c;
    std::cin >> r>> c;
    int** arr = new int* [r];
    for (size_t i = 0; i < r; ++i) {
        arr[i] = new int[c];
        for (size_t j = 0; j < c; ++j) {
            arr[i][j] = rand() % 23;
        }
    }
    tests();
    for (size_t i = 0; i < r; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}