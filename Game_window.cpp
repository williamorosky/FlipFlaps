
#include "Game_window.h"

using namespace Graph_lib;

Game_window::Game_window(Point xy, int w, int h, const string& title,int diff)
    :Window{xy,w,h,title}
{
    stack.create_stack(diff);
	min_moves = calc_min_moves();
	score=0;
    int b_height = (win_height - 50)-(20*diff)+30;
    Button* b2 = new Button{Point{(diff+1)*40,b_height},25,20,"1",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(1);}};
    Button* b3 = new Button{Point{(diff+1)*40,b_height+20},25,20,"2",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(2);}};
    Button* b4 = new Button{Point{(diff+1)*40,b_height+40},25,20,"3",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(3);}};
    Button* b5 = new Button{Point{(diff+1)*40,b_height+60},25,20,"4",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(4);}};
    Button* b6 = new Button{Point{(diff+1)*40,b_height+80},25,20,"5",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(5);}};
    Button* b7 = new Button{Point{(diff+1)*40,b_height+100},25,20,"6",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(6);}};
    Button* b8 = new Button{Point{(diff+1)*40,b_height+120},25,20,"7",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(7);}};
    Button* b9 = new Button{Point{(diff+1)*40,b_height+140},25,20,"8",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(8);}};
    Button* b10 = new Button{Point{(diff+1)*40,b_height+160},25,20,"9",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(9);}};
    Button* b11 = new Button{Point{(diff+1)*40,b_height+180},25,20,"10",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(10);}};
    Button* b12 = new Button{Point{(diff+1)*40,b_height+200},25,20,"11",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(11);}};
	
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
    for(int i = 0; i < stack.size() - 1; ++i)
		{
			this->attach(flip_buttons[i]);
		}
	
	//min_moves=diff;
    time = diff*10;
    if(time >60)
    {
        minute = time / 60;
        seconds = time - 60;
    }
    else
    {
        minute = 0;
        seconds = time;
    }
	flip_count=0;
    
    min_moves_label = new Text{Point{20,25}, "Can be done in " + to_string(min_moves) + " moves"};
    flip_count_label = new Text{Point{20,50}, "Moves: " + to_string(flip_count)};
    score_label = new Text{Point{20,75}, "Score: " + to_string(score)};
    time_label = new Text{Point{20,100},"Time: " + to_string(minute)+":"+to_string(seconds)};
    Fl::add_timeout(1.0,calltime,this);
	r00 =  new Rectangle{Point{0,0},(diff+1)*40,500};
    r00->set_fill_color(color());
    r00->set_color(Color::invisible);

    attach(*flip_count_label);
    attach(*min_moves_label);
    attach(*score_label);
    attach(*time_label);
	redraw_window();
}

void Game_window::cb_flip(int n)
{
    stack.flip(n);
    flip_count++;
    redraw_window();
}

void Game_window::redraw_time_label()
{
    
    if (seconds < 10)
            time_label->set_label("Time: " + to_string(minute)+":0"+to_string(seconds));
       else
           time_label->set_label("Time: " + to_string(minute)+":"+to_string(seconds));
    flush();
}
void Game_window::redraw_window(){
	flush();
	attach(*r00);
	int y = win_height - 50;
	for(int i = 0; i<stack.size(); i++){
		int x = (((stack.size()+1)*40)/2);
		Ellipse* pancake = new Ellipse{Point{x,y},(stack.get(i).get_width() * 20),height};
		Color pancake_color(fl_rgb_color(0,stack.get(i).get_width()*(255/stack.size()),195));
		pancake->set_fill_color(pancake_color);
		pancake->set_color(Color::invisible);
		attach(*pancake);
		y -= height + 10;
	}
    flip_count_label->set_label("Moves: " + to_string(flip_count));
    min_moves_label->set_label("Can be done in " + to_string(min_moves) + " moves");
    score = calc_score();
    score_label->set_label("Score: " + to_string(score));
    //redraw_time_label();
    attach(*flip_count_label);
    attach(*min_moves_label);
    attach(*score_label);
    attach(*time_label);
   // Fl::add_timeout(1.0,calltime,this);
    
   
    if(score < 0){
        score = 0;
        end_game();}
    if(is_solved())
        end_game();
}

bool Game_window::is_solved(){

    for(int i = 0; i < stack.size()-1; ++i)
    {
        if(stack.get(i).get_width() < stack.get(i+1).get_width())
            return false;
    }
    return true;
}

//calculate the minimum moves required to win
	int Game_window::calc_min_moves()
	{
	if(stack.size()<10){
		vector<int> reverse_stack = reverse(stack.get_stack());
		vector<int>* min_moves_vector = find_solution(reverse_stack);
		int min_moves = min_moves_vector->size();
		return min_moves;
	}
	else{
	return 25;
	}
	
	}

	//reverse the Stack vector of pancakes since Stack has the bottom pancake
	//at index 0 and find_solution() requires the top pancake at index 0
	vector<int> Game_window::reverse(vector<Pancake> in)
	{
		vector<int> out;
		for(int i=in.size() - 1; i >= 0; --i)
			out.push_back(in[i].get_width());
		return out;
	}

void Game_window::calltime(void* data)
{
    
    Game_window* gw = (Game_window*) data;
    if( gw->seconds == 0 && gw->minute > 0 )
    {
        gw->minute -=1;
        gw->seconds = 59;
    }
    else
        gw->seconds -= 1;
    if(gw->seconds <= 0 && gw->minute <= 0)
        end_game();
    
    gw->redraw_time_label();
    Fl::repeat_timeout(1.0,calltime, gw);
    
}

int Game_window::calc_score(){
int score = (100-(10 *(flip_count-min_moves)))*stack.size();
return score;
}

int Game_window::get_score(){
return score;
}