#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::fstream file/*("1.txt", std::ios_base::in)*/;
	std::fstream outf/*("2.txt", std::ios_base::out | std::ios_base::trunc)*/;
	file.open("source.txt", std::ios_base::in);
	outf.open("result.txt", std::ios_base::out | std::ios_base::trunc);
	if (file && outf) {
		std::string result;
		while (file.peek() != EOF) {
			char symbol = file.get();
			size_t count = 1;
			while (file.peek() == symbol) {
				++count;
				file.seekg(1, std::ios_base::cur);
			}
			if (count > 1)
				result += std::to_string(count);
			result += symbol;
		}
		for (char i : result) {
			outf.put(i);
		}
	}
	file.close();
	outf.close();


	std::fstream newfile;
	std::fstream newoutf;
	newfile.open("source2.txt", std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	newoutf.open("result2.txt", std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
	if (newfile && newoutf) {
		std::string proba = "a......   (((((?>>?}}#$   $^%^%$$$%$c";
		newfile.write((const char*)&proba, sizeof(proba));
		std::string result;
		char symbol;
		unsigned char count = 1;
		while (newfile.peek() != EOF) {
			//std::cout << "enter int global cycle" << std::endl;
			newfile.read((char*)&symbol, sizeof(char));
			std::cout << symbol;
			while (newfile.peek() == symbol) {
				std::cout << (int)count << " ";
				++count;
				newfile.seekg(1, std::ios_base::cur);
			}
			//std::cout << (int)count << "hah ";
			if ((int)count > 1) {
				//newoutf << 0;
				char bt = 0;
				newoutf.write((const char*)&bt, sizeof(char));
				newoutf.write((const char*)&count, sizeof(char));
			}
			newoutf.write((const char*)&symbol, sizeof(char));
			count = 1;
		}
	}
	newfile.close();
	newoutf.close();
	return 0;
}