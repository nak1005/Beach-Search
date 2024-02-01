///============================================================================
// Name        : 246.cpp
// Authors     : Layne Burkhead, Nikki Kudamik, Darren
// Class       : CPSC 246 11am
// Due Date    : 11/21/2022
// Description : This is a menu/search project we designed using vectors and inheritance.
//=============================================================================

#include <iostream>
#include <string>
#include <vector>
#include "item.h"
#include "shell.h"
#include "glass.h"
#include "wood.h"
#include "plant.h"

using namespace std;

//function declaration
void addItem(vector<shell> &shellList, vector<glass> &glassList, vector<wood> &woodList, vector<plant> &plantList); //prompts the user and gets user input to add a new item to the saved items
//parameters are all item vectors passed by value in the order shellList, glassList, woodList, plantList

void InitializeGlass(vector<glass>&glassList); //creates the initial glass objects and adds them to the glass item vector
//the glass list vector is passed by value as the parameter

void InitializePlant(vector<plant>&plantList); //creates the initial plant objects and adds them to the plant item vector
//the plant list vector is passed by value as the parameter

void InitializeShells(vector<shell>&shellList); //creates the initial shell objects and adds them to the shell item vector
//the shell list vector is passed by value as the parameter

void InitializeWood(vector<wood>&woodList); //creates the initial wood objects and adds them to the wood item vector
//the wood list vector is passed by value as the parameter

void printvectors(vector<shell>&shellList, vector<glass>&glassList,vector<wood>&woodList, vector<plant>&plantList); //used at the end of the program to print all the items in all vectors
//parameters are all item vectors passed by value in the order shellList, glassList, woodList, plantList

void searchItem(vector<shell> &shellList, vector<glass> &glassList, vector<wood> &woodList, vector<plant> &plantList); //asks user for search terms and prints all items that match the terms
//parameters are all item vectors passed by value in the order shellList, glassList, woodList, plantList


//main start
int main() {

	string end;
	string menuInput;  //stores user input for menu options

	//declare vectors
	vector<shell>shellList;
	vector<glass>glassList;
	vector<wood>woodList;
	vector<plant>plantList;

	//initialize objects
	InitializeShells(shellList);
	InitializeGlass(glassList);
	InitializeWood(woodList);
	InitializePlant(plantList);

   //menu loop
	while(true){
	//get user menu option selection
	cout << endl << "Select 'add' or 'search' or 'END'=> ";
	cin >> menuInput;

		//if user chooses add item
		if (menuInput == "add" || menuInput == "Add" || menuInput == "ADD")
			addItem(shellList, glassList, woodList, plantList);


		//if user chooses search
		else if (menuInput == "search" || menuInput == "Search" || menuInput == "SEARCH"){
			searchItem(shellList, glassList, woodList, plantList);
		}

	    //if user chooses end program
		else if(menuInput == "END" || menuInput == "End" || menuInput == "end"){
			cout << "\nAre you sure you want to exit? Type YES for confirmation=> ";
			cin >> end;
			if(end == "YES" || end == "Yes" || end == "yes")
				break;
		}
		//if invalid input for menu choice
		else
			cout << "\nInvalid input - ";

	}//end menu loop
	printvectors(shellList, glassList, woodList, plantList);
	return 0;


}//main end


//add item
void addItem(vector<shell> &shellList, vector<glass> &glassList, vector<wood> &woodList, vector<plant> &plantList){

	string menuInput; //stores menu selection input
	string wholeInput; //entire item input string
	string stringInput[4]; //used for temporarily storing item string attributes
	int i;


	//get user input on what type of item
	cout << "\nIs item shell, wood, glass or plant?\n";
	cin >> menuInput;

	//ADD NEW SHELL
	if (menuInput == "shell" || menuInput == "Shell" || menuInput == "SHELL"){
		//get entire line of user input on the item's attributes
		cout << "\nEnter shell attributes in the form of \"Color, Length(in inches), Height(in inches), Description\"\n";
		cin.ignore();
		getline(cin, wholeInput);
		//takes out and stores an attribute in stringInput, then it removes that attribute's section of wholeInput. Repeats for each attribute
		for(i = 0; i < 4; i++) { //runs 4 times for 4 attributes
		    stringInput[i] = wholeInput.substr(0, wholeInput.find(", ")); //stores current attribute from beginning of wholeInput to before the next ", "
		    wholeInput.erase(0, wholeInput.find(", ") + 2); //removes current attribute from the string and the ", " that came after it
		}
		//cout << "\"" << stringInput[0] << "\"\n\"" << stringInput[1] << "\"\n\"" << stringInput[2] << "\"\n\"" << stringInput[3] << "\"\n"; //for testing
		//create the new shell object
		shell newShell(stringInput[0], stod(stringInput[1]), stod(stringInput[2]), stringInput[3]);
		shellList.push_back(newShell); //new shell object added to vector
		cout << endl;
		newShell.printitem(); //for testing
		cout << "\nNew shell added!\n\n";
	} //end shell add

	//ADD NEW GLASS
	else if (menuInput == "glass" || menuInput == "Glass" || menuInput == "GLASS"){
		//get glass attribute input line
		cout << "\nEnter glass attributes in the form of \"Color, Length(in inches), Origin, Description\"\n";
		cin.ignore();
		getline(cin, wholeInput);
		//takes out an attribute then deletes it from wholeInput. Repeats for each attribute
		for(i = 0; i < 4; i++) {
		    stringInput[i] = wholeInput.substr(0, wholeInput.find(", "));
		    wholeInput.erase(0, wholeInput.find(", ") + 2);
		}
		//cout << "\"" << stringInput[0] << "\"\n\"" << stringInput[1] << "\"\n\"" << stringInput[2] << "\"\n\"" << stringInput[3] << "\"\n"; //for testing
		//create the new glass object
		glass newGlass(stringInput[0], stod(stringInput[1]), stringInput[2], stringInput[3]);
		glassList.push_back(newGlass); //new glass object added to vector
		cout << endl;
		newGlass.printitem(); //for testing
		cout << "\nNew glass added!\n\n";
	} //end glass add

	//ADD NEW WOOD
	else if (menuInput == "wood" || menuInput == "Wood" || menuInput == "WOOD"){
		//get wood attribute input line
		cout << "\nEnter wood attributes in the form of \"Pattern, Color, Length(in inches), Description\"\n";
		cin.ignore();
		getline(cin, wholeInput);
		//takes out an attribute then deletes it from wholeInput. Repeats for each attribute
		for(i = 0; i < 4; i++) {
			stringInput[i] = wholeInput.substr(0, wholeInput.find(", "));
			wholeInput.erase(0, wholeInput.find(", ") + 2);
		}
		//cout << "\"" << stringInput[0] << "\"\n\"" << stringInput[1] << "\"\n\"" << stringInput[2] << "\"\n\"" << stringInput[3] << "\"\n"; //for testing
		//create the new wood object
		wood newWood(stringInput[0], stringInput[1], stod(stringInput[2]), stringInput[3]);
		woodList.push_back(newWood); //new wood object added to vector
		cout << endl;
		newWood.printitem(); //for testing
		cout << "\nNew wood added!\n\n";
	} //end wood add

	//ADD NEW PLANT
	else if (menuInput == "plant" || menuInput == "Plant" || menuInput == "PLANT"){
		//get plant attribute input line
		cout << "\nEnter plant attributes in the form of \"Color, Length(in inches), Description\"\n";
		cin.ignore();
		getline(cin, wholeInput);
		//takes out an attribute then deletes it from wholeInput. Repeats for each attribute
		for(i = 0; i < 3; i++) {
			stringInput[i] = wholeInput.substr(0, wholeInput.find(", "));
			wholeInput.erase(0, wholeInput.find(", ") + 2);
		}
		//cout << "\"" << stringInput[0] << "\"\n\"" << stringInput[1] << "\"\n\"" << stringInput[2] << "\"\n\"" << stringInput[3] << "\"\n"; //for testing
		//create the new plant object
		plant newPlant(stringInput[0], stod(stringInput[1]), stringInput[2]);
		plantList.push_back(newPlant); //new plant object added to vector
		cout << endl;
		newPlant.printitem(); //for testing
		cout << "\nNew plant added!\n\n";
	} //end plant add

	else //invalid input for add item
		cout << "Invalid add\n\n";

}//end item add


//initialize glass objects
void InitializeGlass(vector<glass>&glassList){
	glass glass1("clear", 1, "man-made", "shiny"),
		  glass2("white", 2.5, "origin unknown", "scratched");
	glassList.push_back(glass1);
	glassList.push_back(glass2);
} // end glass initialize


//initialize plant objects
void InitializePlant(vector<plant>&plantList){
	plant plant1("green", 10, "solid"),
		  plant2("brown", 6, "grass-like"),
		  plant3("black", 12, "wiggly"),
		  plant4("tan", 8.5, "solid"),
		  plant5("green", 10, "solid"),
		  plant6("green", 10, "solid");
	plantList.push_back(plant1);
	plantList.push_back(plant2);
	plantList.push_back(plant3);
	plantList.push_back(plant4);
	plantList.push_back(plant5);
	plantList.push_back(plant6);
} //end plant initialize


//initialize shell objects
void InitializeShells(vector<shell>&shellList){
	shell shell1("white", 3, .5, "concave"),
		  shell2("pink", 2, 0.25, "circular"),
		  shell3("orange", 0.5, 0.25, "flat"),
		  shell4("brown", 1, 0.25, "convex"),
		  shell5("white", 3, 1.5, "concave");
	shellList.push_back(shell1);
	shellList.push_back(shell2);
	shellList.push_back(shell3);
	shellList.push_back(shell4);
	shellList.push_back(shell5);
}//end shell initialize


//initialize wood objects
void InitializeWood(vector<wood>&woodList){
	wood  wood1("plain", "brown", 6, "light"),
		  wood2("plain", "brown", 2, "medium"),
		  wood3("variagated", "brown", 4.5, "dark");
	woodList.push_back(wood1);
	woodList.push_back(wood2);
	woodList.push_back(wood3);
}//end wood initialize


//print item vectors
void printvectors(vector<shell>&shellList, vector<glass>&glassList, vector<wood>&woodList, vector<plant>&plantList){
	int i;

	cout << "SHELLS: " << endl;
	for (i=0; i< shellList.size(); i++){
		cout << '\t' << i+1 << " ";
		shellList.at(i).printitem();
	}
	cout << "GLASS: " << endl;
	for (i=0; i< glassList.size(); i++){
		cout << '\t' << i+1 << " ";
		glassList.at(i).printitem();
	}
	cout << "WOOD: " << endl;
	for (i=0; i< woodList.size(); i++){
		cout << '\t' << i+1 << " ";
		woodList.at(i).printitem();
	}
	cout << "PLANTS: " << endl;
	for (i=0; i< plantList.size(); i++){
		cout << '\t' << i+1 << " ";
		plantList.at(i).printitem();
	}
}//end vector print


//item search
void searchItem(vector<shell> &shellList, vector<glass> &glassList, vector<wood> &woodList, vector<plant> &plantList){

	int i;
	string colorinput = " ", junk;
	double min, max;

	cout << "\nEnter search criteria in the form of \"Color minimum to maximum length(in inches)\"\n"; // type in something like 'white 2 to 5'
	cin >> colorinput >> min >> junk >> max;

	if(min > 0){

		cout << "Shells that match your search: \n";
		for(i=0;i<shellList.size();i++){
			if((shellList.at(i).getlength()>=min && shellList.at(i).getlength()<=max) && (colorinput == shellList.at(i).getcolor())){
				cout << '\t' << i+1 << " ";
				shellList.at(i).printitem();
			}
		}
		cout << "Glass items that match your search: \n";
		for(i=0;i<glassList.size();i++){
			if((glassList.at(i).getlength()>=min && glassList.at(i).getlength()<=max) && (colorinput == glassList.at(i).getcolor())){
				cout << '\t' << i+1 << " ";
				glassList.at(i).printitem();
			}
		}
		cout << "Wood items that match your search: \n";
		for(i=0;i<woodList.size();i++){
			if((woodList.at(i).getlength()>=min && woodList.at(i).getlength()<=max) && (colorinput == woodList.at(i).getcolor())){
				cout << '\t' << i+1 << " ";
				woodList.at(i).printitem();
			}
		}
		cout << "Plants that match your search: \n";
		for(i=0;i<plantList.size();i++){
			if((plantList.at(i).getlength()>=min && plantList.at(i).getlength()<=max) && (colorinput == plantList.at(i).getcolor())){
				cout << '\t' << i+1 << " ";
				plantList.at(i).printitem();
			}
		}
	}
	else
		cout << "Enter valid option\n";
} //end search


