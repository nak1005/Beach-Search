///============================================================================
// Name        : glass.h
// Description : header file for the glass class
//=============================================================================

#include <iostream>
#include "item.h"

using namespace std;

#ifndef GLASS_H_
#define GLASS_H_

class glass : public item{
	protected:
		string origin; //man-made or origin unknown
	public:
		void setorigin(string);
		string getorigin();

		void printitem();

		glass(string, double, string, string);
};

#endif /* GLASS_H_ */
