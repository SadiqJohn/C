/*This program has an array of at least 10 string objects that hold
people’s names and phone numbers
*/

//John Sadiq

#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()

{

	const int Num_People = 10; //number of people

	const int Length = 27;

	string people[Num_People] = { 
		"Becky Warren, 555-1223",

		 "Geri Palmer, 555-8787",

		 "Lynn Presnell, 555-1212",

		 "Holly Gaddis, 555-8878",

		 "Sam Wiggins, 555-0998",

		 "Bob Kain, 555-8712",

		 "Tim Haynes, 555-7676",

		 "Warren Gaddis, 555-9037",

		 "Jean James, 555-4939",

		 "Ron Palmer, 555-2783" };

	char lookUp[Length];

	size_t strPos;

	int index, count = 0;

	cout << "\tPeople and Phone Numbers\n\n";

	cout << "Enter a name or partial name to search directory: "; //Prompt the user to enter name or partial name

	cin.getline(lookUp, 27);	//read name or partial name
	
	for (index = 0; index < 10; index++) //Find the name in all string objects

	{

		//if the name is found in the string, the starting position of name is returned into strPos
		strPos = people[index].find(lookUp);

		//strPos equal to no postions, if the name is not found in the string
		if (strPos != string::npos)

		{

			//Print the string, in which the entered name is found
			cout << people[index] << endl;

			count++;//Increase the count

		}

	}

	//count will be 0,if there are no matchings
	if (count == 0)

		cout << "No matching was found.\n";

	return 0;

}