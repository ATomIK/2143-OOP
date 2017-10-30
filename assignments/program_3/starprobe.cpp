#include <iostream>
#include <cmath>
#include "starprobe.h"
#include "asteroid.h"

// check in case the program was compiled on linux as it was created on linux
#ifdef __linux__
	#include <unistd.h>
#else
	#include <windows.h>
#endif

Starprobe::Starprobe() : Starcraft(){
	preciousRoids = 0;
	current = 0;
}

/*
* @MethodName: getScanned
* @Description:
*			Return scanned asteroids
* @Params:
*			n/a
* @Returns:
*			int - scanned asteroids
*/

int Starprobe::getScanned(){ return current; }

/*
* @MethodName: getPrecious
* @Description:
*			Return number of precious asteroids
* @Params:
*			n/a
* @Returns:
*			int - precious asteroids
*/

int Starprobe::getPrecious(){ return preciousRoids; }

/*
* @MethodName: getPrecious
* @Description:
*			Return number of precious asteroids
* @Params:
*			n/a
* @Returns:
*			int - precious asteroids
*/

std::vector<Asteroid> Starprobe::getDb(){ return database; }

/*
* @MethodName: flightPlan
* @Description:
*			Discusses plans with the captain of the starship
* @Params:
*			n/a
* @Returns:
*			void
*/

void Starprobe::flightPlan() {
	// warp using pre-defined or manually defined coords?
	int choice;
	std::cout << "\nWould you like to send the probe using "
		"pre-defined coordinates?\n\n1. Yes\n2. No.\n";
	std::cin >> choice;

	// if manually defined, set x and y
	if (choice == 2) {
		std::cout << "\nPlease enter an x coordinate followed by a y coordinate\n "
			"for the probe to warp to. ( Example: 5 25 ):";
		std::cin >> coords[0] >> coords[1];
	}
	std::cout << "\nProbe warped to (" << coords[0] << "," << coords[1] << ")...\n\n";

	// set the limit of visitation
	std::cout << "\nHow many asteroids would you like the probe to scan before\n "
		"returning to earth? (integer): ";
	std::cin >> limit;
	std::cout << "\n";
}


/*
* @MethodName: doAsteroid
* @Description:
*			Overrides base class' method; Performs a scan on an asteroid
* @Params:
*			int index - the index of the closest asteroid
*			std::vector<Asteroid> &vect - the vector passed in by reference
*			bool ship - true if ship false if probe
*     double max - max weight of asteroid to collect
* @Returns:
*			bool - scanned or not
*/

bool Starprobe::doAsteroid(int index, std::vector<Asteroid> &asts, bool ship, double max) {

	// if the craft has not reached its limit
	if (limit != current) {

		std::cout << "Probe warped to: ("
			<< asts[index].get(0) << ", " << asts[index].get(1)
			<< "). Scanning asteroid...\n";

		// linux has a different sleep function than windows.
		#ifdef __linux__
			usleep(500000);
		#else
			Sleep(500);
		#endif

		if (asts[index].isPrecious()) {
			std::cout << "Asteroid contains precious metals!\n\n";
			// increment total number of precious asteroids
			preciousRoids++;
			// add precious asteroid to probe's database
			database.push_back(asts[index]);
		} else
			std::cout << "Asteroid did not contain precious metals...\n\n";

		// increment total number of scanned asteroids
		current++;
		asts[index].setScanned(true);

		// linux has a different sleep function than windows.
		#ifdef __linux__
			usleep(500000);
		#else
			Sleep(500);
		#endif

		return true;

	} else
		std::cout << "Starprobe is idle...\n";

	return false;

}

Starprobe::~Starprobe() {

}
