///============================================================================
// Name        : wood.h
// Description : header file for the wood child class
//=============================================================================

#include <iostream>
#include "item.h"

using namespace std;

#ifndef WOOD_H_
#define WOOD_H_

class wood : public item{
	protected:
		string pattern;
	public:
		void setpattern(string);
		string getpattern();

		void printitem();

		wood(string, string, double, string);
};

#endif /* WOOD_H_ */
