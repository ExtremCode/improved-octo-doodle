#include <iostream>
#include <time.h>
#include <string>
#include <vector>

int main()
{
    srand(time(0));
    char m[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
    int n;
    std::cout << "Enter the number of elemnts of the array ";
    std::cin >> n;
    std::cout << std::endl;
    std::vector <std::string> arr(n);
    for (int i = 0; i < n; ++i) {
        int tmp = rand() % 1000;
        std::string d;
        while (tmp > 0) {
            d += m[tmp % 16];
            tmp /= 16;
        }
        for (int i2 = d.length() - 1; i2 >= 0; --i2) {
            arr[i] += d[i2];
        }
    }
    std::cout << "Your array of hexadecimal numbers: " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << std::endl;
    system("pause");
}