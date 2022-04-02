#pragma once
struct BadRemoveEl {};

template<typename T>
class List {
	size_t m_size;
	struct ListNode {
		T data_ls;
		ListNode* next;
	};
	ListNode* m_first;
public:
	class Marker {
		ListNode* m_cur_marker;
	public:
		Marker(ListNode* x=nullptr) : m_cur_marker(x) {}
		T& getcur_val() {
			return m_cur_marker->data_ls;
		}
		bool canMove2next() const {
			return (m_cur_marker->next != nullptr);
		}
		void move2next() {
			m_cur_marker = m_cur_marker->next;
		}
		/*void rewind() {
			m_cur_marker = m_first;
		}*/
		friend class List<T>;
	};
	List();
	List(const List<T>&);
	List(List<T> &&);
	List<T>& operator=(const List<T> &);
	~List();
	void addElement(const T&);
	void removeElement(const Marker&);
	size_t getSize() {
		return m_size;
	}
	Marker getMarker() {
		Marker m(m_first);
		return m;
	}
};

template <typename T>
List<T>::List() {
	m_size = 0;
	m_first = nullptr;
}

template <typename T>
List<T>::List(const List<T>& x) {
	m_first = nullptr;
	m_size = x.m_size;
	for (List<T>::Marker pos(x.m_first); pos.canMove2next(); pos.move2next()) {
		addElement(*pos);
	}
}

template <typename T>
List<T>::List(List<T>&& x) {
	m_first = x.m_first;
	m_size = x.m_size;
	x.m_first = nullptr;
	x.m_size = 0;
}

template <typename T>
List<T>::~List() {
	if (m_first == nullptr) return;
	do {
		ListNode* current = m_first->next;
		delete m_first;
		m_first = current;
	} while (m_first != nullptr);
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& x) {
	if (this != x) {
		for (List<T>::Marker pos = m_first; pos.canMove2next(); pos.move2next()) {
			removeElement(pos);
		}
		*this = std::move(List<T>&(x));
	}
	return *this;
}

template <typename T>
void List<T>::removeElement(const Marker& mark) {
	if (m_size == 0 || mark.m_cur_marker==nullptr) {
		throw BadRemoveEl();
	}
	ListNode* prev = m_first;
	ListNode* current = m_first;
	// find previous element for mark
	while (current != mark.m_cur_marker) {
		if (current == nullptr) {
			throw BadRemoveEl();
		}
		prev = current;
		current = current->next;
	}
	prev->next = current->next;
	delete current;
	/*if (current == mark.m_cur_marker) {
		m_first = current->next;
		delete current;
	}
	else {
		ListNode* to = nullptr;
		while (current->next != mark.m_cur_marker) {
			current = current->next;
			if (current == nullptr) {
				throw BadRemoveEl();
			}
		}
		to = current->next->next;
		delete current->next;
		current->next = to;
	}*/
	--m_size;
}

template <typename T>
void List<T>::addElement(const T& elem) {
	ListNode* first = m_first;
	while (first != nullptr) {
		first = first->next;
	}
	ListNode tmp{ elem, nullptr };
	first = &tmp;
	++m_size;
}