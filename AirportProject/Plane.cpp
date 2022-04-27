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

#include "Plane.h"

using namespace std;



	// Contructor for Plane
	Plane:: Plane() {}

	//Constructor sets Plane: name, fuel, and type. Using a switch to pick which plane is needed at the time.
	Plane::Plane(string pname, int pfuel, planeType ptype, int ppriority, string pstatus) {
		name = pname;
		fuel = pfuel;
		type = ptype;
		priority = ppriority;
		status = pstatus;
		
	}
	
	//Destructor for Plane
	Plane:: ~Plane() {}



	//Getters

	//get Plane Name
	string Plane::getName() 
	{
		return name;
	}	
	
	//get Plane Fuel
	int Plane::getFuel()
	{
		return fuel;
	}	
	
	//get Plane Priority
	int Plane::getpriority()
	{
		return priority;
	}

	//get Plane Status
	string Plane::getStatus()
	{
		return status;
	}
	
	//get Plane Type
	planeType Plane::getplanetype()
	{
		return type;
	}

	//get info for display, This is for when the user asks for the status of all the planes
	//grabs info per plane and displays when user prompts and displays them appropiately and with even space
	string Plane::getInfo()
	{
		string converstionTypes[3] = { "Commmercial", "Private", "Air_Force_1" };

		ostringstream outputStream;
		outputStream <<"Name: " << std::setw(10) << name << " | fuel: " << std::setw(4) << fuel <<
			"%" << " | Priority: " << std::setw(3) << priority << " | Plane type: " << std::setw(15) <<
			converstionTypes[type]  << " | Status: " << std::setw(10) << status;

		return outputStream.str();
	}

	//Setters

	//set Plane Name
	void Plane::setName(string planeName)
	{
		name = planeName;
	}
	
	//set Fuel, fuel for a new plane will be a random number between 10% - 90%
	void Plane::changeFuel(int pfuel)
	{
		fuel += pfuel;

	}

	//set Plane Priority
	void Plane::setPriority(int ppriority)
	{
		priority = ppriority;
	}
	
	//Set Plane Status
	void Plane::setStatus(string pstatus)
	{
		status = pstatus;
	}

	//Set Plane Type
	void Plane::setPlanetype(planeType pplaneType)
	{
		type = pplaneType;
	}