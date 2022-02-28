#include "./GUI/Graph.h"
#include "./GUI/Simple_window.h"

#include <string>
#include <iostream>

//g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill13.cpp `fltk-config --ldflags --use-images` -o a2.out

using namespace Graph_lib;

int main()
{
    
        try{
        Point t1{300,50};
        Simple_window win(t1,800,1000, "My window");
        win.wait_for_button();
        
        Lines grid;
        int x_size = 800;
        int y_size = 800;
        for(int i=100; i<=x_size; i+=100)
        {
        grid.add(Point(i,0),Point(i,y_size));
        grid.add(Point(0,i),Point(x_size,i));
        }
        win.attach(grid);
   	win.wait_for_button();
    
    	Vector_ref<Rectangle> vr;
 	for(int i=0; i<8;i++){
        vr.push_back(new Rectangle(Point(i*100,i*100),101,101));
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
    
    
    	}
    	win.wait_for_button();
        } catch(exception& e) {
                cerr << "exception: " << e.what() << '\n';
                return 1;
        } catch (...) {
                cerr << "error\n";
                return 2;
        }
}

