//Samantha Miller
//CPSC-340-01
//Lab 6: Convert DynamicList to a template class.
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
    dynamicList();		
//    dynamicList(int maxnumber);
    ~dynamicList();   	
    bool Full() const;
    bool Empty() const;
	void Getlast(ITEMTYPE &item, bool &found);
	bool Insert(ITEMTYPE item);
	bool Insert(ITEMTYPE item, int location);
	bool Replace(ITEMTYPE item, int location);
	void Remove(ITEMTYPE &item, bool &found);
	void Remove(ITEMTYPE &item, bool &found, int location);
	bool Search(ITEMTYPE item, int &location);
	bool Search(ITEMTYPE item);
    void Clear();
    void Print() const;
    int currentSize() const;
	void init(ITEMTYPE initValue);
	ITEMTYPE getItem(int index);
private:
	ITEMTYPE *element;
    int length;
    int size;
};

#include "dynamicList.cpp"
#endif
