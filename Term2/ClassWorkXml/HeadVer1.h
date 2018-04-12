#pragma once
#include <fstream>
#include <iostream>
#include "stack.h"
using namespace std;
template <typename T>
struct node {
	T data;
	node(T x) {
		data = x;
	}
	node* left;
	node* right;
	node* parent;
};
template <typename T>
struct SimpleTree {
	node<T>* root;
	SimpleTree() {
		root = NULL;
	}
	void read(ifstream &f) {
		T key;
		char c;
		circle(NULL, f);
	}
	void circle(node* parent, ifstream &f) {
		if (eof) return;
		node* place;
		T key;
		char c;
		while(c!='<' && !eof)
		f >> c;
		if(!eof)
		f >> key;
		else throw "eof";
		place = new node;
		place->data = key;
		place->parent = parent;
		if (parent == NULL)
			root = place;
		else {
			parent->left = place;
		}
		if (eof) throw "eof";
		f >> c;
		if (c != '>') {
			fseek(f, -1, SEEK_CUR);
			circle(place, f);
		}
		else {
			if (eof) throw "eof";
			f >> c;
			if (c == '>') return;
			else {
				fseek(f, -1, SEEK_CUR);
				if (c == '<')
					f >> key;
				else
					throw "incorrect";
			}
		}
	}
	catch (string err) {
		if (err == "eof")
			cout << "Внезапный конец файла\n";
		if(err == "incorrect")
			cout << ""
	}
	void tr(){
		node* top = root;
		stack<node*> s;
		while (top != NULL || s.head != NULL) {
			if (s.head != NULL) {
				top = s.pop();
			}
			while (top != NULL) {
				erase(top);
				if (top->right != NULL) s.push(top->right);
				top = top->left;
			}
		}
	}
	void erase(node* n) {
		if (n->left == NULL && n->right == NULL) {
			if (n == root) root = NULL;
			delete n;
		}
		if (n->left != NULL || n->right != NULL) {
			if (n->left != NULL && n->right == NULL) {
				if (n == root)
					root = n->left;
				else {
					if (n->parent->left == n)
						n->parent->left = n->left;
					else
						n->parent->right = n->left;
					n->left->parent = n->parent;
					delete n;
				}
			}
			if (n->left == NULL && n->right != NULL) {
				if (n == root)
					root = n->right;
				else {
					if (n->parent->left == n)
						n->parent->left = n->right;
					else
						n->parent->right = n->right;
					n->right->parent = n->parent;
					delete n;
				}
			}
			if (n->left != NULL && n->right != NULL) {
				temp = n->right;
				while (temp->right != NULL) {
					temp = temp->right;
				}
				temp->right = n->left;
				n->left->parent = temp;
				n->left = NULL;
				erase(n);
			}
		}
	}
	~SimpleTree() {
		tr();
	}
};
