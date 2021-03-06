//Team H08: William  O'Rosky, Akshay Jagadeesh, Tyler Nardecchia
//CSCE 121-509 
//Due: December 2, 2015
//Scores_window.h

#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"

using namespace Graph_lib;

struct Scores_window : Graph_lib::Window
{
	//constructor
	Scores_window(Point xy, int w, int h, const string& title);
	
	//functions
	string get_initials();
	
	private:
	
		//objects
		Rectangle* title_label_rectangle;
		Text* title_label;
		Text* initials_label;
		In_box* initials_input;
		string initials;
		ifstream scores_file;
		vector<string> scores;	
		
		//constants		
		const int button_width{50};
		const int button_height{30};
		const int win_width{750};
		const int win_height{500};
		const string scores_filename{"scores.txt"};
		
		//functions
		vector<string> get_scores(ifstream& scores_file);
		void display_scores(vector<string> scores);
};