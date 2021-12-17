#include <iostream>
#include <vector>
#include <fstream>


int main(int argc, char* argv[])
{
	std::fstream start;
	std::fstream end;
	if (argv[1] != "-o") {
		start.open(argv[2], std::ios_base::in);
		end.open(argv[4], std::ios_base::out);
	}else{
		start.open(argv[4], std::ios_base::in);
		end.open(argv[2], std::ios_base::out);
	}
	if (start.is_open() && end.is_open()) {
		std::cout << "open" << std::endl;
		while (true) {
			char ch; start.get(ch);
			if (start.eof()) { break; }
			end.put(ch);
		}
	}
	else { std::cout << "error"; }

	std::vector<int> m1 = { 1,2,3,4,5,6,7,8,9,0 };
	std::fstream arf1;
	arf1.open("array1.txt", std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
	if (arf1.is_open()) {
		std::cout << "open" << std::endl;
		arf1.write((char*)&m1, 10*sizeof(int));
		arf1.close();
		arf1.open("array1.txt", std::ios_base::in | std::ios_base::binary);
		std::vector<int> m2(10);
		arf1.read((char*)&m2, 10 * sizeof(int));
		if (m1 == m2) { std::cout << "Ogon' " << std::endl; }
	}
	else { std::cout << "error 2"; }
	arf1.close();
}
