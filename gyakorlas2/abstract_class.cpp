#include <iostream>
#include <string>

using namespace std;
class Animal
{
public:
    virtual void voice()=0;
    virtual void legs()=0;
};

class Duck : public Animal
{
public:
    void voice(){
        cout << "glu gluu" << endl;
    }
   virtual void legs(){
        cout << "2 legs" << endl;
    }
};

class Cat : public Animal
{
public:
virtual void voice(){
        cout << "meow" << endl;
    }
    virtual void legs(){
    cout << "4 legs" << endl;
    }
};

class Persian : public Cat
{
public:
    void voice() {
        cout << "meow meow" << endl;
    }
    void legs(){
        cout << "4 legs" << endl;
    }
};

void talk(Animal &Animal){
    Animal.voice();
}

void move(Animal &Animal){
    Animal.legs();
}

int main(){
    Duck hap;
    talk(hap);
    move(hap);
    
    Cat Siamese;
    talk(Siamese);
    move(Siamese);
    
    Persian Kitty;
    talk(Kitty);
    move(Kitty);
}


/*#include <string>
#include <iostream>

using namespace std;
class Animal{
	public:
		virtual void voice()=0;
		void legs(){ cout << "4 legs\n";}
		virtual void habitat(){cout << "forest\n";}
};

class Birds : public Animal{
	public:
		virtual void voice(){cout << "chick chick\n";}
		void legs(){cout << "2 legs\n";}
		virtual void habitat(){cout << "pond\n";}
};

class Duck : public Birds{
	public:
		void voice(){cout << "quack\n";}
		void legs(){cout << "2 legs\n";}
		void habitat(){cout << "farm\n";}
};

void legs(Animal& anref){
	anref.legs();
};

int main(){
	
	Birds owl;
	owl.voice();
	owl.legs();
	owl.habitat();
	
	Duck Tas;
	Tas.voice();
	Tas.legs();
	Tas.habitat();
	
	Animal& aref=owl;
	owl.voice();
	owl.legs();
	owl.habitat();
	
}*/
