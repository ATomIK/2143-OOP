#include <iostream>
#include <cmath>
#include "starprobe.h"

// check in case the program was compiled on linux as it was created on linux
#ifdef __linux__
	#include <unistd.h>
#else
	#include <windows.h>
#endif

Starprobe::Starprobe() {
	preciousRoids = 0;
	scanned = 0;
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

int Starprobe::getScanned(){ return scanned; }

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
* @MethodName: findClosest
* @Description:
*			Loops through the vector of Asteroids and finds the Asteroid closest to
*           the ship's coordinates through basic algebra.
* @Params:
*			std::vector<Asteroid> &vect - the vector passed in by reference
* @Returns:
*			int - index of the Asteroid closest to the ship
*/

int Starprobe::findClosest(std::vector<Asteroid> &vect) {

	// set initial minDist to the maximum double value possible
	double minDist = 1.79769e+308;

	// loop through all asteroids
	int index = 0;
	// go through vector to compare distances
	// set i's type to vector's size_type to avoid possible loss of data
	for (std::vector<Asteroid>::size_type i = 0; i < vect.size(); i++) {

		double tempDist = 0;

		// start new method: computeDistance
		int x, y;
		x = vect[i].get(0) - get(0);
		y = vect[i].get(1) - get(1);
		// ship distancec from asteroid[i]
		tempDist = std::sqrt((x*x + y*y));
		// end new method: computeDistance
		// tempDist = computeDistance(vect[i].getX(), vect[i].getY());

		// if the asteroid hasn't been scanned and
		// the distance is less than the initla minDist
		// then this is the closest asteroid to the ship
		if (!vect[i].isScanned() && tempDist < minDist) {
			// had to typecast i as int because of size_type
			index = (int)i;
			minDist = tempDist;
		}

	}

	// return the final closest index in the vector
	return index;

}

/*
* @MethodName: plans
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
	std::cout << "Would you like to send the probe using "
		"pre-defined coordinates?\n\n1. Yes\n2. No.\n";
	std::cin >> choice;

	// if manually defined, set x and y
	if (choice == 2) {
		std::cout << "Please enter an x coordinate followed by a y coordinate\n "
			"for the probe to warp to. ( Example: 5 25 ):";
		std::cin >> coords[0] >> coords[1];
	}
	std::cout << "\nProbe warped to (" << coords[0] << "," << coords[1] << ")...\n\n";

	// set the limit of visitation
	std::cout << "How many asteroids would you like the probe to scan before\n "
		"returning to earth? (integer): ";
	std::cin >> limit;
	std::cout << "\n";
}


/*
* @MethodName: scanAsteroid
* @Description:
*			Sets the asteroid to scanned
* @Params:
*			int index - the index of the closest asteroid
*			std::vector<Asteroid> &vect - the vector passed in by reference
* @Returns:
*			void
*/

void Starprobe::scanAsteroid(int index, std::vector<Asteroid> &asts) {

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
		std::cout << "Asteroid contains precious metals!\n";
		preciousRoids++;
	} else
		std::cout << "Asteroid did not contain precious metals...\n";

	scanned++;
	asts[index].setScanned(true);

	// linux has a different sleep function than windows.
	#ifdef __linux__
		usleep(500000);
	#else
		Sleep(500);
	#endif

}

Starprobe::~Starprobe() {

}
