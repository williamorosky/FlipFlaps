#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "Stack.h"
#include "Main.h"


using namespace Graph_lib;

struct Game_window: Graph_lib::Window
{
    Game_window(Point xy, int w, int h, const string& title,int diff);
	int get_score();
		
	private:
			Text* title_label;
			int width;
			const int win_height = 500;
			const int win_width = 750;
		//objects
			Stack stack;
			Vector_ref<Button> flip_buttons;
			int flip_count;
			Text* flip_count_label;
			int min_moves;
			Text* min_moves_label;
			int score;
			Text* score_label;
		
		//functions
			void cb_flip(int n);
			void redraw_window();
			bool is_solved();
			//int calc_min_moves();
			vector<int> reverse(vector<Pancake> in);
			int calc_score();

};