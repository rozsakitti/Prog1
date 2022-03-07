#include "../GUI/Graph.h"
#include "../GUI/Simple_window.h"
#include <string>
#include <iostream>

//g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill13.cpp `fltk-config --ldflags --use-images` -o a2.out

using namespace Graph_lib;

int main()
{
    	//1.)
        try{
        Point t1{300,50};
        Simple_window win(t1,800,1000, "My window");
        win.wait_for_button();
        
        //2.)
        Lines grid;
        int x_size = 800;
        int y_size = 800;
        for(int i=100; i<=x_size; i+=100)
        {
        grid.add(Point(i,0),Point(i,y_size)); //függőleges
        grid.add(Point(0,i),Point(x_size,i)); //vízszintes
        }
        win.attach(grid);
        win.label("Grid");
   	win.wait_for_button();
    
    	//3.)
    	Vector_ref<Rectangle> vr;
 	for(int i=0; i<8;i++){
        vr.push_back(new Rectangle(Point(i*100,i*100),101,101));
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
        win.label("Grid(red)");
    	}
    	win.wait_for_button();
    	
    	
    	//4.)
    	Image img1 {Point{0,200},"GUI/cica.jpeg"};
	img1.set_mask(Point{0,200}, 200, 200);
	win.attach(img1);
	Image img2 {Point{200,400},"GUI/cica.jpeg"};
	img2.set_mask(Point{0,200}, 200, 200);
	win.attach(img2);
	Image img3 {Point{400,600},"GUI/cica.jpeg"};
	img3.set_mask(Point{0,200}, 200, 200);
	win.attach(img3);
	win.label("3 images");
	win.wait_for_button();

	//5.)
	Image img_move {Point{0, 0},"GUI/badge.jpg"};
	img_move.set_mask(Point{0,200}, 100, 100); //set_mask()-->kivágja a megfelelő méretet
	win.attach(img_move);
	win.label("images moving");
	win.wait_for_button();
	while(true){
        	for (int i = 0; i < 8; ++i){
        		for (int j = 0; j < 7; ++j){
        			img_move.move(100,0);
        			win.label("My Window(x+100, y+0)");
	           		win.wait_for_button();
        		}
        		if (i<7){
        			img_move.move(-700,100);
        			win.label("My Window(x-700, y+100)");
	       		win.wait_for_button();
	       		}
	       	else{
	       		img_move.move(-700,-700);
	       		win.label("My Window(x-700, y-700)");
	       		win.wait_for_button();
	       	}
	        }
    	}
    	
    	}catch(exception &e){
        	cerr << "exception: " << e.what() << '\n';
        	return 1;
    	}catch (...){
        	cerr << "error\n";
        	return 2;
    	}
    		return 0;
}
