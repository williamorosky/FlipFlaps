
#include "Game_window.h"

using namespace Graph_lib;

Game_window::Game_window(Point xy, int w, int h, const string& title,int diff)
    :Window{xy,w,h,title}
{
    Button* b2 = new Button{Point{600,100},25,25,"1",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(1);}};
    Button* b3 = new Button{Point{600,125},25,25,"2",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(2);}};
    Button* b4 = new Button{Point{600,150},25,25,"3",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(3);}};
    Button* b5 = new Button{Point{600,175},25,25,"4",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(4);}};
    Button* b6 = new Button{Point{600,200},25,25,"5",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(5);}};
    Button* b7 = new Button{Point{600,225},25,25,"6",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(6);}};
    Button* b8 = new Button{Point{600,250},25,25,"7",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(7);}};
    Button* b9 = new Button{Point{600,275},25,25,"8",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(8);}};
    Button* b10 = new Button{Point{600,300},25,25,"9",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(9);}};
    Button* b11 = new Button{Point{600,325},25,25,"10",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(10);}};
    Button* b12 = new Button{Point{600,350},25,25,"11",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(11);}};
    flip_buttons.push_back(b2);
    flip_buttons.push_back(b3);
    flip_buttons.push_back(b4);
    flip_buttons.push_back(b5);
    flip_buttons.push_back(b6);
    flip_buttons.push_back(b7);
    flip_buttons.push_back(b8);
    flip_buttons.push_back(b9);
    flip_buttons.push_back(b10);
    flip_buttons.push_back(b11);
    flip_buttons.push_back(b12);
    
	stack.create_stack(diff);
	//min_moves=calc_min_moves();
	min_moves=diff;
	score=0;
	flip_count=0;
	redraw_window();
}

void Game_window::cb_flip(int n)
{
    stack.flip(n);
    flip_count++;
    redraw_window();
    

}

void Game_window::redraw_window(){
	flush();
	int y = win_height - 50;
	for(int i = 0; i<stack.size(); i++){
	int x = (win_width/2) - ((stack.get(i).get_width() * 50)/2);
	Ellipse* pancake = new Ellipse{Point{x,y},(stack.get(i).get_width() * 50),height};
    attach(flip_buttons[i]);
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