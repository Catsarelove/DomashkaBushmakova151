#include <iostream>
#include <string>
using namespace std;
struct isbn {
	int a;
	int b;
	int c;
	int d;
};

struct book {
	isbn x;
	string writer;
	string name;
	void read() {
		cin >> writer;
		cin >> name;
		scanf_s("%d-%d-%d-%d", &x.a, &x.b, &x.c, &x.d);
	}
};
bool big(book one, book two) {
	if (one.x.a > two.x.a) return true;
	if (one.x.a < two.x.a) return false;
	if (one.x.b > two.x.b) return true;
	if (one.x.b < two.x.b) return false;
	if (one.x.c > two.x.c) return true;
	if (one.x.c < two.x.c) return false;
	if (one.x.d > two.x.d) return true;
	if (one.x.d < two.x.d) return false;
	return false;
}
bool eq(book one, book two) {
	if (one.x.a != two.x.a) return false;
	if (one.x.b != two.x.b) return false;
	if (one.x.c != two.x.c) return false;
	if (one.x.d != two.x.d) return false;
	return true;
}
struct vetka {
	book data;
	vetka* left;
	vetka* right;
	vetka* parent;
};
struct three {
	vetka* root;
	vetka * place;
	int sum;
	void push(book x) {
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
		book t;
		t = x->data;
		x->data = y->data;
		y->data = t;
	}
	bool find(book x, vetka* t) {
		bool v = false;
		if (eq(t->data, x)) v = true;
		if (t->right != NULL && (big(t->data, x))) v = find(x, t->right);
		if (t->left != NULL && (big(x, t->data))) v = find(x, t->left);
		return v;
	}
	void taba(vetka* temp, book x) {
		if (big(temp->data, x)) {
			if (temp->right != NULL)
				taba(temp->right, x);
			else {
				temp->right = new vetka;
				temp->right->right = NULL;
				temp->right->left = NULL;
				temp->right->parent = temp;
				temp->right->data = x;
				if (big(x, temp->data)) swap(temp, temp->right);
			}
		}
		if (big(x, temp->data)) {
			if (temp->left != NULL)
				taba(temp->left, x);
			else {
				temp->left = new vetka;
				temp->left->right = NULL;
				temp->left->left = NULL;
				temp->left->parent = temp;
				temp->left->data = x;
				if (big(temp->data, x)) swap(temp, temp->left);
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
			delete temp;
		}
		else
		{
			if (temp->left != NULL) del(temp->left);
			if (temp->right != NULL) del(temp->right);
		}
	}
	~three() {
		while (root != NULL)
			del(root);
	}
};
int main() {
	three t;
	t.sum = 0;
	t.root = NULL;
	int n;
	cin >> n;
	book x;
	for (int i = 0; i < n; i++) {
		x.read();
		t.push(x);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		x.read();
		if (t.find(x, t.root))
			cout << "found" << endl;
		else
			cout << "not found" << endl;
	}
	t.~three();
	system("pause");
	return 0;
}

