#include <iostream>
#include "matrix.h"

int main()
{
	size_t r, c;
	int num;
	std::cin >> r >> c >> num;
	int** arr = new int* [r];
	int** arrpl = new int* [r];
	int** matplval = new int* [r];
	for (size_t i = 0; i < r; ++i) {
		arr[i] = new int[c];
		arrpl[i] = new int[c];
		matplval[i] = new int[c];
	}
	for (size_t nr = 0; nr < r; ++nr) {
		for (size_t nc = 0; nc < c; ++nc) {
			arr[nr][nc] = rand() % 10;
			arrpl[nr][nc] = rand() % 10;
		}
	}
	matplval = mat_plus(arr, arrpl, r, c, r, c);
	for (size_t j = 0; j < r; ++j) {
		delete[] arr[j];
	}
	delete[] arr;
	for (size_t j = 0; j < r; ++j) {
		delete[] arrpl[j];
	}
	delete[] arrpl;
	int** zavisim = new int* [r * c];
	delete[] zavisim;
}