#include "pch.h"
#include "../List.h"

class ListTest : public ::testing::Test {
protected:
	void SetUp() {
		for (size_t i = 0; i < 9; ++i) {
			occup.addElement("something str");
		}
	}

	List<double> empty;
	List<std::string> occup;
};

TEST_F(ListTest, size) {
	EXPECT_EQ(empty.getSize(), 0);
	EXPECT_EQ(occup.getSize(), 9);
}

TEST_F(ListTest, Getmarker) {
	EXPECT_EQ(occup.getMarker().getcur_val(), "something str");
}

TEST_F(ListTest, adding) {
	EXPECT_EQ(empty.getSize(), 0);
	empty.addElement(-3.12);
	EXPECT_EQ(empty.getSize(), 1);
	empty.addElement(9.5674);
	EXPECT_EQ(empty.getSize(), 2);

	occup.addElement("fake news");
	occup.addElement("fake news");
	occup.addElement("fake news");
	EXPECT_EQ(occup.getSize(), 12);
}
TEST_F(ListTest, removing) {
	EXPECT_ANY_THROW(occup.removeElement(occup.getMarker()));
	EXPECT_EQ(0, 0);
	/*EXPECT_EQ(occup.getSize(), 11);
	occup.removeElement(occup.getMarker());
	EXPECT_EQ(occup.getSize(), 10);

	empty.removeElement(empty.getMarker());
	EXPECT_EQ(empty.getSize(), 1);
	empty.removeElement(empty.getMarker());
	EXPECT_ANY_THROW(empty.removeElement(empty.getMarker()));*/
}