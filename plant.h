///============================================================================
// Name        : plant.h
// Description : header file for the plant child class
//=============================================================================

#include <iostream>
#include "item.h"

using namespace std;

#ifndef PLANT_H_
#define PLANT_H_

class plant : public item{
	public:
		void printitem();
		plant(string, double, string);

};

#endif /* PLANT_H_ */
