#pragma once
#include "Arr.h"

bool testAdd() {
	Arr<int> a{ 6 };
	a.addElement(99);
	if ((a.getElement(6) != 99) || (a.getSize() != 7))
		return false;

	Arr<double> b{ 3 };
	b.addElement(-7.3);
	if ((b.getElement(3) != -7.3) || (b.getSize() != 4))
		return false;

	Arr<char> c{ 7 };
	c.addElement('z');
	if ((c.getElement(7) != 'z') || (c.getSize() != 8))
		return false;
	return true;
}

bool testRemove() {
	Arr<float> a{ 6 };
	a.addElement(-1.2f); a.addElement(2.3f); a.addElement(-3.6f); a.addElement(4.2f); a.addElement(12.5f);
	if ((a.removeElement(6) != -1.2f) || (a.getSize() != 10))
		return false;

	Arr<short> b{ 100 };
	b.addElement((short)8); b.addElement(3); b.addElement(4); b.addElement(9); b.addElement(1);
	if ((b.removeElement(100) != (short)8) || (b.getSize() != 104))
		return false;

	Arr<std::string> s{ 5 };
	s.addElement("Just fine"); s.addElement("I lied"); s.addElement("I'm"); s.addElement("dying"); s.addElement("inside");
	try {
		s.removeElement(11);
	}
	catch (BadRemove) {
		std::cerr << "wrong index in removeElement work successfully" << std::endl;
	}
	return true;
}

bool testGet() {
	Arr<float> a;
	a.addElement(-1.0f); a.addElement(2.3f); a.addElement(-3.6f);
	try {
		a.getElement(8);
	}
	catch (BadGetElement) {
		std::cerr << "error of getting element work successfully" << std::endl;
	}

	Arr<short> b;
	b.addElement(8); b.addElement(3); b.addElement(4); b.addElement(9); b.addElement(1);
	if ((b.getElement(3) != 9) || (b.getSize() != 5))
		return false;

	Arr<std::string> s;
	s.addElement("Just fine"); s.addElement("I lied"); s.addElement("I'm"); s.addElement("dying"); s.addElement("inside");
	if ((s.getElement(2) != "I'm") || (s.getSize() != 5))
		return false;
	return true;
}

bool testResize_arr() {
	Arr<int> a{ 5 };
	a.Resize_arr(4);
	if ((a.getSize() != 4))
		return false;

	Arr<double> b{ 100 };
	b.Resize_arr(3);
	if (b.getSize() != 3)
		return false;

	Arr<char> c{ 8 };
	c.Resize_arr(10);
	if ((c.getSize() != 10))
		return false;
	return true;
}