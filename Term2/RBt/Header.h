#include <stdio.h>
#include "stack.h"
using namespace std;
struct node {
	int data;
	int color;   /* 1 black; 0 red*/
	node* parent;
	node* left;
	node* right;
};
struct RBt {
	int size=0;
	node* root=NULL;
	RBt() {
		root = NULL;
		size = 0;
	}
	RBt(const RBt & a) {
		node* top = a.root;
		stack<node*> s;
		while (top != NULL || s.head!=NULL) {
			if (s.head != NULL) {
				top = s.pop();
			}
			while (top != NULL) {
				insert(top->data);
				if (top->right != NULL) s.push(top->right);
				top = top->left;
			}
		}
	}
	RBt& operator =(const RBt &a) {
		node* top = a.root;
		stack<node*> s;
		while (top != NULL || s.head != NULL) {
			if (s.head != NULL) {
				top = s.pop();
			}
			while (top != NULL) {
				insert(top->data);
				if (top->right != NULL) s.push(top->right);
				top = top->left;
			}
		}
		return *this;
	}
	void insert(int x) {
		if (root == NULL) {
			root = new node;
			root->data = x;
			root->color = 1;
			root->parent = NULL;
			root->left = NULL;
			root->right = NULL;
			size = 1;
		}
		else 
			findandinsert(x, root);
	}
	node* sibling(node* x) {
		if (x->parent->left == x)
			return x->parent->right;
		else return x->parent->left;
	}
    void findandinsert(int x, node* temp) {
		if (x > temp->data) {
			if (temp->left != NULL)
				findandinsert(x, temp->left);
			else {
				temp->left = new node;
				temp->left->data = x;
				temp->left->left = NULL;
				temp->left->right = NULL;
				temp->left->parent = temp;
				temp->left->color = 0;
				size++;
				check(temp);
			}
		}
		if (x < temp->data) {
			if (temp->right != NULL)
				findandinsert(x, temp->right);
			else {
				temp->right = new node;
				temp->right->data = x;
				temp->right->left = NULL;
				temp->right->right = NULL;
				temp->right->parent = temp;
				temp->right->color = 0;
				size++;
				check(temp);
			}
		}
	}
	void check(node* temp) {
		while (temp != root && !(temp->parent->color)) {
			if (temp->parent == temp->parent->parent->left) {
				node *y = temp->parent->parent->right;

				if (y!=NULL && !(y->color)) {
					temp->parent->color = 1;
					y->color = 1;
					temp->parent->parent->color = 0;
					temp = temp->parent->parent;
				}
				else{
					if (temp == temp->parent->right) {
						temp = temp->parent;
						Left(temp);
					}
					temp->parent->color = 1;
					temp->parent->parent->color = 0;
					Right(temp->parent->parent);
				}
			}
			else {
				node *y = temp->parent->parent->left;
				if (y!=NULL && !(y->color)) {
					temp->parent->color = 1;
					y->color = 1;
					temp->parent->parent->color = 0;
					temp = temp->parent->parent;
				}
				else {
					if (temp == temp->parent->left) {
						temp = temp->parent;
						Right(temp);
					}
					temp->parent->color = 1;
					temp->parent->parent->color = 0;
					Left(temp->parent->parent);
				}
			}
		}
		root->color = 1;
	}
	void swap(node* x, node* y) {
		if (x == y) return;
		int t;
		t=x->data;
		x->data = y->data;
		y->data = t;
	}
	void Right(node* x) {
		struct node *pivot = x->left;
		pivot->parent = x->parent;
		if (x->parent != NULL) {
			if (x->parent->left == x)
				x->parent->left = pivot;
			else
				x->parent->right = pivot;
		}
		else
			root = pivot;
		x->left = pivot->right;
		if (pivot->right != NULL)
			pivot->right->parent = x;

		x->parent = pivot;
		pivot->right = x;
	}
	void Left(node* x) {
		struct node *pivot = x->right;
		pivot->parent = x->parent; 
		if (x->parent != NULL) {
			if (x->parent->left == x)
				x->parent->left = pivot;
			else
				x->parent->right = pivot;
		}
		else
			root = pivot;
		x->right = pivot->left;
		if (pivot->left != NULL)
			pivot->left->parent = x;

		x->parent = pivot;
		pivot->left = x;
	}
	void aftercheck(node* x) {
		if (x->parent != root) {
			node* s = sibling(x);
			node* peak = x->parent;
			while (peak != root && peak->color)
			{
				if (s != NULL && !(s->color)) {
					if (s->parent->left == s) {
						node* a = x->parent;
						node* b = s;
						node* c = s->right;
						b->parent = a->parent;
						a->parent = b;
						a->left = c;
						b->right = a;
						c->parent = a;
					}
					else
					{
						node* a = x->parent;
						node* b = s;
						node* c = s->left;
						b->parent = a->parent;
						a->parent = b;
						a->right = c;
						b->left = a;
						c->parent = a;
					}
					x->parent->color = 0;
					x->parent->parent->color = 1;
					peak = peak->parent;
				}
				s = sibling(x);
				if (!(s->left->color || s->right->color)) {
					s->color = 0;
					x->parent->color = 1;
				}
				if (x->parent->left == x) {
					if (!(s->left->color)) {
						s->color = 0;
						s->left->color = 1;
						node* t = s->left;
						s->left = t->right;
						t->right = s;
						t->parent = s->parent;
						s->parent->right = s->left;
						s->parent = t;
					}
					else {
						s->color = s->parent->color;
						s->parent->color = 1;
						s->right->color = 1;
						if (x->parent->right == x) {
							node* a = x->parent;
							node* b = s;
							node* c = s->right;
							b->parent = a->parent;
							a->parent = b;
							a->left = c;
							b->right = a;
							c->parent = a;
						}
						else {
							node* a = x->parent;
							node* b = s;
							node* c = s->left;
							b->parent = a->parent;
							a->parent = b;
							a->right = c;
							b->left = a;
							c->parent = a;
						}
						peak = peak->parent;
					}
				}
			}
		}
		else{
			node * s = sibling(x);
			root->color = 0;
			s->color=1;
			root = s;
			s->parent = NULL;
			x->parent->parent = s;
			if (x->parent->left == x) {
				x->parent->right = s->left;
				s->left = x->parent;
			}
			else {
				s->right = x->parent;
				x->parent->left = s->right;
			}
		}
	}
    node* find(node* temp, int x) {
	if (temp==NULL) return NULL;
	while ((x > temp->data && temp->left != NULL) || (x < temp->data && temp->right != NULL)) {
		if (x < temp->data)
			temp = temp->right;
		if (x > temp->data)
			temp = temp->left;
	   }
	if (temp!=NULL && temp->data == x)
		return temp;
	else return NULL;
	}
	void eraser(node* e) {
		if(e!=NULL){
			if (e->left == NULL && e->right == NULL) {
				if (e->color && e != root) aftercheck(e);
				if (e != root) {
					if (e->parent->left == e)
						e->parent->left = NULL;
					else
						e->parent->right = NULL;
				}
				else root = NULL;
				size--;
				delete e;
			}
			else {
				if (e->left == NULL || right == NULL) {
					if (e->color && e != root) aftercheck(e);
					node* paste;
					if (e->left == NULL)
						paste = e->right;
					else
						paste = e->left;
					paste->parent = e->parent;
					if (e != root) {
						if (e->parent->left == e)
							e->parent->left = paste;
						else
							e->parent->right = paste;
					}
					else root = paste;
					size--;
					delete e;
				}
				else {
					node* temp = e;
					node* t = e->left;
					while (t->right != NULL) {
						t = t->right;
					}
					swap(temp, t);
					eraser(t);
				}
			}
		}
	}
	~RBt() {
		while (root != NULL)
			eraser(root);
	}
};
void swap(RBt a, RBt b);
RBt operator+(RBt a, RBt b);
RBt operator*(RBt a, RBt b);
bool included(int x, RBt a);
bool operator <(RBt a, RBt b);
bool operator > (RBt a, RBt b);
RBt operator -(RBt a, RBt b);
RBt operator % (RBt a, RBt b);
