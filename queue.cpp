#include <iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
struct queue{
	node* tail;
	void push1 (int new_data){
		node * temp = tail;
		temp->next=new node;
		temp->next->data=new_data;
		temp->next->next=NULL;
	}
	void push (int new_data){
		node * temp = tail;
		do{
			temp=temp->next;
		} while(temp->next!=NULL);
		temp->next=new node;
		temp->next->data=new_data;
		temp->next->next=NULL;
	}
	int pop(){
		if(tail->next==NULL){
			cout<<"OMG";
			return 0;
		}
		node* temp = tail->next;
		int temp_data=tail->next->data;
		tail->next=temp->next;
		delete temp;
		return temp_data;	
	}
	~queue(){
		while(tail->next!=NULL){
			node* temp=tail->next;
			tail->next=tail->next->next;
			delete temp;
		}
	}
	};
	int main(){

		queue kuoe;
		kuoe.tail = new node;
		kuoe.push1(33);
		kuoe.push(2);
		kuoe.push(8);
		cout<<kuoe.pop()<<endl;
		cout<<kuoe.pop()<<endl;
		cout<<kuoe.pop()<<endl;
		kuoe.~queue();
		system("pause");
		return 0;	
	}