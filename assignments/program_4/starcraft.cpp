#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include "spaceobject.h"
#include "starcraft.h"

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
  detectedAsteroids = 0;
}

Starcraft::Starcraft(std::string n, int x, int y) : SpaceObject(n,x,y) {
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
  // returns scan mission status and mining mission status
  std::string result = "\nScan mission: (";
  result += std::to_string(computer[1]);
  result += "/";
  result += std::to_string(computer[0]);
  result += "). Mining mission: (";
  result += std::to_string(computer[4]);
  result += "/";
  result += std::to_string(computer[3]);
  result += ").\n\n";
  return result;
}

/*
 * @MethodName: setComputer
 * @Description:
 *			Set Starcraft's computer data
 * @Params:
 *			int a[] - computer data
 * @Returns:
 *			void
 */

void Starcraft::setComputer(int a[]){
  computer[0] = a[0];
  computer[1] = a[1];
  computer[2] = a[2];
  computer[3] = a[3];
}

/*
 * @MethodName: getComputer
 * @Description:
 *			Set Starcraft's computer data
 * @Params:
 *			int a[] - computer data
 * @Returns:
 *			void
 */

int Starcraft::getComputer(int type){
  return computer[type];
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
 * @MethodName: computeDistance
 * @Description:
 *			Computes hypotenuse of two (x,y) locations
 * @Params:
 *			int index - the Asteroid's index within the vector
 *      std::vector<Asteroid> &asts - the Asteroid vector
 *      bool ship - whether to use database or main's asteroid vector
 * @Returns:
 *			double - the hypotenuse
 */

double Starcraft::computeDistance(int i, std::vector<Asteroid> &asts,bool ship){

  double x, y, dist;
  x = (ship ? database[i].get(0) : asts[i].get(0)) - get(0);
  y = (ship ? database[i].get(1) : asts[i].get(1)) - get(1);
  dist = std::sqrt((x*x) + (y*y));
  return dist;

}

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

  double dist = computeDistance(index,asts,0);
  // increase total distance
  distance += dist;

  // ship's coordinates are updated
  coords[0] = asts[index].get(0);
  coords[1] = asts[index].get(1);
  // set(0,asts[index].get(0));
  // set(1,asts[index].get(1));

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
	for (std::vector<Asteroid>::size_type i = 0; i < (!ship ? vect.size() : database.size()); i++) {

		double tempDist = computeDistance(i,vect,ship);

    // if starship check database if probe check from field
    bool nt = ship ? database[i].isCollected() : vect[i].isScanned();
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

bool Starcraft::doAsteroid(int i, std::vector<Asteroid> &asts, bool ship, double max, double traveled){
  // method is overriden in the starprobe class, so everything is defaulted to starship
  // if the mission has not been completed
	if (computer[3] != computer[2]) {

    std::cout << name << " warped " << std::fixed << std::setprecision(2) <<
      traveled << " light years to: ("
      << database[i].get(0) << ", " << database[i].get(1)
      << "). Mining asteroid...\n";

		if (database[i].getWeight() < max) {
			// asteroid in the vector is now collected
      // do the operator= here
			database[i].setCollected(true);
			// asteroid count increases
			current++;
      computer[3]++;
			// ship's cargo weight is updated
      // setWeight(getWeight() + database[i].getWeight());
      cargoWeight += database[i].getWeight();

      #ifdef __linux__
				usleep(800000);
			#else
				Sleep(8000);
			#endif

      std::cout << "Asteroid mined! Cargo bay: " << cargoWeight << " kilotons.\n\n";

			// linux has a different sleep function than windows.
			#ifdef __linux__
				usleep(1000000);
			#else
				Sleep(1000);
			#endif

      return true;

		} else
      std::cout << "Asteroid is bigger than " << max << " kilotons!!\n";

	} else
		std::cout << name << " is idle...\n\n";

  #ifdef __linux__
    usleep(1000000);
  #else
    Sleep(1000);
  #endif

  return false;

}

Starcraft::~Starcraft() {

}
