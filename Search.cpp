#include <iostream>
using namespace std;

struct vetka {
	int data;
	vetka* left;
	vetka* right;
	vetka* parent;
};
struct tree {
	vetka* root;
	vetka * place;
	void push(int x) {
		if (root == NULL) {
			root = new vetka;
			root->data = x;
			root->left = NULL;
			root->right = NULL;
			root->parent = NULL;
			place = root;
		}
		else taba(root, x);
	}
	void swap(vetka * x, vetka* y) {
		int t;
		t = x->data;
		x->data = y->data;
		y->data = t;
	}
	bool find(int x, vetka* t) {
		bool b=false;
		if (t->data == x) b = true;
		if (t->right != NULL && t->data > x) b = find(x, t->right);
		if (t->left != NULL && t->data < x) b = find(x, t->left);
		return b;
	}
	void taba(vetka* temp, int x) {
		if (temp->data > x) {
			if (temp->right != NULL)
				taba(temp->right, x);
			else {
				temp->right = new vetka;
				temp->right->right = NULL;
				temp->right->left = NULL;
				temp->right->parent = temp;
				temp->right->data = x;
				if (temp->data < x) swap(temp, temp->right);
			}
		}
		if (temp->data < x) {
			if (temp->left != NULL)
				taba(temp->left, x);
			else {
				temp->left = new vetka;
				temp->left->right = NULL;
				temp->left->left = NULL;
				temp->left->parent = temp;
				temp->left->data = x;
				if (temp->data > x) swap(temp, temp->left);
			}
		}
		
	}
	void del(vetka* temp) {
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
	~tree() {
		while (root != NULL)
			del(root);
	}

};
int main() {
	tree t;
	t.root = NULL;
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		t.push(x);
	}
	cin >> x;
	if (t.find(x, t.root))
		cout << "found";
	else
		cout << "not found";
	system("pause");
	return 0;
}
