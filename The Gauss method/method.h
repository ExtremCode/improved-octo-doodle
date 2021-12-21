#pragma once
#include <cassert>
#include <math.h>
#include <iostream>

template<typename T> void matrix180_indep(T** a, size_t nr, size_t nc) {
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0, j = nc - 1; c <= j; ++c, --j) {
			T tmp = a[r][c];
			a[r][c] = a[r][j];
			a[r][j] = tmp;
		}
	}
	for (size_t r = 0, j = nr - 1; r <= j; ++r, --j) {
		T* tmp = a[r];
		a[r] = a[j];
		a[j] = tmp;
	}
}

template<typename T> void matrix180_depen(T* a, size_t nr, size_t nc) {
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0, j = nc - 1; c <= j; ++c, --j) {
			T tmp = a[r*nc+c];
			a[r*nc+c] = a[r*nc+j];
			a[r*nc+j] = tmp;
		}
	}

	for (size_t r = 0, j = nr - 1; r <= j; ++r, --j) {
		T* tmp = new T[nc];
		for (size_t i = 0; i < nc; ++i) {
			std::swap(a[r * nc + i], a[j * nc + i]);
		}
	}
}

void method_indep(double** ar, size_t r, size_t c) {
	if (r == c) {
		for (size_t k = 0, bam = 0; k < c; ++k) {
			for (size_t i = bam + 1; i < r; ++i) {
				if (ar[i][k] == 0) {
					continue;
				}
				else {
					if (ar[bam][k] == 0) continue;
					double tmp = (double)ar[i][k] / (double)ar[bam][k];
					for (size_t j = bam; j < c; ++j) {
						ar[i][j] -= ar[bam][j] * tmp;
						ar[i][j] *= 1000000000000000;
						ar[i][j] = nearbyintl(ar[i][j]);
						ar[i][j] /= 1000000000000000;
						if (ar[i][j] <= 0 && abs(ar[i][j]) == 0 || abs(ar[i][j]) <= 9e-15) ar[i][j] = 0;
					}
				}
			}
			if (bam < r - 1 && bam < c - 1) { ++bam; }
			else { break; }
		}
		matrix180_indep(ar, r, c);
		if (ar[0][0] == 0 && ar[0][1] == 0) {
			for (size_t k = 0, bam = 1; k < c; ++k) {
				for (size_t i = bam+1; i < r; ++i) {
					if (ar[i][k] == 0) {
						continue;
					}
					else {
						if (ar[bam][k] == 0) continue;
						double tmp = (double)ar[i][k] / (double)ar[bam][k];
						for (size_t j = bam-1; j < c; ++j) {
							ar[i][j] -= ar[bam][j] * tmp;
							ar[i][j] *= 100000000000000;
							ar[i][j] = nearbyintl(ar[i][j]);
							ar[i][j] /= 100000000000000;
							if (ar[i][j] <= 0 && abs(ar[i][j]) == 0 || abs(ar[i][j])<=9e-15) ar[i][j] = 0; // corection of negative zero and exclusion inaccuracy
						}
					}
				}
				if (bam < r - 1 && bam < c - 1) { ++bam; }
				else { break; }
			}
		}
		else {
			for (size_t k = 0, bam = 0; k < c; ++k) {
				for (size_t i = bam + 1; i < r; ++i) {
					if (ar[i][k] == 0) {
						continue;
					}
					else {
						if (ar[bam][k] == 0) continue;
						double tmp = (double)ar[i][k] / (double)ar[bam][k];
						for (size_t j = bam; j < c; ++j) {
							ar[i][j] -= ar[bam][j] * tmp;
							ar[i][j] *= 100000000000000;
							ar[i][j] = nearbyint(ar[i][j]);
							ar[i][j] /= 100000000000000;
							if (ar[i][j]<=0 && abs(ar[i][j])==0 || abs(ar[i][j]) <= 9e-15) ar[i][j] = 0; // corection of negative zero and exclusion inaccuracy
							
						}
					}
				}
				if (bam < r - 1 && bam < c - 1) { ++bam; }
				else { break; }
			}
		}
		matrix180_indep(ar, r, c);
		for (size_t k = 0, bam = 0; k < c; ++k) {
			for (size_t i = bam + 1; i < r; ++i) {
				if (ar[i][k] == 0) {
					continue;
				}
				else {
					if (ar[bam][k] == 0) continue;
					double tmp = (double)ar[i][k] / (double)ar[bam][k];
					for (size_t j = bam; j < c; ++j) {
						ar[i][j] -= ar[bam][j] * tmp;
						ar[i][j] *= 100000000000000;
						ar[i][j] = nearbyint(ar[i][j]);
						ar[i][j] /= 100000000000000;
						if (ar[i][j] <= 0 && abs(ar[i][j]) == 0 || abs(ar[i][j]) <= 9e-15) ar[i][j] = 0; // corection of negative zero and exclusion inaccuracy
					}
				}
			}
			if (bam < r - 1 && bam < c - 1) { ++bam; }
			else { break; }
		}
	}
	
}

void method_depen(double* ar, size_t nr, size_t nc) {
	if (nr == nc) {
		for (size_t k = 0, bam = 0; k < nc; ++k) {
			for (size_t i = bam + 1; i < nr; ++i) {
				if (ar[i * nc + k] == 0) {
					continue;
				}
				else {
					if (ar[bam * nc + k] == 0) continue;
					double tmp = (double)ar[i * nc + k] / (double)ar[bam * nc + k];
					for (size_t j = bam; j < nc; ++j) {
						ar[i * nc + j] -= ar[bam * nc + j] * tmp;
						ar[i * nc + j] *= 1000000000000000;
						ar[i * nc + j] = nearbyintl(ar[i * nc + j]);
						ar[i * nc + j] /= 1000000000000000;
						if (ar[i * nc + j] <= 0 && abs(ar[i * nc + j]) == 0 || abs(ar[i * nc + j]) <= 9e-15) ar[i * nc + j] = 0;
					}
				}
			}
			if (bam < nr - 1 && bam < nc - 1) { ++bam; }
			else { break; }
		}
		matrix180_depen(ar, nr, nc);
		if (ar[0 * nc + 0] == 0 && ar[0 * nc + 1] == 0) {
			for (size_t k = 0, bam = 1; k < nc; ++k) {
				for (size_t i = bam + 1; i < nr; ++i) {
					if (ar[i * nc + k] == 0) {
						continue;
					}
					else {
						if (ar[bam * nc + k] == 0) continue;
						double tmp = (double)ar[i * nc + k] / (double)ar[bam * nc + k];
						for (size_t j = bam - 1; j < nc; ++j) {
							ar[i * nc + j] -= ar[bam * nc + j] * tmp;
							ar[i * nc + j] *= 100000000000000;
							ar[i * nc + j] = nearbyintl(ar[i * nc + j]);
							ar[i * nc + j] /= 100000000000000;
							if (ar[i * nc + j] <= 0 && abs(ar[i * nc + j]) == 0 || abs(ar[i * nc + j]) <= 9e-15) ar[i * nc + j] = 0; // corection of negative zero and exclusion inaccuracy
						}
					}
				}
				if (bam < nr - 1 && bam < nc - 1) { ++bam; }
				else { break; }
			}
		}
		else {
			for (size_t k = 0, bam = 0; k < nc; ++k) {
				for (size_t i = bam + 1; i < nr; ++i) {
					if (ar[i * nc + k] == 0) {
						continue;
					}
					else {
						if (ar[bam * nc + k] == 0) continue;
						double tmp = (double)ar[i * nc + k] / (double)ar[bam * nc + k];
						for (size_t j = bam; j < nc; ++j) {
							ar[i * nc + j] -= ar[bam * nc + j] * tmp;
							ar[i * nc + j] *= 100000000000000;
							ar[i * nc + j] = nearbyint(ar[i * nc + j]);
							ar[i * nc + j] /= 100000000000000;
							if (ar[i * nc + j] <= 0 && abs(ar[i * nc + j]) == 0 || abs(ar[i * nc + j]) <= 9e-15) ar[i * nc + j] = 0; // corection of negative zero and exclusion inaccuracy

						}
					}
				}
				if (bam < nr - 1 && bam < nc - 1) { ++bam; }
				else { break; }
			}
		}
		matrix180_depen(ar, nr, nc);
		for (size_t k = 0, bam = 0; k < nc; ++k) {
			for (size_t i = bam + 1; i < nr; ++i) {
				if (ar[i * nc + k] == 0) {
					continue;
				}
				else {
					if (ar[bam * nc + k] == 0) continue;
					double tmp = (double)ar[i * nc + k] / (double)ar[bam * nc + k];
					for (size_t j = bam; j < nc; ++j) {
						ar[i * nc + j] -= ar[bam * nc + j] * tmp;
						ar[i * nc + j] *= 100000000000000;
						ar[i * nc + j] = nearbyint(ar[i * nc + j]);
						ar[i * nc + j] /= 100000000000000;
						if (ar[i * nc + j] <= 0 && abs(ar[i * nc + j]) == 0 || abs(ar[i * nc + j]) <= 9e-15) ar[i * nc + j] = 0; // corection of negative zero and exclusion inaccuracy
					}
				}
			}
			if (bam < nr - 1 && bam < nc - 1) { ++bam; }
			else { break; }
		}
	}
}

bool test_indep_method() {
	size_t nr = 3, nc = 3;
	double** test = new double* [nr];
	int num = -5; //works
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new double[nc];
		for (size_t c = 0; c < nc; ++c,++num) {
			test[r][c] = rand()%10;
			test[r][c] += num;
		}
	}
	method_indep(test, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (r != c) assert(test[r][c] == 0);
		}
	}

	nr = 3, nc = 3; //works
	test = new double* [nr];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new double[nc];
		for (size_t c = 0; c < nc; ++c, ++num) {
			test[r][c] = rand() % 20;
		}
	}
	method_indep(test, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (r != c)
				if (test[r][c] != 0) return false;
		}
	}

	nr = 3, nc = 3; //works
	test = new double* [nr];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new double[nc];
		for (size_t c = 0; c < nc; ++c, ++num) {
			test[r][c] = rand()%20;
			test[r][c] -= 30;
		}
	}
	method_indep(test, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (r != c)
				if (test[r][c] != 0) return false;
		}
	}

	nr = 3, nc = 3; //works
	test = new double* [nr];
	num = 0;
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new double[nc];
		for (size_t c = 0; c < nc; ++c, ++num) {
			test[r][c] = num;
		}
	}
	method_indep(test, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (r != c)
				if (test[r][c] != 0) return false;
		}
	}

	nr = 5, nc = 5; // 
	test = new double* [nr];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new double[nc];
		for (size_t c = 0; c < nc; ++c) {
			test[r][c] = rand() % 40;
		}
	}
	method_indep(test, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (r != c)
				if (test[r][c] != 0) return false;
		}
	}

	nr = 5, nc = 5; // works
	test = new double* [nr];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new double[nc];
		for (size_t c = 0; c < nc; ++c) {
			test[r][c] = rand() % 40;
			test[r][c] -=50;
		}
	}
	method_indep(test, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (r != c)
				if (test[r][c] != 0) return false;
		}
	}

	nr = 2, nc = 2; // works
	num = 11;
	test = new double* [nr];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new double[nc];
		for (size_t c = 0; c < nc; ++c, ++num) {
			test[r][c] = num;
		}
	}
	method_indep(test, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (r != c)
				if (test[r][c] != 0) return false;
		}
	}

	for (size_t r = 0; r < nr; ++r) {
		delete[] test[r];
	}delete[] test;

	return true;
}

bool test_depen_method() {
	size_t nr = 3, nc = 3; int num = -5;
	double* arr = new double[nc * nr];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c,++num) {
			arr[r * nc + c]=rand()%10;
			arr[r * nc + c] += num;
		}
	}
	method_depen(arr, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			if (r != c)
				assert(arr[r * nc + c] == 0);
		}
	}

	nr = 4, nc = 4, num = -40;
	arr = new double[nc * nr];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			arr[r * nc + c] = rand()%30;
			arr[r * nc + c] += num;
		}
	}
	method_depen(arr, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			if (r != c)
				assert(arr[r * nc + c] == 0);
		}
	}

	nr = 6, nc = 6, num = 13;
	arr = new double[nc * nr];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			arr[r * nc + c] = rand()%17;
			arr[r * nc + c] += num;
		}
	}
	method_depen(arr, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			if (r != c)
				if(arr[r * nc + c] != 0) return false;
		}
	}
	delete[] arr;
	return true;
}
