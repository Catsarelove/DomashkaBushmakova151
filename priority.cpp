#include <iostream>
using namespace std;
struct node{
	int data;
	node* next;
	int pr;
};
struct queue{
	node* tail;
	void push (int new_data, int prio){
		node * temp = new node;
		temp->data=new_data;
		temp->pr=prio;
		node * paste = tail;
		if(tail!= NULL){
		while(tail->next!=NULL)
			tail=tail->next;
			tail->next=temp;
			tail=paste;
		}
		else 
			tail=temp;
		    temp->next=NULL;

	}
	int pop(){
		if(tail==NULL){
			cout<<"OMG";
			return 0;
		}
		node* del;
		int new_data;
		node* temp = min();
		new_data=temp->next->data;
		del = temp->next;
		if(del==tail)
			{
				if(tail->next!=NULL)
				tail=tail->next;
				else tail=NULL;
			}
        else 
		{
			if(del!=NULL)temp->next=del->next;
			else temp->next=NULL;
		}
		delete del;
		return new_data;
	}
	node* min(){
		node* min= new node;
		min->next=tail;
		node* temp=tail;
		while(temp->next!=NULL)
		{
			if(min->next->pr>temp->next->pr) min=temp;
			temp=temp->next;
		}
		return min;
	}
	~queue(){
		while(tail!=NULL){
			node* temp=tail;
			tail=tail->next;
			delete temp;
		}
	}
	};
	int main(){

		queue kuoe;
		kuoe.tail = NULL;
		kuoe.push(33,2);
		kuoe.push(8,3);
		kuoe.push(2,1);
		kuoe.push(55,2);
		kuoe.push(8,3);
		cout<<kuoe.pop()<<endl;
		cout<<kuoe.pop()<<endl;
		cout<<kuoe.pop()<<endl;
		cout<<kuoe.pop()<<endl;
		cout<<kuoe.pop()<<endl;
		kuoe.~queue();
		system("pause");
		return 0;	
	}