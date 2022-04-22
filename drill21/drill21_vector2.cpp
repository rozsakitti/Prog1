#include <iostream>
#include <stdexcept>
#include <vector>
#include <numeric>
#include <fstream>
#include <algorithm>
using namespace std;

template<typename T>
void print(vector<T> v){
	for(auto& a : v){
		cout << a << endl;
	}
	cout << endl;
}

int main(){
try{
	vector<double> vd;
	string file_name{"input_floats.txt"};
	ifstream ifs{file_name};
	if(!ifs)
		throw runtime_error("Could not read from file: "+ file_name);
	while (!ifs.eof()){
		double d;
		ifs >> d;
		vd.push_back(d);
	}

	cout << "vd elements: " << endl;
	print(vd);

	vector<int> vi(vd.size());
	// copy(vd.begin(), vd.end(), vi.begin());
	for (int i = 0; i < vd.size(); ++i)
	{
		vi[i] = vd[i];
	}
	cout << "vi elements: " << endl;
	print(vi);

	cout << "vd -> vi elements: " << endl;
	for (int i = 0; i < vd.size(); ++i)
	{
		cout << vd[i] << " -> " << vi[i] << endl;
	}

	double sum_vd = 0;
	for(double& a : vd){
		sum_vd += a;
	}
	cout << "\nSum of vd: " << sum_vd << endl;

	double sum_vi = 0;
	for(int& a : vi){
		sum_vi += a;
	}
	cout << "Sum of vi: " << sum_vi << endl;
	double diff_vdi = sum_vd - sum_vi;
	cout << "Diff of vd - vi: " << diff_vdi << endl;

	cout << "\nvd reverse: " << endl;
	reverse(vd.begin(), vd.end());
	print(vd);

	double mean = sum_vd / vd.size();
	cout << "mean of vd: " << mean << endl;

	vector<double> vd2;
	for (int i = 0; i < vd.size(); ++i)
	{
		if(vd[i] < mean)
			vd2.push_back(vd[i]);
	}
	cout << "\nvd2 elements: " << endl;
	print(vd2);

	cout << "vd elements after sort: " << endl;
	sort(vd.begin(), vd.end());
	print(vd);

	} catch(std::exception& e){
		cerr << e.what() << std::endl;
		return 1;
	} catch(...){
		cerr << "unknow exception\n";
	}
}


