#pragma once
#include <fstream>
#include <vector>
#include "spaceobject.h"

class Asteroid : public SpaceObject {

private:

  // weight of Asteroid
  double weight;
  // collected status and scanned status
  bool collected, scanned;
  // does it contain precious metals
  bool p;

public:

  // default constructor
  Asteroid();
  // constructor
  Asteroid(int,int,double,bool,bool,bool);
  // copy constructor
  Asteroid(const Asteroid &);

  // return collected status
  bool isCollected();
  // return scanned status
  bool isScanned();
  // return weight
  double getWeight();
  // returns if the asteroid is precious
  bool getPrecious();
  // set the collected status
  void setCollected(bool);
  // set the scanned status
  void setScanned(bool);

  // default destructor
  ~Asteroid();

};
