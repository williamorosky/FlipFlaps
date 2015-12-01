#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "Stack.h"
#include "Main.h"
#include "find_solution.h"

using namespace Graph_lib;

struct Game_window: Graph_lib::Window
{
    Game_window(Point xy, int w, int h, const string& title,int diff);
	int get_score();
<<<<<<< HEAD
	int get_min_moves();
	int get_flip_count();
	bool get_bonus();
=======
>>>>>>> origin/wo-game
    
    int time;
    int minute;
    int seconds;
    const int n_size=9;
    //int min_moves = 0;
    
    static void calltime(void*);
    void redraw_time_label();
    
	private:
			Text* title_label;
			int width;
			const int height = 10;
			const int win_height = 500;
			const int win_width = 750;
		//objects
			Stack stack;
			Rectangle* r00;
			bool bonus;
			Vector_ref<Button> flip_buttons;
			int flip_count;
			Text* flip_count_label;
			int min_moves;
    bool swap;
			Text* min_moves_label;
<<<<<<< HEAD
			Text* time_label;
=======
    Text* time_label;
>>>>>>> origin/wo-game
			int score;
			Text* score_label;
		
		//functions
			void cb_flip(int n);
			void redraw_window();
            int greater_find_solution(vector<int> in);
			bool is_solved();
			int calc_min_moves();
			vector<int> reverse(vector<Pancake> in);
			int calc_score();

};
