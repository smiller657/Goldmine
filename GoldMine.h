//Samantha Miller
//CPSC-340-01
//Header file for the Object of a 6 by 6 table, filed with Box objects,
//hidden until the user interacts with the game.
#ifndef GOLDMINEH
#define GOLDMINEH
#include "dynamicList.h"
#include "Box.h"

class GoldMine
{
	public:
		//Des: Constructs an instance of the gold mine.
		//Input: None.
		//Output: None, but generates the instance of the 6x6 grid
		//populated Boxes, ready to be discovered.
		GoldMine();

		//Des: Generates a random row and random column in the gold mine.
		//Input: Integers row and column, pass by reference.
		//Output: None, except the randomly selected row and column, passed by reference.
		void randomRowColumn(int &row, int &column);

		//Des: Denotes a random box with the 'R' rainbow character and sets that box's gold to 0.
		//Input: None.
		//Output: None, but updates the grid with a rainbow box.
		void setRainbow();

		//Des: Denotes a random box with the 'G' gold character and sets that box's gold to 0.
		//Input: None.
		//Output: None, but updates the grid with a gold box.
		
		void setGold();

		//Des: Denotes a random box with the 'C' coal character and sets that box's gold to 0.
		//Input: None.
		//Output: None, but updates the grid with a coal box.
		void setCoal();

		//Des: Finds the gold box in the gold mine and generates a string
		//with a specific quadrant in which we can look for the gold.
		//Input: None.
		//Output: A string with the gold's general location, by quadrant of the gold mine.
		string rainbowMessage();

		//Des: Checks to see if the box has been visited
		//otherwise updates the gold lost that turn, checks if coal has been found
		//updates the visited status of the box, and prints the gold mine again.
		//Input: A row and column integers for the user's choice to check this turn.
		//Output: None, but updates the goldmine, and prints the result of the selection to screen.
		void revealSelection(int row, int column);

		//Des: Prints the total of the gold in the mine,
		//and the grid, with tabs, and the a character representing the contents of each box.
		//Input: None.
		//Output: None, but prints:
		//* if unvisited, - if visited and nothing is there, C for coal,
		//G for gold, and R for rainbow.
		void printGoldMine();

		//Des: Returns the amount of the private gold variable.
		//Input: None.
		//Output: An integer for the amount of gold in the mine.
		int getGold();
		
		//Des: Returns the Box by location.
		//Input: Integers for the row and column of the box.
		//Output: The Box in that location.
		Box getBox(int row, int column);
		
		//Des: Initializes the goldmine with a random amount of gold,
		//the Boxes in the mine with random amounts to lose,
		//and sets the rainbow, gold, and coal.
		//Input: None.
		//Output: None, but initializes the gold mine.
		void initialize();
	private:
		dynamicList<Box> gm[6]; //creates the array of boxes
		int gold; //holds the initial amount of gold 1000 - 9000
};
#endif
