#include <iostream>
#include <iomanip>
#ifdef __linux__
  #include <unistd.h>
#endif
#include "starship.h"

Starship::Starship(){
  asteroids = 0;
}

void Starship::captainsLog(){

  // warp using pre-defined or manually defined coords?
  int choice;
  std::cout << "Would you like to warp using "
					"pre-defined coordinates?\n\n1. Yes\n2. No.\n";
	std::cin >> choice;

  // if manually defined, set x and y
  int x = 0, y = 0;
	if(choice == 2){
		std::cout << "Please enter an x coordinate followed by a y coordinate\n "
		"for the ship to warp to. (Example: 5 25):";
		std::cin >> x >> y;
	}
  std::cout << "\nWarping to (" << x << "," << y << ")...\n\n";
  // ship will now begin its mission at the specified launchCoords
  coords[0] = x;
  coords[1] = y;

  // set the limit of the ship's mission
	std::cout << "How many asteroids <9 tons would you like to collect before\n "
					"returning to earth? (integer): ";
	std::cin >> limit;
  std::cout << "\n";

}

void Starship::setDetected(int i){
  detectedAsteroids = i;
}

int Starship::getLimit() {
  return limit;
}

int Starship::getDistance() {
  return distance;
}

int Starship::getAsteroidCount(){
  return asteroids;
}

int Starship::getDetectedAsteroids(){
  return detectedAsteroids;
}

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
    #ifdef __linux__
      usleep(1000000);
    #else
      Sleep(1000);
    #endif
    return true;
  } else {

    int choice;
    std::cout << "\nUh-oh, you've encountered an asteroid too large for our drill!"
              << "\nWould you like to blast it?\n1. Yes\n2. No\n";
    std::cin >> choice;
    std::cout << "\n";

    if(choice == 2)
      asts[index].setCollected(true); // not really collected, just ignored
    else {
      blAsteroid(index, asts);
    }
  }
  return false;

}

void Starship::blAsteroid(int index, std::vector<Asteroid> &asts){
  int pieces;
  double weight;

  srand(time(NULL));

  pieces = rand() % 5;

  weight = asts[index].getWeight()/pieces;

  std::cout << "Asteroid exploded.\n";

  if(!pieces)
    std::cout << "You vaporized that asteroid! Woops..\n";

  for (int j = 0;j < pieces;j++){

    int x = rand()%100, y = rand()%100;

    Asteroid temp = Asteroid(x, y, weight, 0);
    asts.push_back(temp);

    if(x == coords[0] && y == coords[1]){
      std::cout << "A piece flew into your ship. Repair bots are on the way\n";
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

  asts.erase(asts.begin() + index); // blow up that asteroid

}

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
