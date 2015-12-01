
#include "Game_window.h"

using namespace Graph_lib;

Game_window::Game_window(Point xy, int w, int h, const string& title,int diff)
    :Window{xy,w,h,title}
{
    stack.create_stack(diff);
    
	min_moves = calc_min_moves();
  
	score=0;
<<<<<<< HEAD
    swap = true;
   
=======
	bonus=false;
>>>>>>> master
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
	
	
    time = diff*10;
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
	flip_count=0;
    
   
    flip_count_label = new Text{Point{20,50}, "Moves: " + to_string(flip_count)};
    score_label = new Text{Point{20,75}, "Score: " + to_string(score)};
    if (seconds < 10)
            time_label = new Text{Point{20,100},"Time: " + to_string(minute)+":0"+to_string(seconds)};
        else
            time_label = new Text{Point{20,100},"Time: " + to_string(minute)+":"+to_string(seconds)};
    
   
    
    min_moves_label = new Text{Point{20,25}, "Can be done in " + to_string(min_moves) + " moves"};
    Fl::add_timeout(1.0,calltime,this);
  //  cerr<<"After making all the labels: "<<endl;
	r00 =  new Rectangle{Point{0,0},(diff+1)*40,500};
    r00->set_fill_color(color());
    r00->set_color(Color::invisible);

    attach(*flip_count_label);
    attach(*min_moves_label);
    attach(*score_label);
    attach(*time_label);
    cerr<<"It does attach the labels: "<<endl;
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
    
   
    if(score <= 0){
		Text* loser = new Text{Point{(win_width/2)-100,win_height/2},"LOSER!"};
		loser->set_color(fl_rgb_color(255,0,0));
		loser->set_font_size(40);
		attach(*loser);
		Fl::wait(10);
        score = 0;
        end_game();}
    if(is_solved()){
	
		Text* winner = new Text{Point{(win_width/2)-100,win_height/2},"WINNER!"};
		winner->set_font_size(40);
		winner->set_color(fl_rgb_color(255,224,97));
		attach(*winner);
		Fl::wait(10);
		
		if(flip_count<min_moves){
			bonus = true;
			score+=1000;
		}
        end_game();
		}
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
        vector<int> reverse_stack = reverse(stack.get_stack());
        int size = reverse_stack.size();
        
	if(stack.size() <= n_size){
		
		vector<int>* min_moves_vector = find_solution(reverse_stack);
		int min_moves = min_moves_vector->size();
		return min_moves;
	}
	else{
        
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
<<<<<<< HEAD
    if(gw->seconds <= 0 && gw->minute <= 0){
		gw->score=0;
        end_game();
    }
=======
    if(gw->seconds <= 0 && gw->minute <= 0)
        end_game();
    
>>>>>>> origin/wo-game
    gw->redraw_time_label();
    Fl::repeat_timeout(1.0,calltime, gw);
    
}
int Game_window::greater_find_solution(vector<int> pen)
{
    int n_count= pen.size();
    int diff_count = n_count - n_size;
    
    int outer_loop=0;
    int count = 0;
    
    vector<int> in = pen;
    int largest = 0;
    int index = 0;
    int flip = 0;
    int end = n_count-1;
    int n_min = 0;
    
    for(int i = 0; i<end+1;i++)
    {
        cerr<<in[i]<<endl;
    }
    while(outer_loop < diff_count)
    {
        largest = 0;
        for(int i = 0;i<end+1;i++)//Supposed to find the next largest number
        {
            
            if(largest<in[i])
            {
                largest = in[i];
                index = i;
                flip = i+1;
            }
        }
      //  cerr<<"This is the largest number: "<<largest<<" outer loop: "<<outer_loop<< " index: "<<index<<" flip: "<<flip<<endl;
        //cerr<<"size of pancake: "<<in.size();
        if (largest == in[end])// If largest pancake is alread at the bottom
        {
            count+=0;
            cerr<<"Largest is at the bottom: "<<endl;
        }
        // ---------------------------------------------------------------------------------------------------
        else if(largest == in[0])//If largest pancake is alread at the top
        {int d = end;
            for(int s = 0;s<end+1;s++)
            {
                if (s >= d)
                    break;
                else
                {
                int temp = in[d];
                in[d] = in[s];
                in[s] = temp;
                d--;
                }
            }
            count++;
        }//---------------------------------------------------------------------------------------------------
        else
        {
        int d = index;
        for(int start = 0;start<flip;start++)//Flips the largest number to the top
        {
            if (start >= d)
                break;
            else
            {
               // cout << ">>>3>>>" << start;
                //flush();
                 int temp = in[d];
                    in[d] = in[start];
                    in[start] = temp;
                    d--;
            }
            
        }
        count++;
           /* cerr<<"Current end value: "<<end<<endl;
            cerr<<"First loop in outer loop: "<<outer_loop<<endl;
            for(int i = 0; i<end+1;i++)
                cerr<<in[i]<<endl;*/
            
        d = end;
        for(int s = 0;s<end+1;s++)//Flips pancake to the bottom
        {
            if (s >= d)
                break;
            else
            {
            int temp = in[d];
            in[d] = in[s];
            in[s] = temp;
            d--;
            }
        }
            count++;
            /*cerr<<"Second loop in outer loop: "<<outer_loop<<endl;
            for(int i = 0; i<end+1;i++)
                cerr<<in[i]<<endl;*/
        }
        
  //--------------------------------------------------------------------------------------------------------------------
        end--;
        outer_loop++;
    }
   cerr << "After sort loop " << endl;
    vector<int> p;
    for (int i =0; i<in.size()-diff_count;i++)
    {
        cout << in[i] << endl;
        p.push_back(in[i]);
    }
    
 //   cout << "in size: " << in.size() << " p size:" << p.size() << endl;
    
   vector<int>* min_moves_vector = find_solution(p);
  //  cout << "min moves vecotr size: " << min_moves_vector->size() << endl;
 //   flush();
    n_min = min_moves_vector->size();
   // cerr<<"Count: "<<count<<" n min: "<<n_min<<endl;
    count = count+n_min;
    //cerr<<" The new counted add value: "<<count<<endl;
 //   cerr<< "Joshua is God Emperor: "<<endl;
    
    return count;
}

int Game_window::calc_score(){
int score = (100-(10 *(flip_count-min_moves)))*stack.size();


return score;
}

int Game_window::get_score(){
return score;
}
int Game_window::get_min_moves(){
	return min_moves;
}
int Game_window::get_flip_count(){
	return flip_count;
}
bool Game_window::get_bonus(){
	return bonus;
}