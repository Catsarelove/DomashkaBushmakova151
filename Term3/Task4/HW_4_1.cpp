#include <thread>
#include <iostream>
#include <stdio.h>
#include <mutex>
using namespace std;
mutex m;
void Sort(int* arr, int n) 
{
  if(n > 1){
    int size = n;
    for(int i = 1; i < size; ++i){
      int j = i - 1;
      m.lock();
      int key = arr[i];
      while(j >= 0 && arr[j] > key){
        arr[j+1] = arr[j];
        --j;
      }
      arr[j+1] = key;
      m.unlock();
    }
  }
}  
int main(){
	int* a;
	int n = 12000;
	a = new int[n];
	for(int i = 0; i< n; i++)
		a[i] = rand()%200 - 100;
	thread t1(Sort, a, n);
	thread t2(Sort, a, n);
	t1.join();
	t2.join();
	bool flag = true;
	for(int i = 0; i< (n - 1) && flag; i++){
		if(a[i]>a[i+1]){
			cout << "AAAA";
			flag = false;
		}
	}
	delete [] a;
	return 0;
}
