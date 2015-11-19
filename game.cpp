
#include "game.h"

using namespace Graph_lib;
using namespace std;


game::game(Point xy, int w, int h, const string& title,int diff)
    :Window{xy,w,h,title}
{
    num_pan = diff;
    Ellipse e1{Point{50,200},20,20};
    attach(e1);
    
}
void game::draw_pan()
{
    Ellipse e1{Point{50,200},20,20};
    attach(e1);
    
}
