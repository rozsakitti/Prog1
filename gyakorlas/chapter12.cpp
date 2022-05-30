/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp chapter12.cpp `fltk-config --ldflags --use-images` -o ol
*/

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>
using namespace Graph_lib;

int main(){
    try{

        Point t1 {100, 100};
        Simple_window win {t1, 640, 400, "My window"};

//pointeres megoldás
        for (int i = 1; i < 4; i++)
        {
            Circle *c = new Circle {Point{100+(i*80),200},50};
            win.attach(*c);
        }
        for (int i = 1; i < 3; i++)
        {
            Circle *c = new Circle {Point{140+(i*80),275},50};
           // c->set_color(Color::red);
            win.attach(*c);
        }
        	win.wait_for_button();

//--------------------------------------------------------------------------------
/*
/*new->közös memóriterületre helyezi el a valtozot, ezert torolnikell, ha mar nem kell, vector_ref amugy torli, new nelkul csak az adott scopeban hasznalhato
//megoldás Vector_ref_fel
     Vector_ref<Circle> c;
        for (int i=0; i< 5; i++ )  {
            if(i<3){
                c.push_back(new Circle(Point((i+1)*150,100),100));
                win.attach(c[c.size()-1]);
            }else{
                c.push_back(new Circle(Point((i-1.5)*150,250),100));
                win.attach(c[c.size()-1]);
            }
        }
        	win.wait_for_button();
*/
//---------------------------------------------------------------------------------
/*
//megoldás vector_ref nélkül
	Circle c{Point{80,80},50};
	c.set_color(Color::blue);
	c.set_style(Line_style(Line_style::solid,4));
	win.attach(c);


	Circle c1{Point{120,120},50};
	c1.set_color(Color::yellow);
	c1.set_style(Line_style(Line_style::solid,4));
	win.attach(c1);

	Circle c2{Point{160,80},50};
	c2.set_color(Color::black);
	c2.set_style(Line_style(Line_style::solid,4));
	win.attach(c2);

	Circle c3{Point{200,120},50};
	c3.set_color(Color::green);
	c3.set_style(Line_style(Line_style::solid,4));
	win.attach(c3);

	Circle c4{Point{240,80},50};
	c4.set_color(Color::red);
	c4.set_style(Line_style(Line_style::solid,4));
	win.attach(c4);
	win.wait_for_button();

*/
    } catch (exception& e) {
        cerr << "exception: " << e.what()<< '\n';
        return 1; 
    } catch (...) {
        cerr << "error\n";
        return 2;
    }
}
