#include <thread>
#include <mutex>
#include <iostream>
#include <ctime>
using namespace std;
class NotValid{};
int f(int x, int y) { this_thread::sleep_for(15s); return x*y; }
template<typename T>
class Future{
	mutex m;
	unique_lock<mutex> lk;
	condition_variable cv;
	Future (const Future & f){}
public:                
	T * obj;
	bool* valid;
		Future operator = (const Future & fut){
		obj = fut.obj;
		fut.obj = NULL;
		valid = fut.valid;
		fut.valid = NULL;
	}
 	Future(): obj(NULL), valid(NULL){}
 	T get(){
 	    while(!(*valid))
 	    cv.wait(lk); 
 		return *obj;
 	}
    Future (Future && other): obj(NULL), valid(NULL){
    	obj = other.obj;
    	other.obj = NULL;	
    	valid = other.valid;
		other.valid = NULL;
    }
    ~Future(){
    	delete obj;
    	delete valid;
    }
};

template <typename Tres> 
class Packaged_task{
public:	
	bool* val;
	Tres* res = NULL;
	function<Tres(int, int)> fuu;
	Packaged_task(function<Tres(int, int)> f): fuu(f){ val = new bool; *val = false;}
	void operator()(int a, int b){
		*res = fuu(a,b);
		*val = true;
	}
	Future<Tres> get_future(){
		if(res == NULL){
			res = new Tres;
			Future<Tres> ftr;
			ftr.valid = val;
			ftr.obj = res;
			return ftr;
		}	
	}                                 
};

int main(){
	Packaged_task<int> task(f);
    Future<int> result = task.get_future();  
 
    thread task_td(move(task), 2, 10);
    task_td.join();
 
    cout << "task_thread:\t" << result.get() << '\n';      
	return 0;
}
