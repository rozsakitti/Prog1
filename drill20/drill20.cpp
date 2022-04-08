#include <string>
#include <array>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <exception>
#include <algorithm>

//iterator: ramutat az elso elemre, ha novelem a kovire. -> nem szamit a merete, tudja az iterator

template<typename C>
void print_contents(const C& c){
    for(auto& a : c)
        std::cout << a << ' ';
    std::cout << std::endl;    
}

template<typename C>
void inc(C& c,int n){
    for(auto& a : c){
        a+=n;
    }

}
 //itt hibás:
template<typename Iter1, typename Iter2>
//requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 ora_copy(Iter1 f1, Iter1 e1, Iter2 f2){
    for(Iter1 p=f1;p!= e1; ++p){
    *f2++ =*p;
    //f2++
    }
    return f2;
}

//containers
int main(){
try{
    constexpr int size=10;
    int arr[size];
    for(int i=0;i<size;++i) arr[i]=i;
    std::cout<<"C array:\t"<< std::endl;
    print_contents(arr);
    
    std::array<int, size>ai;
    std::copy(arr, arr + size, ai.begin());
    std::cout<<"std array:\t"<< std::endl;
    print_contents(ai);

    std::vector<int> vi(size); //elérhetem bármelyik elemet
    std::copy(arr, arr + size, vi.begin());
    std::cout<<"std vector:\t"<<std::endl;
    print_contents(vi);
    
    std::list<int> li(size); //első vagy utolsó elemet tudom csak elérni: push_back,push_front, pop_back, pop_front
    std::copy(arr, arr + size, li.begin());
    std::cout<<"std list:\t"<<std::endl;
    print_contents(li);
    
    std::array<int,size> ai2=ai;
    std::vector<int> vi2=vi;
    std::list<int> li2=li;
    
    print_contents(ai2);
    print_contents(vi2);
    print_contents(li2);
    
    inc(ai2,2);
    inc(vi2,3);
    inc(li2,5);
    
    print_contents(ai2);
    print_contents(vi2);
    print_contents(li2);
    
    ora_copy(ai2.begin(),ai2.end(),vi2.begin());
    ora_copy(li2.begin(),li2.end(),ai2.begin());
    std::cout << "copy" << std::endl;
    
    print_contents(ai2);
    print_contents(vi2);
    print_contents(li2);
    
    std::vector<int>::iterator vit; //az iterátorok a típusokhoz tartoznak, a find fv is iterátort ad vissza
    vit= std::find(vi2.begin(),vi2.end(),3);
    if(vit!=vi2.end()){
        std::cout << "Found at:" << std::distance(vi2.begin(),vit) << std::endl;
    }else{
        std::cout << "Not found" << std::endl;
    }
    
std::list<int>::iterator lit;
std::cout << "Does the list contains the value 27? ";
lit = find(li2.begin(), li2.end(), 27);
if(lit != li2.end()) {
	std::cout << "Found at: " << std::distance(li2.begin(),lit) << std::endl;
}else {
	std::cout << "Not found" << std::endl;
}
  
}catch(std::exception& e) {
        std::cerr << "exception: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception\n";
        return 2;
    }
}


