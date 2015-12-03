//Team H08: William  O'Rosky, Akshay Jagadeesh, Tyler Nardecchia
//CSCE 121-509 
//Due: December 2, 2015
//Result_window.cpp

#include "Result_window.h"

using namespace Graph_lib;

//constructor
Result_window::Result_window(Point xy, int w, int h, const string& title):Window{xy,w,h,title}
{
	//create GUI
	Fl_Color old_color = fl_color();
	fl_color(80,0,0);
	color(fl_color());
	
	title_label = new Text{Point{(win_width/2)-60, win_height/15}, "High Scores"};
	title_label->set_font_size(30);
	attach(*title_label);
	//obtain initials and scores
	input_scores();
}

//functions
//sets the player's initials
void Result_window::set_initials(string inits)
{
	initials = inits;
}

//sets the player's score
void Result_window::set_player_score(int p_score)
{
	player_score = p_score;
}

//sets what the game difficulty	was
void Result_window::set_difficulty(int diff)
{
	p_difficulty=diff;
}

//sets what the minimum amount of moves	was
void Result_window::set_min_moves(int min)
{
		p_min_moves=min;
}

//sets what the flip count	was
void Result_window::set_flip_count(int flips)
{
	p_flip_count=flips;
}

//sets whether or not a bonus was earned
void Result_window::set_bonus(bool bonus){
	p_bonus=bonus;
}

//called in game.cpp to update the data and screen after the player's data has been acquired
void Result_window::update()
{
	sort_scores();
	display_calculation();
	display_scores();
	output_scores();
}

//displays the vectors of initials and scores on the screen; the player's score is bolded
void Result_window::display_scores()
{
	int y = 320;
	for (int i = 0; i < initials_vector.size(); ++i)
	{
		Text* t = new Text{Point{(win_width/2)-180, y}, to_string(i+1) + ")           "+ initials_vector[i] + "            " + to_string(scores_vector[i])};
		t->set_font_size(18);
		t->set_font(FL_COURIER);
		t->set_color(Color::white);
		if(initials_vector[i] == initials && scores_vector[i] == player_score)
		{
			t->set_label(to_string(i+1) + ")         "+ initials_vector[i] + "          " + to_string(scores_vector[i]));
			t->set_font(FL_COURIER_BOLD);
		}
		attach(*t);
		y += 30;
	}
}

//displays how the score was calculated
void Result_window::display_calculation()
{
	Text* title = new Text{Point{(win_width/2)-35, 90}, "Calculation"};
	title->set_font_size(18);
	title->set_color(fl_rgb_color(0,0,0));	
	
	Text* equation = new Text{Point{(win_width/2)-215, 120}, "((100 - (10 x (Flip Count - Minimum Moves))) x Difficulty) + Bonus )"};
	equation->set_font_size(14);
	equation->set_color(fl_rgb_color(0,0,0));
	
	Text* flip_count = new Text{Point{(win_width/2)-65, 145}, "Flip Count:                 " + to_string(p_flip_count)};
	flip_count->set_font_size(16);
	flip_count->set_color(fl_rgb_color(0,0,0));
	
	Text* min_moves = new Text{Point{(win_width/2)-65, 165}, "Minimum Moves:      " + to_string(p_min_moves)};
	min_moves->set_font_size(16);
	min_moves->set_color(fl_rgb_color(0,0,0));
	
	Text* difficulty = new Text{Point{(win_width/2)-65, 185}, "Difficulty:                    " + to_string(p_difficulty)};
	difficulty->set_font_size(16);
	difficulty->set_color(fl_rgb_color(0,0,0));
	
	Text* bonus = new Text{Point{(win_width/2)-65, 205}, "Bonus:                      0"};
	bonus->set_font_size(16);
	bonus->set_color(fl_rgb_color(0,0,0));
	
	Text* beat = new Text{Point{(win_width/2)-35, 220}, ""};
	beat->set_font_size(10);
	beat->set_color(Color::invisible);
	
	if(p_bonus)
	{
		bonus->set_label("Bonus:                   1000");
		beat->set_label("You beat the computer!");
		bonus->set_color(fl_rgb_color(255,224,97));
		beat->set_color(fl_rgb_color(255,224,97));
	}
	
	Text* score = new Text{Point{(win_width/2)-25, 245}, "Score: " + to_string(player_score)};
	score->set_font_size(18);
	score->set_color(fl_rgb_color(0,0,0));
	
	Rectangle *rect = new Rectangle(Point{(win_width/2)-220, 55},440,210);
	rect->set_fill_color(Color{16});
	rect->set_color(Color::invisible);
	
	attach(*rect);
	attach(*title);
	attach(*equation);
	attach(*flip_count);
	attach(*min_moves);
	attach(*difficulty);
	attach(*bonus);
	attach(*beat);
	attach(*score);
}

//inputs the scores from scores.txt
void Result_window::input_scores()
{
	scores_in.open(scores_filename, ifstream::in);
	
	if (!scores_in)
		error("can't open input file ",scores_filename);
		
	string initials;
	int score;
	
	while(scores_in >> initials >> score)
	{
		initials_vector.push_back(initials);
		scores_vector.push_back(score);
	}
	
	scores_in.close();
}

//sorts the player's score into the list of high scores
void Result_window::sort_scores()
{
	initials_vector.push_back(initials);
	scores_vector.push_back(player_score);
	for(int p=0; p<5; p++)
	{
		for(int i=0; i < scores_vector.size() - 1; ++i)
		{
			for(int j=i; j < scores_vector.size() - i - 1; ++j)
			{
				if(scores_vector[j] < scores_vector[j+1])
				{
					int tmpi = scores_vector[j];
					scores_vector[j] = scores_vector[j+1];
					scores_vector[j+1] = tmpi;
					string tmps = initials_vector[j];
					initials_vector[j] = initials_vector[j+1];
					initials_vector[j+1] = tmps;
				}
			}
		}
	}
}
		
//outputs the top 5 scores into scores.txt
void Result_window::output_scores()
{
	scores_out.open(scores_filename, std::ofstream::out);
	if (!scores_out)
		error("can't open output file ",scores_filename);
		
	int stack_size = 5;
	
	if(initials_vector.size() < 5)
		stack_size = initials_vector.size();
		
	for(int i = 0; i < stack_size; ++i)
	{
		scores_out << initials_vector[i] + " " + to_string(scores_vector[i]) + '\n';
	}
	
	scores_out.close();
}