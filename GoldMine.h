//Samantha Miller
//CPSC-340-01
//Header file for the oObject of a 6 by 6 table, filed with Box objects,
//hidden until the user interacts with the game.
#ifndef GOLDMINEH
#define GOLDMINEH
#include "dynamicList.h"
#include "Box.h"

class GoldMine
{
	public:
		GoldMine();
		void randomRowColumn(int &row, int &column);
		void setRainbow();
		void setGold();
		void setCoal();
		string rainbowMessage();
		void revealSelection(int row, int column);
		void printGoldMine();
		int getGold();
		Box getBox(int row, int column);
		void initialize();
	private:
		dynamicList<Box> gm[6];
		int gold;
};
#endif
