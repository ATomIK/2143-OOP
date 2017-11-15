// starprobe.cpp

#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include "spaceobject.h"
#include "starcraft.h"
#include "starprobe.h"
#include "asteroid.h"

// check in case the program was compiled on linux as it was created on linux
#ifdef __linux__
	#include <unistd.h>
#else
	#include <windows.h>
#endif

/*
* @DefaultConstructorName: Starprobe
* @Description:
*			Sets all Starprobe variables to defaults
* @Params:
*			n/a
* @Returns:
*			n/a
*/

Starprobe::Starprobe() : Starcraft() {
	preciousRoids = 0;
}

/*
* @ParameterizedConstructorName: Starprobe
* @Description:
*			Sets name, coordinates, then the rest to their defaults
* @Params:
*			std::string n - name of Starprobe
*			int x - x coordinate
*			int y - y coordinate
* @Returns:
*			n/a
*/

Starprobe::Starprobe(std::string n, int x, int y) : Starcraft(n, x, y) {
	preciousRoids = 0;
}

/*
* @MethodName: getPrecious
* @Description:
*			Return number of precious asteroids
* @Params:
*			n/a
* @Returns:
*			int - precious asteroids
*/

int Starprobe::getPrecious() { return preciousRoids; }

/*
 * @MethodName: toString
 * @Description:
 *			Returns string of pretty object data
 * @Params:
 *			n/a
 * @Returns:
 *			string - pretty object data
 */

std::string Starprobe::toString() {
	std::string result = name; // name
	result += " at (";
	result += std::to_string(coords[0]);
	result += ", "; // coordinates
	result += std::to_string(coords[1]);
	result += "). Total distance: ";
	std::stringstream dbl; // double distance conversion to string
	dbl << std::fixed << std::setprecision(2) << distance;
	std::string s = dbl.str();
	result += s;
	result += ". Scanned asteroids: ";
	result += std::to_string(current); // total scanned asteroids
	result += ".\n";
	return result;
}

/*
* @MethodName: doAsteroid
* @Description:
*			Overrides base class' method; Performs a scan on an asteroid
* @Params:
*			int index - the index of the closest asteroid
*			std::vector<Asteroid> &vect - the vector passed in by reference
*			bool ship - true if ship false if probe
*			double max - max weight of asteroid to collect
*			double traveled - passed to print accurately
* @Returns:
*			bool - scanned or not
*/

bool Starprobe::doAsteroid(int index, std::vector<Asteroid> &asts, bool ship, double max, double traveled) {

	// if the scanning mission has not been completed
		// if there's less asteroids than the mission requires, then it is an impossible mission
	if (computer[1] != computer[0] && detectedAsteroids >= computer[0]) {

		// probe action
		std::cout << name << " warped " << std::fixed << std::setprecision(2)
			<< traveled << " light years to: (" << asts[index].get(0) << ", "
			<< asts[index].get(1) << "). Scanning...\n";

		#ifdef __linux__
			usleep(1000000);
		#else
			Sleep(1000);
		#endif

		if (asts[index].isPrecious()) {
			std::cout << "Asteroid contains precious metals! " << (computer[1] + 1) << "/"
				<< computer[0] << "\n\n";
			// increment total number of precious asteroids
			preciousRoids++;
			// add precious asteroid to probe's database
			database.push_back(asts[index]);
		} else
			std::cout << "Asteroid did not contain precious metals... " << (computer[1] + 1)
			<< "/" << computer[0] << "\n\n";

		// increment total number of scanned asteroids
		current++;
		computer[1]++;
		asts[index].setScanned(true);

		#ifdef __linux__
			usleep(800000);
		#else
			Sleep(800);
		#endif

		return true;

	} else // nothing for the probe to do
		std::cout << name << " is idle...\n";

	#ifdef __linux__
		usleep(1000000);
	#else
		Sleep(1000);
	#endif

	return false;

}

Starprobe::~Starprobe() {

}
