///============================================================================
// Name        : item.h
// Description : header file for the item parent class
//=============================================================================

#include <iostream>

using namespace std;

#ifndef ITEM_H_
#define ITEM_H_

class item{
	protected:
		string description;
		string color;
		double length;
	public:
		void setcolor(string);
		void setlength(double);
		void setdescription(string);

		string getcolor();
		double getlength();
		string getdescription();

		item(string = " ", double = 0, string = " ");

		void printitem(); //prints the 3 attributes
};

#endif /* ITEM_H_ */
