#pragma once
#include <vector>
#include "starcraft.h"
#include "asteroid.h"

class Starprobe : public Starcraft {

private:
	int preciousRoids;
	int scanned;
	std::vector<Asteroid> pAsteroids;

protected:

public:

  Starprobe();

  // discusses plans with the captain of the star ship
  void flightPlan();

  // finds the closest non scanned asteroid
  int findClosest(std::vector<Asteroid>&);

  // scans the asteroid ( starships are capable of this, but are more focused on mining )
  void scanAsteroid(int, std::vector<Asteroid>&);

  // return how many asteroids it scanned that are precious
  int getPreciousRoids();

  int getScannedCount();

  ~Starprobe();

};
