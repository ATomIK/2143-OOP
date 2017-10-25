#pragma once
#include <fstream>
#include <vector>
#include "spaceobject.h"

class Asteroid : public SpaceObject {

private:

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
  Asteroid(int,int,double,bool,bool);
  // copy constructor
  Asteroid(const Asteroid &);

  // return collected status
  bool isCollected();
  // return weight
  double getWeight();
  // returns if the asteroid is precious
  bool getPrecious();
  // set the collected status
  void setCollected(bool);

  // default destructor
  ~Asteroid();

};
