#include <iostream>
#include <iomanip>
#include <sstream>
#include "spaceobject.h"
#include "starcraft.h"
#include <cmath>

// check in case the program was compiled on linux as it was created on linux
#ifdef __linux__
  #include <unistd.h>
#else
  #include <windows.h>
#endif

// initialize static variables
std::vector<Asteroid> Starcraft::database = {};

int Starcraft::computer[4] = {0};

Starcraft::Starcraft() : SpaceObject() {
  coords[0] = 0;
  coords[1] = 0;
  cargoWeight = 0.0;
  distance = 0.0;
  current = 0;
  limit = 0;
  detectedAsteroids = 0;
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

std::vector<Asteroid> Starcraft::getDb(){ return database; }

/*
 * @MethodName: getLimit
 * @Description:
 *			Return the craft's visitation/collection limit
 * @Params:
 *			n/a
 * @Returns:
 *			int - number limit
 */

int Starcraft::getLimit(){ return limit; }

/*
 * @MethodName: getDetected
 * @Description:
 *			Return detected asteroids in a field
 * @Params:
 *			n/a
 * @Returns:
 *			int - detected asteroids
 */

int Starcraft::getDetected(){ return detectedAsteroids; }

/*
 * @MethodName: getDist
 * @Description:
 *			Return total distance traveled
 * @Params:
 *			n/a
 * @Returns:
 *			double - total distance traveled
 */

double Starcraft::getDist(){ return distance; }

/*
 * @MethodName: getWeight
 * @Description:
 *			Return cargo weight of craft
 * @Params:
 *			n/a
 * @Returns:
 *			double - cargo weight
 */

double Starcraft::getWeight(){ return cargoWeight; }

/*
 * @MethodName: toString
 * @Description:
 *			Returns string of pretty object data
 * @Params:
 *      n/a
 * @Returns:
 *			string - pretty object data
 */

std::string Starcraft::toString(){
  std::string result = "\nCraft mission limit: (";
  result += std::to_string(current);
  result += "/";
  result += std::to_string(limit);
  result += "). Distance traveled: ";
  std::stringstream dbl;
  dbl << std::fixed << std::setprecision(2) << distance;
  std::string s = dbl.str();
  result += s;
  result += ". Cargo bay: ";
  std::stringstream db;
  db << std::fixed << std::setprecision(2) << cargoWeight;
  std::string l = db.str();
  result += l;
  result += ".\n\n";
  return result;
}

/*
 * @MethodName: setDetected
 * @Description:
 *			Set detected asteroids in a field
 * @Params:
 *			int num - number of detected asteroids
 * @Returns:
 *			void
 */

void Starcraft::setDetected(int num){ detectedAsteroids = num; }

/*
 * @MethodName: setWeight
 * @Description:
 *			Set cargo weight of craft
 * @Params:
 *			double w - weight
 * @Returns:
 *			void
 */

void Starcraft::setWeight(double w){ cargoWeight = w; }

/*
 * @MethodName: moveTo
 * @Description:
 *			Moves to the selected asteroid and updates the ship's coordinates.
 * @Params:
 *			int index - the Asteroid's index within the vector
 *      std::vector<Asteroid> &asts - the Asteroid vector
 * @Returns:
 *			double - the distance the ship just traveled
 */

double Starcraft::moveTo(int index, std::vector<Asteroid> &asts){

  double x, y, dist;
  x = asts[index].get(0) - get(0);
  y = asts[index].get(1) - get(1);
  dist = std::sqrt((x*x) + (y*y));
  // increase total distance
  distance+= dist;

  // ship's coordinates are updated
  set(0,asts[index].get(0));
  set(1,asts[index].get(1));

  return dist;

}

/*
* @MethodName: findClosest
* @Description:
*			Loops through the vector of Asteroids and finds the Asteroid closest to
*       the ship's coordinates through basic algebra.
* @Params:
*			std::vector<Asteroid> &vect - the vector passed in by reference
* @Returns:
*			int - index of the Asteroid closest to the ship
*/

int Starcraft::findClosest(std::vector<Asteroid> &vect,bool ship) {

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

    // if ship is false, then it's the starprobe else starship
    bool nt = !ship ? vect[i].isScanned() : vect[i].isCollected();
    // if the asteroid hasn't been collected/scanned and
    // the distance is less than the initial minDist
    // then this is the closest asteroid to the ship
		if (!nt && tempDist < minDist) {
			// had to typecast i as int because of size_type
			index = (int)i;
			minDist = tempDist;
		}

	}

	// return the final closest index in the vector
	return index;

}

/*
* @MethodName: doAsteroid
* @Description:
*			Performs action on the asteroid depending on the ship's type
* @Params:
*     int index -  index of asteroid
*			std::vector<Asteroid> &vect - the vector passed in by reference
*     bool ship - true if ship false if probe
*     double max - max weight of asteroid to collect
* @Returns:
*			void
*/

bool Starcraft::doAsteroid(int index, std::vector<Asteroid> &asts, bool ship, double max){

  // if the craft has not reached its limit
	if (limit != current) {

		if (asts[index].getWeight() < max) {
			// asteroid in the vector is now collected
			asts[index].setCollected(true);
			// asteroid count increases
			current++;
			// ship's cargo weight is updated
      setWeight(getWeight() + asts[index].getWeight());

			std::cout << "Starship warped to: ("
				<< asts[index].get(0) << ", " << asts[index].get(1)
				<< "). Mining asteroid...\n\n";

			// linux has a different sleep function than windows.
			#ifdef __linux__
				usleep(1000000);
			#else
				Sleep(1000);
			#endif

      return true;

		}

	} else
		std::cout << "Starship is idle...\n";

  return false;

}

Starcraft::~Starcraft() {

}
