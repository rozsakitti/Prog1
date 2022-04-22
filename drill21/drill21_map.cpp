#include <iostream>
#include <string>
#include <map>
#include <numeric>
#include <stdexcept>
using namespace std;

template<typename T, typename C>
void print_map(const map<T, C>& m){ //pairek egy kollekciója a map
	for(auto& a : m){ // for(pair<T, C> a : m)
		cout << a.first << "\t" << a.second << endl; // nem fgv, csak sima tag(first, second)
	}
	cout << endl;
}

template<typename T, typename C>
void read_map(map<T, C>& m, int n){
	T key;
	C value;
	for (int i = 0; i < n; ++i)
	{
		cout << "Enter a key, value pair: ";
		cin >> key >> value;
		m.insert(pair<T, C>(key, value));
	}
}

int main() {
try{
	//map: rendez(kulcs, érték abc rendbe)
	map<string, int> msi; 
	msi["a"] = 1;
	msi["b"] = 2;
	msi["abc"] = 3;
	msi["x"] = 4;
	msi["ab"] = 5;
	msi["ac"] = 6;
	msi["ba"] = 7;
	msi["ca"] = 8;
	msi["bc"] = 9;
	msi["cb"] = 10;

	cout << "map elements: " << endl;
	print_map(msi);

	cout << "map elements after remove: " << endl;
	msi.erase("abc");
	print_map(msi);

	cout << "map elements after remove all elements: " << endl;
	msi.erase(msi.begin(), msi.end());
	print_map(msi);

	read_map(msi, 1);
	cout << "\nmap elements after reading: " << endl;
	print_map(msi);

	read_map(msi, 10);
	cout << "\nmap elements after reading: " << endl;
	print_map(msi);

	int map_sum = 0;
	for(auto& a : msi){
		map_sum += a.second;
	}
	cout << "msi sum: " << map_sum << endl;

	map<int, string> mis;

	for(auto& a : msi){
		mis.insert(pair<int, string>(a.second, a.first));
	}
	cout << "\nmis elements: " << endl;
	print_map(mis);

	} catch(exception& e){
		cerr<<"Exception " << e.what() << endl;
		return 1;

	} catch(...){
		cerr<<"Exception " << endl;
		return 2;
	}
}
