
#include "Game_window.h"

using namespace Graph_lib;

Game_window::Game_window(Point xy, int w, int h, const string& title,int diff)
    :Window{xy,w,h,title}
{
	stack.create_stack(diff);
	//min_moves=calc_min_moves();
	min_moves=diff;
	score=0;
	flip_count=0;
	redraw_window();
}

void Game_window::cb_flip(int n){}

void Game_window::redraw_window(){
	flush();
	int y = win_height - 50;
	for(int i = 0; i<stack.size(); i++){
	int x = (win_width/2) - ((stack.get(i).get_width() * 50)/2);
	Ellipse* pancake = new Ellipse{Point{x,y},(stack.get(i).get_width() * 50),height};
	Color pancake_brown(fl_rgb_color(199,168,89));
	pancake->set_fill_color(pancake_brown);
    attach(*pancake);
	y -= height + 10;
	}
}

bool Game_window::is_solved(){

return false;
}

//int calc_min_moves(){}

vector<int> Game_window::reverse(vector<Pancake> in){

}

int Game_window::calc_score(){
int score = (100-(10 *(flip_count-min_moves)))*stack.size();
return score;
}

int Game_window::get_score(){
return score;
}