#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	unsigned char m[10] = { 1,2,3,4,5,6,7,8,9 };
	float sa = 0;
	for (int i = 0; i < 10; ++i) {
		sa += m[i];
	}
	cout << sa/10.0 << endl;
    return 0;
}
