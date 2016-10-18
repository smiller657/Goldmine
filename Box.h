class Box
{
	public:
		Box();
		bool getVisited() const;
		void setVisited(bool visited);
		int getGoldLost() const;
		void setGoldLost(int amount);
		char getCharacter() const;
		void setCharacter(char special);
	private:
		char character; //(N)othing, (C)oal, (G)old, (R)ainbow
		int goldLost; //holds the amount of gold lost
		bool selected; //determines if the box has been selected
};
