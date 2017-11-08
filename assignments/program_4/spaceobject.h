#pragma once
#include <string>

class SpaceObject {

protected:
  int coords[2]; // coordinates of the object

  string name; // name of object

public:

  SpaceObject();

  // get coordinate
  int get(int);

  // set coordinate
  void set(int,int);

  ~SpaceObject();

};
