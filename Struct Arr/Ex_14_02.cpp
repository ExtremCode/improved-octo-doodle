#include <iostream>
#include "Struct_arr.h"

int main()
{
	int* mas = new int[10]{ 0,1,2,3,4,5,6,7,8,9 };
	Arr<int> a = { mas,10 };
	std::cout << testRemove();
	delete[] mas;
	return 0;
}
