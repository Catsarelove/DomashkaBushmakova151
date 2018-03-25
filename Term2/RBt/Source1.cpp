#include "Header.h"
using namespace std;
void swap(RBt a, RBt b) {
	int s; 
	node* r;
	s = a.size;
	r = a.root;
	a.root = b.root;
	a.size = s;
	b.root = r;
	b.size = s;
}
RBt operator+(RBt a, RBt b) {
	RBt s;
	node* top = a.root;
	stack<node*> st;
	while (top != NULL || st.head != NULL) {
		if (st.head != NULL) {
			top = st.pop();
		}
		while (top != NULL) {
			s.insert(top->data);
			if (top->right != NULL) st.push(top->right);
			top = top->left;
		}
	}
	top = b.root;
	while (top != NULL || st.head != NULL) {
		if (st.head != NULL) {
			top = st.pop();
		}
		while (top != NULL) {
			s.insert(top->data);
			if (top->right != NULL) st.push(top->right);
			top = top->left;
		}
	}
	return s;
}
RBt operator*(RBt a, RBt b) {
	RBt s;
	node* top = a.root;
	stack<node*> st;
	while (top != NULL || st.head != NULL) {
		if (st.head != NULL) {
			top = st.pop();
		}
		while (top != NULL) {
			node* temp = b.find(b.root, top->data);
			if (temp!=NULL)
				s.insert(top->data);
			if (top->right != NULL) st.push(top->right);
			top = top->left;
		}
	}
	return s;
}
bool included(int x, RBt a) {
	return a.find(a.root, x);
}
bool operator <(RBt a, RBt b) {
	for (int i = 0; i < a.size;i++) {
		if (!(b.find(b.root, a.root->data)))
			return false;
	}
	return true;
}
bool operator > (RBt a, RBt b) {
	return b < a;
}
RBt operator -(RBt a, RBt b) {
	RBt s;
	node* top = a.root;
	stack<node*> st;
	while (top != NULL || st.head != NULL) {
		if (st.head != NULL) {
			top = st.pop();
		}
		while (top != NULL) {
			node* temp = b.find(b.root, a.root->data);
			if (!temp)
				s.insert(a.root->data);
			if (top->right != NULL) st.push(top->right);
			top = top->left;
		}
	}
	return s;
}
RBt operator % (RBt a, RBt b) {
	RBt s;
	s = (a + b) - a*b;
	return s;
}
