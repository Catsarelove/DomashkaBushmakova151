#include <iostream>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
	node* parent;
	int diff;

};
struct avl {
	node* root;
	void push(int x) {
		if (root == NULL) {
			root = new node;
			root->data = x;
			root->left = NULL;
			root->right = NULL;
			root->parent = NULL;
			root->diff = 0;
		}
		else taba(root, x);

	}
	void svap(node * x, node* y) {
		int t;
		t = x->data;
		x->data = y->data;
		y->data = t;
	}
	bool find(int x, node* t) {
		bool b = false;
		if (t->data == x) b = true;
		if (t->right != NULL && t->data > x) b = find(x, t->right);
		if (t->left != NULL && t->data < x) b = find(x, t->left);
		return b;
	}
	void taba(node* temp, int x) {
		if (temp->data > x) {
			if (temp->right != NULL)
				taba(temp->right, x);
			else {
				temp->right = new node;
				temp->right->right = NULL;
				temp->right->left = NULL;
				temp->right->parent = temp;
				temp->right->data = x;
				temp->right->diff = 0;
				if (temp->data < x) svap(temp, temp->right);
				temp->diff++;
				if (temp->diff == 1 && temp != root) {
					if (temp->parent->left == temp)
						hl(temp->parent);
					else
						hr(temp->parent);
				}
			}
		}
		if (temp->data < x) {
			if (temp->left != NULL)
				taba(temp->left, x);
			else {
				temp->left = new node;
				temp->left->right = NULL;
				temp->left->left = NULL;
				temp->left->parent = temp;
				temp->left->data = x;
				temp->left->diff = 0;
				if (temp->data > x) svap(temp, temp->left);
				temp->diff--;
				if (temp->diff == -1 && temp != root) {
					if (temp->parent->left == temp)
						hl(temp->parent);
					else
						hr(temp->parent);
				}
			}
		}
	}
	void hl(node* temp) {
		node* new_key = temp;
		if (temp->diff == -1) {
			if (temp->left->diff <= 0) {
				if (temp->left->diff == -1)
				{
					temp->diff = 0;
					temp->left->diff = 0;
				}
				else {
					temp->diff = -1;
					temp->left->diff = 1;
				}
				new_key = temp->left;
				smr(temp);
			}
			else {
				if (temp->left->right->diff == 1) {
					temp->diff = 0;
					temp->left->diff = -1;
					temp->left->right->diff = 0;
				}
				if (temp->left->right->diff == -1) {
					temp->diff = 1;
					temp->left->diff = 0;
					temp->left->right->diff = 0;
				}
				if (temp->left->right->diff == 0) {
					temp->diff = 0;
					temp->left->diff = 0;
					temp->left->right->diff = 0;
				}
				new_key = temp->left->right;
				br(temp);
			}
		}
		new_key->diff--;
		if (new_key->diff == -1 && new_key != root) {
			if (new_key->parent->left == new_key)
				hl(new_key->parent);
			else
				hr(new_key->parent);
		}
	}
	void hr(node* temp) {
		node* new_key = temp;
		if (temp->diff == 1) {
			if (temp->right->diff >= 0) {
				if (temp->right->diff == 1)
				{
					temp->diff = 0;
					temp->right->diff = 0;
				}
				else {
					temp->diff = 1;
					temp->right->diff = -1;
				}
				new_key = temp->right;
				sml(temp);
			}
			else {
				if (temp->right->left->diff == -1) {
					temp->diff = 0;
					temp->right->diff = 1;
					temp->right->left->diff = 0;
				}
				if (temp->right->left->diff == 1) {
					temp->diff = -1;
					temp->right->diff = 0;
					temp->right->left->diff = 0;
				}
				if (temp->right->left->diff == 0) {
					temp->diff = 0;
					temp->right->diff = 0;
					temp->right->left->diff = 0;
				}
				new_key = temp->right->left;
				bl(temp);
			}
		}
		new_key->diff++;
		if (new_key->diff == 1 && new_key != root) {
			if (new_key->parent->left == new_key)
				hl(new_key->parent);
			else
				hr(new_key->parent);
		}
	}
	void sml(node* temp) {
		node* a = temp;
		node* b = temp->right;
		a->right = b->left;
		if (b->left != NULL)
			b->left->parent = a;
		b->left = a;
		b->parent = a->parent;
		if (a != root) {
			if (a->parent->left == a)
				a->parent->left = b;
			else
				a->parent->right = b;
		}
		else root = b;
		a->parent = b;
	}
	void smr(node* temp) {
		node* a = temp;
		node* b = temp->left;
		a->left = b->right;
		if (b->right != NULL)
			b->right->parent = a;
		b->right = a;
		b->parent = a->parent;
		if (a != root) {
			if (a->parent->left == a)
				a->parent->left = b;
			else
				a->parent->right = b;
		}
		else root = b;
		a->parent = b;
	}
	void bl(node* temp) {
		node* a = temp;
		node* b = a->right;
		node* c = b->left;
		a->right = c->left;
		b->left = c->right;
		if (c->left != NULL)
			c->left->parent = a;
		if (c->right != NULL)
			c->right->parent = b;
		c->left = a;
		c->parent = a->parent;
		a->parent = c;
		b->parent = c;
		c->right = b;
		if (root != a) {
			if (c->parent->left == a)
				c->parent->left = c;
			else c->parent->right = c;
		}
		else root = c;

	}
	void br(node* temp) {
		node* a = temp;
		node* b = a->left;
		node* c = b->right;
		a->left = c->right;
		b->right = c->left;
		if (c->right != NULL) c->right->parent = a;
		if (c->left != NULL) c->left->parent = b;
		c->right = a;
		c->parent = a->parent;
		a->parent = c;
		b->parent = c;
		c->left = b;
		if (root != a) {
			if (c->parent->left == a)
				c->parent->left = c;
			else c->parent->right = c;
		}
		else
			root = c;
	}
	void del(node* temp) {
		if (temp->left == NULL && temp->right == NULL && temp != NULL) {
			if (temp != root) {
				if (temp->parent->left == temp)
					temp->parent->left = NULL;
				else
					temp->parent->right = NULL;
			}
			else root = NULL;
			delete[] temp;
		}
		else
		{
			if (temp->left != NULL) del(temp->left);
			if (temp->right != NULL) del(temp->right);
		}
	}
	~avl() {
		while (root != NULL)
			del(root);
	}

};
int main() {
	avl t;
	t.root = NULL;
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		t.push(x);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (t.find(x, t.root))
			cout << "found"<<endl;
		else
			cout << "not found"<< endl;
	}
	system("pause");
	return 0;
}
