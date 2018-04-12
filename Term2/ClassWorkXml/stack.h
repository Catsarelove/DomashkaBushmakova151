#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct n {
	T data;
	n* next;
};
template <typename T>
struct stack {
	n<T>* head = NULL;
	void push(T new_data) {
		n<T> * temp = new n<T>;
		temp->data = new_data;
		temp->next = head;
		head = temp;
	}
	T pop() {
		n<T>* temp = head;
		head = head->next;
		T temp_data = temp->data;
		delete temp;
		return temp_data;
	}
	stack() {
		head = NULL;
	}
	stack(const stack &a) {
		n<T>* temp = a.head;
		while (temp != NULL) {
			push(temp->data);
			temp = temp->next;
		}
	}
	~stack() {
		while (head != NULL) {
			n<T>* temp = head;
			head = head->next;
			delete temp;
		}
	}
};
