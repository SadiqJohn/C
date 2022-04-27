/* Write a program that demonstrates the Coin class.The program should create aninstance of the 
class and display the side that is initially facing up.Then, use a loopto toss the coin 20 times.
Each time the coin is tossed, display the side that is facingup.The program should keep
count of the number of times heads is facing up and thenumber of times tails is facing up,
and display those values after the loop finishes. */

//John Sadiq

#include "pch.h"
#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;

class Coin {
private:
	string sideUp;
public:
	Coin() //Constructor
	{
		//This indicates which is facing up head or tails
		int side = rand() % 2;
		if (side == 0) {
			sideUp = "heads";
		}
		else {
			sideUp = "tails";
		}
	}
	//This void toss simulates the tossing of the coin,
	//it randomly determines heads or tails for each toss.
	void toss() {

		int side = rand() % 2;
		if (side == 0) {
			sideUp = "heads";
		}
		else {
			sideUp = "tails";
		}
	}
	//Member fuction that returns the sideUp member variable
	string getSideUp() {
		return sideUp;
	}
};

int main() {
	srand(time(0)); //generates random side to be facing up.
	Coin c;
	int headCount = 0, tailCount = 0;
	cout << "Initial value on top : " << c.getSideUp() << endl;
	for (int i = 0; i < 20; i++) {
		c.toss();
		string side = c.getSideUp(); //retrives data in for counting number of heads and tails.
		cout << side << endl;
		if (side.compare("heads") == 0) { 
			headCount++; //counts number of heads facing up.
		}
		else {
			tailCount++; //counts number of tails facing up.
		}
	}
	cout << "Number of times head appears on top is " << headCount << endl; //display number of heads
	cout << "Number of times tail appears on top is " << tailCount << endl; //display number of tails

	return 0;
}