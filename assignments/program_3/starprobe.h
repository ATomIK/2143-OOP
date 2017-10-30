#pragma once
#include <vector>
#include "starcraft.h"
#include "asteroid.h"

class Starprobe : public Starcraft {

protected:
	int preciousRoids, scanned;
	std::vector<Asteroid> pAsteroids;

public:

  Starprobe();

	// return scanned asteroids
	int getScanned();

	// return number of precious asteroids
	int getPrecious();

  // discusses plans with the captain of the star ship
  void flightPlan();

  // finds the closest non scanned asteroid
  int findClosest(std::vector<Asteroid>&);

  void scanAsteroid(int, std::vector<Asteroid>&);

  ~Starprobe();

};
