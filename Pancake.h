//Team H08: William  O'Rosky, Akshay Jagadeesh, Tyler Nardecchia
//CSCE 121-509 
//Due: December 2, 2015
//Pancake.h

#include "std_lib_facilities_4.h"

class Pancake
{
	int w;
	
	//constructors
	public:
	
		Pancake(int ww)
		{
			w = {ww};
		}
		void set_width(int ww)
		{
			w = ww;
		}
		int get_width()
		{
			return w;
		}
};