#include <iostream>

int main() {
	int n;
	std::cout << "Input n: ";
	std::cin >> n;
	for (int i = n; i > 0; --i) {
		for (int p = i - 1; p > 0; --p) {
			std::cout << " ";
		}
		for (int j = n - i + 1; j > 0; --j) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	return 0;
}
