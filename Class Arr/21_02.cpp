#include "Arr.h"
#include "unitTests.h"

int main()
{
	try {
		Arr<int> shelf(-4);
		shelf.addElement(46);
		int ex1 = 42;
		shelf.addElement(ex1);
		shelf.getElement(0);
	}
	catch (BadSize) {
		std::cerr << "Error of wrong size of array" << std::endl;
	}
	catch (BadGetElement) {
		std::cerr << "undefined element" << std::endl;
	}
	catch (...) {
		std::cerr << "Error occured" << std::endl;
	}
	std::cout << testResize_arr();
	return 0;
}