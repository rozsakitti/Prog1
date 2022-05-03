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
    void legs(){
        cout << "2 legs" << endl;
    }
};

class Cat : public Animal
{
public:
virtual void voice(){
        cout << "meow" << endl;
    }
    void legs(){
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

