//Samantha Miller
//CPSC-340-01
//Header file for the class that constructs a cell of the goldmine.
#ifndef BOXH
#define BOXH

class Box
{
	public:
		
		//Des: Constructor for a Box object.
		//Input: None
		//Output: None, but a Box is constructed.
		Box();

		//Des: Returns object's selected status.
		//Input: None.
		//Output: True if the user has opened the box. False if they have not.
		bool getVisited() const;

		//Des: Changes the selected status.
		//Input: True if user opens the box. False if they have not.
		//Output: None.
		void setVisited(bool visited);
		
		//Des: Returns the object's goldLost amount.
		//Input: None.
		//Output: The amount of gold lost for opening that box.
		int getGoldLost() const;

		//Des: Changes the value of the goldLost for the box.
		//Input: An integer value of the amount of gold to lose.
		//Output: None.
		void setGoldLost(int amount);
		
		//Des: Returns the character denoting the item of the box.
		//Input: None.
		//Output: The character denoting Nothing, Coal, Rainbow, or Gold.
		char getCharacter() const;
		void setCharacter(char special);
	private:
		char character; //(N)othing, (C)oal, (G)old, (R)ainbow
		int goldLost; //holds the amount of gold lost
		bool selected; //determines if the box has been selected
};
#endif
