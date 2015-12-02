//Team H08: William  O'Rosky, Akshay Jagadeesh, Tyler Nardecchia
//CSCE 121-509 
//Due: December 2, 2015
//Stack.h

#include "Pancake.h"

class Stack
{
	vector<Pancake> stack;
	
	public:
	
		void create_stack(int num_pancakes);
		void add(Pancake p);
		void flip(int n);
		int size();
		Pancake get(int n);
		vector<Pancake> get_stack();
};