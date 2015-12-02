//Team H08: William  O'Rosky, Akshay Jagadeesh, Tyler Nardecchia
//CSCE 121-509 
//Due: December 2, 2015
//Stack.cpp

#include "Stack.h"

//creates the stack of pancakes from 1 to the size of the stack
//and then shuffles the stack
void Stack::create_stack(int num_pancakes)
{
	for (int i = 1; i <= num_pancakes; ++i)
	{
		Pancake p{i};
		add(p);
	}
	unsigned seed = time(NULL);
	if(num_pancakes != 2)
		shuffle(stack.begin(), stack.end(), std::default_random_engine(seed));
}

//adds a pancake to the stack
void Stack::add(Pancake p)
{
	stack.push_back(p);
}

//flips the stack from the selected pancake to the top
//using iterators moving up and down the stack which
//swap the pancakes until the iterators are at the same place
void Stack::flip(int n)
{
	if(n > stack.size())
		error("flip size greater than number of pancakes");
	else
	{
		
		int d = stack.size()-1-n;
        for(int start = stack.size()-1;start>0;start--)
        {
            if (start <= d)
                return;
            else
            {
                Pancake temp = stack[d];
                stack[d] = stack[start];
                stack[start] = temp;
                d++;
            }
        }
	}
}

//returns the size of the stack
int Stack::size()
{
	return stack.size();
}

//returns a specific pancake in the stack
Pancake Stack::get(int n)
{
	return stack[n];
}

//returns the entires Stack object
vector<Pancake> Stack::get_stack()
{
	return stack;
}