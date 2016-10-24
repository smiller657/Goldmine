//Smaantha Miller
//CPSC-340-01
//Goldmine Project: This file contains the main function and controls the 
//workflow of the game.

#include <iostream>
#include <string>
#include "GoldMine.h"

using namespace std;

//The program that runs the user interface to interface with the goldmine.
//No inputs.  Output returns 0 if no errors.
int main() {

	//Seed the number generator
	//srand(time(0)%INT_MAX);
	
	GoldMine gm = GoldMine();
	gm.setRainbow();
	gm.setGold();
	gm.setCoal();
	gm.printGoldMine();
	return 0;
}
