//Samantha Miller
//CPSC-340-01
//Lab 6: Convert DynamicList to a template class.
// Implementation file for Unsorted List ADT.
#ifndef DYNAMICLISTCPP
#define DYNAMICLISTCPP
#include <iostream>
#include "dynamicList.h"

template <class ITEMTYPE>
dynamicList<ITEMTYPE>::dynamicList()		// Class constructor
{
	length = 0;
	size = defmaxlistsize;
	element = new ITEMTYPE[defmaxlistsize];
	//for (int i = 0; i < defmaxlistsize; i++)
	//	element[i] = 0;
}

/*template <class ITEMTYPE>
dynamicList<ITEMTYPE>::dynamicList(int maxnumber = defmaxlistsize)		// Class constructor
{
	length = 0;
	size = maxnumber;
	element = new ITEMTYPE[maxnumber];
	//for (int i = 0; i < maxnumber; i++)
	//	element[i] = 0;
}*/

template <class ITEMTYPE>
dynamicList<ITEMTYPE>::~dynamicList()
// Post: List is empty; all items have been deallocated.
{
	delete[] element;
	length = 0;
}

template <class ITEMTYPE>
void dynamicList<ITEMTYPE>::Print() const
{
	for (int i = 0; i < length; i++)
	{
		cout << "\tLocation " << i << " = " << element[i] << endl;

	}
}

template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Full() const
// Returns true if there is no room for another int on the free store;
// false otherwise.
{
	if (length == size){
		return true;
	}
	else
		return false;
}


template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Empty() const
// Post: List is empty; all items have been deallocated.
{
	if (length == 0)
		return true;
	else
		return false;
}

template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Search(ITEMTYPE item)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the list and 
//       a copy of that element has been stored in item; otherwise, item is
//       unchanged. 
{
	bool moreToSearch;
	int location = 0;


	moreToSearch = true;

	while ((moreToSearch) && (location < size))
	{
		if (item == element[location])
		{
			return true;
		}
		else
		{
			location++;
		}
	}
	return false;
}

template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Search(ITEMTYPE item, int &location)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the list and 
//       a copy of that element has been stored in item; otherwise, item is
//       unchanged. 
{
	bool moreToSearch;
	location = 0;

	moreToSearch = true;

	while ((moreToSearch) && (location < size))
	{
		if (item == element[location])
		{
			return true;
		}
		else
		{
			location++;
		}
	}
	return false;
}

template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Insert(ITEMTYPE item)
// item is in the list; length has been incremented.
{

	if (!Full())
	{
		element[length] = item;
		length++;
		return true;
	}
	else
	{
		cout << "Error: Cannot Insert.  List is Full.\n";
		return false;
	}

}

template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Insert(ITEMTYPE item, int location)
// item is in the list; length has been incremented.
{

	if (!Full())
	{
		if (location >= 0 && location < size && !Full())
		{
			if (location > length)
			{
				//Used for static int DynamicList.
				//Kept for reference/testing.
				//for (int i = length; i < location; i++)
				//element[i] = -1;
				length = location + 1;
			}
			else
				length++;
			for (int i = length; i > location; i--){
				element[i] = element[i-1];
			}
			element[location] = item;
			return true;
		}
		cout << "Error: Cannot Insert at " << location << " that is out of bounds\n";
	}
	else
	{
//		cout << "Error: Cannot Insert "<<item<<" List is Full.\n";
		return false;
	}
}

template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Replace(ITEMTYPE item, int location)
// item is in the list; length has been incremented.
{

	if (!Full())
	{
		if (location >= 0 && location < length && !Full())
		{
			element[location] = item;
			return true;
		}
		cout << "Error: Cannot Insert at " << location << " that is out of bounds\n";
	}
	else
	{
		return false;
	}
}

template <class ITEMTYPE>
void dynamicList<ITEMTYPE>::Remove(ITEMTYPE &item, bool &found, int location)
// Pre: item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
	// Locate node to be deleted.
	if (!Empty())
	{
		if (location > 0 && location < length)
		{
			item = element[location];
			for (int i = location; i < length; i++)
			{
				element[i] = element[i + 1];
			}
			length--;
			found = true;
			return ;
		}else{
			cout << "Error: Location "<<location<<" is not a valid location at this time.\n";
			found = false;
			return;
		}
	}
	else
	{
		cout << "Error: List is Empty.  Cannot Delete.\n";
		found = false;
	}
}

template <class ITEMTYPE>
void dynamicList<ITEMTYPE>::Remove(ITEMTYPE &item, bool &found)
// Pre: item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
	// Locate node to be deleted.
	if (!Empty())
	{
		int location = -1;
		if (Search(item, location))
		{
			item = element[location];
			for (int i = location; i < length; i++)
			{
				element[i] = element[i + 1];
			}
			length--;
			found = true;
			return;
		} else {
//			cout << "Error: "<<item<<" Not Found\n";
			found = false;
			return;
		}
	}
	else
	{
		cout << "Error: List is Empty.  Cannot Delete.\n";
		found = false;
	}

}

template <class ITEMTYPE>
int dynamicList<ITEMTYPE>::currentSize() const
// Post: Current position has been initialized.
{
	return length;
}

template <class ITEMTYPE>
void dynamicList<ITEMTYPE>::Clear()
// Post: Current position has been initialized.
{
	length = 0;
}

template <class ITEMTYPE>
void dynamicList<ITEMTYPE>::Getlast(ITEMTYPE &item, bool &found)
// Post:  Current position has been updated; item is current item.
{
	if (!Empty())
	{
		item = element[length - 1];
		found = true;
	}
	else
	{
		cout << "Error: List is Empty.  Cannot Get Top Element.\n";
		found = false;
	}
}

template <class ITEMTYPE>
void dynamicList<ITEMTYPE>::init(ITEMTYPE initValue)
{
	for (int i = 0; i < size - 1; i++) {
		element[i] = initValue;
	}
}

template <class ITEMTYPE>
ITEMTYPE dynamicList<ITEMTYPE>::getItem(int index) {
	if (index >= 0 && index < length) {
		return element[index];
	} else if (index > length && index < size) {
		cout<<"Error: Index "<<index<<" is outside of the current array length."<<endl;
	} else {
		cout<<"Error: Index "<<index<<" is out of bounds."<<endl;
	}
}
#endif
