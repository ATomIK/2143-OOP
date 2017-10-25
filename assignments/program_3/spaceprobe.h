#pragma once
#include <vector>
#include "spacecraft.h"
#include "asteroid.h"

class SpaceProbe : public SpaceCraft {

private:
	int preciousRoids;
	int scanned;

protected:

public:

  SpaceProbe();

  // discusses plans with the captain of the star ship
  void plans();

  // finds the closest non scanned asteroid
  int findClosest(std::vector<Asteroid>&);

  // scans the asteroid ( starships are capable of this, but are more focused on mining )
  void scanAsteroid(int, std::vector<Asteroid>&);

  // return how many asteroids it scanned that are precious
  int getPreciousRoids();

  int getScannedCount();

  ~SpaceProbe();

};
