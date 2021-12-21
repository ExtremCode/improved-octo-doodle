#pragma once
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
	return result;
}

bool tests_det() {
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
