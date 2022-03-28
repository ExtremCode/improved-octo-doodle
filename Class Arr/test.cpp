#include "pch.h"
#include "../../21_02/Arr.h"

TEST(TestArr, adding) {
	Arr<int> a{ 6 };
	a.addElement(99);
	EXPECT_EQ(a.getElement(6), 99);
	EXPECT_EQ(a.getSize(), 7);

	Arr<double> b{ 3 };
	b.addElement(-7.3);
	EXPECT_EQ(b.getElement(3), -7.3);
	EXPECT_EQ(b.getSize(),4);
	
	Arr<char> c{ 7 };
	c.addElement('z');
	EXPECT_EQ(c.getElement(7), 'z');
	EXPECT_EQ(c.getSize(),8);
}

TEST(TestArr, removing) {
	Arr<float> a{ 6 };
	a.addElement(-1.2f);
	a.addElement(2.3f);
	a.addElement(-3.6f);
	a.addElement(4.2f);
	a.addElement(12.5f);
	a.removeElement(6);
	// EXPECT_EQ(a.removeElement(6), -1.2f); left value is link so it's not equal to float number
	EXPECT_EQ(a.getSize(), 10);

	Arr<short> b{ 100 };
	b.addElement((short)8);
	b.addElement((short)3);
	b.addElement(4);
	b.addElement(9);
	b.addElement(1);
	b.removeElement(103);
	EXPECT_EQ(b.getSize(), 104);

	Arr<std::string> c{ 5 };
	c.addElement("Just fine");
	c.addElement("I lied");
	c.addElement("I'm");
	c.addElement("dying");
	c.addElement("inside");
	EXPECT_ANY_THROW(c.removeElement(11));
}

TEST(TestArr, getting) {
	Arr<float> a{ 6 };
	a.addElement(-3.6f);
	a.addElement(12.5f);
	EXPECT_ANY_THROW(a.getElement(8));

	Arr<short> b{ 100 };
	b.addElement((short)8);
	b.addElement(3);
	b.addElement(4);
	b.addElement(9);
	b.addElement(1);
	EXPECT_EQ(b.getElement(103), 9);
	EXPECT_EQ(b.getSize(), 105);

	Arr<std::string> c{ 5 };
	c.addElement("Just fine");
	c.addElement("I lied");
	c.addElement("I'm");
	c.addElement("dying");
	c.addElement("inside");
	EXPECT_EQ(c.getElement(7), "I'm");
	EXPECT_EQ(c.getSize(), 10);
}

TEST(TestArr, resizing) {
	Arr<int> a{ 5 };
	a.Resize_arr(4);
	EXPECT_EQ(a.getSize(), 4);

	Arr<double> b{ 3 };
	b.Resize_arr(3);
	EXPECT_EQ(b.getSize(), 3);

	Arr<char> c{ 8 };
	EXPECT_ANY_THROW(c.Resize_arr(-1));
	EXPECT_EQ(c.getSize(), 8);
}