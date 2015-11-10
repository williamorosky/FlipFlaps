
#include "Graph.h"        // get access to our graphics library facilities
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title );
    
private:
    Button button_x1;
    Button button1;
    Circle lightbulb;
    
    Button quit_button;
    Text title;
    static void cb_off(Address, Address);
    void off();
    static void cb_on(Address, Address);
    void on();
    static void cb_quit(Address, Address);
    void quit();
};

//------------------------------------------------------------------------------

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
:Window(xy,w,h,title),
<<<<<<< Updated upstream
button_x1(Point(50,149), 100, 30, "Off", cb_off),
button1(Point(50,150), 100, 30, "On", cb_on),
=======
button_x1(Point(50,150), 100, 30, "Off", cb_off),
button1(Point(50,150), 200, 30, "On", cb_on),
>>>>>>> Stashed changes
lightbulb(Point(100,100),50),
quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit),
title(Point(300,300),"Flip Flaps");

{
    lightbulb.set_fill_color(Color::black);
    attach(button1);
    attach(lightbulb);
    attach(quit_button);
    attach(title);
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

void Lines_window::cb_off(Address, Address pw)     // "the usual"
{
    reference_to<Lines_window>(pw).off();
}

//------------------------------------------------------------------------------

void Lines_window::off()
{
    detach(button_x1);
    attach(button1);
    lightbulb.set_fill_color(Color::black);
    (Fl::wait ());
    (Fl::flush ());
    redraw();
}

//------------------------------------------------------------------------------


void Lines_window::cb_on(Address, Address pw)     // "the usual"
{
    reference_to<Lines_window>(pw).on();
}

//------------------------------------------------------------------------------

void Lines_window::on()
{
    detach(button1);
    attach(button_x1);
    lightbulb.set_fill_color(Color::white);
    (Fl::wait ());
    (Fl::flush ());
    redraw();
}

int main()
try
{
    Lines_window win(Point(100,100),600,600,"Lightbulb");
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