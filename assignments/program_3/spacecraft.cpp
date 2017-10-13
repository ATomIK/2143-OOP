SpaceCraft::SpaceCraft() : SpaceObject(){

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
  x = asts[index].getX() - coords[0];
  y = asts[index].getY() - coords[1];
  dist = std::sqrt((x*x) + (y*y));
  // increase total distance
  distance+= dist;

  // ship's coordinates are updated
  coords[0] = asts[index].getX();
  coords[1] = asts[index].getY();

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
    x = vect[i].getX() - coords[0];
    y = vect[i].getY() - coords[1];
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

SpaceCraft::~SpaceCraft() : ~SpaceObject(){

}
