///============================================================================
// Name        : shell.h
// Description : header file for the shell child class
//============================================================================

#include <iostream>
#include "item.h"

using namespace std;

#ifndef SHELL_H_
#define SHELL_H_

class shell : public item{
	protected:
		double height;
	public:
		void setheight(double);
		double getheight();

		void printitem();

		shell(string, double, double, string);
};

#endif /* SHELL_H_ */
