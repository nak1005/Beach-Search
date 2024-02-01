///============================================================================
// Name        : glass.cpp
// Description : source file for the glass child class
//=============================================================================

#include <iostream>
#include "glass.h"

using namespace std;

#ifndef GLASS_I_
#define GLASS_I_

//set origin
void glass :: setorigin(string origin){
	this->origin = origin;
}

//get origin
string glass :: getorigin(){
	return origin;
}

//print 3 item attributes and the glass attribute
void glass:: printitem(){
	item :: printitem();
	cout << " Origin: " << origin << endl;
}

//constructor
glass :: glass(string color, double length, string origin, string description){
	this->color = color;
	this->length = length;
	this->origin = origin;
	this->description = description;
}

#endif /* GLASS_I_ */
