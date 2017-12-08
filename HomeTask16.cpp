#include <iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
struct queue {
	node* tail;
	void push(int new_data) {
		node * temp = new node;
		temp->data = new_data;
		node * paste = tail;
		if (tail != NULL) {
			while (tail->next != NULL)
				tail = tail->next;
			tail->next = temp;
			tail = paste;
		}
		else
			tail = temp;
		temp->next = NULL;

	}
	int pop() {
		if (tail == NULL) {
			cout << "OMG";
			return 0;
		}
		node* temp = tail;
		int temp_data = temp->data;
		tail = temp->next;
		delete temp;
		return temp_data;
	}
	~queue() {
		while (tail != NULL) {
			node* temp = tail;
			tail = tail->next;
			delete temp;
		}
	}
};
int main() {

	queue kuoe;
	kuoe.tail = NULL;
	kuoe.push(33);
	kuoe.push(2);
	kuoe.push(8);
	cout << kuoe.pop() << endl;
	cout << kuoe.pop() << endl;
	cout << kuoe.pop() << endl;
	kuoe.~queue();
	system("pause");
	return 0;
}
