#pragma once
#include <iostream>

struct BadSize {};
struct BadGetElement {};
struct BadRemove {};

template <typename T>
class Marker {
	T* m_storage;
	size_t m_size;
protected:
	T* m_cur_marker;
public:
	Marker(T* current = nullptr, T* store = nullptr, size_t size = 0) :
		m_cur_marker(current), m_storage(store), m_size(size) {}
	T& getcur_val();
	void rewind();
	bool canMove2next();
	void move2next();
	void fast_forward();
};

template<typename T>
class Arr : public Marker<T> {
	T* m_storage;
	size_t m_size;
	Marker<T> mark{ m_storage, m_storage, m_size };
public:
	Arr();
	Arr(int);
	~Arr();
	T removeElement(const size_t);
	T& getElement(const size_t) const;
	inline size_t getSize() const;
	void addElement(const T);
	void Resize_arr(const size_t);
	T* getMarker() {
		return mark.m_cur_marker;
	}
};

template <typename T>
Arr<T>::Arr() {
	/*mark.m_size = */m_size = 0;
	/*mark.m_cur_marker = mark.m_storage = */m_storage = nullptr;
}

template <typename T>
Arr<T>::Arr(int size) {
	if (size < 1) {
		throw BadSize();
	}
	else {
		/*mark.m_size = */m_size = size;
		/*mark.m_cur_marker = mark.m_storage = */m_storage = new T[m_size];
	}
}

template <typename T>
Arr<T>::~Arr() {
	if (m_storage) {
		delete[] m_storage;
	}
}

template <typename T>
T Arr<T>::removeElement(const size_t index) {
	T parametr;
	if (m_size > index) {
		parametr = m_storage[index];
		T* tmp = new T[m_size - 1];
		for (size_t j = 0, k = 0; k < m_size; ++j) {
			if (j != index) {
				tmp[k++] = m_storage[j];
			}
			else {
				if (j + 1 < m_size) {
					tmp[k++] = m_storage[++j];
				}
			}
		}
		if(m_storage)
			delete[] m_storage;
		m_storage = tmp;
		--m_size;
	}
	else {
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
	/*for (size_t i = 0; i < m_size; ++i) {
		tmp[i]= m_storage[i];
	}*/
	while (mark.canMove2next()) {
		//*(tmp + (getMarker() - m_storage) ) = mark.getcur_val(); don't work
		mark.move2next();
	}
	mark.rewind();
	delete[] m_storage;
	m_storage = tmp;
	++m_size;
}

template <typename T>
void Arr<T>::Resize_arr(const size_t new_size) {
	T* tmp = new T[m_size];
	/*for (size_t i = 0; i < m_size; ++i) {
		tmp[i] = m_storage[i];
	}*/
	while (mark.canMove2next()) {
		//*(tmp + (getMarker() - m_storage) ) = mark.getcur_val(); don't work
		mark.move2next();
	}
	mark.rewind();
	/*mark.m_storage = */m_storage = tmp;
	/*mark.m_size = */m_size = new_size;
}

template <typename T>
void presentShelf(const Arr<T>& a, const size_t size) {
	for (size_t i = 0; i < a.getSize; ++i) {
		std::cout << a.getElement(i) << std::endl;
	}
}

template <typename T>
T& Marker<T>::getcur_val() {
	return m_storage[m_cur_marker - m_storage];
}

template <typename T>
void Marker<T>::move2next() {
	++m_cur_marker;
}

template <typename T>
bool Marker<T>::canMove2next() {
	return (m_cur_marker < m_storage + m_size);
}

template <typename T>
void Marker<T>::rewind() {
	m_cur_marker = m_storage;
}

template <typename T>
void Marker<T>::fast_forward() {
	m_cur_marker = m_storage + m_size;
}