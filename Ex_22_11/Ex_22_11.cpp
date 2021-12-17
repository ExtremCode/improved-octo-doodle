#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>


int main()
{
	size_t r = 5, c = 7;
	std::vector<std::vector<int>> vector1(r, std::vector<int>(c, 0));
	std::vector<std::vector<int>> vector2(r, std::vector<int>(c, 0));
	for (size_t i = 0; i < r; ++i) {
		for (size_t j = 0; j < c; ++j) {
			vector1[i][j] = rand() % 91;
		}
	}
	auto start = std::chrono::steady_clock::now();
	std::fstream file;
	file.open("vector1.txt", std::ios_base::out | std::ios_base::trunc);
	if (file.is_open()) {
		for (size_t i = 0; i < r; ++i) {
			for (size_t j = 0; j < c; ++j) {
				file << vector1[i][j] << ' ';
			}file << std::endl;
		}
	}
	else { std::cout << "You are a fool" << std::endl; }
	file.close();

	file.open("vector1.txt", std::ios_base::in);
	if (file.is_open()) {
		for (size_t i = 0; i < r; ++i) {
			for (size_t j = 0; j < c; ++j) {
				file >> vector2[i][j];
			}
		}
	}
	else { std::cout << "You are a fool" << std::endl; }
	file.close();
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> dif = end - start;
	std::cout << "Diferent 1 " << dif.count() << std::endl;

	if (vector1 == vector2) { std::cout << "All is normal " << std::endl; }

	int mas[3][2] = { {1,2},{3,4},{5,6} };
	std::fstream fi;
	std::fstream fin;
	fin.open("newfile.txt",std::ios_base::out | std::ios_base::trunc);
	fi.open("myfile.txt",std::ios_base::in);
	if(fi.is_open() && fin.is_open()){
		char text[] = {'H','e','l','l','o',' ','e','v','e','r','y','o','n','e'};
		while (true) {
			char ch = fi.get(); // equals to fi>>ch;
			if (fi.eof()) { break; }
			fin.put(ch); // equals to fin<<ch;
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 2; ++j) {
				fin << mas[i][j]<<' ';
			}fin << std::endl;
		}
		for (int i = 0; i < sizeof(text)/sizeof(text[0]); ++i) {
			fin.put(text[i]);
		}fin << std::endl;
	}
	else{std::cout<<"eror";}
	fi.close();
	fin.close();

	/*   read and write from a file together    */
	auto start2 = std::chrono::steady_clock::now();
	file.open("vector1.txt", std::ios_base::out | std::ios_base::in | std::ios_base::trunc);
	if (file.is_open()) {
		for (size_t i = 0; i < r; ++i) {
			for (size_t j = 0; j < c; ++j) {
				file << vector1[i][j] << ' ';
			}file << std::endl;
		}
		for (size_t i = 0; i < r; ++i) {
			for (size_t j = 0; j < c; ++j) {
				file >> vector2[i][j];
			}
		}
	}
	else { std::cout << "You are a fool" << std::endl; }
	file.close();
	auto end2 = std::chrono::steady_clock::now();
	std::chrono::duration<double> dif2 = end2 - start2;
	std::cout << "Diferent 2 " << dif2.count() << std::endl;

	if (vector1 == vector2) { std::cout << "All is normal " << std::endl; }
}
