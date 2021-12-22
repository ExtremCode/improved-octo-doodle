#include <iostream>
#include <vector>
#include <time.h>

void transp_mat_indep(std::vector< std::vector <int> > & p, size_t nr, size_t nc) {
	std::vector<std::vector <int>> nw(nc,std::vector<int> (nr,0));
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			nw[c][r] = p[r][c];
		}
	}
	p = nw;
}

template <typename T> T** transp_mat_indep(T** p, size_t nr, size_t nc) {
	T** nw = new T*[nc];
	for (size_t c = 0; c < nc; ++c) {
		nw[c] = new T[nr];
	}
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			nw[c][r] = p[r][c];
		}
	}
	return nw;
}

template <typename T> T* transp_mat_depend(T* p, size_t nr, size_t nc) {
	T* nw = new T[nr * nc];
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			nw[c * nr + r] = p[r * nc + c];
		}
	}
	return nw;
}

bool test_transp_mat_indep() {
	size_t nr = 2, nc = 2;
	int** test = new int* [nr]; int** ori = new int*[nc];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new int[nc];
	}
	for (size_t c = 0; c < nc; ++c) {
		ori[c] = new int[nr];
	}
	test[0][0] = 1, test[0][1] = 2, test[1][0] = -3, test[1][1] = 4;
	ori[0][0] = 1, ori[0][1] = -3, ori[1][0] = 2, ori[1][1] = 4;
	test=transp_mat_indep(test, nr, nc);
	for (size_t c = 0; c < nc; ++c) {
		for (size_t r = 0; r < nr; ++r) {
			if (ori[c][r] != test[c][r]) return false;
		}
	}

	nr = 2, nc = 3;
	test = new int*[nr], ori = new int*[nc];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new int[nc];
	}
	for (size_t c = 0; c < nc; ++c) {
		ori[c] = new int[nr];
	}
	test[0][0] = 1, test[0][1] = 2, test[0][2] = -3, test[1][0] = 0, test[1][1] = 9, test[1][2] = 43;
	ori[0][0] = 1, ori[0][1] = 0, ori[1][0] = 2, ori[1][1] = 9, ori[2][0] = -3, ori[2][1] = 43;
	test=transp_mat_indep(test, nr, nc);
	for (size_t c = 0; c < nc; ++c) {
		for (size_t r = 0; r < nr; ++r) {
			if (ori[c][r] != test[c][r]) return false;
		}
	}

	nr = 3, nc = 3;
	test = new int* [nr], ori = new int* [nc];
	for (size_t r = 0; r < nr; ++r) {
		test[r] = new int[nc];
	}
	for (size_t c = 0; c < nc; ++c) {
		ori[c] = new int[nr];
	}
	test[0][0] = 10, test[0][1] = 14, test[0][2] = 35, test[1][0] = -96, test[1][1] = 65, test[1][2] = 34, 
	test[2][0] = 0, test[2][1] = 55, test[2][2] = 43;
	ori[0][0] = 10, ori[0][1] = -96, ori[0][2] = 0, ori[1][0] = 14, ori[1][1] = 65, ori[1][2] = 55,
	ori[2][0] = 35, ori[2][1] = 34, ori[2][2] = 43;
	test=transp_mat_indep(test, nr, nc);
	for (size_t c = 0; c < nc; ++c) {
		for (size_t r = 0; r < nr; ++r) {
			if (ori[c][r] != test[c][r]) return false;
		}
	}

	return true;
}

bool test_transp_mat_depen() {
	size_t nr = 2, nc = 2;
	int* test = new int[nr*nc]; int* ori = new int[nc*nc];
	test[0 * nc + 0] = 1, test[0 * nc + 1] = 2, test[1 * nc + 0 ] = -3, test[1 * nc + 1] = 4;
	ori[0 * nr + 0] = 1, ori[0 * nr + 1] = -3, ori[1 * nr+0] = 2, ori[1 * nr + 1] = 4;
	test = transp_mat_depend(test, nr, nc);
	for (size_t c = 0; c < nc; ++c) {
		for (size_t r = 0; r < nr; ++r) {
			if (ori[c * nr + r] != test[c * nr + r]) return false;
		}
	}

	nr = 2, nc = 3;
	test = new int[nr*nc], ori = new int[nc*nr];
	test[0 * nc + 0] = 1, test[0 * nc + 1] = 2, test[0 * nc + 2] = -3, test[1 * nc + 0] = 0, test[1 * nc + 1] = 9, test[1 * nc + 2] = 43;
	ori[0 * nr + 0] = 1, ori[0 * nr + 1] = 0, ori[1 * nr + 0] = 2, ori[1 * nr + 1] = 9, ori[2 * nr + 0] = -3, ori[2 * nr + 1] = 43;
	test = transp_mat_depend(test, nr, nc);
	for (size_t c = 0; c < nc; ++c) {
		for (size_t r = 0; r < nr; ++r) {
			if (ori[c * nr + r] != test[c * nr + r]) return false;
		}
	}

	nr = 3, nc = 3;
	test = new int[nr*nc], ori = new int[nc*nr];
	test[0*nc+0] = 10, test[0 * nc + 1] = 14, test[0 * nc + 2] = 35, test[1 * nc + 0] = -96, test[1 * nc + 1] = 65, test[1 * nc + 2] = 34,
	test[2 * nc + 0] = 0, test[2 * nc + 1] = 55, test[2 * nc + 2] = 43;
	ori[0 * nr + 0] = 10, ori[0 * nr + 1] = -96, ori[0 * nr + 2] = 0, ori[1 * nr + 0] = 14, ori[1 * nr + 1] = 65, ori[1 * nr + 2] = 55,
	ori[2 * nr + 0] = 35, ori[2 * nr + 1] = 34, ori[2 * nr + 2] = 43;
	test = transp_mat_depend(test, nr, nc);
	for (size_t c = 0; c < nc; ++c) {
		for (size_t r = 0; r < nr; ++r) {
			if (ori[c*nr+r] != test[c*nr+r]) return false;
		}
	}

	return true;
}

int main()
{
	srand(time(NULL));
	std::cout << "Enter numbers of rows and columns ";
	int r, c;
	std::cin >> r >> c;
	std::vector <std::vector <int> > arr(r, std::vector<int> (c,0));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			arr[i][j] = rand() % 100;
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			std::cout<<arr[i][j]<<' ';
		}
		std::cout << std::endl;
	}
	transp_mat_indep(arr, r, c);
	std::cout << "Transoposed matrix " << std::endl;
	for (int i = 0; i < c; ++i) {
		for (int j = 0; j < r; ++j) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}
