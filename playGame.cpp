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

	//Initialize game variables.
	GoldMine gm = GoldMine();
	bool solved, goodRow, goodCol;
	int row, column;
	char playAgain = 'y';
	
	cout<<"Welcome to the Goldmine Game!"<<endl;
	cout<<"Enter a row and column to find the gold in the mine."<<endl;
	cout<<"If you're not careful, you'll find coal and lose all the gold!"<<endl;
	cout<<endl;

	//Begin game loop
	while (playAgain == 'y') {
		solved = false;
		row = -1;
		column = -1;
		goodRow = false;
		goodCol = false;

		gm.printGoldMine();

		//for each turn of the current game
		while (!solved && gm.getGold() > 0) {
			while (!goodRow) {
				cout<<"Enter a row: ";
				while (cin.peek() >= '0' && cin.peek() <= '5') {
					cin>>row;
				}
				if (row >= 0 && row <= 5) {
					goodRow = true;	
				} else {
					cout<<"Your guess did not fall between 0 and 5. Try again."<<endl;
				}
				cin.ignore(80, '\n');
			}
			while (!goodCol) {
				cout<<"Enter a column: ";
				while (cin.peek() >= '0' && cin.peek() <= '5') {
					cin>>column;
				}
				if (column >= 0 && column <= 5) {
					goodCol = true;	
				} else {
					cout<<"Your guess did not fall between 0 and 5. Try again."<<endl;
				}
				cin.ignore(80, '\n');
			}
			cout<<endl;

			//Print status
			if (row >= 0 && row <= 5 && column >=0 && column <= 5) {
				Box thisTurn = gm.getBox(row, column);
				if (thisTurn.getVisited()) {
					cout<<"Pay attention! You've been here before! Try again."<<endl;
				} else {
					//update the goldmine
					gm.revealSelection(row, column);
					//subtract the gold from the totoal
					char currentChar = thisTurn.getCharacter();
					if (currentChar == 'C') {
						cout<<"Oh no! You found the coal!  You have lost."<<endl;
					} else if (currentChar == 'R') {
						string message = gm.rainbowMessage();
						cout<<message<<endl;
						cout<<"You lost "<<thisTurn.getGoldLost()<<" gold."<<endl;
					} else if (currentChar == 'G') {
						solved = true;
						cout<<"Congratulations! You found the gold!"<<endl;
					} else { //currentChar = 'N'
						cout<<"Keep looking!"<<endl;
						cout<<"You lost "<<thisTurn.getGoldLost()<<" gold."<<endl;
					}
					cout<<endl;
				}

			} else {
				cout<<"Your parameters are not correct. Try again."<<endl;
			}
			cout<<endl;

			//reset values for next turn
			goodRow = false;
			goodCol = false;
			row = -1;
			column = -1;
		} //while solved
		if (solved) {
			cout<<"The pot of gold has "<<gm.getGold()<<" gold."<<endl;
		} else {
			cout<<"You have lost all the gold. Better luck next time!"<<endl;
		}
		cout<<"Do you want to look for more gold (y or n)? ";
		cin.get(playAgain);
		cin.ignore(80, '\n');
		if (playAgain != 'y' && playAgain != 'n') {
			cout<<"That character was invalid. Clearly you want to look for more gold."<<endl;
			playAgain = 'y';
		}
		if (playAgain == 'y') {
			gm.initialize();
		}
	} //while playAgain == 'y'
	return 0;
}
