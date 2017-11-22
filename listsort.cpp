#include <iostream>
#include <iomanip>
using namespace std;
struct node{
	int data;
	node* next;
	node* prev;
};
struct list{
	node* head;
	node* tail;
	void push(int x){
	node* temp = new node;
	temp->data=x;
	temp->next=head;
	if(head!= NULL)
	head->prev=temp;
	temp->prev=NULL;
	if (head == NULL)
		tail=temp;
	head=temp;
	}
	int pop(){
		if(tail==NULL) {cout<<"wrong"; return 0;}
		int x=tail->data;
		node* temp=tail;
		if(tail!=NULL)
		tail=tail->prev;
		delete temp;
		return x;
	}
	node* insert(node* paste, node* place)
	{
		node* temp=new node;
		temp->data=paste->data;
		if(place->prev!=NULL)
		place->prev->next=temp;
		temp->next=place;
		temp->prev=place->prev;
		place->prev=temp;
		if (temp->prev == NULL) head=temp;
		paste->prev->next=paste->next;
		if(paste!=tail)
		paste->next->prev=paste->prev;
		else tail=paste->prev;
		delete paste;
		return temp;
	}
	~list(){
		while(tail!=NULL){
			node* temp=tail;
			tail=tail->prev;
			delete temp;
		}
	}
	void read(int n){
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		push(x);
	}
	}
	void write(int n){
		for(int i=0; i<n; i++)
	cout<<pop()<<' ';
	}
	node* minimum(node* temp)
	{
		node* min=temp;
		temp=temp->next;
		while(temp!=NULL){
			if(min->data > temp->data) min=temp;
			temp=temp->next;
		}
		return min;
	}
};
void exchange(node* change, list & l){
	if(change!=l.tail){
		node* temp;
		node* min=l.minimum(change);
		if(min!=change)
		temp=l.insert(min,change);
		else temp=change;
		exchange(temp->next, l);
	}
}
int main(){
	list leezd;
	int n; 
	cin>>n;
	leezd.head=NULL;
	leezd.tail=NULL;
	leezd.read(n);
	node* change=leezd.head;
	exchange(change, leezd);
    leezd.write(n);
	system("pause");
	leezd.~list();
	return 0;
}