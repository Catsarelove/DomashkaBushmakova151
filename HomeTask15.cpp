#include <iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
struct stack{
	node* head; 

	void push (int new_data){
		node * temp = new node;
		temp->data=new_data;
		temp->next=head;
		head=temp;
	}
	int pop(){
		if(head==NULL){
			cout<<"OMG";
			return 0;
		}
		node* temp=head;
		head=head->next;
		int temp_data=temp->data;
		delete temp;
		return temp_data;
	}
	~stack(){
		while(head!=NULL){
			node* temp=head;
			head=head->next;
			delete temp;
		}
	}
	};
	int main(){
		stack sduk;
		sduk.head = NULL;
		sduk.push(33);
		sduk.push(77);
		sduk.push(1);
		cout<<sduk.pop()<<endl;
		cout<<sduk.pop()<<endl;
		cout<<sduk.pop()<<endl;
		sduk.~stack();
		system("pause");
		return 0;	
	}
