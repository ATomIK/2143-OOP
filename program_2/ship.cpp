#include <iostream>
#include "ship.h"

Ship::Ship(){



}

// Ship::Ship(double, double, int)

void Ship::captainsLog(){

  cout << "Would you like to warp using "
					"pre-defined coordinates?\n\n1. Yes\n2. No.\n";

	int choice;
	cin >> choice;

	if(choice == 1)
		cout << "\nWarping to (0,0)...\n\n";
	else {
		int x = 0, y = 0;
		cout << "Please enter an x coordinate followed by a y coordinate\n "
		"for the ship to warp to. (Example: 5 25):";
		cin >> x >> y;
		cout << "\nWarping to (" << x << "," << y << ")...\n\n";
	}

	cout << "How many asteroids would you like to collect before "
					"returning to earth? ";
	int amt;
	cin >> amt;

}
