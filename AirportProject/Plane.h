/*
 * John Sadiq
 * CS 281 Fall 2019
 * Airport Project
 *
 * Airport.h
 *
 *
 *
 */
#pragma once
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <conio.h>

enum planeType { Commmercial, Private, Air_Force_1 };


class Plane {
private:
	
	//Plane type
	//enum type to discribe the type of plane, can be called upon as a user assigned type
	//Now whenever a function is looking for a plane type it will have to fall between Comm, priv, or AF1 plane

	//name of plane
	std::string name;

	//fuel, new plane is random between 10%-90%
	int fuel;

	//priority, Priority goes 1 for comm planes, 2 for priv planes, then 3 for AF1 plane
	//The plane with the highest priority will land in the que,
	//but once a plane goes into emergency mode they will skip to the top of the priority
	int priority;

	//status of plane, the status a plane can have are either, QUEUED, CIRCLING, LANDING_NEXT, LANDED, or CRASHED.
	//Plane will get their status as situation is appropiate, each plane can only hold one status and will change as conditions change
	std::string status;

	//plane type, calling from enum planeType making type be a planeType type.
	planeType type;


public:

	// Contructor
	Plane();

	//Constructor sets name, fuel, and priority
	Plane(std::string pname, int pfuel, planeType ptype, int ppriority, std::string pstatus);

	//Destructor
	~Plane();

	//Getters, getters will get name, fuel levels, priority number, Status, Plane Type
	std::string getName();
	int getFuel();
	int getpriority();
	std::string getStatus();
	planeType getplanetype();
	std::string getInfo();


	//Setters, setters will set name, fuel levels, priority number, Status, Plane Type
	void setName(std::string planeName);
	void changeFuel(int pfuel);
	void setPriority(int priority);
	void setStatus(std::string status);
	void setPlanetype(planeType pplaneType);

};