//Samantha Miller
//CPSC-340-01
//Goldmine Project
// File dynamicList.h: Header file for Unsorted List ADT.
#ifndef DYNAMICLISTH
#define DYNAMICLISTH
#include <iostream>
#include <string>
using namespace std;

const int defmaxlistsize=50;

template <class ITEMTYPE>
class dynamicList   
{
public:
    //Des: Constructs an instance of the dynamic list.
	//Input: None.
	//Output: An instance of the dynamic list with the default size.
	dynamicList();		

	//Des: Constructs an instance of the dymanic list with a given maximum size.
	//Commented out for prosperity, but good for other applications of the list.
	//Input: An integer for the largest the list should be.
	//Output: An instance of the dymanic list with a given size.
	//dynamicList(int maxnumber);
   
	//Des: Deconstructor for the dynamic list.
	//Input: None, although a list should be preexisting to deconstruct it.
	//Output: Deallocated memory returned to the CPU.
	~dynamicList();   	
    
	//Des: Checks if the list is full.
	//Input: None.
	//Output: True if the array has the same length as it does size.
	//False if length is less than size.
	bool Full() const;
    
	//Des: Checks if the list is empty.
	//Input: None.
	//Output: True if length is 0. False if length is greater than 0.
	bool Empty() const;
	
	//Des: Returns the last item in the list, if it exists.
	//Input: Pass by reference for the last item in the list and a boolean if the item exists.
	//Output: None, but the input items passed by reference.
	void Getlast(ITEMTYPE &item, bool &found);
	
	//Des: Append a given item to the end of the list.
	//Input: An item to insert of the list type.
	//Output: True if successfully inserted, false if list is full and insert failed.
	bool Insert(ITEMTYPE item);
	
	//Des: Add a given item at a specified location in the list.
	//Input: An item of list type and an integer for the index in the list.
	//Output: True if successfully inserted, false if failed.
	//If failed, list is full or location is out of bounds.
	bool Insert(ITEMTYPE item, int location);
	
	//Des: Swap an existing item with a given item of a specified location.
	//Input: An item to place in the list and the index of placement.
	//Output: True if successfully replaced, or false if location is out of bounds.
	bool Replace(ITEMTYPE item, int location);
	
	//Des: Removes an item from the list.
	//Input: An item to be removed and a boolean, true if remove is successful.
	//These parameters are pass-by-reference.
	//Output: None, but the PBR inputs.
	void Remove(ITEMTYPE &item, bool &found);
	
	//Des: Removes the item from a specified location.
	//Input: A pass-by-ref item that has been removed from the list,
	//a boolean if the remove was sucessful, and an index of the list to remove.
	//Output: None, but the PBR inputs.
	void Remove(ITEMTYPE &item, bool &found, int location);
	
	//Des: Searches for an item in the list, returning the location and if found.
	//Input: An item of the implemented type of the list, and an integer for the index in the list.
	//Location is pass by reference.
	//Output: True if found, false if not, as well as the pass-by-ref location.
	bool Search(ITEMTYPE item, int &location);
	
	//Des: Searches for a given item in the list.
	//Input: An item of the implemented type of the list.
	//Output: A boolean if found, true for found, false if not.
	bool Search(ITEMTYPE item);
	
	//Des: Clears the array list without deconstructing the list.
	//Input: None.
	//Output: None, but resets the object to length of 0.
	void Clear();
    
	//Des: Prints "Location i = element[i]" for each element in the list, 
	//where i is the index to the length. 
	//Input: None.
	//Output: None, but prints the contents of the array to the screen, unless overriden.
	void Print() const;
    
	//Des: Returns the length of the list.
	//Input: None.
	//Output: An integer for the length, not size, of the array.
	int currentSize() const;
	
	//Des: Initializes the array with a given "blank" object.
	//Input: An object that the user recognizes as "blank" or default of the list type.
	//Output: None, but "cleans" array by setting each element to a default object.
	void init(ITEMTYPE initValue);
	
	//Des: Returns an element in the array given a valid index.
	//Input: An integer for the location in the list.
	//Output: THe element in the list.
	ITEMTYPE getItem(int index);
private:
	ITEMTYPE *element; //The array.
    int length; //The current length of the array.
    int size; //The maximum size of the array.
};

#include "dynamicList.cpp"
#endif
