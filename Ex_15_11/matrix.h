#pragma once
#include <iostream>

template<typename T> void matrixE(T** arr, size_t nr, size_t nc) {
	if(nr==nc){
		for (size_t r = 0; r < nr; ++r) {
			for (size_t c = 0; c < nc; ++c) {
				if (r == c) { arr[r][c] = 1; }
				else { arr[r][c] = 0; }
			}
		}
	}
}

template<typename T> void matrix180(T** a, size_t nr, size_t nc) {
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

template<typename T> void matrix_num(T** arr, size_t nr, size_t nc, int num) {
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			arr[r][c] = num;
			num += 1;
		}
	}
}

template<typename T> T** mat_plus(T** ar, T** m, size_t nr1, size_t nc1, size_t nr2, size_t nc2) {
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

template<typename T> T** mat_mult(T** ar, size_t nr1, size_t nc1, T** mas, size_t nr2, size_t nc2) {
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

template<typename T> void change_el(T** ar, size_t r, size_t c,size_t num1, size_t num2, std::string what) {
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

template<typename T> void number_mult_mat(T** ar, size_t r, size_t c, int num) {
	for (size_t i = 0; i < r; ++i) {
		for (size_t j = 0; j < c; ++j) {
			ar[i][j] *= num;
		}
	}
}

template<typename T> bool test_matE(T** arr) {
	T m[5][5] = { { 1,0,0,0,0 },{ 0, 1, 0, 0, 0,}, {0,0,1,0,0} , {0,0,0,1,0},{0,0,0,0,1} };
	T num = 5;
	for (size_t r = 0; r < 5; ++r) {
		for (size_t c = 0; c < 5; ++c) {
			arr[r][c] = num;
			num += 1;
		}
	}
	matrixE(arr, 5, 5);
	for (size_t r = 0; r < num; ++r) {
		for (size_t c = 0; c < num; ++c) {
			if (arr[r][c] = m[r][c]) { return true; }
			else { break; return false; }
		}
	}
	m[2][2] = { { 1,0,0,0,0 },{ 0, 1, 0, 0, 0,} };
	num = 2;
	for (size_t r = 0; r < 5; ++r) {
		for (size_t c = 0; c < 5; ++c) {
			arr[r][c] = num;
			num += 1;
		}
	}
	matrixE(arr, 2, 2);
	for (size_t r = 0; r < num; ++r) {
		for (size_t c = 0; c < num; ++c) {
			if (arr[r][c] = m[r][c]) { return true; }
			else { break; return false; }
		}
	}
	m[7][7] = { { 1,0,0,0,0,0,0 },{ 0, 1, 0, 0, 0,0,0} , { 0,0,1,0,0,0,0 },{ 0, 0, 0, 1, 0,0,0} ,{ 0,0,0,0,1,0,0 },{ 0, 0, 0, 0, 0,1,0} ,{ 0,0,0,0,0,0,1 } };
	for (size_t r = 0; r < 7; ++r) {
		for (size_t c = 0; c < 7; ++c) {
			arr[r][c] = num;
			num += 1;
		}
	}
	matrixE(arr, 7, 7);
	for (size_t r = 0; r < num; ++r) {
		for (size_t c = 0; c < num; ++c) {
			if (arr[r][c] = m[r][c]) { return true; }
			else { break; return false; }
		}
	}
	return true;
}

bool test_mat_mult() {
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
	f = mat_mult(a, 2, 3, b, 3, 2);
	for (size_t nr = 0; nr < 2; ++nr) {
		for (size_t nc = 0; nc < 2; ++nc) {
			if (f[nr][nc] != t[nr][nc]) { return false; }
		}
	}
	return true;
}

bool test_mat_num()
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
		number_mult_mat(arr, 5, 7, 10);
		for (size_t r = 0; r < 5; ++r) {
			for (size_t c = 0; c < 7; ++c) {
				if (arr[r][c] != t[r][c]) { break; return false; }
			}
		}
	}
	return true;
}
