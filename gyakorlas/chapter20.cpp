#include <vector>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <array>
#include <string>
using namespace std;

template<typename T>
void increase(T& inc, int n){ // --> int n mennyivel nőjjön
	for(int& a : inc){ //végig megyünk a konténeren auto referenciával --> & kell, ha módosulna ez is módosuljon
		a+=n;
	}
}

template<typename T>
void print(T& p){
	for(int& a : p){
		cout << a << " ";
	}
	cout << endl;
}

template<typename Iter1, typename Iter2> 
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2){ //vektor eleje | vege| ahova masolunk annak az eleje,ide masol
	while(f1!=e1){
		*f2=*f1; // *(érték-'acces')
		f1++; //++: következő elemre mutat
		f2++;
	}
	return f2;
}
bool predicate(int n) {
   return (n %10 == 0);
}

int main(){
	constexpr int size = 10;
	int ar[size];
	array<int, size> arr;
	vector<int> vec;
	list<int> ls;

	for (int i = 0; i < 10; ++i)
	{
		ar[i] = i;
		arr[i] = i;
		vec.push_back(i);
		ls.push_back(i);
	}
	cout << "Ar elements: ";
	for(auto& a : ar){
		cout << a << " ";
	}
	cout << endl;

	cout << "Array elements: ";
	for(auto& a : arr){
		cout << a << " ";
	}
	cout << endl;

	cout << "Vector elements: "; //memóriában sorban
	for(auto& a : vec){
		cout << a << " ";
	}
	cout << endl;

	cout << "List elements: "; //memóriában bárhol
	for(auto& a : ls){
		cout << a << " ";
	}
	cout << endl << endl;
	
	

	array<int, size> arr2 = arr;
	vector<int> vec2 = vec;
	list<int> ls2 = ls;

	cout << "Array2 elements: ";
	for(auto& a : arr2){
		cout << a << " ";
	}
	cout << endl;

	cout << "Vector2 elements: ";
	for(auto& a : vec2){
		cout << a << " ";
	}
	cout << endl;

	cout << "List2 elements: ";
	for(auto& a : ls2){
		cout << a << " ";
	}
	cout << endl << endl;
	
	

	increase(arr2, 2);
	increase(vec2, 3);
	increase(ls2, 5);

	cout << "Array2(inc): ";
	print(arr2);
	cout << "Vector2(inc): ";
	print(vec2);
	cout << "List2(inc): ";
	print(ls2);
	cout << endl;

	my_copy(arr2.begin(), arr2.end(), vec2.begin()); //Mit meddig hova
	my_copy(ls2.begin(), ls2.end(), arr2.begin());

	cout << "Array2 after copy: ";
	print(arr2);
	cout << "Vector2 after copy: ";
	print(vec2);
	cout << "List2 after copy: ";
	print(ls2);
	cout << endl;

	vector<int>::iterator vit; //vector<int> tipusu iterator -->like a pointer that points to an element inside the container
	vit = find(vec2.begin(), vec2.end(), 3); //visszaadja hogy hanyadik helyen van 
	cout << "Is the vector contain the 3?\n";

	if(vit != vec2.end()){
		cout << "Found at: " << distance(vec2.begin(), vit) << endl << endl; //DISTANCE: MILYEN MESSZE VAN AZ ELEJETOL A VIT-IG
	}

	else{
		cout<< "Not found" << endl << endl;
	}	
	
	cout << "Is the List contain the 27?\n";
	list<int>::iterator lit;
	lit = find(ls2.begin(), ls2.end(), 27);
		
	if(lit != ls2.end()){
		cout << "Found at: " << distance(ls2.begin(), lit) << endl << endl;
	}
	else{
		cout << "Not found" << endl << endl;
	}
	    auto it = copy_if (ai2.begin(), ai2.end(), vi2.begin(), predicate);
}
