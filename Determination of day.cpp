#include <iostream>
using namespace std;

int main()
{
    int d, m, y;
    cout << "Input day, month and year with whitespace: ";
    cin >> d >> m >> y;
    string dn[] = { "Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday" };
    int cc=6,cy,cm;
    if (m == 1 || m == 10) { cm = 1; }
    else if (m == 5) { cm = 2; }
    else if (m == 8) { cm = 3; }
    else if (m == 2 || m == 3 || m == 11) { cm = 4; }
    else if (m == 6) { cm = 5; }
    else if (m == 12 || m == 9) { cm = 6; }
    else { cm = 0; }
    if (y / 100 % 4 == 0) { cc = 6; }
    else if (y / 100 % 4 == 1) { cc = 4; }
    else if (y / 100 % 4 == 2) { cc = 2; }
    else if (y / 100 % 4 == 3) { cc = 0; }
    cy = (cc + y % 100 + y % 100 / 4)% 7;
    if (y % 4 == 0 & y % 100 != 0 || y % 100 == 0 & y % 400 == 0) {
        if (m <= 2) {
            if ((d + cm + cy) % 7 == 0) {
                cout << "Day of the week is " << dn[(d + cm + cy) % 7 + 6] << endl;
            }
            else { cout << "Day of the week is " << dn[(d + cm + cy) % 7 - 1] << endl; }
        }
        else { cout << "Day of the week is " << dn[(d + cm + cy) % 7] << endl; }
    }
    else { cout << "Day of the week is " << dn[(d + cm + cy) % 7] << endl; }
    
    system("pause");
    return 0;
}