
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
    Text title_text;
	Text names_text;
	Closed_polyline x1;
	Closed_polyline x1h1;
	Closed_polyline x1h2;
	Closed_polyline x1h3;
	Closed_polyline x2;
	Closed_polyline x2h1;
	Closed_polyline x2h2;
	Closed_polyline x2h3;
	Rectangle background;
	
    static void cb_next(Address, Address);
    void next();

    static void cb_quit(Address, Address);
    void quit();
};

//------------------------------------------------------------------------------

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
:Window(xy,w,h,title),
next_button(Point((x_max()/2)-50,200), 100, 30, "Next", cb_next),
quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit),
background(Point(200,50),420,120),
title_text(Point((x_max()/2)-165,100), "Flip Flaps"),
names_text(Point((x_max()/2)-180,140), "William O'Rosky, Akshay Jagadeesh, and Tyler Nardecchia")
{
	background.set_fill_color(Color{7});
	title_text.set_font_size(50);
	title_text.set_font(Graph_lib::Font::courier_bold);
	
	x1.add(Point(265,550));
	x1.add(Point(515,350));
	x1.add(Point(495,320));
	x1.add(Point(555,265));
	x1.add(Point(605,340));
	x1.add(Point(545,395));
	x1.add(Point(525,365));
	x1.add(Point(275,565));
	
	x1h1.add(Point(505,320));
	x1h1.add(Point(555,275));
	x1h1.add(Point(565,290));
	x1h1.add(Point(515,335));
	
	x1h2.add(Point(520,343));
	x1h2.add(Point(570,298));
	x1h2.add(Point(580,313));
	x1h2.add(Point(530,358));
	
	x1h3.add(Point(535,366));
	x1h3.add(Point(585,321));
	x1h3.add(Point(595,336));
	x1h3.add(Point(545,381));
	
	x2.add(Point(515,550));
	x2.add(Point(265,350));
	x2.add(Point(285,320));
	x2.add(Point(225,265));
	x2.add(Point(175,340));
	x2.add(Point(235,395));
	x2.add(Point(255,365));
	x2.add(Point(505,565));
	
	x2h1.add(Point(275,320));
	x2h1.add(Point(225,275));
	x2h1.add(Point(215,290));
	x2h1.add(Point(265,335));
	
	x2h2.add(Point(260,343));
	x2h2.add(Point(210,298));
	x2h2.add(Point(200,313));
	x2h2.add(Point(250,358));
	
	x2h3.add(Point(245,366));
	x2h3.add(Point(195,321));
	x2h3.add(Point(185,336));
	x2h3.add(Point(235,381));
	
	Fl_Color old_color = fl_color();
	fl_color(80,0,0);	
	
	x1.set_fill_color(Color{30});
	x1h1.set_fill_color(fl_color());
	x1h2.set_fill_color(fl_color());
	x1h3.set_fill_color(fl_color());
	x2.set_fill_color(Color{30});
	x2h1.set_fill_color(fl_color());
	x2h2.set_fill_color(fl_color());
	x2h3.set_fill_color(fl_color());
	
	color(fl_color());
	fl_color(old_color);

    attach(next_button);
    attach(quit_button);
	attach(background);
	attach(title_text);
	attach(names_text);
	attach(x1);
	attach(x1h1);
	attach(x1h2);
	attach(x1h3);
	attach(x2);
	attach(x2h1);
	attach(x2h2);
	attach(x2h3);

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
    detach(names_text);
	detach(x1);
	detach(x2);
	detach(x1h1);
	detach(x1h2);
	detach(x1h3);
	detach(x2h1);
	detach(x2h2);
	detach(x2h3);
	detach(background);//_____________________________________________________________________________________here
  //  attach(button1);
	title_text.set_label("Rules");
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