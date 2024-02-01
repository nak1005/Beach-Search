///============================================================================
// Name        : plant.cpp
// Description : source file for the plant child class
//=============================================================================

#include <iostream>
#include "plant.h"

using namespace std;

#ifndef PLANT_I_
#define PLANT_I_

//prints 3 item attributes
void plant :: printitem(){
	item :: printitem();
	cout << endl;
}

//constructor
plant :: plant(string color, double length, string description){
	this->color = color;
	this->length = length;
	this->description = description;
}

#endif /* PLANT_I_ */
