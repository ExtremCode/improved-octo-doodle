#pragma once
#include <fstream>
#include <iostream>
#include <chrono>
template<typename T>
void matrix_to_file_bin(T mat, size_t r, size_t c) {
    std::fstream inf;
    inf.open("matrix.txt", std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
    if (inf.is_open()) {
        for (size_t i = 0; i < r; ++i) {
            inf.write((const char*)mat[i], c*sizeof(T));
        }
    }
    else { std::cout << "Error of write" << std::endl; }
    inf.close();
}
