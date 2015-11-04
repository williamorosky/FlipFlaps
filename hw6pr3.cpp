//William O'Rosky
//CSCE 121-509
//Due: Ocotber 27, 2015
//hw6pr3.cpp 

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

struct Scandinavian_flag:Rectangle
{

Scandinavian_flag(Point p,Color background, Color cross, string name);
 void draw_lines() const;

  /*  void move(int dx, int dy);
    void set_color(Color c);
    void set_style(Line_style ls);
    void set_radius(int rr);*/

private:
    Rectangle cross1;
    Rectangle cross2;
	Text name_Text;
  
};
Scandinavian_flag::Scandinavian_flag(Point p,Color background, Color cross, string name)
:Rectangle(p,200,100),cross1(Point((p.x+60),p.y),30,100),cross2(Point(p.x,(p.y+35)),200,30),name_Text(Point((p.x+90),p.y+110),name)	
{		
	Shape::set_fill_color(background);
	cross1.set_fill_color(cross);
	cross2.set_fill_color(cross);
}
void Scandinavian_flag::draw_lines() const
{
    Rectangle::draw_lines();
    if (color().visibility()) 
	{
        cross1.draw();
        cross2.draw();
		name_Text.draw();
    }
}

int main()
try 
{
	Simple_window win1(Point(50,50),800,600,"God Hates Flags");
	Scandinavian_flag Denmark(Point(20,20),Color::red,Color::white,"Denmark");
	Scandinavian_flag Sweden(Point(20,150),Color::blue,Color::yellow,"Sweden");
	Scandinavian_flag Finland(Point(20,280),Color::white,Color::blue,"Finland");
	win1.attach(Denmark);
	win1.attach(Sweden);
	win1.attach(Finland);
	win1.wait_for_button();
	return 0;
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
