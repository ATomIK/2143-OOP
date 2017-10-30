#pragma once
#include <vector>
#include "asteroid.h"
#include "spaceobject.h"

class Starcraft : public SpaceObject {

protected:

  // asteroids in the field
  int detectedAsteroids;
  // limit of asteroids to collect/visit
  int limit;
  // total weight of asteroids collected
  double cargoWeight;
  // total distance traveled
  double distance;

public:
  Starcraft();

  // return the craft's visitation/collection limit
  int getLimit();

  // return detected asteroids in a field
  int getDetected();

  // return total distance traveled
  double getDist();

  // set detected asteroids in a field
  void setDetected(int);

  // updates the SpaceObject's coordinates (moves to an asteroid) and returns distance
  double moveTo(int,std::vector<Asteroid>&);

  // calculates the closest asteroid
  int findClosest(std::vector<Asteroid>&);

  ~Starcraft();

};
