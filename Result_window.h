//Team H08: William  O'Rosky, Akshay Jagadeesh, Tyler Nardecchia
//CSCE 121-509 
//Due: December 2, 2015
//Result_window.h

#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"

using namespace Graph_lib;

struct Result_window : Graph_lib::Window
{
	//constructor
	Result_window(Point xy, int w, int h, const string& title);
	
	//functions
	void set_initials(string inits);
	void set_player_score(int p_score);
	void set_difficulty(int diff);
	void set_min_moves(int min);
	void set_flip_count(int flips);
	void set_bonus(bool bonus);
	void update();
	
	private:
	
		//objects
		Text* title_label;
		string initials;
		ifstream scores_in;
		ofstream scores_out;
		vector<string> initials_vector;
		vector<int> scores_vector;
		int player_score;
		int p_difficulty;
		int p_min_moves;
		int p_flip_count;
		bool p_bonus;
		
		//constants		
		const int button_width{50};
		const int button_height{30};
		const int win_width{750};
		const int win_height{500};
		const string scores_filename{"scores.txt"};
		
		//functions
		void display_scores();
		void display_calculation();
		void input_scores();
		void sort_scores();
		void output_scores();
};