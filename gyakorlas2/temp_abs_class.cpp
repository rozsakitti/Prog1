#include <iostream>

using namespace std;

template<typename T>
class A {
	public:
		virtual T sum(T a, T b) = 0;	
};

template<typename T>
class B : public A<T> {
	public :
		T sum(T a, T b) { return a+b;};
};

int main(){
	B<int> b;
	cout << b.sum(3,5) << endl;
	return 0;
}
