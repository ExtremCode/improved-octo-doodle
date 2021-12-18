#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool test(const std::string argv){
    std::fstream file;
    file.open(argv, std::ios_base::out  | std::ios_base::trunc | std::ios_base::binary | std::ios_base::in);
    if (file.is_open()) {
        std::cout << "Open" << std::endl;
        std::vector<int> test = { 9,8,7,6,5 };
        std::vector<int> m = { 1,2,3,4,5 };
        for (size_t j = 0; j < m.size(); ++j) {
            file.write((char*)&m[j], sizeof(int));
        }
        file.close();
        file.open(argv,std::ios_base::binary | std::ios_base::in);
        if (file.is_open()) {
            for (size_t i = 0; i < m.size(); ++i) {
                file.read((char*)&test[i], sizeof(int));
            }
        }file.close();
        if(m!=test) return false;
        
        m = { -1,-2,-3,-4,-10,67,35};
        test.resize(m.size(),0);
        for (size_t j = 0; j < m.size(); ++j) {
            file.write((char*)&m[j], sizeof(int));
        }
        file.close();
        file.open(argv,std::ios_base::binary | std::ios_base::in);
        if (file.is_open()) {
            for (size_t i = 0; i < m.size(); ++i) {
                file.read((char*)&test[i], sizeof(int));
            }
        }file.close();
        if(m!=test) return false;
        
        std::vector<std::vector<int>> nw = {{ -1,-2,-3,-4,-10,67,35},{ -1,-2,-3,-4,-10,67,35},{ -1,-2,-3,-4,-10,67,35}};
        std::vector<std::vector<int>> nwtest(nw.size(),std::vector<int>(nw[0].size(),0));
        for (size_t j = 0; j < nw.size(); ++j) {
            file.write((char*)&nw[j], 7*sizeof(int));
        }
        file.close();
        file.open(argv,std::ios_base::binary | std::ios_base::in);
        if (file.is_open()) {
            for (size_t i = 0; i < nw.size(); ++i) {
                file.read((char*)&nwtest[i], 7*sizeof(int));
            }
        }file.close();
        if(nw!=nwtest) return false;
        
        nw = {{ -1,100,-3,0,-10,67,6,-12},{ -1,-2,-3,-4,-10,32,35,96},{ -1,-2,-3,-9,-10,67,35,0}};
        nwtest.resize(nw.size(),std::vector<int>(nw[0].size(),0));
        for (size_t j = 0; j < nw.size(); ++j) {
            file.write((char*)&nw[j], 7*sizeof(int));
        }
        file.close();
        file.open(argv,std::ios_base::binary | std::ios_base::in);
        if (file.is_open()) {
            for (size_t i = 0; i < nw.size(); ++i) {
                file.read((char*)&nwtest[i], 7*sizeof(int));
            }
        }file.close();
        if(nw!=nwtest) return false;
    }
    return true;
}

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
    std::cout<<test("Example.txt")<<std::endl;
}
