
#include "Splash_window.h"
#include "Instructions_window.h"
#include "Scores_window.h"
#include "Difficulty_window.h"
#include "Main.h"
#include "Game_window.h"

using namespace Graph_lib;
using namespace std;

//variables
	string initials;	
	int* difficulty;
	int score;

//GUI objects
	Splash_window* splash_win;
	Instructions_window* instructions_win;
	Scores_window* scores_win;
	Difficulty_window* difficulty_win;
    Game_window* game_win;

	Button* splash_win_button;
	Button* instructions_win_button;
	Button* scores_win_button;
	Button* result_win_button;
    //Button* game_win_button;

//functions
	void cb_splash_win_button();
	void cb_scores_win_button();
	void cb_instructions_window_button();
    void cb_pancake_win_button();


int main()
{
try
{
    //create windows
		splash_win = new Splash_window{Point{100,100}, 750, 500, "FlipFlaps"};
		instructions_win = new Instructions_window{Point{100,100}, 750, 500, "FlipFlaps"};
		scores_win = new Scores_window{Point{100,100}, 750, 500, "FlipFlaps"};
		difficulty_win = new Difficulty_window{Point{100,100}, 750, 500, "FlipFlaps"};
    
		//hide all windows except splash screen
		instructions_win->hide();
		scores_win->hide();
		difficulty_win->hide();
        //game_win->hide();

		//add "Next" buttons and attach
		splash_win_button = new Button{Point{540,460},80,30,"Let's Play!",Callback(cb_splash_win_button)};	
		instructions_win_button = new Button{Point{540, 460}, 80, 30, "Next", Callback(cb_instructions_window_button)};
		scores_win_button = new Button{Point{540,460},80,30,"Next",Callback(cb_scores_win_button)};
       // game_win_button = new Button{Point{540,460},50,30,"Next",Callback(cb_pancake_win_button)};
    
    
		splash_win->attach(*splash_win_button);
		instructions_win->attach(*instructions_win_button);
		scores_win->attach(*scores_win_button);
        //game_win->attach(*game_win_button);
    
   
   // cout<<"Difficulty Test: "<<*(difficulty_win->get_difficulty());
    return gui_main();
}
catch(exception& e)
{
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...)
{
        cerr << "Some exception\n";
        return 2;
}
}
//"next" button functions
void cb_splash_win_button()
{
	splash_win->hide();
	instructions_win->show();
}

void cb_instructions_window_button()
{
	instructions_win->hide();
	scores_win->show();
}

void cb_scores_win_button()
{
	scores_win->hide();
	initials = scores_win->get_initials();
	if(initials == "")
		initials = "AAA";
	difficulty_win->show();
}
void difficulty_win_next()
{
    
    difficulty_win->hide();
    int d = difficulty_win->get_difficulty();
    cout<<" She wants the d: "<<d;
    game_win = new Game_window{Point{100,100}, 750, 500, "FlipFlaps",d};
    
   
}


