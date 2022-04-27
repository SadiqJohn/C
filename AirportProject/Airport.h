/*
 * John Sadiq
 * CS 281 Fall 2019
 * Airport Project
 *
 * Plane.h
 *
 *
 *
 */
#include "Plane.h"
#pragma once

class Airport {
private:

	//que for planes in sky.
	struct queItem {
		Plane plane;
		queItem* nxtqueItem;
		queItem* prvqueItem;

	};

	// stack for show landed.
	struct plate {
		Plane plane;
		plate* nxtPlate;
	};

	//current landed plane in stack
	plate* currentPlate;

	//current crashed plane in stack
	plate* currentCrash;

	//traversal que node
	queItem* currentqueItem;
	
	//front of que
	queItem* headqueItem;

	//Set Bool, so that there can only be one Air Force plane flying
	bool hasAirForce1;

public:

	// Contructor
	Airport();

	//Destructor
	~Airport();

	//Pusher
	void stackPush(Plane airplane);

	//Pusher for crashed planes
	void stackedPushCrashed(Plane airplane);

	//Creates the plane as by its status then fills in the rest such as name and fuel, pre adding to the que
	void CreatePlane(std::string pname, int pfuel, int ptype);

	//adding airplane to a vector, within the vector fuction values with sort in numeral order
	//aswell as code using a for loop so once value gets to the front of the vector to insert and push the list over that its not operating with a null pointer by mistake
	void addAirplane(Plane newPlane);

	//show status, clasifies plane by its class; QUEUED, CIRCLING, LANDING_NEXT, LANDED, and CRASHED. via Couting vector
	void showStatus();

	//standard stack operations.
	void landedstackShow();
	void crashedstackShow();

	//simulation loop, each time space button is hit, an interation goes through and subtract 5% from all flying planes, and has high priority plane land
	//aswell as reorganizing priority, if plane goes in to emergency state then we remove it from the vector and insert it to the front giving it a higher priority.
	void simLoop();

	//functions the same as simLoop, except goes through the list untill all planes are either crashed or landed
	void fullsimLoop();

	//remove head node.
	Plane dequeAirplane(struct queItem* currentqueItem);

};