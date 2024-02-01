///============================================================================
// Name        : wood.cpp
// Description : source file for the wood child class
//=============================================================================

#include <iostream>
#include "wood.h"

using namespace std;

#ifndef WOOD_I_
#define WOOD_I_

//set pattern
void wood :: setpattern(string){
	this->pattern=pattern;
}

//get pattern
string wood :: getpattern(){
	return pattern;
}

//print 3 item attributes and the wood attribute
void wood :: printitem(){
	item :: printitem();
	cout << " Pattern: " << pattern << endl;
}

//constructor
wood :: wood(string pattern, string color, double length, string description){
	this->pattern = pattern;
	this->color = color;
	this->length = length;
	this->description = description;
}

#endif /* WOOD_I_ */
