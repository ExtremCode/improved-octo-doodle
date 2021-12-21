#pragma once
#include <math.h>
void method_straight_indep(double** ar, size_t r, size_t c) {
	for (size_t k = 0, bam = 0; k < c; ++k) {
		for (size_t i = bam + 1; i < r; ++i) {
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
		if (bam < r - 1 && bam < c - 1) { ++bam; }
		else { break; }
	}
}
template<typename T> T det_mat_indep(T** m, size_t r) {
	T result = 1;
	if (r == 2) { result = m[0][0] * m[1][1] - m[0][1] * m[1][0]; return result; }
	else if (r == 3) {
		result = m[0][0] * m[1][1] * m[2][2] + m[2][0] * m[0][1] * m[1][2]
			+ m[0][2] * m[1][0] * m[2][1] - m[0][2] * m[1][1] * m[2][0] - m[2][2] * m[0][1]
			* m[1][0] - m[0][0] * m[2][1] * m[1][2];
	}
	else {
		method(m, r, r);
		for (size_t i=0; i < r; ++i) {
			result *= m[i][i];
		}
	}
	return nearbyint(result);
}
void method_straight_depen(double* ar, size_t r, size_t c) {
	for (size_t k = 0, bam = 0; k < c; ++k) {
		for (size_t i = bam + 1; i < r; ++i) {
			if (ar[i*c+k] == 0) {
				continue;
			}
			else {
				double tmp = (double)ar[i*c+k] / (double)ar[bam*c+k];
				for (size_t j = bam; j < c; ++j) {
					ar[i*c+j] -= ar[bam*c+j] * tmp;
				}
			}
		}
		if (bam < r - 1 && bam < c - 1) { ++bam; }
		else { break; }
	}
}

template<typename T> T det_mat_depen(T* m, size_t r) {
	T result = 1;
	if (r == 2) { result = m[0 * r + 0] * m[1 * r + 1] - m[0 * r + 1] * m[1 * r + 0]; return result; }
	else if (r == 3) {
		result = m[0 * r + 0] * m[1 * r + 1] * m[2 * r + 2] + m[2 * r + 0] * m[0 * r + 1] * m[1 * r + 2]
			+ m[0 * r + 2] * m[1 * r + 0] * m[2 * r + 1] - m[0 * r + 2] * m[1 * r + 1] * m[2 * r + 0] - m[2 * r + 2] * m[0 * r + 1]
			* m[1 * r + 0] - m[0 * r + 0] * m[2 * r + 1] * m[1 * r + 2];
	}
	else {
		method_straight_depen(m, r, r);
		for (size_t i = 0; i < r; ++i) {
			result *= m[i*r+i];
		}
	}
	return nearbyint(result); // exclusion of inaccuracy
}

bool tests_det_depen() {
	size_t r = 4;
	double* mas = new double[r*r];
	for (size_t i = 0, num = 1; i < r; ++i, ++num) {
		for (size_t j = 0; j < r; ++j) {
			mas[i*r+j] = num;
		}
	}
	if (0 != det_mat_depen(mas, r)) { return false; }

	r = 2;
	mas = new double[r*r];
	mas[0*r+0] = 23; mas[0*r+1] = 0; mas[1 * r + 0] = 13; mas[1 * r + 1] = 7;
	if (161 != det_mat_depen(mas, r)) { return false; }

	r = 3;
	mas = new double[r*r];
	for (size_t i = 0, num = 1; i < r; ++i, ++num) {
		for (size_t j = 0; j < r; ++j) {
			mas[i*r+j] = num;
		}
	}
	if (0 != det_mat_depen(mas, r)) { return false; }

	r = 5;
	mas = new double[r * r];
	for (size_t i = 0, num = 1; i < r; ++i, ++num) {
		for (size_t j = 0; j < r; ++j) {
			mas[i * r + j] = num;
		}
	}
	if (0 != det_mat_depen(mas, r)) { return false; }

	r = 6;
	mas = new double[r * r];
	for (size_t i = 0, num = 1; i < r; ++i, ++num) {
		for (size_t j = 0; j < r; ++j) {
			mas[i * r + j] = num;
		}
	}
	if (0 != det_mat_depen(mas, r)) { return false; }

	r = 3;
	mas = new double[r * r];
	mas[0 * r + 0] = 17; mas[0 * r + 1] = 39; mas[0 * r + 2] = 63; mas[1 * r + 0] = 7;
	mas[1 * r + 1] = -53; mas[1 * r + 2] = 0; mas[2 * r + 0] = -4; mas[2 * r + 1] = 10, mas[2 * r + 2] = 102;
	if (-128694 != det_mat_depen(mas, r)) { return false; }

	r = 4;
	mas = new double[r * r];
	mas[0 * r + 0] = 11;
	mas[0 * r + 1] = 9;
	mas[0 * r + 2] = -6;
	mas[0 * r + 3] = 12;
	mas[1 * r + 0] = 17;
	mas[1 * r + 1] = 34;
	mas[1 * r + 2] = -8;
	mas[1 * r + 3] = 10;
	mas[2 * r + 0] = -23;
	mas[2 * r + 1] = 15;
	mas[2 * r + 2] = 3;
	mas[2 * r + 3] = 63;
	mas[3 * r + 0] = 7;
	mas[3 * r + 1] = 100;
	mas[3 * r + 2] = 1;
	mas[3 * r + 3] = 67;
	if (-230778 != det_mat_depen(mas, r)) { return false; }

	delete[] mas;
	return true;
}
bool tests_det_indep() {
	size_t r = 4;
	double** mas = new double* [r];
	for (size_t i = 0,num=1; i < r; ++i,++num) {
		mas[i] = new double[r];
		for (size_t j = 0; j < r; ++j) {
			mas[i][j] = num;
		}
	}
	if (0 != det_mat_indep(mas, r)) { return false; }

	r = 2;
	mas = new double* [r];
	for (size_t i = 0, num = 0; i < r; ++i, ++num) {
		mas[i] = new double[r];
	}
	mas[0][0] = 23; mas[0][1] = 0; mas[1][0] = 13; mas[1][1] = 7;
	if (161 != det_mat_indep(mas, r)) { return false; }

	r = 3;
	mas = new double* [r];
	for (size_t i = 0, num = 1; i < r; ++i, ++num) {
		mas[i] = new double[r];
		for (size_t j = 0; j < r; ++j) {
			mas[i][j] = num;
		}
	}
	if (0 != det_mat_indep(mas, r)) { return false; }

	for (size_t i = 0; i < r; ++i) {
		delete[] mas[i];
	}
	delete[] mas;
	return true;
}
