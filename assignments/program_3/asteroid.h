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

  // need to do these next
  // void setCollected(bool);

  // void setScanned(bool);

  // default destructor
  ~Asteroid();

};
