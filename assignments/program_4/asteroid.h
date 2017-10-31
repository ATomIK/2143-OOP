#pragma once
#include <fstream>
#include <vector>
#include "spaceobject.h"

class Asteroid : public SpaceObject {

protected:

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

  // return collection status
  bool isCollected();

  // return scanned status
  bool isScanned();

  // return precious status
  bool isPrecious();

  // return weight of asteroid
  double getWeight();

  // sets collected status
  void setCollected(bool);

  // sets scanned status
  void setScanned(bool);

  // default destructor
  ~Asteroid();

};
