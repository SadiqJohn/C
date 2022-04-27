/*
 * John Sadiq
 * CS 281 Fall 2019
 * Airport Project
 *
 * Airport.cpp
 *
 *
 *
 */

#include "Airport.h"

using namespace std;

// Contructor
Airport::Airport() {

	headqueItem = nullptr;
	currentPlate = nullptr;
	hasAirForce1 = false;

};

//Destructor
Airport::~Airport() {};

//Creates the plane as by its status then fills in the rest such as name and fuel, pre adding to the que
void Airport::CreatePlane(string pname, int pfuel, int ptype)
{
	/*
	The user can add planes while the simulation is running.
	Each time the planes circle and the code reports status, present the menu to the user.
	When the user selects Complete the Simulation, just report status at every iteration and don't prompt the user anymore. 
	*/	

	//Prompts choice for the user to choose which plane they would like to create
	switch (ptype)
	{
	case 1:
	{	planeType y = Private;
		addAirplane(*(new Plane(pname, pfuel, y, 1, "QUEUED"))); 
		break; }
	case 2:
	{	planeType x = Commmercial;
		addAirplane(*(new Plane(pname, pfuel, x, 2, "QUEUED")));
		break; }
	case 3:
	{	planeType z = Air_Force_1;

	if (hasAirForce1 == false)
	{
	addAirplane(*(new Plane(pname, pfuel, z, 3, "QUEUED")));

	//only allows one air force 1 plane
	hasAirForce1 = true;
	}
		break; }
	}	
}

//Add airplane to que
void Airport::addAirplane(Plane newPlane)
{

	//currentplanes que item
	queItem *newqueItem = new queItem();
	newqueItem->plane = newPlane;

	// When adding a new node if the que is empty then add the new node as the head node
	if (headqueItem == nullptr)
	{
		headqueItem = newqueItem;
		return;
	}
	// When the new node has a priority larger then the head node then becomes the head node
	else if (newqueItem->plane.getpriority() > headqueItem->plane.getpriority()) {
		
		headqueItem->prvqueItem = newqueItem;
		newqueItem->nxtqueItem = headqueItem;
		headqueItem = newqueItem;
		return;
	}
	// any other situation, it will sive through and find its place
	else {

		currentqueItem = headqueItem->nxtqueItem;
		queItem* lastqueItem = headqueItem;

		//While loop for scanning through and finding its place within the que
		while (true)
		{

			//If the current node its compairing to is a null
			//then the new node will become that place in the que
			//using a lastqueItem and currentqueItem to keep correct nodes linked
			if (currentqueItem == nullptr)
			{
				lastqueItem->nxtqueItem = newqueItem;
				newqueItem->prvqueItem = lastqueItem; 
				return;

			} 
			//If it comes that the newNode has a value that is between 2 nodes
			//that already have a connection
			else if (newqueItem->plane.getpriority() > currentqueItem->plane.getpriority()) 
			{
				lastqueItem->nxtqueItem = newqueItem;
				currentqueItem->prvqueItem = newqueItem;
				newqueItem->nxtqueItem = currentqueItem;
				newqueItem->prvqueItem = lastqueItem;
				return;
			}
			//moves currentqueItem and LastqueItem over by one until
			//it finds its place within the que
			else
			{
				lastqueItem = currentqueItem;
				currentqueItem = lastqueItem->nxtqueItem;
			}
		}
	}
}

//Dequed Plane by taking it out of the list for other use.
Plane Airport::dequeAirplane(struct queItem* currentqueItem) {

	//currentplanes que item
	Plane returnPlane = currentqueItem->plane;

	//If one plane is the only plane in the list 
	if (currentqueItem->prvqueItem == nullptr && currentqueItem->nxtqueItem == nullptr)
	{
		//sets the only plane to nullptr
		headqueItem = nullptr;
	}
	//If dequeing a node at the front of the list
	else if (currentqueItem->prvqueItem == nullptr)
	{
		//sets the head pointer to the new head node
		headqueItem = currentqueItem->nxtqueItem;
		//sets the head node to nullptr
		currentqueItem->nxtqueItem->prvqueItem = nullptr;
	}
	//If dequeing a node at the end of the list
	else if (currentqueItem->nxtqueItem == nullptr)
	{
		//sets the tail node to nullptr
		currentqueItem->prvqueItem->nxtqueItem = nullptr;
	}
	//If dequeing a node in the middle of the list, between the first and last node
	else 
	{
		//sets the current next pointer to the current previous node
		currentqueItem->nxtqueItem->prvqueItem = currentqueItem->prvqueItem;
		//sets the current previous pointer to the current next node
		currentqueItem->prvqueItem->nxtqueItem = currentqueItem->nxtqueItem;
	}

	currentqueItem = nullptr;
	delete currentqueItem;
	return returnPlane;
}


//show status, clasifies plane by its class; QUEUED, CIRCLING, LANDING_NEXT, LANDED, and CRASHED. via Couting vector
void Airport::showStatus() {

	//sets currentqueItem to point to the same location as headqueItem
	queItem* currentqueItem = headqueItem;


	//sives through the list until its end of list
	while (currentqueItem != nullptr)
	{
		//COUT all info for the plane which is from getInfo method from Plane.cpp
		//Will COUT Name, Fuel, Priority, Type, and Status
		cout << currentqueItem->plane.getInfo() << endl;
		currentqueItem = currentqueItem->nxtqueItem;
	}
}

//simulation loop, each time system is looped, an interation goes through and subtract 5% from all flying planes, and has high priority plane land
//aswell as reorganizing priority, if plane goes in to emergency state then we remove it from the vector and insert it to the front giving it a higher priority.
void Airport::simLoop() {

	//sets currentqueItem to point to the same location as headqueItem
	queItem* currentqueItem = headqueItem;


	//FOR LANDED PLANES
	//sives through the list until its end of list
	if (currentqueItem != nullptr)
	{

		//Creates a stack called stackplane for landed planes 
		Plane stackplane = dequeAirplane(currentqueItem);
		stackplane.setStatus("LANDED");
		stackPush(stackplane);

		//If crashed plane is a air force 1 then set to false, allowing a user to make a new air force 1 plane
		if (stackplane.getplanetype() == Air_Force_1)
		{
			hasAirForce1 = false;
		}
	}

	currentqueItem = headqueItem;

	//during loop, this function lowers the fuel of all planes in the air by 5%
	while (currentqueItem != nullptr)
	{
		currentqueItem->plane.changeFuel(- 5);
		currentqueItem->plane.setStatus("CIRCLING");
		currentqueItem = currentqueItem->nxtqueItem;
	}

	currentqueItem = headqueItem;

	//this function determines which plane needs to be at the front or is crashed
	while (currentqueItem != nullptr)
	{
		

		//If plane crashed then give lable as crashed and push it to the crashed stack
		if (currentqueItem->plane.getFuel() <= 0)
		{
			currentqueItem->plane.setStatus("CRASHED");
			stackedPushCrashed(currentqueItem->plane);
			dequeAirplane(currentqueItem);
			currentqueItem = currentqueItem->nxtqueItem;

			//If crashed plane is a air force 1 then set to false, allowing a user to make a new air force 1 plane
			if (currentqueItem->plane.getplanetype() == Air_Force_1)
			{
				hasAirForce1 = false;
			}

		}
		//If fuel is less then 10% then reprioritize and set the plane to emergency mode
		//give new priority as higher then non emergency planes
		else if (currentqueItem->plane.getFuel() < 10 )
		{
			Plane dequePlane = dequeAirplane(currentqueItem);
			currentqueItem = currentqueItem->nxtqueItem;
			dequePlane.setPriority(100 - dequePlane.getFuel());
			addAirplane(dequePlane);

		}
		//else interate through the list
		else
		{
			currentqueItem = currentqueItem->nxtqueItem;

		}
	}



	//If plane has the highest priority and is next in line to land, give status as "LANDING_NEXT"
	if (headqueItem != nullptr) {
		headqueItem->plane.setStatus("LANDING_NEXT");
	}

}
 
//functions the same as simLoop, except goes through the list untill all planes are either crashed or landed
void Airport::fullsimLoop() {

	while (headqueItem != nullptr)
	{
		simLoop();
		showStatus();
		cout << "---------------------------------------------------------------------------------------------------- \n";

		//adds delay
		system("timeout /t 5 /nobreak>nul");
	}
}




//Stack Pusher
void Airport::stackPush(Plane airplane) {

	//creating plate for the landing airplane
	plate* Plate = new plate();
	Plate->plane = airplane;

	//pushing it onto the stack
	Plate->nxtPlate = currentPlate;
	currentPlate = Plate;

}

//Stack Pusher for crashed planes
void Airport::stackedPushCrashed(Plane airplane) {

	//creating plate for the landing airplane
	plate* Plate = new plate();
	Plate->plane = airplane;

	//pushing it onto the stack
	Plate->nxtPlate = currentCrash;
	currentCrash = Plate;

}

//Display the stack for landed planes
void Airport::landedstackShow() {

	//sets landedpate to point to the same location as currentPlate
	plate* landedplate = currentPlate;

	while (landedplate != nullptr)
	{
		cout << landedplate->plane.getInfo() << endl;
		landedplate = landedplate->nxtPlate;
	}
}

//Display the stack for crashed planes
void Airport::crashedstackShow() {

	//sets crashedplate to point to the same location as currentCrash
	plate* crashedplate = currentCrash;

	while (crashedplate != nullptr)
	{
		cout << crashedplate->plane.getInfo() << endl;
		crashedplate = crashedplate->nxtPlate;
	}
}