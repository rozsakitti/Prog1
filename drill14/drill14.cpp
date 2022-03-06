#include <string>
#include <iostream>

using namespace std;

class B1{
    public:
        virtual void vf(){ //virtuális: felül lehet majd írni
        cout << "B1::vf()\n";
        }
        void f(){
            cout << "B1::f()\n";
        }
      /*  virtual void pvf()=0; */
};

class D1: public B1{ //örökli majd a B1-et
    public:
        virtual void vf(){
        cout << "D1::vf()\n";
        }
        void f(){
            cout << "D1::f()\n";
        }    
     /*   virtual void pvf()=0; */
};

class D2: public D1{
    public:
        virtual void vf(){
            cout << "D2::vf()\n";
            }
            void f(){
                cout << "D2::f()\n";
            }    
            void pvf(){
                cout << "D2::pvf()\n";
    }
};
    
class B2{
    public:
        virtual void pvf()=0;
};

class D21: public B2{
    public: 
    	string s;
    	void pvf(){
        cout << s << endl;
        }
};

class D22: public B2{
    public:
	int n;
	void pvf(){
	cout << n << endl;
	}
};

void f(B2& b2ref){
	b2ref.pvf();
};


int main(){
    B1 b1; //B1 osztályból b1 objektum --> példányosítás
    b1.vf();
    b1.f();
    
    D1 d1;
    d1.vf();
    d1.f();
    
    B1& bref=d1; //referencia
    bref.vf(); //felülírja D-re a virtuális szó miatt
    bref.f(); //nem írja felül (B-t ad)
    
    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();
    
    D21 d21;
    d21.s="d21.s";
    d21.pvf();
    
    D22 d22;
    d22.n=22;
    d22.pvf();
    
    f(d21);
    f(d22);
};




