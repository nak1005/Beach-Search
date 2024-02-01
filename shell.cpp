///============================================================================
// Name        : shell.cpp
// Description : source file for the shell child class
//=============================================================================

#include <iostream>
#include "shell.h"

using namespace std;

#ifndef SHELL_I_
#define SHELL_I_

//set height
void shell :: setheight(double height){
	this->height = height;
}

//get height
double shell :: getheight(){
	return height;
}

//print 3 item attributes and the shell attribute
void shell :: printitem(){
	item :: printitem();
	cout << " Height: " << height << endl;
}

//constructor
shell :: shell(string color, double length, double height, string description){
	this->color = color;
	this->length = length;
	this->height = height;
	this->description = description;
}

#endif /* SHELL_I_ */

