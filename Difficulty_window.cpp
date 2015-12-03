//Team H08: William  O'Rosky, Akshay Jagadeesh, Tyler Nardecchia
//CSCE 121-509 
//Due: December 2, 2015
//Difficulty_window.cpp

#include "Difficulty_window.h"

using namespace Graph_lib;

//constructor
Difficulty_window::Difficulty_window(Point xy, int w, int h, const string& title):Window{xy,w,h,title}
{
	//create GUI
	Fl_Color old_color = fl_color();
	fl_color(80,0,0);
	color(fl_color());
	
	title_label = new Text{Point{(win_width/2)-90, win_height/15+50}, "Difficulty"};
	description = new Text{Point{(win_width/2)-330, win_height/4+28}, "Each difficulty corresponds to the number of pancakes in the stack."};
	title_label_rectangle = new Rectangle{Point{265,40},250,70};
	description_rectangle = new Rectangle{Point{35,130},682,40};
	title_label->set_font(Graph_lib::Font::courier_bold);
	description->set_font(Graph_lib::Font::courier_bold);
	title_label->set_color(Color{0});
	description->set_color(Color{0});
	title_label->set_font_size(30);
	title_label_rectangle->set_fill_color(Color{16});
	description_rectangle->set_fill_color(Color{16});
	
	attach(*title_label_rectangle);
	attach(*title_label);
	attach(*description_rectangle);
	attach(*description);
	
	b2 = new Button{Point{100,300},50,50,"2",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(2);}};
	b3 = new Button{Point{150,300},50,50,"3",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(3);}};
	b4 = new Button{Point{200,300},50,50,"4",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(4);}};
	b5 = new Button{Point{250,300},50,50,"5",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(5);}};
	b6 = new Button{Point{300,300},50,50,"6",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(6);}};
	b7 = new Button{Point{350,300},50,50,"7",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(7);}};
	b8 = new Button{Point{400,300},50,50,"8",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(8);}};
	b9 = new Button{Point{450,300},50,50,"9",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(9);}};
	b10 = new Button{Point{500,300},50,50,"10",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(10);}};
	b11 = new Button{Point{550,300},50,50,"11",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(11);}};
	b12 = new Button{Point{600,300},50,50,"12",[](Address,Address pw){reference_to<Difficulty_window>(pw).set_difficulty(12);}};
	
	attach(*b2);
	attach(*b3);
	attach(*b4);
	attach(*b5);
	attach(*b6);
	attach(*b7);
	attach(*b8);
	attach(*b9);
	attach(*b10);
	attach(*b11);
	attach(*b12);
}

//functions
//called by the button that is pushed to set the difficutly level
void Difficulty_window::set_difficulty(int n)
{
	difficulty = n;
	difficulty_win_next();
}
//used by game.cpp to acquire the difficulty level for the rest of the game
int Difficulty_window::get_difficulty()
{
	return difficulty;
}