#include "functions_bmp.h"
void collage_col(std::string from, std::string to) {
	std::fstream bmpfile, bmp_sample;
	bmpfile.open(to, std::ios_base::binary | std::ios_base::in | std::ios_base::out);
	bmp_sample.open(from, std::ios_base::binary | std::ios_base::in);
	if (bmpfile && bmp_sample.is_open()) {
		std::cout << "Files opened for working" << std::endl;
		int width1, height1, width2, height2, bit_count1, bit_count2;
		bmpfile.seekg(18);
		bmpfile.read((char*)&width1, sizeof(int));
		bmpfile.read((char*)&height1, sizeof(int));
		bmp_sample.seekg(18);
		bmp_sample.read((char*)&width2, sizeof(int));
		bmp_sample.read((char*)&height2, sizeof(int));
		std::cout << "width1 " << width1 << " height1 " << height1 << std::endl;
		std::cout << "width_2 " << width2 << " height_2 " << height2 << std::endl;

		bmpfile.seekg(0x1c);
		bmpfile.read((char*)&bit_count1, sizeof(int));
		std::cout << "bit_count_1: " << bit_count1 << std::endl;
		bmp_sample.seekg(0x1c);
		bmp_sample.read((char*)&bit_count2, sizeof(int));
		std::cout << "bit_count_2: " << bit_count2 << std::endl;
		if (bit_count1 != bit_count2) std::cout << "The number of bits per color of the files is different,there may be a mistake!" << std::endl;

		bmpfile.seekg(-width1 * 3, std::ios_base::end);
		bmp_sample.seekg(-width2 * 3, std::ios_base::end);
		for (size_t r = 0; r < height2; ++r) {
			for (size_t c = 0; c < width2; ++c) {
				char ch[3];
				bmp_sample.read((char*)ch, 3 * sizeof(char));
				bmpfile.write(ch, 3 * sizeof(char));
			}
			bmp_sample.seekg(-width2 * 6, std::ios_base::cur);
			bmpfile.seekg(-(width1 + width2) * 3, std::ios_base::cur);
		}
		std::cout << "Well done!" << std::endl;
	}
	else std::cout << "Files didn't opened" << std::endl;
	bmp_sample.close(); bmpfile.close();
}

void out_col_image(std::string fn) {
	std::fstream bmpfile;
	bmpfile.open(fn, std::ios_base::binary | std::ios_base::in); // 3 bytes are colour of one dote
	if (bmpfile) {
		std::cout << "File opened for working" << std::endl; // colour saved as blue green red
		unsigned int bitoff = 0;
		bmpfile.seekg(10);
		bmpfile.read((char*)&bitoff, sizeof(int));

		unsigned int width, height,bit_count;
		bmpfile.seekg(18);
		bmpfile.read((char*)&width, sizeof(int));
		bmpfile.read((char*)&height, sizeof(int));

		bmpfile.seekg(0x1c);
		bmpfile.read((char*)&bit_count, sizeof(int));
		if (bit_count != 24) std::cout << "There may be a mistake, because bit count isn't 24!" << std::endl;

		bmpfile.seekg(bitoff);
		for (size_t r = 0; r < height; ++r) {
			for (size_t c = 0; c < width; ++c) {
				for (size_t j = 0; j < 3; ++j) {
					if (bmpfile.eof()) break;
					unsigned char ch;
					bmpfile.read((char*)&ch, sizeof(char));
					std::cout << ch % 0x100;
				}
			}std::cout << "|" << std::endl;
		} bmpfile.close(); std::cout << "Well done!" << std::endl;
	}
}

void pic_in_pic_monoh(std::string from, std::string to) {
	std::fstream bmpfile, bmp_sample;
	bmpfile.open(to, std::ios_base::in | std::ios_base::binary | std::ios_base::out); // size of 1.bmp > size of 2.bmp
	bmp_sample.open(from, std::ios_base::in | std::ios_base::binary);
	if (bmpfile.is_open() && bmp_sample) {
		std::cout << "Files opened for working " << std::endl;
		bmpfile.seekg(2);
		bmp_sample.seekg(2);
		int f1, f2;
		bmpfile.read((char*)&f1, sizeof(int));
		bmp_sample.read((char*)&f2, sizeof(int));
		if (f1 > f2) {
			int wid, hei, wid1, hei1;
			bmp_sample.seekg(18);
			bmp_sample.read((char*)&wid, sizeof(int));
			bmp_sample.read((char*)&hei, sizeof(int));
			bmpfile.seekg(18);
			bmpfile.read((char*)&wid1, sizeof(int));
			bmpfile.read((char*)&hei1, sizeof(int));

			bmpfile.seekg(-wid1 / 8, std::ios_base::end);
			bmp_sample.seekg(-wid / 8, std::ios_base::end);
			for (size_t r = 0; r < hei; ++r) {
				char ch[96];
				bmp_sample.read(ch, (wid / 8) * sizeof(char));
				bmpfile.write(ch, (wid / 8) * sizeof(char));
				bmp_sample.seekg(-(wid / 4), std::ios_base::cur);
				bmpfile.seekg(-(wid1 + wid) / 8, std::ios_base::cur);
			}
			std::cout << "Well done!" << std::endl;
		}
		else std::cout << "You should swap names of files in arguments of function!" << std::endl;
	}
	else std::cout << "Error" << std::endl;
	bmpfile.close(); bmp_sample.close();
}

void out_non_stan_im(std::string fn) {
	std::fstream bmpfile;
	bmpfile.open(fn, std::ios_base::binary | std::ios_base::in);
	if (bmpfile) {
		std::cout << "File opened for working" << std::endl;
		unsigned int bitoff = 0;
		bmpfile.seekg(10);
		bmpfile.read((char*)&bitoff, sizeof(int));

		unsigned int width, height;
		bmpfile.seekg(18, std::ios_base::beg);
		bmpfile.read((char*)&width, sizeof(int));
		bmpfile.seekg(22, std::ios_base::beg);
		bmpfile.read((char*)&height, sizeof(int));

		bmpfile.seekg(bitoff);
		for (size_t r = 0; r < height; ++r) {
			for (unsigned int c = 0,k=0; c < width; c += 8) {
				if (bmpfile.eof()) break;
				char ch = 0;
				bmpfile.read(&ch, sizeof(char));
				for (unsigned char mask = 0x80; mask != 0; mask >>= 1) {
					if ((c + 8) > width) ++k;
					std::cout << (((ch & mask) == 0) ? 'x' : ' ');
					if (k == width % 32) break;
				}
			}std::cout << "|" << std::endl;
			bmpfile.seekg(3, std::ios_base::cur);
		}
		bmpfile.close();
		std::cout << "Well done!" << std::endl;
	}
}

void copy_out_im(std::string from, std::string to) {
	std::fstream bmpfile, bmp_sample;
	bmpfile.open(from, std::ios_base::binary | std::ios_base::in);
	bmp_sample.open(to, std::ios_base::binary | std::ios_base::out | std::ios_base::trunc); //50*100 didn't opened because crashed
	if (bmpfile && bmp_sample.is_open()) {
		std::cout << "Bmp files opened for working" << std::endl;
		unsigned int bitoff = 0;
		bmpfile.seekg(10);
		bmpfile.read((char*)&bitoff, sizeof(int));

		char ch[18];
		bmpfile.read((char*)ch, 18 * sizeof(char));
		bmp_sample.write((char*)ch, 18 * sizeof(char));

		unsigned int width, height;
		bmpfile.seekg(18, std::ios_base::beg);
		bmpfile.read((char*)&width, sizeof(int));
		bmpfile.seekg(22, std::ios_base::beg);
		bmpfile.read((char*)&height, sizeof(int));

		bmp_sample.write((char*)&height, sizeof(int));
		bmp_sample.write((char*)&width, sizeof(int));

		bmpfile.seekg(26, std::ios_base::beg);
		while (bmpfile.peek() != EOF) {
			char arr[8];
			bmpfile.read((char*)arr, 8 * sizeof(char));
			bmp_sample.write((char*)arr, 8 * sizeof(char));
		}

		bmpfile.seekg(bitoff);
		for (size_t r = 0; r < height; ++r) {
			for (size_t c = 0; c < width; c += 8) {
				if (bmpfile.eof()) break;
				char ch = 0;
				bmpfile.read((char*)&ch, sizeof(char));
				for (unsigned char mask = 0x80; mask != 0; mask >>= 1) {
					std::cout << (((ch & mask) == 0) ? 'w' : ' ');
				}
			}std::cout << "|" << std::endl;
		}
		bmp_sample.close();
		bmpfile.close();
	}
	else std::cout << "Bmp files didn't opened for working" << std::endl;
}