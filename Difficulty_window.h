//Team H08: William  O'Rosky, Akshay Jagadeesh, Tyler Nardecchia
//CSCE 121-509 
//Due: December 2, 2015
//Difficulty_window.h

#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"
#include "Main.h"

using namespace Graph_lib;

struct Difficulty_window : Graph_lib::Window
{
	//constructor
	Difficulty_window(Point xy, int w, int h, const string& title);
	
	//functions
	int get_difficulty();
	
	private:
	//objects
	Text* title_label;
	Rectangle* title_label_rectangle;
	Button* b2;
	Button* b3;
	Button* b4;
	Button* b5;
	Button* b6;
	Button* b7;
	Button* b8;
	Button* b9;
	Button* b10;
	Button* b11;
	Button* b12;
	int difficulty;
	
	//constants
	const int win_width{750};
	const int win_height{500};
	
	//functions
	void set_difficulty(int n);
};