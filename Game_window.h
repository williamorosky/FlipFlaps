//Team H08: William  O'Rosky, Akshay Jagadeesh, Tyler Nardecchia
//CSCE 121-509 
//Due: December 2, 2015
//Game_window.h

#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "Stack.h"
#include "Main.h"
#include "find_solution.h"

using namespace Graph_lib;

struct Game_window: Graph_lib::Window
{
	//constructor
    Game_window(Point xy, int w, int h, const string& title,int diff);
	
	// public functions
	int get_score();
	int get_min_moves();
	int get_flip_count();
	bool get_bonus();

	static void calltime(void*);
    void redraw_time_label();
	
	// public variables
    int time;
    int minute;
    int seconds;
	
    const int n_size=9;

	private:
		
		// private variables
		int width;
		bool bonus;
		int flip_count;
		int min_moves;
		int score;
		
		// public constants
		const int height = 10;
		const int win_height = 500;
		const int win_width = 750;
		
		//private objects
		Text* title_label;
		Stack stack;
		Rectangle* r00;
		Vector_ref<Button> flip_buttons;
		Text* flip_count_label;
		Text* min_moves_label;
		Text* time_label;
		Text* score_label;
		
		//private functions
		void cb_flip(int n);
		void redraw_window();
        int greater_find_solution(vector<int> in);
		int calc_min_moves();
		int calc_score();
		bool is_solved();
		vector<int> reverse(vector<Pancake> in);
};