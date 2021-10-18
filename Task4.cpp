#include <iostream>

int main() {
	int n,f=-1;
	std::cout << "Input n: ";
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int p = n - i - 1; p > 0; --p) {
			std::cout << " ";
		}
		f += 1;
		for (int j = 1; j < i + 2 + f; j += 1) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}f = -1;
	for (int i = 0; i < n-1; ++i) {
		for (int p = 0; p < i+1; ++p) {
			std::cout << " ";
		}
		for (int j = n - i - f; j > 0; --j) {
			std::cout << "*";
		}f += 1;
		std::cout << std::endl;
	}
	return 0;
}
