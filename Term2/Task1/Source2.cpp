#include <iostream>
#include "Header1.h"
void f() {
	int * a;
	int n;
        cout<<"pls write de number of numbers"<<endl;
	cin>>n;
	cout<<"danks"<<endl;
	a = new int[n];
	dequeue kuoe;
	createarray(a, n);
	kuoe.tail = NULL;
	kuoe.head = NULL;
	for (int i = 0; i < n; i+=2) {
		kuoe.pushforw(a[i]);
		if (i < (n - 1))
			kuoe.pushback(a[i + 1]);
	}
	for(int i=0; i<n; i++)
	cout << kuoe.pop() << endl;
}
