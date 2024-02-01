///============================================================================
// Name        : item.cpp
// Description : source file for the item parent class
//=============================================================================

#include <iostream>
#include "item.h"

using namespace std;

#ifndef ITEM_I_
#define ITEM_I_

//set color
void item :: setcolor(string color){
	this->color = color;
}

//set length
void item :: setlength(double length){
	this->length = length;
}

//set description
void item :: setdescription(string description){
	this->description = description;
}

//get color
string item :: getcolor(){
	return color;
}

//get length
double item :: getlength(){
	return length;
}

//get description
string item :: getdescription(){
	return description;
}

//print the 3 item attributes
void item :: printitem(){
	cout << "Color: " << color << " Length: " << length << " Description: " << description;
}

//constructor
item :: item(string color, double length, string description){
	this->color = color;
	this->length = length;
	this->description = description;
}

#endif /* ITEM_I_ */
