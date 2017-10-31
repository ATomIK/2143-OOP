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
  // current number of asteroids scanned/collected
  int current;
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

  // return weight of craft's cargo bay
  double getWeight();

  // set detected asteroids in a field
  void setDetected(int);

  // set cargo weight of craft
  void setWeight(double);

  // updates the SpaceObject's coordinates (moves to an asteroid) and returns distance
  double moveTo(int,std::vector<Asteroid>&);

  // calculates the closest asteroid
  // bool if ship else probe
  int findClosest(std::vector<Asteroid>&,bool);

  // perferms action on the asteroid depending on ship type
  // bool if ship else probe
  virtual bool doAsteroid(int,std::vector<Asteroid>&,bool,double);

  ~Starcraft();

};
