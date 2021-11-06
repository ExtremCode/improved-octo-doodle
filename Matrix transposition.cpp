#include <iostream>
#include <vector>
#include <time.h>

void trm(std::vector< std::vector <int> > & p, size_t nr, size_t nc) {
	std::vector<std::vector <int>> nw(nc,std::vector<int> (nr,0));
	for (size_t r = 0; r < nr; ++r) {
		for (size_t c = 0; c < nc; ++c) {
			nw[c][r] = p[r][c];
		}
	}
	p = nw;
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
	trm(arr, r, c);
	std::cout << "Transoposed matrix " << std::endl;
	for (int i = 0; i < c; ++i) {
		for (int j = 0; j < r; ++j) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}