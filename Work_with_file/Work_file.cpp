#include"function.h"

int main(int argc, char* argv[])
{
    float arr[5][7];
    for (size_t i = 0; i < 5; ++i) {
        for (size_t j = 0; j < 7; ++j) {
            arr[i][j] = rand() % 33+0.5;
        }
    }
    matrix_to_file_bin(arr, 5, 7);

    std::fstream infn, outf, f3, f4, bmpfile, bmp_sample;

    infn.open(argv[1], std::ios_base::in);
    outf.open(argv[2], std::ios_base::out |std::ios_base::trunc);
    if (infn.is_open() && outf.is_open()) {
        std::cout << "Files infn and outf opened" << std::endl;
        while (!infn.eof()) {
            char ch[100];
            infn.getline(ch,10000);
            outf << ch << std::endl;
        }
    }

    f3.open("f3.txt", std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
    int m[] = { 1,2,3,4,5,6,7,8,9,0,11,22,33,44,55,66,77,88,99,00 };
    if(f3.is_open()){
        for (int i = 0; i < 6; ++i) {
            f3.write((char*)&m[i], 4 * sizeof(int));
        }f3.close();
    }

    f3.open("f3.txt", std::ios_base::binary | std::ios_base::in);
    f4.open("f4.txt", std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
    if (f3.is_open() && f4.is_open()) {
        std::cout << "f3 and f4 opened" << std::endl;
        auto start = std::chrono::steady_clock::now();
        while (!f3.eof()) {
            const size_t k = 5; // the more the block is taken, the faster the reading
            int buffer[k];
            f3.read((char*)buffer, k * sizeof(int));
            f4.write((char*)buffer, k * sizeof(int));
        }
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> dif = end - start;
        std::cout << "Diferent : " << dif.count() << std::endl;
    }
    else {
        std::cout << "error" << std::endl;
    } f3.close(); f4.close();

    f4.open("f4.txt", std::ios_base::binary | std::ios_base::in);
    if (f4) {
        std::cout << "F4 opened for reading " << std::endl;
        unsigned int count = 0;
        while (f4.peek() != EOF) {
            char ch;
            f4.seekg(count);
            f4.read((char*)&ch, sizeof(char));
            std::cout << ch << ' ';
            count += 3;
        }std::cout << std::endl;
    }
    else {std::cout << "f4 didn't open for reading " << std::endl;} f4.close();

    bmpfile.open("sample_640_426.bmp", std::ios_base::binary | std::ios_base::in);
    bmp_sample.open("new_sam_426_640.bmp", std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
    if (bmpfile) {
        std::cout << "bmpfile opened for reading " << std::endl;
        bmpfile.seekg(2);
        int pic_size;
        bmpfile.read((char*)&pic_size, sizeof(int));
        std::cout << "pic_size 1: " << pic_size << std::endl;
        bmpfile.seekg(18, std::ios_base::beg);
        int width, height;
        bmpfile.read((char*)&width, sizeof(int));
        bmpfile.seekg(22, std::ios_base::beg);
        bmpfile.read((char*)&height, sizeof(int));
        std::cout << "width 1: " << width << "  height 1: " << height << std::endl;
    }
    else { std::cout << "bmpfile didn't opened for reading " << std::endl; }
    bmpfile.close();

    bmpfile.open("sample_640_426.bmp", std::ios_base::binary | std::ios_base::in);
    if (bmpfile && bmp_sample.is_open()) {
        std::cout << "bmp Files opened for working" << std::endl;
        char ch[18];
        bmpfile.read((char*)ch, 18 * sizeof(char));
        bmp_sample.write((char*)ch, 18 * sizeof(char));

        int width, height;
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
        } bmp_sample.close();
        bmpfile.close();
    }// result: new bmp file not suppotred or crashed with windows utilit, but it opened with online tools and looked like strange

    bmp_sample.open("new_sam_426_640.bmp", std::ios_base::binary | std::ios_base::in);
    if (bmp_sample) {
        std::cout << "bmpfile opened for reading " << std::endl;
        bmp_sample.seekg(2);
        int pic_size;
        bmp_sample.read((char*)&pic_size, sizeof(int));
        std::cout << "pic_size 2: " << pic_size << std::endl;
        bmp_sample.seekg(18, std::ios_base::beg);
        int width, height;
        bmp_sample.read((char*)&width, sizeof(int));
        bmp_sample.seekg(22, std::ios_base::beg);
        bmp_sample.read((char*)&height, sizeof(int));
        std::cout << "width 2: " << width << "  height 2: " << height << std::endl;
    }
    bmp_sample.close();
}