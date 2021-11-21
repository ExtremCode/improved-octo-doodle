#pragma once
#include <cassert>
#include <vector>
template<typename T> void method(T** ar, size_t r, size_t c) {
	for (size_t k = 0, bam=0; k < c; ++k) {
		for (size_t i = bam+1; i < r; ++i) {
			if (ar[i][k] == 0) {
				continue;
			}
			else {
				double tmp = (double)ar[i][k] / (double)ar[bam][k];
				for (size_t j = bam; j < c; ++j) {
					ar[i][j] -= ar[bam][j] * tmp;
				}
			}
		}
		if (bam < r-1 && bam < c-1) { ++bam; }
		else { break; }
	}
	std::cout << std::endl;
}

bool tests() {
	size_t r=2, c=2;
	int** m = new int* [r];
	for (size_t i = 0,num=1; i < r; ++i) {
		m[i] = new int[c];
		for (size_t j = 0; j < c; ++j,++num) {
			m[i][j] = num;
		}
	}
	int** fo = new int* [r];
	for (size_t i = 0; i < r; ++i) {
		fo[i] = new int[c];
	}
	fo[0][0] = 1; fo[0][1] = 2; fo[1][0] = 0; fo[1][1] = -2;
	method(m, r, c);
	assert(m[0][0] == fo[0][0]);
	assert(m[1][0] == fo[1][0]);
	assert(m[0][1] == fo[0][1]);
	assert(m[1][1] == fo[1][1]);
	r = 2; c = 3;
	m = new int* [r];
	for (size_t i = 0, num = 1; i < r; ++i) {
		m[i] = new int[c];
		for (size_t j = 0; j < c; ++j, ++num) {
			m[i][j] = num;
		}
	}
	fo = new int* [r];
	for (size_t i = 0; i < r; ++i) {
		fo[i] = new int[c];
	}
	fo[0][0] = 1; fo[0][1] = 2; fo[0][2] = 3; fo[1][0] = 0; fo[1][1] = -3; fo[1][2] = -6;
	method(m, r, c);
	assert(m[0][0] == fo[0][0]);
	assert(m[0][1] == fo[0][1]);
	assert(m[0][2] == fo[0][2]);
	assert(m[1][0] == fo[1][0]);
	assert(m[1][1] == fo[1][1]);
	assert(m[1][2] == fo[1][2]);
	for (size_t i = 0; i < r; ++i) {
		delete[] m[i];
	}
	delete[] m;
	for (size_t i = 0; i < r; ++i) {
		delete[] fo[i];
	}
	delete[] fo;
	return true;
}
