#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[])
{
    std::fstream file;
    std::vector<int> m1 = { 9,8,7,6,5 };
    std::vector<int> m = { 1,2,3,4,5 };
    file.open(argv[1], std::ios_base::out  | std::ios_base::trunc | std::ios_base::binary | std::ios_base::in);
    if (file.is_open()) {
        std::cout << "Open" << std::endl;
        for (size_t j = 0; j < 5; ++j) {
            file.write((char*)&m[j], sizeof(int));
        }
        file.close();
        file.open(argv[1],std::ios_base::binary | std::ios_base::in);
        if (file.is_open()) {
            for (size_t i = 0; i < m.size(); ++i) {
                file.read((char*)&m1[i], sizeof(int));
            }
        }
        (m == m1) ? std::cout << "It's fire" << std::endl : std::cout << "========= Error ========" << std::endl;
    }
    else { std::cout << "Error"; }
    file.close();
}