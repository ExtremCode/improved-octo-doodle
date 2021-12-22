#pragma once
#include <iostream>

template <typename T> T& link_return_depen(T* ar, size_t r, size_t c,size_t nc) {
	T &pp = ar[r * nc + c];
	return pp;
}

template<typename T> void matrixE_indep(T** arr, size_t nr, size_t nc) {
	if(nr==nc){
		for (size_t r = 0; r < nr; ++r) {
			for (size_t c = 0; c < nc; ++c) {
				if (r == c) { arr[r][c] = 1; }
				else { arr[r][c] = 0; }
			}
		}
	}
}

template<typename T> void matrixE_depen(T* arr, size_t nr, size_t nc) {
	if (nr == nc) {
		for (size_t r = 0; r < nr; ++r) {
			for (size_t c = 0; c < nc; ++c) {
				if (r == c) { arr[r*nc+c] = 1; }
				else { arr[r*nc+c] = 0; }
			}
		}
	}
}

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

template<typename T> void matrix_num_indep(T** arr, size_t nr, size_t nc, int num) {
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			arr[r][c] = num;
			num += 1;
		}
	}
}

template<typename T> void matrix_num_depen(T* arr, size_t nr, size_t nc, int num) {
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c,++num) {
			arr[r*nc+c] = num;
		}
	}
}

template<typename T> T** mat_plus_mat_indep(T** ar, T** m, size_t nr1, size_t nc1, size_t nr2, size_t nc2) {
	T** nw = new T* [nr1];
	for (size_t i = 0; i < nr1; ++i) {
		nw[i] = new T[nc1];
	}
	if (nr1 != nr2 || nc1 != nc2) {
		for (size_t r = 0; r < nr1; ++r) {
			for (size_t c = 0; c < nc1; ++c) {
				nw[r][c] = 0;
			}
		}
		return nw;
	}
	else {
		for (size_t r = 0; r < nr1; ++r) {
			for (size_t c = 0; c < nc1; ++c) {
				nw[r][c] = ar[r][c] + m[r][c];
			}
		}
	}
	return nw;
}

template<typename T> T* mat_plus_mat_depen(T* ar, T* m, size_t nr1, size_t nc1, size_t nr2, size_t nc2) {
	T* nw = new T [nr1*nc1];
	if (nr1 != nr2 || nc1 != nc2) {
		for (size_t r = 0; r < nr1; ++r) {
			for (size_t c = 0; c < nc1; ++c) {
				nw[r*nc1+c] = 0;
			}
		}
		return nw;
	}
	else {
		for (size_t r = 0; r < nr1; ++r) {
			for (size_t c = 0; c < nc1; ++c) {
				nw[r*nc1+c] = ar[r*nc1+c] + m[r*nc2+c];
			}
		}
	}
	return nw;
}

template<typename T> T** mat_mult_mat_indep(T** ar, size_t nr1, size_t nc1, T** mas, size_t nr2, size_t nc2) {
	T** nw = new T* [nr1];
	for (size_t i = 0; i < nr1; ++i) {
		nw[i] = new T[nc2];
	}
	if (nc1 != nr2) {
		for (size_t r = 0; r < nr1; ++r) {
			for (size_t c = 0; c < nc2; ++c) {
				nw[r][c] = 0U;
			}
		}
		return nw;
	}
	for (size_t r = 0; r < nr1; ++r) {
		for (size_t c = 0; c < nc2; ++c) {
			nw[r][c] = 0;
		}
	}
	for (size_t r = 0; r < nr1; ++r) {
		for (size_t nc = 0; nc < nc2;++nc) {
			for (size_t c = 0; c < nc1; ++c) {
				nw[r][nc] += ar[r][c] * mas[c][nc];
			}
		}
	}
	return nw;
}

template<typename T> T* mat_mult_mat_depen(T* ar, size_t nr1, size_t nc1, T* mas, size_t nr2, size_t nc2) {
	T* nw = new T [nr1];
	if (nc1 != nr2) {
		for (size_t r = 0; r < nr1; ++r) {
			for (size_t c = 0; c < nc2; ++c) {
				nw[r*nc2+c] = 0U;
			}
		}
		return nw;
	}
	else {
		for (size_t r = 0; r < nr1; ++r) {
			for (size_t c = 0; c < nc2; ++c) {
				nw[r * nc2 + c] = 0;
			}
		}
		for (size_t r = 0; r < nr1; ++r) {
			for (size_t nc = 0; nc < nc2; ++nc) {
				for (size_t c = 0; c < nc1; ++c) {
					nw[r * nc2 + nc] += ar[r * nc1 + c] * mas[c * nc2 + nc];
				}
			}
		}
		return nw;
	}
}

template<typename T> void change_el_indep(T** ar, size_t r, size_t c,size_t num1, size_t num2, std::string what) {
	if (what == "rows") {
		T* tmp = new T [c];
		tmp = ar[num1];
		ar[num1] = ar[num2];
		ar[num2] = tmp;
	}
	else if (what == "colunms") {
		for (size_t i = 0; i < r; ++i) {
			T tmp = ar[i][num1];
			ar[i][num1] = ar[i][num2];
			ar[i][num2] = tmp;
		}
	}
}

template<typename T> void change_el_depen(T* ar, size_t r, size_t c, size_t num1, size_t num2, std::string what) {
	if (what == "rows") {
		if (num2 < r) {
			T* tmp = new T[c];
			for (size_t nc = 0; nc < c; ++nc) {
				tmp[nc] = ar[num1 * c + nc];
				ar[num1 * c + nc] = ar[num2 * c + nc];
				ar[num2 * c + nc] = tmp[nc];
			}
			delete[] tmp;
		}
	}
	else if (what == "cols") {
		if (num2 < c) {
			for (size_t i = 0; i < r; ++i) {
				T tmp = ar[i * c + num1];
				ar[i * c + num1] = ar[i * c + num2];
				ar[i * c + num2] = tmp;
			}
		}
	}
}

template<typename T> void number_mult_mat_indep(T** ar, size_t r, size_t c, int num) {
	for (size_t i = 0; i < r; ++i) {
		for (size_t j = 0; j < c; ++j) {
			ar[i][j] *= num;
		}
	}
}

template<typename T> void number_mult_mat_depen(T* ar, size_t r, size_t c, int num) {
	for (size_t i = 0; i < r; ++i) {
		for (size_t j = 0; j < c; ++j) {
			ar[i*c+j] *= num;
		}
	}
}

bool test_matE_indep() {
	int m[7][7] = { { 1,0,0,0,0,0,0 },{ 0, 1, 0, 0, 0,0,0} , { 0,0,1,0,0,0,0 },{ 0, 0, 0, 1, 0,0,0} ,{ 0,0,0,0,1,0,0 },{ 0, 0, 0, 0, 0,1,0} ,{ 0,0,0,0,0,0,1 } };
	int num = 5;
	int** arr=new int*[5];
	for (size_t r = 0; r < 5; ++r) {
		arr[r]=new int[5];
		for (size_t c = 0; c < 5; ++c) {
			arr[r][c] = num;
			num += 1;
		}
	}
	matrixE_indep(arr, 5, 5);
	for (size_t r = 0; r < 5; ++r) {
		for (size_t c = 0; c < 5; ++c) {
			if (arr[r][c] != m[r][c]) { return false; }
		}
	}
	num = 2;
	arr=new int*[2];
	for (size_t r = 0; r < 2; ++r) {
		arr[r]=new int[2];
		for (size_t c = 0; c < 2; ++c) {
			arr[r][c] = num;
			num += 1;
		}
	}
	matrixE_indep(arr, 2, 2);
	for (size_t r = 0; r < 2; ++r) {
		for (size_t c = 0; c < 2; ++c) {
			if (arr[r][c] != m[r][c]) { return false; }
		}
	}
	arr=new int*[7];
	for (size_t r = 0; r < 7; ++r) {
		arr[r]=new int[7];
		for (size_t c = 0; c < 7; ++c) {
			arr[r][c] = num;
			num += 1;
		}
	}
	matrixE_indep(arr, 7, 7);
	for (size_t r = 0; r < 7; ++r) {
		for (size_t c = 0; c < 7; ++c) {
			if (arr[r][c] != m[r][c]) { return false; }
		}
	}
	for (size_t r = 0; r < 7; ++r) {
		delete[] arr[r];
	}delete[] arr;
	return true;
}

bool test_matE_depen() {
	int m[7][7] = { { 1,0,0,0,0,0,0 },{ 0, 1, 0, 0, 0,0,0} , { 0,0,1,0,0,0,0 },{ 0, 0, 0, 1, 0,0,0} ,{ 0,0,0,0,1,0,0 },{ 0, 0, 0, 0, 0,1,0} ,{ 0,0,0,0,0,0,1 } };
	int num = 5;
	size_t nc = 5;
	int* arr = new int[5 * 5];
	for (size_t r = 0; r < 5; ++r) {
		for (size_t c = 0; c < 5; ++c,++num) {
			arr[r*nc+c] = num;
		}
	}
	matrixE_depen(arr, 5, 5);
	for (size_t r = 0; r < 5; ++r) {
		for (size_t c = 0; c < 5; ++c) {
			if (arr[r*nc+c] != m[r][c]) { return false; }
		}
	}
	num = 2, nc = 2;
	arr = new int[2 * 2];
	for (size_t r = 0; r < 2; ++r) {
		for (size_t c = 0; c < 2; ++c) {
			arr[r * nc + c] = num;
			num += 1;
		}
	}
	matrixE_depen(arr, 2, 2);
	for (size_t r = 0; r < 2; ++r) {
		for (size_t c = 0; c < 2; ++c) {
			if (arr[r * nc + c] != m[r][c]) { return false; }
		}
	}
	nc = 7;
	arr = new int[7 * 7];
	for (size_t r = 0; r < 7; ++r) {
		for (size_t c = 0; c < 7; ++c) {
			arr[r * nc + c] = num;
			num += 1;
		}
	}
	matrixE_depen(arr, 7, 7);
	for (size_t r = 0; r < 7; ++r) {
		for (size_t c = 0; c < 7; ++c) {
			if (arr[r*nc+c] != m[r][c]) { return false; }
		}
	}
	delete[] arr;
	return true;
}

bool test_matrix180_indep() {
	size_t nr = 2, nc = 3; int num = 10;
	int** test = new int* [nr]; int** mas = new int* [nr];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new int[nc];
		mas[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c,++num) {
			test[r][c] = num;
			mas[r][c] = num;
		}
	}
	matrix180_indep(test, nr, nc);
	for (int r = nr-1; r>0; --r) {
		for (int c = nc-1; c>0; --c) {
			if (test[r][c] != mas[nr - 1 - r][nc - 1 - c]) return false;
		}
	}

	nr = 5, nc = 3, num = -3;
	test = new int* [nr], mas = new int* [nr];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new int[nc];
		mas[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c, ++num) {
			test[r][c] = num;
			mas[r][c] = num;
		}
	}
	matrix180_indep(test, nr, nc);
	for (int r = nr - 1; r > 0; --r) {
		for (int c = nc - 1; c > 0; --c) {
			if (test[r][c] != mas[nr - 1 - r][nc - 1 - c]) return false;
		}
	}

	nr = 4, nc = 6, num = -30;
	test = new int* [nr], mas = new int* [nr];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new int[nc];
		mas[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c, ++num) {
			test[r][c] = num;
			mas[r][c] = num;
		}
	}
	matrix180_indep(test, nr, nc);
	for (int r = nr - 1; r > 0; --r) {
		for (int c = nc - 1; c > 0; --c) {
			if (test[r][c] != mas[nr - 1 - r][nc - 1 - c]) return false;
		}
	}
	for (size_t r = 0; r < nr; ++r) {
		delete[] test[r];
		delete[] mas[r];
	}
	delete[] test; delete[] mas;
	return true;
}

bool test_matrix180_depen() {
	size_t nr = 2, nc = 2; int num = 10;
	int* test = new int[nr*nc]; int* mas = new int[nr*nc];
	for (size_t r = 0; r < nr*nc; ++r,++num) {
		test[r] = num;
		mas[r] = num;
	}
	matrix180_depen(test, nr, nc);
	for (int r = nr-1; r>0; --r) {
		for (int c = nc-1; c>0; --c) {
			if (test[r*nc+c] != mas[(nr - 1 - r)*nc+(nc - 1 - c)]) return false;
		}
	}
	nr = 5, nc = 3, num = -3;
	test = new int[nr*nc], mas = new int[nr*nc];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			test[r * nc + c] = num;
			mas[r * nc + c] = num;
		}
	}
	matrix180_depen(test, nr, nc);
	for (int r = nr - 1; r > 0; --r) {
		for (int c = nc - 1; c > 0; --c) {
			if (test[r * nc + c] != mas[(nr - 1 - r) * nc + (nc - 1 - c)]) return false;
		}
	}

	nr = 4, nc = 6, num = -30;
	test = new int[nr*nc], mas = new int[nr*nc];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			test[r * nc + c] = num;
			mas[r * nc + c] = num;
		}
	}
	matrix180_depen(test, nr, nc);
	for (int r = nr - 1; r > 0; --r) {
		for (int c = nc - 1; c > 0; --c) {
			if (test[r * nc + c] != mas[(nr - 1 - r) * nc + (nc - 1 - c)]) return false;
		}
	}

	nr = 5, nc = 5, num = -5;
	test = new int[nr * nc], mas = new int[nr * nc];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			test[r * nc + c] = num;
			mas[r * nc + c] = num;
		}
	}
	matrix180_depen(test, nr, nc);
	for (int r = nr - 1; r > 0; --r) {
		for (int c = nc - 1; c > 0; --c) {
			if (test[r * nc + c] != mas[(nr - 1 - r) * nc + (nc - 1 - c)]) return false;
		}
	}
	delete[] test; delete[] mas;
	return true;
}

bool test_matrix_num_indep() {
	size_t nr = 5, nc = 5; int num = 3;
	int** mas = new int*[nr];
	for (size_t r = 0; r < nr; ++r) {
		mas[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c) {
			mas[r][c] = rand() % 30;
		}
	}
	matrix_num_indep(mas, nr, nc, num);
	num = 3;
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			if (mas[r][c] != num) return false;
		}
	}

	nr = 3, nc = 3, num = -15;
	mas = new int*[nr];
	for (size_t r = 0; r < nr; ++r) {
		mas[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c) {
			mas[r][c] = rand() % 30;
		}
	}
	matrix_num_indep(mas, nr, nc, num);
	num = -15;
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			if (mas[r][c] != num) return false;
		}
	}

	nr = 2, nc = 2, num = -1;
	mas = new int* [nr];
	for (size_t r = 0; r < nr; ++r) {
		mas[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c) {
			mas[r][c] = rand() % 30;
		}
	}
	matrix_num_indep(mas, nr, nc, num);
	num = -1;
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			if (mas[r][c] != num) return false;
		}
	}

	nr = 6, nc = 6, num = 0;
	mas = new int* [nr];
	for (size_t r = 0; r < nr; ++r) {
		mas[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c) {
			mas[r][c] = rand() % 30;
		}
	}
	matrix_num_indep(mas, nr, nc, num);
	num = 0;
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			if (mas[r][c] != num) return false;
		}
	}
	for (size_t r = 0; r < nr; ++r)
		delete[] mas[r];
	delete[] mas;
	return true;
}

bool test_matrix_num_depen() {
	size_t nr = 5, nc = 5; int num = 3;
	int* mas = new int[nr * nc];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			mas[r * nc + c] = rand()%30;
		}
	}
	matrix_num_depen(mas, nr, nc, num);
	num = 3;
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c,++num) {
			if(mas[r * nc + c] != num) return false;
		}
	}

	nr = 3, nc = 3, num = -15;
	mas = new int[nr * nc];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			mas[r * nc + c] = rand() % 30;
		}
	}
	matrix_num_depen(mas, nr, nc, num); num = -15;
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			if (mas[r * nc + c] != num) return false;
		}
	}

	nr = 2, nc = 2, num = -1;
	mas = new int[nr * nc];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			mas[r * nc + c] = rand() % 30;
		}
	}
	matrix_num_depen(mas, nr, nc, num); num = -1;
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			if (mas[r * nc + c] != num) return false;
		}
	}

	nr = 6, nc = 6, num = 0;
	mas = new int[nr * nc];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			mas[r * nc + c] = rand() % 30;
		}
	}
	matrix_num_depen(mas, nr, nc, num); num = 0;
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c, ++num) {
			if (mas[r * nc + c] != num) return false;
		}
	}
	delete[] mas;
	return true;
}

bool test_mat_plus_mat_indep() {
	size_t nr = 3, nc = 3;
	int** mas = new int*[nr];
	int** test = new int*[nr];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c) {
			test[r][c] = rand() % 30;
		}
	}
	mas = mat_plus_mat_indep(test, test, nr, nc,nr,nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (mas[r][c] != 2 * test[r][c]) return false;
		}
	}

	nr = 5, nc = 5;
	mas = new int*[nr], test = new int*[nr];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c) {
			test[r][c] = rand() % 50;
		}
	}
	mas = mat_plus_mat_indep(test, test, nr, nc, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (mas[r][c] != 2 * test[r][c]) return false;
		}
	}

	nr = 7, nc = 7;
	mas = new int* [nr], test = new int* [nr];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c) {
			test[r][c] = rand() % 70+1;
		}
	}
	mas = mat_plus_mat_indep(test, test, nr, nc, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (mas[r][c] != 2 * test[r][c]) return false;
		}
	}

	nr = 2, nc = 2;
	mas = new int* [nr], test = new int* [nr];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c) {
			test[r][c] = rand() % 20+3;
		}
	}
	mas = mat_plus_mat_indep(test, test, nr, nc, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (mas[r][c] != 2 * test[r][c]) return false;
		}
	}
	for (size_t r = 0; r < nr; ++r) {
		delete[] mas[r];
		delete[] test[r];
	}
	delete[] mas; delete[] test;
	return true;
}

bool test_mat_plus_mat_depen() {
	size_t nr = 3, nc = 3;
	int* mas = new int[nr * nc];
	int* test = new int[nr * nc];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			test[r * nc + c] = rand() % 30;
		}
	}
	mas = mat_plus_mat_depen(test, test, nr, nc,nr,nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (mas[r * nc + c] != 2 * test[r * nc + c]) return false;
		}
	}

	nr = 5, nc = 5;
	mas = new int[nr * nc], test = new int[nr * nc];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			test[r * nc + c] = rand() % 50;
		}
	}
	mas = mat_plus_mat_depen(test, test, nr, nc, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (mas[r * nc + c] != 2 * test[r * nc + c]) return false;
		}
	}

	nr = 7, nc = 7;
	mas = new int[nr * nc], test = new int[nr * nc];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			test[r * nc + c] = rand() % 70+1;
		}
	}
	mas = mat_plus_mat_depen(test, test, nr, nc, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (mas[r * nc + c] != 2 * test[r * nc + c]) return false;
		}
	}

	nr = 2, nc = 2;
	mas = new int[nr * nc], test = new int[nr * nc];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			test[r * nc + c] = rand() % 20+3;
		}
	}
	mas = mat_plus_mat_depen(test, test, nr, nc, nr, nc);
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			if (mas[r * nc + c] != 2 * test[r * nc + c]) return false;
		}
	}
	delete[] mas; delete[] test;
	return true;
}

bool test_mat_mult_mat_indep() {
	int** a = new int* [2];
	int num = 1;
	for (size_t i = 0; i < 2; ++i) {
		a[i] = new int[3];
		for (size_t j = 0; j < 3; ++j) {
			a[i][j] = num;
			num += 1;
		}
	}num = 1;
	int** b = new int* [3];
	for (size_t i = 0; i < 3; ++i) {
		b[i] = new int[2];
		for (size_t j = 0; j < 2; ++j) {
			b[i][j] = num;
			num += 1;
		}
	}
	int** t = new int* [2];
	for (size_t i = 0; i < 2; ++i) {
		t[i] = new int[2];
	}
	t[0][0] = 22; t[0][1] = 28; t[1][0] = 49; t[1][1] = 64;
	int** f = new int* [2];
	for (size_t i = 0; i < 2; ++i) {
		f[i] = new int[2];
	}
	f = mat_mult_mat_indep(a, 2, 3, b, 3, 2);
	for (size_t nr = 0; nr < 2; ++nr) {
		for (size_t nc = 0; nc < 2; ++nc) {
			if (f[nr][nc] != t[nr][nc]) { return false; }
		}
	}
	for (size_t i = 0; i < 2; ++i) {
		delete[] t[i];
	}delete[] t;
	for (size_t i = 0; i < 2; ++i) {
		delete[] a[i];
	}delete[] a;
	for (size_t i = 0; i < 3; ++i) {
		delete[] b[i];
	}delete[] b;
	return true;
}

bool test_mat_mult_mat_depen() {
	int* a = new int [2*3];
	int num = 1;
	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			a[i*3+j] = num;
			num += 1;
		}
	}num = 1;

	int* b = new int[3*2];
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			b[i*2+j] = num;
			num += 1;
		}
	}
	int* t = new int[2*2];
	t[0*2+0] = 22; t[0*2+1] = 28; t[1*2+0] = 49; t[1*2+1] = 64;

	int* f = new int[2*2];
	f = mat_mult_mat_depen(a, 2, 3, b, 3, 2);
	for (size_t nr = 0; nr < 2; ++nr) {
		for (size_t nc = 0; nc < 2; ++nc) {
			if (f[nr*2+nc] != t[nr*2+nc]) { return false; }
		}
	}

	t = new int[2 * 2];
	t[0 * 2 + 0] = 1; t[0 * 2 + 1] = 2; t[1 * 2 + 0] = 3; t[1 * 2 + 1] = 4;

	f = new int[2 * 2];
	f = mat_mult_mat_depen(t, 2, 2, t, 2, 2);
	t[0 * 2 + 0] = 7; t[0 * 2 + 1] = 10; t[1 * 2 + 0] = 15; t[1 * 2 + 1] = 22;
	for (size_t nr = 0; nr < 2; ++nr) {
		for (size_t nc = 0; nc < 2; ++nc) {
			if (f[nr * 2 + nc] != t[nr * 2 + nc]) { return false; }
		}
	}
	t = new int[3 * 3];
	t[0 * 3 + 0] = 1; t[0 * 3 + 1] = 2; t[0 * 3 + 2] = 3; t[1 * 3 + 0] = 4, 
	t[1 * 3 + 1] = 5; t[1 * 3 + 2] = 6; t[2 * 3 + 0] = 7; t[2 * 3 + 1] = 8, t[2 * 3 + 2] = 9;

	f = new int[3 * 3];
	f = mat_mult_mat_depen(t, 3, 3, t, 3, 3);
	t[0 * 3 + 0] = 30; t[0 * 3 + 1] = 36; t[0 * 3 + 2] = 42; t[1 * 3 + 0] = 66,
	t[1 * 3 + 1] = 81; t[1 * 3 + 2] = 96; t[2 * 3 + 0] = 102; t[2 * 3 + 1] = 126, t[2 * 3 + 2] = 150;
	for (size_t nr = 0; nr < 2; ++nr) {
		for (size_t nc = 0; nc < 2; ++nc) {
			if (f[nr * 2 + nc] != t[nr * 2 + nc]) { return false; }
		}
	}
	delete[] t;
	delete[] a;
	delete[] b;
	return true;
}

bool test_change_el_indep() {
	size_t nr = 3, nc = 5; int num1 = 0, num2 = 2, num = -10;
	int** a = new int*[nr];
	int** b = new int*[nr];
	for (size_t r = 0; r < nr; ++r) {
		a[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c, ++num) {
			a[r][c] = num;
		}
	}num = -10;
	for (size_t r = 0; r < nr; ++r) {
		b[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c, ++num) {
			b[r][c] = num;
		}
	}
	change_el_indep(a, nr, nc, num1, num2, "cols");
	for (size_t r = 0; r < nr; ++r) {
		if (a[r][num2] != b[r][num1]) return false;
	}
	nr = 5, nc = 3; num1 = 1, num2 = 2;
	a = new int*[nr], b = new int*[nr];
	for (size_t r = 0; r < nr; ++r) {
		a[r] = new int[nc];
		b[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c,++num) {
			a[r][c] = num;
			b[r][c] = num;
		}
	}
	change_el_indep(a, nr, nc, num1, num2, "cols");
	for (size_t r = 0; r < nr; ++r) {
		if (a[r][num2] != b[r][num1]) return false;
	}

	nr = 2, nc = 3; num1 = 0, num2 = 1;
	a = new int*[nr], b = new int*[nr];
	a = new int* [nr], b = new int* [nr];
	for (size_t r = 0; r < nr; ++r) {
		a[r] = new int[nc];
		b[r] = new int[nc];
		for (size_t c = 0; c < nc; ++c,++num) {
			a[r][c] = num;
			b[r][c] = num;
		}
	}
	change_el_indep(a, nr, nc, num1, num2, "rows");
	for (size_t c = 0; c < nc; ++c) {
		if (a[num2][c] != b[num1][c]) return false;
	}
	for (size_t r = 0; r < nr; ++r) {
		delete[] a[r];
		delete[] b[r];
	}
	delete[] a; delete[] b;
	return true;
}

bool test_change_el_depen() {
	size_t nr = 3, nc = 5; int num1 = 0, num2 = 3;
	int* a = new int[nr * nc]; int* b = new int[nr * nc];
	for (size_t i = 0; i < nr * nc; ++i) {
		a[i] = i;
		b[i] = i;
	}
	change_el_depen(a, nr, nc, num1, num2, "cols");
	for (size_t r = 0; r < nr; ++r) {
		if (a[r * nc + num2] != b[r * nc + num1]) return false;
	}
	nr = 5, nc = 3; num1 = 1, num2 = 2;
	a = new int[nr * nc], b = new int[nr * nc];
	for (size_t i = 0; i < nr * nc; ++i) {
		a[i] = i;
		b[i] = i;
	}
	change_el_depen(a, nr, nc, num1, num2, "cols");
	for (size_t r = 0; r < nr; ++r) {
		if (a[r * nc + num2] != b[r * nc + num1]) return false;
	}

	nr = 2, nc = 3; num1 = 0, num2 = 1;
	a = new int[nr * nc], b = new int[nr * nc];
	for (size_t i = 0; i < nr * nc; ++i) {
		a[i] = i;
		b[i] = i;
	}
	change_el_depen(a, nr, nc, num1, num2, "rows");
	for (size_t c = 0; c < nc; ++c) {
		if (a[num2 * nc + c] != b[num1 * nc + c]) return false;
	}
	delete[] a; delete[] b;
	return true;
}

bool test_number_mult_mat_indep()
{
	for (int num = 1; num < 30; ++num) {
		int** arr = new int* [5];
		int ch = 1;
		for (size_t i = 0; i < 5; ++i) {
			arr[i] = new int[7];
			for (size_t j = 0; j < 7; ++j) {
				arr[i][j] = ch;
				ch += 1;
			}
		}
		int** t = new int* [5];
		ch = 1;
		for (size_t i = 0; i < 5; ++i) {
			t[i] = new int[7];
			for (size_t j = 0; j < 7; ++j) {
				t[i][j] = ch*num;
				ch += 1;
			}
		}
		number_mult_mat_indep(arr, 5, 7, num);
		for (size_t r = 0; r < 5; ++r) {
			for (size_t c = 0; c < 7; ++c) {
				if (arr[r][c] != t[r][c]) { return false; }
			}
		}
	}
	return true;
}

bool test_number_mult_mat_depen()
{
	for (int num = 1; num < 30; ++num) {
		int* arr = new int[5*7];
		int ch = 1;
		for (size_t i = 0; i < 5; ++i) {
			for (size_t j = 0; j < 7; ++j,++ch) {
				arr[i*7+j] = ch;
			}
		}
		int* t = new int[5*7];
		ch = 1;
		for (size_t i = 0; i < 5; ++i) {
			for (size_t j = 0; j < 7; ++j,++ch) {
				t[i*7+j] = ch * num;
			}
		}
		number_mult_mat_depen(arr, 5, 7, num);
		for (size_t r = 0; r < 5; ++r) {
			for (size_t c = 0; c < 7; ++c) {
				if (arr[r*7+c] != t[r*7+c]) { return false; }
			}
		}
	}
	return true;
}
