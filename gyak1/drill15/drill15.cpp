#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Person {
public:
	Person(){}
	Person(string f, string l,int a) : f{f},l{l},a{a}{ //string f --> {} | osztály metódusa, mely példányosításkor hívódik meg

		if(a < 0 || a >=150) {
			throw runtime_error("Invalid age");
		}

		string n = f + l;

		char bad_characters [] = {';',':','"','\'','[',']','*','&','^','%','$','#','@','!'};

		for (int i = 0; i < n.length(); i++){
			for(int j = 0; j < 14; j++){
				if (n[i] == bad_characters[j])
					throw runtime_error("Invalid name");
			}
		}
	};

	string first() const {return f;} //beolvas
	string last() const {return l;}
	int age() const {return a;}

private:
	string f;
	string l;
	int a;
};

ostream& operator<<(ostream& os,const Person& p){
	return os << p.first() << " " << p.last() << " " << p.age();                  
}

istream& operator>>(istream& is, Person& p){
	string f;
	string l;
	int a;

	is >> f >> l >> a;
	p = Person(f,l,a); 

	return is;
}

int main()
{
	Person p;
	p = Person("Goofy","Dog", 63);

	cout << p.first() << " " << p.last() << " " << p.age() << endl;
	cout << p << endl;

	Person p2;

	cin >> p2;
	cout << p2 << endl;

	vector<Person> vec;

	for(Person p; cin >> p;){ 
		if(p.first() == "end") break;
		vec.push_back(p);
	}

	for(Person p: vec)
		cout << p << endl;


}
