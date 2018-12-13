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