#pragma once
#include <fstream>
#include <vector>
#include "spaceobject.h"

class Asteroid : public SpaceObject {

private:
  // coords[2] are inherited from SpaceObject

  // weight of Asteroid
  double weight;
  // collected status
  bool collected;
  // does it contain precious metals
  bool p;

public:

  // default constructor
  Asteroid();
  // constructor
  Asteroid(int,int,double,bool);
  // copy constructor
  Asteroid(const Asteroid &);

  // return collected status
  bool isCollected();
  // return weight
  double getWeight();
  // return x coordinate
  int getX();
  // return y coordinate
  int getY();

  // set the collected status
  void setCollected(bool);

  // default destructor
  ~Asteroid();

};