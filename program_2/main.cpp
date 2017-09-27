#include <iostream>

#include "asteroid.h"
#include "ship.h"
#include "asteroidlist.h"

using namespace std;

// void generateRoids(int size){
// 	ifstream infile("input.txt");
// 	while(!infile.eof()){
//
// 		double x, y, w;
//
// 		infile >> x >> y >> w;
//
// 		cout << x << " " << y << " " << w << "\n\n";
//
// 	}
// }

int main(){

	cout << "Would you like to warp using "
					"pre-defined coordinates?\n\n1. Yes\n2. No.\n";

	int choice;
	cin >> choice;

	if(choice == 1)
		cout << "\nWarping to (0,0)...\n\n";
	else {
		int x = 0, y = 0;
		cout << "Please enter an x coordinate followed by a y coordinate "
		"for the ship to warp to. (Example: 5 25):";
		cin >> x >> y;
		cout << "\nWarping to (" << x << "," << y << ")...\n\n";
	}

	cout << "How many asteroids would you like to collect before "
					"returning to earth? ";
	int amt;
	cin >> amt;

	// generate asteroids from input file
	AsteroidList RoidList;
	RoidList.generateRoids(amt);

	// launch ship

	// loop x times

		// find target

		// mine asteroid
				// asteroid > ship ? explode
				// else collect()

	// endloop

	cout << "Ran\n";

	return 0;
}
