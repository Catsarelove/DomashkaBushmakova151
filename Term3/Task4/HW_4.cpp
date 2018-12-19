#include <thread>
#include <iostream>
#include <stdio.h>
#include <chrono>  
using namespace std;
void foo(int & a, int & b){
	int c;	
	for(int i = 0; i <= 3; i++){
		c = a;
		this_thread::sleep_for(chrono::seconds(rand()%4));
		a = b;
		b = c;
	}
}     
int main(){
    int a = 66;
    int b = 77;
	thread t1(foo, ref(a),ref(b));
	thread t2(foo, ref(a),ref(b));
	t1.join();
	t2.join();
	printf("a = %d, b = %d\n", a, b);
	printf("The right answer is a = 66, b = 77\n");
	return 0;
}