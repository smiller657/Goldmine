# Goldmine

Class: CPSC-340-01: Data Structures in C++
Due: 10/25/2016

Assignment:
Using a two dimensional array, create a 6 by 6 grid that represents a gold mine.  The grid consists of an array of dynamic lists which hold Boxes that contain a character, the gold lost if the box is selected, and a boolean which determines if the box has been visited. The grid also maintains a random gold count for the total of gold to be found.

The program asks the user for a row and column set to check the grid for 
 - G(old), meaning the game is won.
 - R(ainbow), which prints a hint as to where the gold is located.
 - C(oal), which automatically loses the game.

 If the user runs out of gold or finds gold, the game ends. The user may play multiple rounds of the game.
