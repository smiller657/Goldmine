//Samantha Miller
//CPSC-340-01
//Header file for the Object of a 6 by 6 table, filed with Box objects,
//hidden until the user interacts with the game.
#ifndef GOLDMINECPP
#define GOLDMINECPP
#include <string>
#include "GoldMine.h"
#include "Box.h"
#include "dynamicList.h"

using namespace std;

GoldMine::GoldMine()
{
	//create an array of boxes
	//for each row of the goldmine, create an array with 6 boxes
	for (int i = 0; i < 6; i++) {
		dynamicList<Box> boxList(6);
		Box temp = Box();
		boxList.init(temp);
		gm[i] = boxList;
	}
	gold = 0;
}
/*
void GoldMine::randomRowColumn(int &row, int &column)
{

}
void GoldMine::setMyBox(char c)
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
			Box box = gm[i].getItem[j]; 
			cout<<box.getCharacter()<<"\t";
		}
		cout<<endl;
	}
}

int GoldMine::getGold()
{
	return gold;
}
#endif	
//	For reference: private:
//dynamicList<Box> gm[6];
//int gold;
