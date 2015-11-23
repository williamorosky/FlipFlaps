
#include "Scores_window.h"

using namespace Graph_lib;

//constructor
	Scores_window::Scores_window(Point xy, int w, int h, const string& title)
		:Window{xy,w,h,title}
	{
	
	Fl_Color old_color = fl_color();
    fl_color(80,0,0);
    color(fl_color());
		title_label = new Text{Point{(win_width/2)-50, 75}, "Scores"}; // <------------------------------
		
//------------------------------------------------------------------------
		title_label->set_font(Graph_lib::Font::courier_bold);
		title_label->set_color(Color{0});

		title_label_rectangle = new Rectangle{Point{300,40},175,55};
		title_label_rectangle->set_fill_color(Color{16});
//------------------------------------------------------------------------

		title_label->set_font_size(30);
		initials_input = new In_box{Point{(win_width/2)-100, (win_height/3)-20}, 200, 50, "Initials"}; // <------------------------------
		scores_file.open(scores_filename, ifstream::in);
		if (!scores_file) 
			error("can't open input file ",scores_filename);
		scores = get_scores(scores_file);
		scores_file.close();
		
	
		
//------------------------------------------------------------------------
		attach(*title_label_rectangle);
		attach(*title_label);
		attach(*initials_input);
		display_scores(scores);
	}

//functions
	//public function that returns the player's initials entered
	//in the In_box; if the player enters more than 3 characters,
	//only the first 3 are used
	string Scores_window::get_initials()
	{	
		initials = initials_input->get_string();
		if (initials.length() > 3)
			initials = initials.substr(0,3);
		return initials;
	}

	//inputs the scores from scores.txt
	vector<string> Scores_window::get_scores(ifstream& scores_file)
	{
		vector<string> tmp;
		string name;
		string score;
		while(scores_file >> name >> score)
		{
			string s = name + '\t' + score;
			tmp.push_back(s);
		}
		return tmp;
	}

	//displays the initials and scores to the screen
	void Scores_window::display_scores(vector<string> scores)
	{
		int y = 225;
		for (int i = 0; i < scores.size(); ++i)
		{
			Text* t = new Text{Point{(win_width/2)-35, y}, to_string(i + 1) + ") " + scores[i]};
			t->set_color(Color{16});
			t->set_font_size(20);
			attach(*t);
			y += 50;
		}
	}