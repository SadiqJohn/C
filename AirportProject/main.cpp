/*
 * John Sadiq
 * CS 281 Fall 2019
 * Airport Project
 *
 * Plane.cpp
 *
 *
 *
 */

#include "Airport.h"

using namespace std;

int main()
{
	//sets time to be 0 so when the time of the programmed is run and a new plane is created, It will be random
	srand(unsigned int (time(0)));
	
	Airport* Aport = new Airport();

	//Introduction
	cout << "Welcome to the San Diego Airlines! \n" <<
		"Enter l to have simulation go one cycle \n" <<
		"Then enter a number for the given options \n" <<
		"1) Create a new plane \n" <<
		"2) Check status on all planes \n" <<
		"3) Check list of landed planes \n" <<
		"4) Check list of crashed planes \n" <<
		"5) Loops all planes until all planes are on the ground \n" <<
		"Enter q to quit \n" <<
		"----------------------------------------- \n";

	
	// sets a variable for input, for the do while loop
	//allowing a quit option for user
		string input;

	//loops until user decides to quit
	do
	{
		//Variables
		string name;
		int fuel;
		int type;

		//Adds >> to show where user will enter their imput
		cout << "\n >>";
		cin >> input;

		//switch giving the user options to choose
		switch (input.at(0))
		{
		
			case 'l': // Simulate loop
					
				//loops once through the list
				Aport->simLoop();
				//displays the status of planes
				Aport->showStatus();


			  /*
				one cycle goes through with every space buttom pressed,
				plane does a lap and 5% of fuel is lost, one plane lands per cycle
				*/
				
				break;

			case '1': //New Plane

				// user enter values for name and type
				cout << "Enter Plane Name: ";
				cin >> name;
				cout << "Would you like plane type to be \n 1) Private 2) Commercial 3) Air Force 1 :";
				cin >> type;

				
				//Random fuel for new plane, fuel can only be between 10% - 90%
				fuel = rand() % 90 + 10;
				
				//Sends values the user inputed to the Airport.cpp to go through algorithm 
				Aport->CreatePlane(name, fuel, type);

				/*
				creates new plane, sets a random number between 10-90 for fuel percent,
				set priority depending on plane type, user inputs name for plane, set plane status
				*/
				break;

			case '2': //check status

				//COUT msg
				cout << "current status of all planes \n";
				cout << "---------------------------- \n";

				//Show Status, background work is in Airport.cpp
				Aport->showStatus();
				break;

			case '3': // Show stack of LANDED planes
				
				//COUT msg
				cout << "List of landed planes \n";
				cout << "--------------------- \n";

				//Show Stack of landed planes, background work is in Airport.cpp
				Aport->landedstackShow();

				break;
			
			case '4': // Show stack of CRASHED planes

				//COUT msg
				cout << "List of crashed planes \n";
				cout << "---------------------- \n";

				//Show Stack of crashed planes, background work is in Airport.cpp
				Aport->crashedstackShow();

				break;

			case '5': //loops until all planes are either landed or crashed

				//COUT msg
				cout << "Looped through all planes \n";
				cout << "------------------------- \n";

				//completes simloop until empty
				Aport->fullsimLoop();

				break;
		}

		//When user enters 'q' the program quits
	} while (input != "q");

	return 0;
}