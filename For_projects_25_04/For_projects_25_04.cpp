#include <iostream>
#include "Header.h"


int main()
{
	std::cout << "Hello, world." << std::endl;
	Stakk<int> s;
	s.push(123);
	std::cout << s.get();
	return 0;
}

/* Input {
state;
symbol;
}
Output{
state;
symbol;
move;
}
firstly comperison state then symbol
circle array - lenta
curcle buffer osnovanni on list*/


// в случае неполного заполнения буфера мы переходим с последнего непустого элемента дальше к непустым или к первому непустому элементу

//BigInteger BigInteger::operator/(BigInteger& x) {
//	if (b_size < x.b_size) {
//		return *this;
//	}
//	BigInteger tmp;
//	for (size_t i = 0; i < b_size; ++i) {
//		for (size_t j = 0; j < x.b_size; ++j) {
//
//		}
//	}
//}