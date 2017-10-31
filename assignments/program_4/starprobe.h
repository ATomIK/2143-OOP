#pragma once
#include <vector>
#include "starcraft.h"
#include "asteroid.h"

class Starprobe : public Starcraft {

protected:
	int preciousRoids;
	std::vector<Asteroid> database;

public:

  Starprobe();

	// return scanned asteroids
	int getScanned();

	// return number of precious asteroids
	int getPrecious();

	// return database of scanned asteroids
	std::vector<Asteroid> getDb();

  // discusses plans with the captain of the star ship
  void flightPlan();

	// override base class' doAsteroid method
  bool doAsteroid(int,std::vector<Asteroid>&,bool,double);

  ~Starprobe();

};
