

#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"

using namespace Graph_lib;

struct Instructions_window : Graph_lib::Window
{
	//constructor
		Instructions_window(Point xy, int w, int h, const string& title);
	//functions
	private:
		Point* win_top_left = new Point{100,100};
		Point* top_bullet = new Point{205,150}; // <------------------------------
		Point* middle_bullet = new Point{205,260}; // <------------------------------
		Point* lower_bullet = new Point{205,370}; // <------------------------------
		
		Text* title_label;
		Text* top_text;
		Text* top_text2;
		Text* middle_text;
		Text* middle_text2;
		Text* lower_text;
		Text* lower_text2;
		
//------------------------------------------------------------------------		
		Rectangle* title_rectangle;
		Rectangle* rules_rectangle;
//------------------------------------------------------------------------
		
		int size = 15;
		const int win_width{750};
};

Instructions_window::Instructions_window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title}
{
	title_label = new Text{Point{240,50}, "Instructions"}; // <------------------------------
	title_label->set_font_size(30);
	top_text = new Text{*top_bullet,"1) The goal is to arrange the pancakes with"};
	top_text->set_font_size(size);
	top_text2 = new Text{Point{230,200}, "the smallest on top and largest on bottom."}; // <------------------------------
	top_text2->set_font_size(size);
	middle_text = new Text{*middle_bullet,"2) You can insert between any two pancakes and"};
	middle_text->set_font_size(size);
	middle_text2 = new Text{Point{230,310}, "flip the order above the insertion."}; // <------------------------------
	middle_text2->set_font_size(size);
	lower_text = new Text{*lower_bullet,"3) The game is over when the pancakes are ordered, or if"};
	lower_text->set_font_size(size);
	lower_text2 = new Text{Point{230,420}, "your score falls below 0 by using too many moves."}; // <------------------------------
	lower_text2->set_font_size(size);

//------------------------------------------------------------------------
	title_label->set_font(Graph_lib::Font::courier_bold);
	
	title_label->set_color(Color{0});
	top_text->set_color(Color{0});
	top_text2->set_color(Color{0});
	middle_text->set_color(Color{0});
	middle_text2->set_color(Color{0});
	lower_text->set_color(Color{0});
	lower_text2->set_color(Color{0});
//------------------------------------------------------------------------
	
//------------------------------------------------------------------------
	
	Fl_Color old_color = fl_color();
    fl_color(80,0,0);
    color(fl_color());
	
	title_rectangle = new Rectangle{Point{215,10},300,60};
	rules_rectangle = new Rectangle{Point{155,120},455,325};
	
	
	title_rectangle->set_fill_color(Color{16});
	rules_rectangle->set_fill_color(Color{16});
//------------------------------------------------------------------------

//------------------------------------------------------------------------
	attach(*title_rectangle);
	attach(*rules_rectangle);
//------------------------------------------------------------------------	

	attach(*title_label);
	attach(*top_text);
	attach(*top_text2);
	attach(*middle_text);
	attach(*middle_text2);
	attach(*lower_text);
	attach(*lower_text2);
}