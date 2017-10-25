#include "spaceobject.h"
#include "spacecraft.h"
#include <cmath>

SpaceCraft::SpaceCraft(){
  setCoord(0,0);
  setCoord(0,1);
  cargoWeight = 0.0;
  distance = 0.0;

  limit = 0;
  detectedAsteroids = 0;
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

double SpaceCraft::moveTo(int index, std::vector<Asteroid> &asts){

  double x, y, dist;
  x = asts[index].getCoord(0) - getCoord(0);
  y = asts[index].getCoord(1) - getCoord(1);
  dist = std::sqrt((x*x) + (y*y));
  // increase total distance
  distance+= dist;

  // ship's coordinates are updated
  setCoord(asts[index].getCoord(0),0);
  setCoord(asts[index].getCoord(1),1);

  return dist;

}

/*
 * @MethodName: setDetected
 * @Description:
 *			Sets detected asteroids so the ship will know when to stop trying to collect
 * @Params:
 *			int i - the number of asteroids that exist in the field
 * @Returns:
 *			void
 */

void SpaceCraft::setDetected(int i){
  detectedAsteroids = i;
}

/*
 * @MethodName: setLimit
 * @Description:
 *			Sets the collection limit.
 * @Params:
 *			int - limit
 * @Returns:
 *			void
 */

void SpaceCraft::setLimit(int lim) {
  limit = lim;
}

/*
 * @MethodName: setWeight
 * @Description:
 *			Sets the weight of the spacecraft.
 * @Params:
   *			double - weight
 * @Returns:
 *			void
 */

void SpaceCraft::setWeight(double w) {
  cargoWeight = w;
}

/*
 * @MethodName: getLimit
 * @Description:
 *			Returns the user-specified collection limit.
 * @Params:
 *			n/a
 * @Returns:
 *			int - user-specified asteroid collection limit
 */

int SpaceCraft::getLimit() {
  return limit;
}

/*
 * @MethodName: getDistance
 * @Description:
 *			Returns the current total distance traveled by the ship.
 * @Params:
 *			n/a
 * @Returns:
 *			int - total distance the ship has traveled
 */

double SpaceCraft::getDistance() {
  return distance;
}

/*
 * @MethodName: getDetectedAsteroids
 * @Description:
 *			Returns the amount of asteroids detected in a field.
 * @Params:
 *			n/a
 * @Returns:
 *			int - detected asteroids
 */

int SpaceCraft::getDetectedAsteroids(){
  return detectedAsteroids;
}

/*
 * @MethodName: getWeight
 * @Description:
 *			Returns the weight of the craft's cargo bay
 * @Params:
 *			n/a
 * @Returns:
 *			double - weight
 */

double SpaceCraft::getWeight(){
  return cargoWeight;
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
int SpaceCraft::findClosest(std::vector<Asteroid> &vect) {

  // set initial minDist to the maximum double value possible
  double minDist = 1.79769e+308;

  // loop through all asteroids
  int index = 0;
  // go through vector to compare distances
  // set i's type to vector's size_type to avoid possible loss of data
  for(std::vector<Asteroid>::size_type i = 0;i < vect.size();i++){

    double tempDist = 0;

    // start new method: computeDistance
    int x, y;
    x = vect[i].getCoord(0) - getCoord(0);
    y = vect[i].getCoord(1) - getCoord(1);
    // ship distancec from asteroid[i]
    tempDist = std::sqrt((x*x + y*y));
    // end new method: computeDistance
    // tempDist = computeDistance(vect[i].getX(), vect[i].getY());

    // if the asteroid hasn't been collected and
    // the distance is less than the initla minDist
    // then this is the closest asteroid to the ship
    if(!vect[i].isCollected() && tempDist < minDist){
	  // had to typecast i as int because of size_type
      index = (int)i;
      minDist = tempDist;
    }

  }

  // return the final closest index in the vector
  return index;

}

SpaceCraft::~SpaceCraft(){

}
