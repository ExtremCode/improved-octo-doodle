#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

void intarr(std::vector< std::vector <int> >& p, size_t nr, size_t nc) {
	for (size_t r = 1; r < nr; ++r) {
		for (size_t c = 1; c < nc; ++c) {
			p[r][c] = p[r][c] - p[r - 1][c - 1] + p[r][c - 1] + p[r - 1][c];
		}
	}
	for (size_t r = 0; r < nr; ++r) {
		std::sort(p[r].begin(), p[r].end());
	}
	std::vector<int> kol;
	for (size_t r = 0; r < nr; ++r) {
		int c = 0;
		kol.push_back(p[r][c]);
	}
	std::sort(kol.begin(), kol.end());
	for (size_t i = 0; i < nr; ++i) {
		p[i].erase(p[i].begin());
		p[i].insert(p[i].begin(), kol[i]);
	}
}

void fel(std::vector< std::vector <int> >& p, size_t nr, size_t nc, int f) {
	size_t end = 0;
	if (nr > nc) {
		size_t it = 0;
		while (end == 0) {
			for (size_t r = 0 + it; r < nc+it; ++r) {
				if (p[r][r] > f) {
					end = r;
					break;
				}
			} it += nc;
			if (it > nr - nc) {
				break;
			}
		}
	}
	else {
		size_t it = 0;
		while (end == 0) {
			for (size_t i = 0 + it; i < nr + it; ++i) {
				if (p[i][i] > f) {
					end = i;
					break;
				}
			} it += nr;
			if (it > nc - nr) {
				break;
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	std::cout << "Enter numbers of rows and columns ";
	int r, c, f;
	std::cin >> r >> c;
	std::cout << "Enter the element wich you want find ";
	std::cin >> f;
	std::vector <std::vector <int> > arr(r, std::vector<int>(c, 0));
	int m = 1;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			arr[i][j] = m;
			m += 1;
			//rand() % 100;
		}
	}
	intarr(arr, r, c);
	std::cout << "Your sorted integral image is " << std::endl;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	system("pause");
}