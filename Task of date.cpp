#include <iostream>
using namespace std;

int main()
{
    int d1, m1, y1, d2, m2, y2,s=0;
    int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int month_vis[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    cout << "Input day , month , year of start and day, month, year of end (separated by a space) ";
    cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    if (y1 != y2) {
        if ((y1 % 4 == 0) || ((y1 % 4 == 0) & (y1 % 100 != 0)) || ((y1 % 100 == 0) & (y1 % 400 == 0))) {
            s += month_vis[m1 - 1] - d1;
            for (int i = m1 + 1; i <= 12; ++i) {
                s += month_vis[i - 1];
            }
        }
        else {
            s += month[m1 - 1] - d1;
            for (int i = m1 + 1; i <= 12; ++i) {
                s += month[i - 1];
            }
        } //посчитали до 1 января не вкл следующего года
        for (int i = y1+1; i < y2; ++i) {
            if (((i % 4 == 0)) || ((i % 4 == 0) & (i % 100 != 0)) || ((i % 100 == 0) & (i % 400 == 0))) {
                s += 366;
            }
            else {
                s += 365;
            } // посчитали дни от следующего года вкл до конечного не вкл
        }for (int i = 1; i < m2; ++i) {
            if ((y2 % 4 == 0) || ((y2 % 4 == 0) & (y2 % 100 != 0)) || ((y2 % 100 == 0) & (y2 % 400 == 0))) {
                s += month_vis[i-1];
            }
            else {
                s += month[i-1];
            }
        }
        s += d2;
    }
    else {
        if (m1 < m2) {
            if ((y1 % 4 == 0) || ((y1 % 4 == 0) & (y1 % 100 != 0)) || ((y1 % 100 == 0) & (y1 % 400 == 0))) {
                s += month_vis[m1 - 1] - d1;
                for (int i = m1+1; i < m2; ++i) {
                    s += month_vis[i - 1];
                }
                s += d2;
            }
            else {
                s += month[m1 - 1] - d1;
                for (int i = m1+1; i < m2; ++i) {
                    s += month[i - 1];
                }
                s += d2;
            }
        }
        else {
            s += d2 - d1;
        }
    }
    cout << "sum of days after select date : " << s << endl;
}