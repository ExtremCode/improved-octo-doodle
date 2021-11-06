#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

void intarr(std::vector< std::vector <int> >& p, size_t nr, size_t nc) {
	for (size_t r = 1; r < nr; ++r) {
		for (size_t c = 1; c < nc; ++c) {
			p[r][c] = p[r][c]-p[r-1][c-1]+ p[r][c-1] + p[r-1][c];
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

int main()
{
	srand(time(NULL));
	std::cout << "Enter numbers of rows and columns ";
	int r, c;
	std::cin >> r >> c;
	std::vector <std::vector <int> > arr(r, std::vector<int>(c, 0));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			arr[i][j] = rand() % 100;
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	intarr(arr, r, c);
	std::cout << std::endl;
	std::cout << "Your sorted integral image is " << std::endl;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	system("pause");
}