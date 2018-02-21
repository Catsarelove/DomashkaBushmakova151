#include <iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
struct dequeue {
	node* tail;
	node* head;
	void pushback(int new_data) {
		node * temp = new node;
		temp->data = new_data;
		node * paste = tail;
		if (tail != NULL) {
			tail = temp;
			paste->next = tail;
		}
		else {
			tail = temp;
			head = temp;
		}
		temp->next = NULL;
	}
	void pushforw(int new_data) {
		node * temp = new node;
		temp->data = new_data;
		node * paste = head;
		if (head != NULL) {
			head = temp;
			head->next = paste;
		}
		else {
			head = temp;
			tail = temp;
			head->next = NULL;
		}
	}
	int pop() {
		if (head == NULL) {
			cout << "OMG";
			return 0;
		}
		int temp_data = head->data;
		node* temp = head;
		head = head->next;
		delete[] temp;
		return temp_data;
	}
	~dequeue() {
		while (head != NULL) {
			node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};
void createarray(int* a, int n);
void f();
