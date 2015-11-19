
#include "Game_window.h"

using namespace Graph_lib;
using namespace std;


Game_window::Game_window(Point xy, int w, int h, const string& title,int diff)
    :Window{xy,w,h,title}
{
    num_pan = diff;
    Ellipse e1{Point{50,200},20,20};
    attach(e1);
    
}
void Game_window::draw_pan()
{
    Ellipse e1{Point{50,200},20,20};
    attach(e1);
    
}
