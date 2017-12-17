#include <iostream>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;
	node* parent;

};
void svap(node* a, node* b) {
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}
struct heap {
	node* root;
	void push(int* a, int n){
		root = new node;
		root->data = a[0];
		root->parent = NULL;
		node* temp = root;
		createheap(0, temp, a, n);
	}
	void heapify(node* x) {
		node* temp = x;
		while (temp->parent != NULL && temp->parent->data < temp->data ) {
			svap(temp, temp->parent);
			temp = temp->parent;
		}
	}
	void createheap(int i, node* temp, int* a, int n) {
		if ((2 * i + 1) < n) {
			temp->right = new node;
			temp->right->parent = temp;
			temp->right->data = a[2 * i + 1];
			if (temp->right->data > temp->data) {
				heapify(temp->right);
			}
			createheap(2 * i + 1, temp->right, a, n);
		}
		else temp->right = NULL;
		if ((2 * i + 2) < n) {
			temp->left = new node;
			temp->left->data = a[2 * i + 2];
		    temp->left->parent = temp;
			if (temp->left->data > temp->data) {
				heapify(temp->left);
			}
			createheap(2 * i + 2, temp->left, a, n);
		}
		else temp->left = NULL;
	}
	int getel() {
		int x = root->data;
		node* temp = root;
		node* t;
		if (root->left!=NULL && (root->right==NULL || root->left->data > root->right->data))
			t = root->left;
		else
			t = root->right;
		while (t!= NULL) {
			svap(temp, t);
			temp = t;
			if (t->right == NULL && t->left == NULL)
				t = NULL;
			else {
				if (t->right != NULL && t->left != NULL)
				{
					if (t->right->data > t->left->data)
						t = t->right;
					else t = t->left;
				}
				else {
					if (t->right != NULL)
						t = t->right;
					else
						t = t->left;
				}
			}
		}
		erase(temp);
		return x;
	}
	void heapsort(int * a, int n) {
		for (int i = 0; i < n; i++)
			a[i] = getel();
	}
	void erase(node* e) {
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
				node* paste;
				if (e->left == NULL)
					paste = e->left;
				else
					paste = e->right;
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
				node* temp = e;
				do {
					if(temp->left!=NULL)
					svap(temp, temp->left);
					temp = temp->left;
				} while (temp->left != NULL);
				erase(temp);
			}
		}
	}
	~heap() {
		while (root != NULL)
			erase(root);
	}
};
int main() {
	int* a;
	int n;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	heap heapo;
	heapo.push(a, n);
	heapo.heapsort(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] <<"  ";
	system("pause");
	return 0;
}