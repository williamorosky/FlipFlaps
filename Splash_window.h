//Allison Snodgrass
//CSCE 121-505
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
			Color* baby_blue;
			Rectangle* bg_rect;
			Text* title_label = new Text{Point{(win_width/2),50}, "FlipFlaps"};
			Text* subtitle = new Text{Point{(win_width/2),80}, "The Pancake Sorting Game!"};
			Text* team = new Text{Point{(win_width/2)-60,100}, "H08ers Gonna Hate (Team H08)"};
			Text* will = new Text{Point{(win_width/2)-45,120}, "William O'Rosky"};
			Text* akshay = new Text{Point{(win_width/2)-50,140}, "Akshay Jagadeesh"};
			Text* tyler = new Text{Point{(win_width/2)-50, 160}, "Tyler Nardecchia"};
			Rectangle* next_button = new Rectangle{Point{540,460},50,30};
			Text* next_button_label = new Text{Point{550,480}, "Next"};

};

Splash_window::Splash_window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title}
{
	baby_blue = new Color(fl_rgb_color(153,218,234));
	bg_rect = new Rectangle{Point{0,0}, 750, 500};
	bg_rect->set_fill_color(*baby_blue);
	attach(*bg_rect);
	title_label = new Text{Point{(win_width/2)-100,50}, "FlipFlaps"};
	subtitle = new Text{Point{(win_width/2)-100,80}, "The Pancake Sorting Game!"};
	team = new Text{Point{(win_width/2)-60,100}, "H08ers Gonna Hate (Team H08)"}; 
	title_label->set_font(Graph_lib::Font::screen_bold);
	title_label->set_font_size(40);
	title_label->set_color(Color::black);
	attach(*title_label);
	subtitle->set_font(Graph_lib::Font::screen_bold);
	subtitle->set_font_size(20);
	subtitle->set_color(Color::black);
	attach(*subtitle);
	team->set_font(Graph_lib::Font::screen_bold);
	team->set_font_size(15);
	team->set_color(Color::black);
	attach(*team);
		attach(*will);
		attach(*akshay);
		attach(*tyler);
	next_button->set_fill_color(FL_BACKGROUND_COLOR);
	attach(*next_button);
	attach(*next_button_label);
}