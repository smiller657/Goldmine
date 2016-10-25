//Samantha Miller
//CPSC-340-01
//Implementation file for the Object of a 6 by 6 table, filed with Box objects,
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
	gold = 10000;
	Box temp;
	for (int i = 0; i < 6; i++) {
		gm[i].init(temp);	
	}
	//See the number generator
	srand(time(0)%INT_MAX);
	initialize();
}

void GoldMine::randomRowColumn(int &row, int &column)
{
	row = rand()%6;
	column = rand()%6;
}

void GoldMine::setRainbow()
{
	int row = -1;
	int column = -1;
	bool set = false;
	while (!set) {
		randomRowColumn(row, column);
		Box box = gm[row].getItem(column);
		char letter = box.getCharacter();
		if (letter == 'N') {
			box.setCharacter('R');
			box.setGoldLost(0);
			set = gm[row].Replace(box, column);	
		}
	}
}

void GoldMine::setGold()
{
	int row = -1;
	int column = -1;
	bool set = false;
	while (!set) {
		randomRowColumn(row, column);
		Box box = gm[row].getItem(column);
		char letter = box.getCharacter();
		if (letter == 'N') {
			box.setCharacter('G');
			box.setGoldLost(0);
			set = gm[row].Replace(box, column);	
		}
	}
}

void GoldMine::setCoal()
{
	int row = -1;
	int column = -1;
	bool set = false;
	while (!set) {
		randomRowColumn(row, column);
		Box box = gm[row].getItem(column);
		char letter = box.getCharacter();
		if (letter == 'N') {
			box.setCharacter('C');
			box.setGoldLost(0);
			set = gm[row].Replace(box, column);	
		}
	}
}

string GoldMine::rainbowMessage()
{
	string message = "";
	int row = -1;
	int column = -1;
	//find the rainbow
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			Box box = gm[i].getItem(j); 
			if (box.getCharacter() == 'G') {
				row = i;
				column = j;
			}
		}
	}
	//Determine the quadrant
	if (row >= 0 && row < 3 && column >=0 && column < 3) {
		message = "It is said the gold is in the northwest quadrant.";
	} else if (row >= 3 && row <= 5 && column >= 0 && column < 3) {
		message = "A bird told me the gold is in the southwest quadrant.";
	} else if (row >= 3 && row <= 5 && column >= 3 && column <= 5) {
		message = "The winds say the gold is in the southeast quadrant.";
	} else {
		message = "The rainbow ends in the northeast quadrant.";
	}
	return message;
}

void GoldMine::revealSelection(int row, int column)
{
	//Print status
	if (row >= 0 && row <= 5 && column >=0 && column <= 5) {
		Box current = gm[row].getItem(column);
		if (current.getVisited()) {
			cout<<"This box has already been revealed! Try again."<<endl;
		} else {
			//subtract the gold from the totoal
			gold -= current.getGoldLost();
			if (current.getCharacter() == 'C') {
				gold = -1;
			}
			current.setVisited(true);
			gm[row].Replace(current, column);
			printGoldMine();
		}
	} else {
		cout<<"Your parameters are not correct. Try again."<<endl;
	}
}

void GoldMine::printGoldMine()
{
	if (gold >= 0) {
		cout<<"Gold Total: "<<gold<<endl;
	} else { //don't print negatives
		cout<<"Gold Total: 0"<<endl;
	}
	cout<<"\t0\t1\t2\t3\t4\t5\t"<<endl;
	
	for (int i = 0; i < 6; i++) {
		cout<<i<<"\t";
		for (int j = 0; j < 6; j++) {
			Box box = gm[i].getItem(j); 
			if (box.getVisited()) {
				char letter = box.getCharacter();
				if (letter == 'N') {
					cout<<"-\t";
				} else {
					cout<<letter<<"\t";
				}
			} else {
				cout<<"*\t";
			}
		}
		cout<<endl;
	}
}

int GoldMine::getGold()
{
	return gold;
}

Box GoldMine::getBox(int row, int column) {
	if (row >= 0 && row <= 5 && column >=0 && column <= 5) {
		Box box = gm[row].getItem(column);
		return box;
	} else {
		cout<<"Box requested is out of bounds."<<endl;
	}
}

void GoldMine::initialize()
{
	//Set total gold for game
	gold = rand()%8000 + 1000;
	//Iniitalize a box
	Box temp;
	int amount = 0;
	bool success = true;
	//Create a grid of boxes
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			amount = rand()%90 + 10;
			temp.setGoldLost(amount);
			success = gm[i].Insert(temp, j);
			if (!success) {
				cout<<"Could not add box "<<i<<" "<<j<<" to grid."<<endl;
			}

		}
	}
	setRainbow();
	setGold();
	setCoal();
}
#endif	
//	For reference: private:
//dynamicList<Box> gm[6];
///int gold;
