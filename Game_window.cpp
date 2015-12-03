//Team H08: William  O'Rosky, Akshay Jagadeesh, Tyler Nardecchia
//CSCE 121-509 
//Due: December 2, 2015
//Game_window.cpp

#include "Game_window.h"

using namespace Graph_lib;

Game_window::Game_window(Point xy, int w, int h, const string& title,int diff)
    :Window{xy,w,h,title}
{
	//Create GUI and initialize variables
	color(Color::white);
    stack.create_stack(diff);
	min_moves = calc_min_moves();
	score=0;
	flip_count=0;
    time = diff*10;
	bonus=false;

    int b_height = (win_height - 50)-(20*diff)+30;
    Button* b2 = new Button{Point{(diff+1)*40,b_height},25,20,"2",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(1);}};
    Button* b3 = new Button{Point{(diff+1)*40,b_height+20},25,20,"3",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(2);}};
    Button* b4 = new Button{Point{(diff+1)*40,b_height+40},25,20,"4",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(3);}};
    Button* b5 = new Button{Point{(diff+1)*40,b_height+60},25,20,"5",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(4);}};
    Button* b6 = new Button{Point{(diff+1)*40,b_height+80},25,20,"6",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(5);}};
    Button* b7 = new Button{Point{(diff+1)*40,b_height+100},25,20,"7",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(6);}};
    Button* b8 = new Button{Point{(diff+1)*40,b_height+120},25,20,"8",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(7);}};
    Button* b9 = new Button{Point{(diff+1)*40,b_height+140},25,20,"9",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(8);}};
    Button* b10 = new Button{Point{(diff+1)*40,b_height+160},25,20,"10",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(9);}};
    Button* b11 = new Button{Point{(diff+1)*40,b_height+180},25,20,"11",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(10);}};
    Button* b12 = new Button{Point{(diff+1)*40,b_height+200},25,20,"12",[](Address,Address pw){reference_to<Game_window>(pw).cb_flip(11);}};

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

    if(time >60)
    {
        minute = time / 60;
        if(time % 60 == 0)
        {
            seconds = 0;
        }
        else
            seconds = time - 60;
    }
    else
    {
        if(time == 60)
        {
            minute = 1;
            seconds = 0;
        }
        else
        {
            minute = 0;
            seconds = time;
        }
    }
	
    flip_count_label = new Text{Point{20,50}, "Moves: " + to_string(flip_count)};
    score_label = new Text{Point{20,75}, "Score: " + to_string(score)};
	min_moves_label = new Text{Point{20,25}, "Can be done in " + to_string(min_moves) + " moves"};
	
    if (seconds < 10)
            time_label = new Text{Point{20,100},"Time: " + to_string(minute)+":0"+to_string(seconds)};
        else
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

//Flip function reverses order of the stack of n pancakes 
void Game_window::cb_flip(int n)
{
    stack.flip(n);
    flip_count++;
    redraw_window();
}

//Redraws timer every time it changes
void Game_window::redraw_time_label()
{ 
    if (seconds < 10)
            time_label->set_label("Time: " + to_string(minute)+":0"+to_string(seconds));
       else
           time_label->set_label("Time: " + to_string(minute)+":"+to_string(seconds));
    flush();
}

//Redraws the window after every time the pancakes are flipped
void Game_window::redraw_window()
{
	flush();
	attach(*r00);
	draw_pancakes();
	
    flip_count_label->set_label("Moves: " + to_string(flip_count));
    min_moves_label->set_label("Can be done in " + to_string(min_moves) + " moves");
    score = calc_score();
    score_label->set_label("Score: " + to_string(score));

    attach(*flip_count_label);
    attach(*min_moves_label);
    attach(*score_label);
    attach(*time_label);
	
	check_score();
	check_solved();
}

//Draws pancakes
void Game_window::draw_pancakes()
{
	int y = win_height - 50;
<<<<<<< HEAD
    vector<int>v;
    
 
	//Draws pancakes
    for(int i = 0; i<stack.size(); i++)
=======
	
	/*vector<int> v = {5, 7, 9, 4, 6, 8};
	for (int x : v)        // for each x in v
          cout << x << '\n';
	*/
	for(auto i = 0; i<stack.size(); i++)
>>>>>>> master
	{
		int x = (((stack.size()+1)*40)/2);
		
		Ellipse* pancake = new Ellipse{Point{x,y},(stack.get(i).get_width() * 20),height};
		Color pancake_color(fl_rgb_color(stack.get(i).get_width()*(255/stack.size()),0,0));
		pancake->set_fill_color(pancake_color);
		pancake->set_color(Color::invisible);
		attach(*pancake);
		y -= height + 10;
	}
}

//Ends game if score reaches or goes below 0.
void Game_window::check_score()
{ 
    if(score <= 0)
	{
		Text* loser = new Text{Point{(win_width/2)-100,win_height/2},"LOSER!"};
		loser->set_color(fl_rgb_color(255,0,0));
		loser->set_font_size(40);
		attach(*loser);
		Fl::wait(10);
        score = 0;
        end_game();
	}
}

//Ends game if problem is solved	
void Game_window::check_solved()
{
    if(is_solved())
	{
		Text* winner = new Text{Point{(win_width/2)-100,win_height/2},"WINNER!"};
		winner->set_font_size(40);
		winner->set_color(fl_rgb_color(255,224,97));
		attach(*winner);
		Fl::wait(10);
		
		if(flip_count<min_moves)
		{
			bonus = true;
			score+=1000;
		}
		
        end_game();
	}
}

//Checks is stack is in order from largest on the botton to largest on the top
bool Game_window::is_solved()
{
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
    vector<int> reverse_stack = reverse(stack.get_stack());
    int size = reverse_stack.size();
        
	if(stack.size() <= n_size)
	{
		vector<int>* min_moves_vector = find_solution(reverse_stack);
		int min_moves = min_moves_vector->size();
		return min_moves;
	}
	else
	{
        int min_moves = greater_find_solution(reverse_stack);
        return min_moves;
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

//Updates the time every second
void Game_window::calltime(void* data)
{  
    Game_window* gw = (Game_window*) data;
	
    if(gw->seconds == 0 && gw->minute > 0)
    {
        gw->minute -=1;
        gw->seconds = 59;
    }
    else
        gw->seconds -= 1;
		
    if(gw->seconds <= 0 && gw->minute <= 0)
	{
		gw->score=0;
        end_game();
    }

    gw->redraw_time_label();
    Fl::repeat_timeout(1.0,calltime, gw); 
}

//Finds minimum moves for stack of pancakes size 10 and up
int Game_window::greater_find_solution(vector<int> pen)
{
   
    int diff_count = pen.size() - n_size;
    int outer_loop=0;
    int count = 0;
    vector<int> in = pen;
    int end = pen.size()-1;
  
    
   
    while(outer_loop < diff_count)
    {
        int index =find_index(in,0,end);
        int largest = find_largest( in, 0,end);
        
        if (largest == in[end])// If largest pancake is alread at the bottom
        {}
        else if(largest == in[0])//If largest pancake is alread at the top
        {
            in = flip_to_top(in, end);
            count++;
        }
		else
        {
		
            in = flip_to_top(in,index);
			in = flip_to_bottom(in,end);
            count+=2;
        }
		end--;
        outer_loop++;
    }
    
    vector<int> p = make_vector(in,diff_count);
    vector<int>* min_moves_vector = find_solution(p);
    int n_min = min_moves_vector->size();
    count = count+n_min;
	return count;
}
vector<int>  Game_window::make_vector(vector<int> in,int diff_count)
{
    vector<int> p;
    cerr<<" THis is P: "<< endl;
    for (int i =0; i<in.size()-diff_count;i++)
    {
        p.push_back(in[i]);
        cerr<<p[i]<<endl;
    }
    return p;
}
int Game_window::find_largest(vector<int> in,int largest, int end)
{
    int index = 0;
    for(int i = 0;i<end+1;i++)//Supposed to find the next largest number
    {
        if(largest<in[i])
        {
            largest = in[i];
            index = i;
            
        }
    }
    
    return largest;
    
}
vector<int> Game_window::flip_to_top(vector<int> in,int end)
{
    vector<int> p = in;
    int d = end;
    for(int s = 0;s<end+1;s++)
    {
        if (s >= d)
            break;
        else
        {
            int temp = p[d];
            p[d] = p[s];
            p[s] = temp;
            d--;
        }
    }
    
    return p;
    
}
vector<int> Game_window::flip_to_bottom(vector<int>in,int end)
{
    vector<int> p = in;
    int d = end;
    for(int s = 0;s<end+1;s++)//Flips pancake to the bottom
    {
        if (s >= d)
            break;
        else
        {
            int temp = p[d];
            p[d] = p[s];
            p[s] = temp;
            d--;
        }
    }
    return p;
    
}
int Game_window::find_index(vector<int> in,int r, int end)
{
    int index = r;
    int largest = 0;
    for(int i = 0;i<end+1;i++)//Supposed to find the next largest number
    {
        if(largest<in[i])
        {
            largest = in[i];
            index = i;
            
        }
    }
    
    return index;
    

    
}
//Calcultes player's score
int Game_window::calc_score()
{
	int score = (100-(10 *(flip_count-min_moves)))*stack.size();
	return score;
}

//Returns player's score
int Game_window::get_score()
{
	return score;
}

//Returns minimum moves to reach solution
int Game_window::get_min_moves()
{
	return min_moves;
}

//Returns minimum moves to reach solution
int Game_window::get_flip_count()
{
	return flip_count;
}

//Returns whether or not player completed game in less moves then minimum moves
bool Game_window::get_bonus()
{
	return bonus;
}