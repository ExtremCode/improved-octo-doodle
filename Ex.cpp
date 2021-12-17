#include <iostream>

template<typename T> void snake_arr(T** m, size_t nr, size_t nc, int k) {
	for (size_t r = 0; r < nr; ++r) {
		if (r % 2 != 0) {
			for (size_t c = nc; c > 0; --c) {
				m[r][c-1] = k;
				k += 1;
			}
		}
		else {
			for (int c = 0; c < nc; ++c) {
				m[r][c] = k;
				k += 1;
			}
		}
	}
}

template<typename T> void angle_arr(T** arr, size_t nr, size_t nc, int k) {
	size_t r = 0, c = 0;
	while (size_t j = 0 < nc * nr) {
		if (r == 0 && c == 0) {
			arr[r][c] = k;
			std::cout << arr[r][c] << ' ';
			r += 1;
			k += 1;
			j += 1;
		}
		else {
			if (r == nr && nr > 1) {
				for (size_t v = r; v > 0; --v) {
					arr[v][c + (r - v)] = k;
					std::cout << arr[v][c + (r - v)] << ' ';
					k += 1;
					j += 1;
				}
				if (r > c) {
					for (size_t v = r; v > 0; --v) {
						arr[v][c + (r - v)] = k;
						std::cout << arr[v][c + (r - v)] << ' ';
						k += 1;
						j += 1;
					}if (c <= nc - 2) { c += 2; }
					else { c += 1; }
					std::cout << std::endl;
				}
				else {
					for (size_t v = c; v > 0; --v) {
						arr[c - v][v] = k;
						std::cout << arr[c - v][v] << ' ';
						k += 1;
						j += 1;
					}if (r <= nr + 2) { r += 2; }
					else { r += 1; }
					std::cout << std::endl;
				}
			}
		}
	}
}

int main() {
	size_t nr,nc;
	int num;
	std::cout << "Enter number of rows and colunms, number for start value ";
	std::cin >> nr>>nc>>num;
	int** m = new int*[nr];
	for (size_t i = 0; i < nr; ++i) {
		m[i] = new int[nc];
	}
	int** ar = new int* [nr];
	for (size_t i = 0; i < nr; ++i) {
		m[i] = new int[nc];
	}
	snake_arr(m, nr, nc, num);
	for (int r = 0; r < nr; ++r) {
		for (int c = 0; c < nc; ++c) {
			std::cout << m[r][c] << ' ';
		}std::cout << std::endl;
	}
	angle_arr(ar, nr, nc, num);
	/*for (int r = 0; r < nr; ++r) {
		for (int c = 0; c < nc; ++c) {
			std::cout << m[r][c] << ' ';
		}std::cout << std::endl;
	}*/
	for(size_t i=0;i<nr;++i)
		delete[] m[i];
	delete[] m;
}
