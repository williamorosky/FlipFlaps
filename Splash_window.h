//Team H08: William  O'Rosky, Akshay Jagadeesh, Tyler Nardecchia
//CSCE 121-509 
//Due: December 2, 2015
//Splash_window.h

#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"

using namespace Graph_lib;

struct Splash_window : Graph_lib::Window
{
	//constructor
	Splash_window(Point xy, int w, int h, const string& title);
	
	//functions
	private:
	
		const int win_width{750};
		
		//objects
		Text title_text;
		Text names_text;
		Image texas_image;
		Closed_polyline x1;
		Closed_polyline x1h1;
		Closed_polyline x1h2;
		Closed_polyline x1h3;
		Closed_polyline x2;
		Closed_polyline x2h1;
		Closed_polyline x2h2;
		Closed_polyline x2h3;
		Rectangle background;
};

//constructor
Splash_window::Splash_window(Point xy, int w, int h, const string& title)
:Window(xy,w,h,title),
background(Point((x_max()/2)-205,35),425,105),
title_text(Point((x_max()/2)-165,80), "Flip Flaps"),
names_text(Point((x_max()/2)-180,120), "William O'Rosky, Akshay Jagadeesh, and Tyler Nardecchia"),
texas_image(Point{(x_max()/2)-110, 220},"texas.jpg")
{
	//Sets up GUI
	background.set_fill_color(Color{7});
    title_text.set_font_size(50);
    title_text.set_font(Graph_lib::Font::courier_bold);
    attach(texas_image);
	
    x1.add(Point(265,450));
    x1.add(Point(515,250));
    x1.add(Point(495,220));
    x1.add(Point(555,165));
    x1.add(Point(605,240));
    x1.add(Point(545,295));
    x1.add(Point(525,265));
    x1.add(Point(275,465));
    
    x1h1.add(Point(505,220));
    x1h1.add(Point(555,175));
    x1h1.add(Point(565,190));
    x1h1.add(Point(515,235));
    
    x1h2.add(Point(520,243));
    x1h2.add(Point(570,198));
    x1h2.add(Point(580,213));
    x1h2.add(Point(530,258));
    
    x1h3.add(Point(535,266));
    x1h3.add(Point(585,221));
    x1h3.add(Point(595,236));
    x1h3.add(Point(545,281));
    
    x2.add(Point(515,450));
    x2.add(Point(265,250));
    x2.add(Point(285,220));
    x2.add(Point(225,165));
    x2.add(Point(175,240));
    x2.add(Point(235,295));
    x2.add(Point(255,265));
    x2.add(Point(505,465));
    
    x2h1.add(Point(275,220));
    x2h1.add(Point(225,175));
    x2h1.add(Point(215,190));
    x2h1.add(Point(265,235));
    
    x2h2.add(Point(260,243));
    x2h2.add(Point(210,198));
    x2h2.add(Point(200,213));
    x2h2.add(Point(250,258));
    
    x2h3.add(Point(245,266));
    x2h3.add(Point(195,221));
    x2h3.add(Point(185,236));
    x2h3.add(Point(235,281));
    
    Fl_Color old_color = fl_color();
    fl_color(80,0,0);
    
    x1.set_fill_color(Color::black);
    x1h1.set_fill_color(fl_color());
    x1h2.set_fill_color(fl_color());
    x1h3.set_fill_color(fl_color());
    x2.set_fill_color(Color::black);
    x2h1.set_fill_color(fl_color());
    x2h2.set_fill_color(fl_color());
    x2h3.set_fill_color(fl_color());
    
    color(fl_color());
    
    attach(background);
    attach(title_text);
    attach(names_text);

    attach(x1);
    attach(x1h1);
    attach(x1h2);
    attach(x1h3);
    attach(x2);
    attach(x2h1);
    attach(x2h2);
    attach(x2h3);
}