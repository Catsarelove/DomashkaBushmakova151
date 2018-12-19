#include <mutex>
#include <stdio.h>
class LockedErr{};
template <typename T>
class A {
	std::mutex m;
	T data;
public:
	A(){}
	A operator =(const T & x){
		if(!is_lock_free) throw LockedErr();
		m.lock();
		data = x;
		m.unlock();	
		return *this;
	}
	bool is_lock_free(){
		return m.try_lock();
	}
	T load(){
		if(!is_lock_free()) throw LockedErr();
		m.lock();
		T x = data;
		m.unlock();
		return x; 
	} 
	void store( const T & x){
		if(!is_lock_free()) throw LockedErr();
		m.lock();
		data = x;
		m.unlock(); 
	}
	operator T() const{
		return data;
	}
private:
	A(const A & a){}
	A(const A && a){}
};
int main() {
	A<int> a;
	a = 189;
	int b = a/10;
	printf("%d", b);
	return 0;
}         
#include <mutex>
#include<thread>
#include <algorithm>
#include <stdio.h>
#include <chrono>
#include <vector>

using namespace std;
class LockedErr{};

template <typename T>
class A {
	std::mutex m;
	T data;
public:
	A(){}
	A operator =(const T & x){
		m.lock();
		data = x;
		m.unlock();	
		return *this;
	}
	A operator =(const A & x){
		m.lock();
		data = x.data;
		m.unlock();	
		return *this;
	}
	T load(){
		m.lock();
		T x = data;
		m.unlock();
		return x; 
	} 
	void store( const T & x){
		m.lock();
		data = x;
		m.unlock(); 
	}
	operator T() const{
		return data;
	}
private:
	A(const A & a){}
	A(const A && a){}
};
void foo(int * b){
	sort(b, b+n);
}

void Sort(A* array, int n)
{
  if(n > 1){
    int size = n;
    for(int i = 1; i < size; ++i){
      int j = i - 1;
      A key = array[i];
      while(j >= 0 && array[j] > key){
        array[j+1] = array[j];
        --j;
      }
      array[j+1] = key;
    }
  }
}


int main()
{
    A* a;
    int n = 12000;
    a = new A[n];
    for(int i = 0; i < n; i++)
        a[i] = rand()%100 - 100;
    thread t1(Sort, a, n);
    thread t2(Sort, a, n);
    t1.join();
    t2.join();
    bool check = true;
    for(int i = 0; i< (n - 1) && check; i++){
        if(a[i]>a[i+1]){
            cout << "AAAAA";
            check = false;
        }
    }
    delete [] a;
    return 0;
}         
