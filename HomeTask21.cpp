#include <iostream>
using namespace std;

struct vetka {
	int data;
	vetka* left;
	vetka* right;
	vetka* parent;
};
struct three {
	vetka* root;
	vetka * place;
	int sum = 0;
	void push(int x) {
		sum += x;
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
				if (temp->data < x) svap(temp, temp->right);
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
				if (temp->data > x) svap(temp, temp->left);
			}
		}

	}
	void svap(vetka * x, vetka* y) {
		int t;
		t = x->data;
		x->data = y->data;
		y->data = t;
	}
	vetka* find(int x, vetka* t) {
		vetka* f = NULL;
		if (t->data == x) f = t;
		if (t->right != NULL && t->data > x) f = find(x, t->right);
		if (t->left != NULL && t->data < x) f = find(x, t->left);
		return f;
	}
	void erase(vetka* e) {
		sum -= e->data;
		if (e->left == NULL && e->right == NULL) {
			if (e != root) {
				if (e->parent->left == e)
					e->parent->left = NULL;
				else
					e->parent->right = NULL;
			}
			else root = NULL;
			delete e;
		}
		else {
			if (e->left == NULL || right == NULL) {
				vetka* paste;
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
				delete e;
			}
			else {
				vetka* temp = e;
				vetka* t=e->left;
				while (t->right != NULL) {
						t = t->right;
				     }
				svap(temp, t);
				sum += t->data;
				erase(t);
			}
		}
	}
	~three() {
		while (root != NULL)
			erase(root);
	}

};
int main() {
	three t;
	t.root = NULL;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		t.push(x);
	}
	cout << t.sum;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		vetka* f = t.find(x, t.root);
		if (f != NULL) {
			cout << "found";
			t.erase(f);
		}
		else
			cout << "not found";
	}
	cout << t.sum;
	system("pause");
	return 0;
}
