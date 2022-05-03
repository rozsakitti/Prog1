#include <iostream>
#include <stdexcept>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>

template<typename C>
void print(const C& c,char sep = '\n'){
	std::cout << "Container elements:\n";

	for(const auto elem : c){
		std::cout << elem << sep;
	}
	std::cout << std::endl;
}

int main()
try{

	const std::string iname {"input_floats.txt"};
	std::ifstream ifs {iname};
	if(!ifs) throw std::runtime_error("Could not read file: " +  iname);

	std::vector<double> vd;
	for(double d; ifs >> d;){
		vd.push_back(d);
	}

	print(vd);

	std::vector<int> vi(vd.size());
	/*for(auto& d : vd){
		vi.push_back(d);
	}*/
	std::copy(vd.begin(),vd.end(),vi.begin());
	print(vi);

	for(int i = 0; i < vd.size();i++){
		std::cout << vd[i] << '\t' << vi[i] << std::endl;
	}

	double sum_of_vd = 0;
	int sum_of_vi = 0;

	for(int i = 0; i < vd.size();i++){
		sum_of_vd += vd[i];
	}
	//accumulate helyett eleg a for ciklus is
	for(int i = 0; i < vi.size();i++){
		sum_of_vi += vi[i];
	}

	std::cout << std::endl << "sum of the elements of vd: " << sum_of_vd << std::endl;
	std::cout << "sum of the elements of vi: " << sum_of_vi << std::endl;
	std::cout << "the diff between the sum_vd and sum_vi: " << (sum_of_vd - sum_of_vi) << std::endl; 

	//forgatas
	std::reverse(vd.begin(),vd.end());
	print(vd);

	double vd_mean = sum_of_vd / vd.size();
	std::cout << "Mean value of vd: " << vd_mean << std::endl;

	std::vector<double> vd2;
	for(int i = 0; i < vd.size();i++){
		if (vd[i] < vd_mean){
			vd2.push_back(vd[i]);
		}
	}
	
	std::cout << "vd2 elements: " << std::endl;
	print(vd2);

	std::sort(vd.begin(),vd.end());
	print(vd);

}catch (std::exception& e) {
	std::cerr << "Exception: " << e.what() << std::endl;
	return 1;
}catch (...){
	std::cerr << "Unknown exception " << std::endl;
	return 2;
}
