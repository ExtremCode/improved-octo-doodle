#pragma once
#include <iostream>

template<typename T>
struct Arr {
	T* storage;
	size_t size;
	Arr() {
		storage = nullptr;
		size = 0;
	}
	Arr(T* link, size_t rage) : storage(link), size(rage) {}
	/*~Arr() {
		delete[] storage;
	}*/
};

template<typename T>
T* removeElement(Arr<T>& a, const size_t index) {
	T parametr;
	if (a.size > index) {
		parametr = a.storage[index];
		T* tmp = new T[a.size];
		for (size_t j = 0; j < a.size; ++j) {
			tmp[j] = a.storage[j];
		}
		//delete[] a.storage;
		a.storage = new T[a.size - 1];
		for (size_t j = 0; j < a.size; ++j) {
			if (j != index)
				a.storage[j] = tmp[j];
		}
		--a.size;
		delete[] tmp;
	}
	return (a.size > index) ? &parametr : nullptr;
}

template <typename T>
T* getElement(const Arr<T>& a, const size_t index) {
	return (a.size > index) ? (a.storage + index) : nullptr;
}

template <typename T>
void addElement(Arr<T>& a, const T elem) {
	T* tmp = new T[a.size];
	for (size_t i = 0; i < a.size; ++i) {
		tmp[i] = a.storage[i];
	}
	//delete[] a.storage;
	a.storage = new T[a.size + 1];
	for (size_t i = 0; i < a.size; ++i) {
		a.storage[i] = tmp[i];
	}
	a.storage[a.size] = elem;
	++a.size;
	delete[] tmp;
}

template <typename T>
void Resize_arr(Arr<T>& a, const size_t new_size) {
	T* tmp = new T[a.size];
	for (size_t i = 0; i < a.size; ++i) {
		tmp[i] = a.storage[i];
	}
	//delete[] a.storage;
	a.storage = new T[new_size];
	a.size = new_size;
	for (size_t i = 0; i < a.size; ++i) {
		a.storage[i] = tmp[i];
	}
	delete[] tmp;
}

bool testAdd() {
	int* mas = new int[6]{ 1, 2, 3, 4, 5, 6 };
	Arr<int> a{ mas, 6 };
	addElement(a, 99);
	if ((a.storage[6] != 99) || (a.size != 7))
		return false;
	delete[] mas;

	double* m = new double[3]{ -5.8,3.0,0.5 };
	Arr<double> b{ m, 3 };
	addElement(b, -7.3);
	if ((b.storage[3] != -7.3) || (b.size != 4))
		return false;
	delete[] m;

	char ch[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	Arr<char> c{ ch, 7 };
	addElement(c, 'z');
	if ((c.storage[7] != 'z') || (c.size != 8))
		return false;
	return true;
}

bool testRemove() {
	float mas[] = { -1.0f, 2.3f, -3.6f, 4.2f, 12.5f, 13.9f };
	Arr<float> a{ mas, 6 };
	if ((*removeElement(a, 2) != -3.6f) || (a.size != 5))
		return false;

	short m[100] = { 8, 3, 4, 9, 1 };
	Arr<short> b{ m, 100 };
	if ((*removeElement(b, 3) != 9) || (b.size != 99))
		return false;

	std::string str[] = { "Just fine", "I lied", "I'm", "dying", "inside" };
	Arr<std::string> s{ str, 5 };
	if ((removeElement(s, 10) != nullptr) || (s.size != 5))
		return false;
	return true;
}

bool testGet() {
	float mas[] = { -1.0f, 2.3f, -3.6f, 4.2f, 12.5f, 13.9f };
	Arr<float> a{ mas, 6 };
	if ((getElement(a, 8) != nullptr) || (a.size != 6))
		return false;

	short m[100] = { 8, 3, 4, 9, 1 };
	Arr<short> b{ m, 100 };
	if ((b.size != 100) || (*getElement(b, 3) != 9))
		return false;

	std::string str[] = { "Just fine", "I lied", "I'm", "dying", "inside" };
	Arr<std::string> s{ str, 5 };
	if ((s.size != 5) || (*getElement(s, 2) != "I'm"))
		return false;
	return true;
}

bool testResize_arr() {
	int mas[] = { -1, 2, -3, 4, 12, 13 };
	Arr<int> a{ mas, 5 };
	Resize_arr(a, 4);
	if ((a.size != 4) || (a.storage[3] != 4))
		return false;

	double* m = new double[100]{ 9.7, 3.5, 4.6, 9.9, 1.2 };
	Arr<double> b{ m, 100 };
	Resize_arr(b, 3);
	if (b.size != 3)
		return false;
	delete[] m;

	char ch[] = { 'a', 'c', 'g', 'b', 't', 'q', 'r', 'k' };
	Arr<char> c{ ch, 8 };
	Resize_arr(c, 10);
	if ((c.size != 10) || (c.storage[7] != 'k'))
		return false;
	return true;
}

template <typename T>
void presentShelf(const Arr<T>& a, const size_t size) {
	for (size_t i = 0; i < size; ++i) {
		//std::cout << *getElement(a, i) << " ";
		std::cout << a.storage[i] << " ";
	}
}
