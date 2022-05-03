//drill első része - vector

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

//lambda: név nélküli fv

struct Item {
	std::string name;
	int iid;
	double value;
};

std::ostream& operator<<(std::ostream& os, const Item& it){
	return os << it.name << '\t' << it.iid << '\t' << it.value;
}

std::istream& operator>>(std::istream& is, Item& it){
	std::string ss;
	int ii;
	double dd;
	is >> ss >> ii >> dd;
	Item itt {ss, ii, dd};
	it = itt;
	return is;
}

template<typename C>
void print(const C& c, char sep = '\n'){
	std::cout << "Container elements:\n";

	for(const auto elem : c){
		std::cout << elem << sep;
	}
	std::cout << std::endl;
}

class findbyname {
	std::string name;
public:
	findbyname(const std::string& n) : name{n} { }
	bool operator()(const Item& x) const {return x.name == name;}
};

class findbyiid {
	int iid;
public:
	findbyiid(int id) : iid{id} { }
	bool operator()(const Item& x) const {return x.iid == iid;}
};

int main(){
	try {
		
		// 1
		const std::string iname {"ten_int.txt"};
		std::ifstream ifs {iname};
		if(!ifs) throw std::runtime_error("Could not read file:" + iname);

		std::vector <Item> vi;
		for(Item ii; ifs >> ii;){
			vi.push_back(ii);
		}
		std::cout << "1. vi vector\n" << std::endl;
		print(vi);

		std::list<Item> li (vi.size());
		std::copy(vi.begin(), vi.end(), li.begin()); //vi elemei li-be

		// 2
		std::sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b) {return a.name < b.name;});
		std::cout << "2. Sorted by name\n" << std::endl;
		print(vi);

		// 3
		std::sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b) {return a.iid < b.iid;});
		std::cout << "3. Sorted by iid\n" << std::endl;
		print(vi);

		// 4
		std::sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b) {return a.value > b.value;});
		std::cout << "4. Sorted by value, decreasing order\n" << std::endl;
		print(vi);

		// 5
		Item h {"horse shoe", 99, 12.34};
		vi.insert(vi.end(), h);

		Item c {"Canon S400", 9988, 499.95};
		vi.insert(vi.end(), c);
		std::cout << "5. 2 Items added\n" << std::endl;
		print(vi);

		// 6
		vi.erase(std::find_if(vi.begin(), vi.end(), findbyname("alma")));
		vi.erase(std::find_if(vi.begin(), vi.end(), findbyname("áfonya")));
		std::cout << "6. 2 Items erased by name\n" << std::endl;
		print(vi);

		// 7
		vi.erase(std::find_if(vi.begin(), vi.end(), findbyiid(3)));
		vi.erase(std::find_if(vi.begin(), vi.end(), findbyiid(6)));
		std::cout << "7. 2 Items erased by iid\n" << std::endl;
		print(vi);

		// 8
		std::cout << "8.1 li list\n" << std::endl;
		print(li);

		li.sort([](const Item& a, const Item& b) {return a.name < b.name;});
		std::cout << "8.2 Sorted by name\n" << std::endl;
		print(li);

		li.sort([](const Item& a, const Item& b) {return a.iid < b.iid;});
		std::cout << "8.3. Sorted by iid\n" << std::endl;
		print(li);

		li.sort([](const Item& a, const Item& b) {return a.value > b.value;});
		std::cout << "8.4. Sorted by value, decreasing order\n" << std::endl;
		print(li);

		// lista
		Item g {"horse shoe", 99, 12.34};
		li.insert(li.end(), g);

		Item f {"Canon S400", 9988, 499.95};
		li.insert(li.end(), f);

		std::cout << "8.5. 2 Items added\n" << std::endl;
		print(li);

		li.erase(std::find_if(li.begin(), li.end(), findbyname("meggy")));
		li.erase(std::find_if(li.begin(), li.end(), findbyname("datolya")));
		std::cout << "8.6. 2 Items erased by name\n" << std::endl;
		print(li);

		li.erase(std::find_if(li.begin(), li.end(), findbyiid(4)));
		li.erase(std::find_if(li.begin(), li.end(), findbyiid(7)));
		std::cout << "8.7. 2 Items erased by iid\n" << std::endl;
		print(li);

	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	} catch (...) {
		std::cerr <<"Unknown exception\n";
		return 2;

	}
}
