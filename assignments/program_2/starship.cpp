#include <iostream>
#include <iomanip>

// check in case the program was compiled on linux as it was created on linux
#ifdef __linux__
  #include <unistd.h>
#endif

#include "starship.h"

/*
 * @DefaultConstructorName: Starship
 * @Description:
 *			Sets all Starship variables to 0
 * @Params:
 *			n/a
 * @Returns:
 *			n/a
 */

Starship::Starship(){
  asteroids = 0;
  cargoWeight = 0.0;
  distance = 0.0;

  coords[0] = 0;
  coords[1] = 0;

  limit = 0;
  detectedAsteroids = 0;
}

/*
 * @MethodName: captainsLog
 * @Description:
 *			Prompts the user for initial warp coordinates and asteroid collection
 * @Params:
 *			n/a
 * @Returns:
 *			void
 */

void Starship::captainsLog(){

  // warp using pre-defined or manually defined coords?
  int choice;
  std::cout << "Would you like to warp using "
					"pre-defined coordinates?\n\n1. Yes\n2. No.\n";
	std::cin >> choice;

  // if manually defined, set x and y
	if(choice == 2){
		std::cout << "Please enter an x coordinate followed by a y coordinate\n "
		"for the ship to warp to. (Example: 5 25):";
		std::cin >> coords[0] >> coords[1];
	}
  std::cout << "\nWarping to (" << coords[0] << "," << coords[1] << ")...\n\n";

  // set the limit of the ship's mission
	std::cout << "How many asteroids <9 tons would you like to collect before\n "
					"returning to earth? (integer): ";
	std::cin >> limit;
  std::cout << "\n";

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

void Starship::setDetected(int i){
  detectedAsteroids = i;
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

int Starship::getLimit() {
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

int Starship::getDistance() {
  return distance;
}

/*
 * @MethodName: getAsteroidCount
 * @Description:
 *			Returns the current total amount of collected asteroids.
 * @Params:
 *			n/a
 * @Returns:
 *			int - number of asteroids collected by the ship
 */

int Starship::getAsteroidCount(){
  return asteroids;
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

int Starship::getDetectedAsteroids(){
  return detectedAsteroids;
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
int Starship::findClosest(std::vector<Asteroid> &vect) {

  double minDist = 0;

  // loop through all asteroids
  int index = 0;
  // set initial minDist to the maximum double value possible
  minDist = 1.79769e+308;
  // go through vector to compare distances
  for(int i = 0;i < vect.size();i++){

    double tempDist = 0;

    int x, y;
    x = vect[i].getX() - coords[0];
    y = vect[i].getY() - coords[1];
    // ship distancec from asteroid[i]
    tempDist = std::sqrt((x*x + y*y));
    // if the asteroid hasn't been collected and
    // the distance is less than the initla minDist
    // then this is the closest asteroid to the ship
    if(!vect[i].isCollected() && tempDist < minDist){
      index = i;
      minDist = tempDist;
    }

  }

  // return the final closest index in the vector
  return index;

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

double Starship::moveTo(int index, std::vector<Asteroid> &asts){

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
 * @MethodName: mineAsteroid
 * @Description:
 *			If the Asteroid's weight is less than 9.0 tons, the ship will "mine"
 *      the asteroid. The Asteroid will be set to collected, the ship's asteroid
 *      count will be incremented, and the cargo weight will be updated. If it's
 *      bigger than 9.0, prompt the user whether to blast it or ignore it.
 * @Params:
 *			int index - index of the Asteroid the ship will be "mining"
 *      std::vector<Asteroid> &asts - vector of Asteroids
 * @Returns:
 *			bool - whether the ship mined something or not
 */

bool Starship::mineAsteroid(int index, std::vector<Asteroid> &asts){

  if(asts[index].getWeight() < 9.0){
    // asteroid in the vector is now collected
    asts[index].setCollected(true);
    // asteroid count increases
    asteroids++;
    // ship's cargo weight is updated
    cargoWeight = cargoWeight + asts[index].getWeight();

    // std::cout << "Asteroid weight: " << asts[index].getWeight() << "\n";
    std::cout << "Warped to: ("
              << asts[index].getX() << ", " << asts[index].getY()
              << "). Mining asteroid...\n";

    // linux has a different sleep function than windows.
    #ifdef __linux__
      usleep(1000000);
    #else
      Sleep(1000);
    #endif

    // ship mined an asteroid.
    return true;
  } else {

    // prompt the user for a choice
    int choice;
    std::cout << "\nUh-oh, you've encountered an asteroid too large for our drill!"
              << "\nWould you like to blast it?\n1. Yes\n2. No\n";
    std::cin >> choice;
    std::cout << "\n";

    // User chose not to blast it, ignoring it.
    if(choice == 2){
      asts.erase(asts.begin() + index); // delete asteroid from field

      std::cout << "Ignoring asteroid...\n\n";
    } else {
      // blast the asteroid
      blAsteroid(index, asts);
    }
  }
  // ship did no mine an asteroid
  return false;

}

/*
 * @MethodName: blAsteroid
 * @Description:
 *			Randomly generates number of pieces from 0 - 5. The weight of those
 *      pieces is equal to the original asteroid. The pieces are added onto the
 *      Asteroid vector and dispersed throughout the 100x100 field randomly. If
 *      a piece is dispersed directly into the ship, the ship will be damaged
 *      and will have to wait 3 seconds until repaired to complete the mission.
 * @Params:
 *			n/a
 * @Returns:
 *			void
 */

void Starship::blAsteroid(int index, std::vector<Asteroid> &asts){
  int pieces;
  double weight;

  srand(time(NULL));

  pieces = rand() % 5;

  weight = asts[index].getWeight()/pieces;

  std::cout << "Asteroid exploded.\n";

  // if pieces is 0
  if(!pieces)
    std::cout << "You vaporized that asteroid! Woops..\n";

  // loop will only work if pieces is > 0.
  for (int j = 0;j < pieces;j++){

    // generate random coordinates
    int x = rand()%100, y = rand()%100;

    // created asteroid and add it to the vector
    Asteroid temp = Asteroid(x, y, weight, 0);
    asts.push_back(temp);

    // A piece flew into the ship if its coordinates equal the ship's coordinates
    if(x == coords[0] && y == coords[1]){
      // Captain is alerted and repait bots are called
      std::cout << "A piece flew into your ship. Repair bots are on the way\n";
      // Repair bots are repairing the ship...
      #ifdef __linux__
        usleep(3000000);
      #else
        Sleep(3000);
      #endif
      std::cout << "Repaired!\n";
    } else
      std::cout << "A piece flew to: (" << x << ", " << y << ")\n";

  }

  std::cout << "\n";

  asts.erase(asts.begin() + index); // asteroid blows up

}

/*
 * @MethodName: transmitData
 * @Description:
 *			Formats output for the best legibility
 * @Params:
 *			int i - index of the Asteroid being described
 *      std::vector<Asteroid> &asts - vector of Asteroids
 *      double distance - distance it took to get to that Asteroid
 *      std::fstream &ofile - output stream to format to
 * @Returns:
 *			void
 */

void Starship::transmitData(int i, std::vector<Asteroid> &asts, double distance, std::fstream &ofile){

  ofile << std::left << std::setw(4) << " " << std::setw(10) << i;

  ofile << "("
        << std::setfill('0') << std::setw(3) << std::right << asts[i].getX()
       << ", "
        << std::setfill('0') << std::setw(3) << std::right << asts[i].getY()
       << std::setfill(' ') << std::left << std::setw(4) << ")";

  ofile << std::fixed << std::setprecision(2) << std::setw(15) << asts[i].getWeight();

  ofile << std::fixed << std::setprecision(2) << std::setw(12) << (distance*10) << "\n";

}

/*
 * @DestructorName: ~Starship
 * @Description:
 *			-
 * @Params:
 *			n/a
 * @Returns:
 *			n/a
 */

Starship::~Starship(){

}
