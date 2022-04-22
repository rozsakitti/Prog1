#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main(){
try{
	cout << "char\t " << sizeof(char) << endl;
	cout << "short\t" << sizeof(short) << endl;
	cout << "int\t" << sizeof(int) << endl;
	cout << "long\t" << sizeof(long) << endl;
	cout << "float\t" << sizeof(float) << endl;
	cout << "double\t" << sizeof(double) << endl;
	cout << "int*\t" << sizeof(int*) << endl;
	cout << "double*\t" << sizeof(double*) << endl;

	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10, 10);
	Matrix<int, 3> e(10, 10, 10);

	cout << "\nMatrix sizes: \n";
	cout << "1D int, 10 elements \t\t" << sizeof(a) << endl;
	cout << "1D int, 100 elements \t\t" << sizeof(b) << endl;
	cout << "1D double, 10 elements \t\t" << sizeof(c) << endl;
	cout << "2D int, 10x10 elements \t\t" << sizeof(d) << endl;
	cout << "3D int, 10x10x10 elements \t" << sizeof(e) << endl;

	cout << "\nNumber of elements:\n";
	cout << "a:\t" << a.size() << endl;
	cout << "b:\t" << b.size() << endl;
	cout << "c:\t" << c.size() << endl;
	cout << "d:\t" << d.size() << endl;
	cout << "e:\t" << e.size() << endl;

	int n;
	do
	{
		cout << "\nEnter a number: ";
		cin >> n;
		if(n<0)
			cout << "Invalid number!\n";
	} while (n<0);
	cout << "sqrt(" << n << "): " << sqrt(n) << endl;

	Matrix<double> m(3);
	cout << "\nEnter " << m.size() << " floating point values:\n";
	for (int i = 0; i < m.size(); ++i)
	{
		double a;
		cout << "Number" << i+1 << ": ";
		cin >> a;
		if(!cin)
			throw runtime_error("Problem reading from cin.");
		m[i] = a;
	}
	cout << "\nMatrix:\n" << m << endl;

	cout << "\nEnter n2 and m2: ";
	int n2, m2;
	cin >> n2 >> m2;

	Matrix<int, 2> m3(n2, m2);

	for (int i = 0; i < n2/*m3.dim1()*/; ++i) 
	{
		for (int j = 0; j < m2 /*m3.dim2()*/; ++j)
		{
			m3(i, j) = (i+1)*(j+1);
			cout << '\t' << m3(i, j);
		}
	}
	cout << endl;

	Matrix<complex<double>> m4(10);
	cout << "\nEnter 10 complex numbers (Re, Im): ";
	complex<double> comp;
	for (int i = 0; i < 10; ++i)
	{
		cin >> comp;
		if(!cin)
			throw runtime_error("Problem reading complex number!");
		m4[i] = comp;
	}

	cout << "Complex matrix" << endl;
	complex<double> sum = 0;
	for (int i = 0; i < m4.size(); ++i)
	{
		sum += m4[i];
	}
	cout << "Sum: " << sum << endl;

	Matrix<int, 2> mi(2,3);
    int number;
    for (int i = 0; i < mi.dim1(); ++i){
        for(int j = 0; j < mi.dim2(); ++j){
            cout << "\nNumber mi(" << i << ", " << j << "): ";
            cin >> number;
         	mi(i, j) = number;
        }
    }

    cout << "\nMátrix: \n";
    for (int i = 0; i < mi.dim1(); ++i){
        for(int j = 0; j < mi.dim2(); ++j){
            cout << mi(i,j) << " ";
        }
        cout << "\n";
    }



	} catch(exception& e){
		cerr << "Exception: " << e.what() << endl;
		return 1;
	} catch(...){	
		cerr << "Exception\n";
		return 2;
	}	
}
