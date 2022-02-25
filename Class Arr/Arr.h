#pragma once
#include <iostream>

struct BadSize {};
struct BadGetElement {};
struct BadRemove {};

template<typename T>
class Arr {
	T* m_storage;
	size_t m_size;
public:
	Arr();
	Arr(int);
	~Arr();
	T removeElement(const size_t);
	T& getElement(const size_t) const;
	size_t getSize() const;
	void addElement(const T);
	void Resize_arr(const size_t);
};

template <typename T>
Arr<T>::Arr() {
	m_size = 0;
	m_storage = nullptr;
}

template <typename T>
Arr<T>::Arr(int size) {
	if (size < 1) {
		throw BadSize();
	}
	else {
		m_size = size;
		m_storage = new T[m_size];
	}
}

template <typename T>
Arr<T>::~Arr() {
	if (m_storage != nullptr) {
		delete[] m_storage;
	}
}

template <typename T>
T Arr<T>::removeElement(const size_t index) {
	T parametr;
	if (m_size > index) {
		parametr = m_storage[index];
		T* tmp = new T[m_size-1];
		for (size_t j = 0, k=0; k < m_size; ++j) {
			if (j != index) {
				tmp[j] = m_storage[k++];
			} else {
				tmp[j] = m_storage[++k];
				++k;
			}
		}
		delete[] m_storage;
		m_storage = new T[--m_size];
		for (size_t j = 0; j < m_size; ++j) {
			m_storage[j] = tmp[j];
		}
		delete[] tmp;
	} else {
		throw BadRemove();
	}
	return parametr;
}

template <typename T>
T& Arr<T>::getElement(const size_t index) const {
	if (index >= m_size) {
		throw BadGetElement();
	}
	else {
		return  *(m_storage + index);
	}
}

template <typename T>
size_t Arr<T>::getSize() const {
	return m_size;
}

template <typename T>
void Arr<T>::addElement(const T elem) {
	T* tmp = new T[m_size + 1];
	tmp[m_size] = elem;
	for (size_t i = 0; i < m_size; ++i) {
		tmp[i] = m_storage[i];
	}
	delete[] m_storage;
	m_storage = tmp;
	++m_size;
}

template <typename T>
void Arr<T>::Resize_arr(const size_t new_size) {
	T* tmp = new T[m_size];
	for (size_t i = 0; i < m_size; ++i) {
		tmp[i] = m_storage[i];
	}
	m_storage = new T[new_size];
	m_size = new_size;
	for (size_t i = 0; i < m_size; ++i) {
		m_storage[i] = tmp[i];
	}
	delete[] tmp;
}

template <typename T>
void presentShelf(const Arr<T>& a, const size_t size) {
	for (size_t i = 0; i < a.getSize; ++i) {
		std::cout << a.getElement(i) << std::endl;
	}
}