//Samantha Miller
//CPSC-340-01
//Header file for the class that constructs a cell of the goldmine.
#ifndef BOXCPP
#define BOXCPP
#include "Box.h"

using namespace std;

Box::Box()
{
	character = 'N';
	goldLost = 0;
	selected = false;
}

bool Box::getVisited() const
{
	return selected;
}

void Box::setVisited(bool visited)
{
	selected = visited;
}

int Box::getGoldLost() const
{
	return goldLost;
}

void Box::setGoldLost(int amount)
{
	goldLost = amount;
}

char Box::getCharacter() const
{
	return character;
}

void Box::setCharacter(char special)
{
	character = special;
}

#endif
//Private variables for reference:
//char character; //(N)othing, (C)oal, (G)old, (R)ainbow
//int goldLost; //holds the amount of gold lost
//bool selected; //determines if the box has been selected
