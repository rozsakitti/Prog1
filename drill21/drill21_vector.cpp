#include <iostream>
#include <stdexcept>
#include <vector>
#include <numeric>
#include <fstream>
#include <algorithm>
#include <list>
#include <iterator>
#include <string>
using namespace std;

struct Item
{
	string name;
	int iid;
	double value;

	Item(string n, int i, double v) : name{n}, iid{i}, value{v} {}
};

struct comp_name {
	bool operator()(const Item& a, const Item& b) const
	{
		return a.name < b.name;
	}
};

struct comp_id {
	bool operator()(const Item& a, const Item& b) const
	{
		return a.iid < b.iid;
	}
};

struct comp_value {
	bool operator()(const Item& a, const Item& b) const
	{
		return a.value > b.value;
	}
};

struct find_name {
	string name;
	find_name(string& n) : name{ n } {};
	bool operator()(const Item& a) const
	{
		return a.name == name;
	}
};

struct find_id {
	int id;
	find_id(int& n) : id{ n } {};
	bool operator()(const Item& a) const
	{
		return a.iid == id;
	}
};

void print_vector(vector<Item>& vec) {
	for (auto& a : vec)
	{
		cout << a.name << " " << a.iid << " " << a.value << endl;
	}
	cout << endl;
}

void print_list(list<Item>& li) {
	for (auto& a : li)
	{
		cout << a.name << " " << a.iid << " " << a.value << endl;
	}
	cout << endl;
}


int main() {
	try {
		vector<Item> vi;
		string file_name{ "ten_int.txt" };
		ifstream ifs{ file_name };
		if (!ifs)
			throw runtime_error("Could not read from file: " + file_name);

		while (!ifs.eof()) {
			string a;
			int b;
			double c;
			ifs >> a >> b >> c;
			vi.push_back({ a,b,c });
		}

		cout << "vi elements: " << endl;
		print_vector(vi);

		sort(vi.begin(), vi.end(), comp_name());
		cout << "Order By Name: " << endl;
		print_vector(vi);

		sort(vi.begin(), vi.end(), comp_id());
		cout << "Order By ID: " << endl;
		print_vector(vi);

		sort(vi.begin(), vi.end(), comp_value());
		cout << "Order By Value: " << endl;
		print_vector(vi);

	/*	Item h("horse shoe", 99, 12.34);
		Item c("Canon S400", 9988, 499.95);*/

		vi.push_back({ "horse shoe", 99, 12.34 });
		vi.push_back({ "Canon S400", 9988, 499.95 });

		string ee = "horse shoe";
		string re = "r";
		for (int i = 0; i < vi.size(); i++)
		{
			if (vi[i].name == ee)
			{
				vi.erase(vi.begin() + i);
			}
			else if (vi[i].name == re)
			{
				vi.erase(vi.begin() + i);
			}
		}
		
		cout << "After remove by name: " << endl;
		print_vector(vi);

		int e1 = 1;
		int e2 = 2;
		for (int i = 0; i < vi.size(); i++)
		{
			if (vi[i].iid == e1)
			{
				vi.erase(vi.begin() + i);
			}
			else if (vi[i].iid == e2)
			{
				vi.erase(vi.begin() + i);
			}
		}

		cout << "\nAfter remove by ID: " << endl;
		print_vector(vi);


		list<Item> li;
		string file_name2{ "ten_int.txt" };
		ifstream ifs2{ file_name2 };
		while (!ifs2.eof()) {
			string a;
			int b;
			double c;
			ifs2 >> a >> b >> c;
			li.push_back({ a,b,c });
		}

		cout << "\nli elements: " << endl;
		print_list(li);
		
		li.sort(comp_name());
		cout << "Order By Name: " << endl;
		print_list(li);
		
		li.sort(comp_id());
		cout << "Order By ID: " << endl;
		print_list(li);

		li.sort(comp_value());
		cout << "Order By Value: " << endl;
		print_list(li);

		/*	Item h("horse shoe", 99, 12.34);
			Item c("Canon S400", 9988, 499.95);*/

		li.push_back({ "horse shoe", 99, 12.34 });
		li.push_back({ "Canon S400", 9988, 499.95 });

		ee = "horse shoe";
		re = "r";

		list<Item>::iterator lit = find_if(li.begin(), li.end(), find_name(ee));
		li.erase(lit);
		lit = find_if(li.begin(), li.end(), find_name(re));
		li.erase(lit);
		
		cout << "After remove by name: " << endl;
		print_list(li);

		e1 = 1;
		e2 = 2;
		lit = find_if(li.begin(), li.end(), find_id(e1));
		li.erase(lit);
		lit = find_if(li.begin(), li.end(), find_id(e2));
		li.erase(lit);

		cout << "\nAfter remove by ID: " << endl;
		print_list(li);
	}

	catch (exception& e) {
		cerr << "Exception: " << e.what() << endl;
		return 1;
	}
	catch (...) {
		cerr << "Error:" << endl;
		return 2;
	}
}
