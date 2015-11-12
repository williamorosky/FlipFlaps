
#include "Graph.h"        // get access to our graphics library facilities
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title );
    
private:
    Button next_button;
    Button quit_button;
    Text title_Text;
	
    static void cb_next(Address, Address);
    void next();

    static void cb_quit(Address, Address);
    void quit();
};

//------------------------------------------------------------------------------

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
:Window(xy,w,h,title),
next_button(Point(50,150), 100, 30, "next", cb_next),
quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit),
title_Text(Point((x_max()/2)-20,30), "Flip Flaps")
{
	title_Text.set_color(Color::black);
    attach(next_button);
    attach(quit_button);
	attach(title_Text);
}

//------------------------------------------------------------------------------

void Lines_window::cb_quit(Address, Address pw)    // "the usual"

{
    reference_to<Lines_window>(pw).quit();
}

//------------------------------------------------------------------------------

void Lines_window::quit()

{

    hide();        // curious FLTK idiom for delete window

}

//------------------------------------------------------------------------------

void Lines_window::cb_next(Address, Address pw)     // "the usual"

{

    reference_to<Lines_window>(pw).next();

}

//------------------------------------------------------------------------------

void Lines_window::next()

{
    //detach(button_x1);
  //  attach(button1);
	title_Text.set_label("Rules");
    (Fl::wait ());
    (Fl::flush ());
    redraw();
}

//------------------------------------------------------------------------------

int main()
try
{
    Lines_window win(Point(100,100),800,600,"Flip Flaps");
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