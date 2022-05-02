#pragma once
#include <fstream>
#include <iostream>

void calc_symb(char* array, char* filename) {
	std::fstream file(filename, std::ios_base::in);
	if (file.is_open()) {
		while (file.peek() != EOF) {
			char symb = file.get();
			array[symb] += 1;
		}
	}
	else { std::cout << "something wrong" << std::endl; }
	file.close();
}

class tree {
	struct node {
		char symb_t;
		int count_t;
		node* parent;
		node* left;
		node* right;
		node() {
			parent = left = right = nullptr;
		}
		~node() {
			if (parent)
				delete parent;
			if (left)
				delete left;
			if (right)
				delete right;
		}
	};
	node* root;
	/*struct node {
		unsigned char symbol;
		size_t freq; //ACHTUNG?? i don't know, what is it for?
		node* left;
		node* right;
	};
	node *first;*/
public:
	friend void decode(std::fstream, const char*, tree&);
};

tree& creating_tree(char* array) {

}

void decode(std::fstream file, const char* name, tree& x) {
	file.open(name, std::ios_base::binary);
	std::fstream out("result.txt", std::ios_base::out | std::ios_base::trunc);
	if (file.is_open() && out.is_open()) {
		tree::node* cur = x.root;
		int cnt = 0;
		file.read((char*)cnt, 1);
		while (file.peek() != EOF) {
			char symb = ' ';
			file.read((char*)symb, 1);
			if (file.peek() == EOF) {
				for (int i = 0; i < cnt; ++i) {
					switch ((int)symb & (int)pow(2, 7 - i)) {
					case 0:
						if (cur) {
							cur = cur->left;
							if (cur == nullptr) {
								out.put(cur->parent->symb_t);
								cur = x.root->left;
							}
						}
						else {
							out.put(cur->parent->symb_t);
							cur = x.root->left;
						}
						break;
					default:
						if (cur) {
							cur = cur->right;
						}
						else {
							out.put(cur->parent->symb_t);
							cur = x.root;
						}
						if (cur == nullptr) {
							out.put(cur->parent->symb_t);
							cur = x.root;
						}
						break;
					}
				}
			}
			else {
				for (int i = 7; i >= 0; --i) {
					switch ((int)symb & (int)pow(2, i)) {
					case 0:
						if (cur) {
							cur = cur->left;
							if (cur == nullptr) {
								out.put(cur->parent->symb_t);
								cur = x.root->left;
							}
						}
						else {
							out.put(cur->parent->symb_t);
							cur = x.root->left;
						}
						break;
					default:
						if (cur) {
							cur = cur->right;
						}
						else {
							out.put(cur->parent->symb_t);
							cur = x.root;
						}
						if (cur == nullptr) {
							out.put(cur->parent->symb_t);
							cur = x.root;
						}
						break;
					}
				}
			}
		}
	}
	file.close();
	out.close();
}