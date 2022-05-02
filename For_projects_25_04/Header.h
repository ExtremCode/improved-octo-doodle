#pragma once
#include "NewArr.h"
#include <fstream>

template <typename T> class Stakk {
	Arr<T> st_base; //list or array
public:
	Stakk() {};
	~Stakk() {
		st_base.~Arr<T>();
	}
	void push(const T& val) {
		st_base.addElement(val);
	}
	const T& get() const {
		if (st_base.getSize()) {
			return st_base.getElement();
		}
		else {
			throw std::exception();
		}
	}
	void pop() {
		if (st_base.getSize()) {
			st_base.removeElement();
		}
		else throw std::exception();
	}

};

template <typename T> class circBuff { //for Turing machine
	Arr<T> c_base; // may be better storage is array
public:
	circBuff(size_t s) {
		c_base = Arr<T>{ s };
	}
	circBuff() {
		c_base = Arr<T>();
	}
	//ïîìåñòèòü ýëåìåíò â òåêóùóþ ïîçèöèþ è ïåðåìåñòèòü óêàçàòåëü?
	void put(const T& val) {
		if (c_base.getsize() && c_base.getMarker()) {
			c_base.setEl(val);
		}
	}
	// ïîëó÷èòü ýëåìåíò èç òåêóùåé ïîçèöèè
	const T& get() const {
		//c_base.getElement();
		c_base.mark.getcur_val();
	}
	/*friend Arr<T>;
	friend Marker<T>;*/
};

struct Input {
	//T* posit;
	const char* condition;
	bool symbol;
	Input(const char* cond, char symb) : condition(cond), symbol(symb) {}
};
struct Output {
	//T* posit;
	const char* condition;
	bool symbol;
	char move;// -1 0 1 == left stay right
	Output(const char* cond, char symb, char m) : condition(cond), symbol(symb), move(m) {}
};
class command {
	Input start;
	Output finish;
public:
	bool operator<(const command& x) {
		if (strcmp(start.condition, x.start.condition) == 1) {
			return false;
		}
		else if (strcmp(start.condition, x.start.condition) == 0) {
			if (start.symbol < x.start.symbol) {
				return true;
			}
			else return false;
		}
		else return true;
	}
	bool operator==(const command& x) {
		if (strcmp(start.condition, x.start.condition) == 0) {
			if (start.symbol == x.start.symbol) {
				return true;
			}
		}
		return false;
	}
};

template <typename T>
class tree {
	struct node {
		T data;
		node* left;
		node* right;
		node* parent;
		node(const T& x) : right(nullptr), left(nullptr), parent(nullptr), data(x) {}
		~node() {
			if (right) delete right;
			if (left) delete left;
			parent = right = left = nullptr;
		}
	};
	node* t_root;
public:
	tree() : t_root(nullptr) {}
	~tree() {
		if (t_root) delete t_root;
		t_root = nullptr;
	}
	void add(node* newnode) {
		if (t_root = nullptr) {
			t_root = newnode;
		}
		else {
			node* cur = t_root;
			while (cur != nullptr) {
				if (cur->data == newnode.data) return;
				if (newnode.data < cur->data) {
					if (cur->left != nullptr)  cur = cur->left;
					else {
						cur->left = newnode;
						newnode->parent = cur;
						return;
					}
				}
				else {
					if (cur->right != nullptr) cur = cur->right;
					else {
						cur->right = newnode;
						newnode->parent = cur;
						return;
					}
				}
			}
		}
	}
	T* find(const T& what) {
		node* cur = t_root;
		while (cur != nullptr) {
			if (cur->data == what) return cur->data;
			if (cur->data < what) cur = cur->left;
			else cur = cur->right;
		}
		return nullptr;
	}

	void balance() { //complete
		if (t_root == nullptr) return;
		node* p, * r;
		p = t_root;

	}
};

//template <typename T>
//class tree {
//	struct node {
//		T data;
//		node *left;
//		node *right;
//		node *parent;
//		node(const T& x): right(nullptr), left(nullptr), parent(nullptr), data(x) {}
//		~node() {
//			if (right) delete right;
//			if (left) delete left;
//			parent = right = left = nullptr;
//		}
//	};
//	node *root;
//public:
//	tree() : root(nullptr) {}
//	~tree() {
//		if (root) delete root;
//		root = nullptr;
//	}
//	bool find(command::Input& what) {
//		node* cur = root;
//		while (cur != nullptr) {
//			if(cur->data)
//		}
//	}
//};

class bitWriter {
	unsigned char w_bitbuffer;
	size_t w_curr;
public:
	bitWriter(const char* fname);
	~bitWriter();
	void putBit(bool);
	void putBits(const Arr<bool>& bits);
};

bitWriter::bitWriter(const char* fname) {
	std::fstream file(fname, std::ios_base::in | std::ios_base::binary);
}

class bitReader {
	unsigned char r_bitbuffer;
	size_t r_curr;
public:
	bitReader(const char* fname);
	~bitReader() {};
	Arr<bool> getBits(size_t numBits);
	bool getBit();
	bool eof();
};

bitReader::bitReader(const char* fname) {
	std::fstream file(fname, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
}