
#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"

using namespace Graph_lib;
using namespace std;

struct game: Graph_lib::Window
{
    game(Point xy, int w, int h, const string& title,int diff);
    void draw_pan();
    
private:
    int num_pan;
    Text* title_label;
    int width;
    const int height = 20;
    
    
    
    
    
    
};