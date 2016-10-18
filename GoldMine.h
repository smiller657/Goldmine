class GoldMine
{
	public:
		GoldMine();
		void randomRownColumn(int &row, int &column);
		void setMyBox(char c);
		void setRainbow();
		void setGold();
		void setCoal();
		string rainbowMessage();
		void revealSelection(int row, int column);
		void printGoldMine();
		int getGold();
	private:
		dynamicList<Box> gm[6];
		int gold;
};
