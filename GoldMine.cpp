//Samantha Miller
//CPSC-340-01
//Header file for the Object of a 6 by 6 table, filed with Box objects,
//hidden until the user interacts with the game.
#ifndef GOLDMINECPP
#define GOLDMINECPP
#include <string>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <iostream>
#include "dynamicList.h"
#include "Box.h"
#include "GoldMine.h"

using namespace std;

GoldMine::GoldMine()
{
	gold = 0;
	Box temp;
	for (int i = 0; i < 6; i++) {
		gm[i].init(temp);	
	}
	//See the number generator
	srand(time(0)%INT_MAX);
	initialize();
}
/*
void GoldMine::randomRowColumn(int &row, int &column)
{

}

void GoldMine::setRainbow()
{

}

void GoldMine::setGold()
{

}

void GoldMine::setCoal()
{

}

string GoldMine::rainbowMessage()
{

}

void GoldMine::revealSelection(int row, int column)
{

}*/
void GoldMine::printGoldMine()
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			Box box = gm[i].getItem(j); 
			cout<<box.getCharacter()<<"\t";
		}
		cout<<endl;
	}
}

int GoldMine::getGold()
{
	return gold;
}

void GoldMine::initialize()
{
	//Set total gold for game
	gold = rand()%9000 + 1000;
	//Iniitalize a box
	Box temp;
	int amount = 0;
	bool success = true;
	//Create a grid of boxes
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			amount = rand()%100 + 10;
			temp.setGoldLost(amount);
			success = gm[i].Insert(temp, j);
			if (!success) {
				cout<<"Could not add box "<<i<<" "<<j<<" to grid."<<endl;
			}

		}
	}
}
#endif	
//	For reference: private:
//dynamicList<Box> gm[6];
///int gold;
