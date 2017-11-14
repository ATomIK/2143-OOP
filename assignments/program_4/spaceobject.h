#pragma once
#include <string>

class SpaceObject {

protected:
  int coords[2]; // coordinates of the object

  std::string name; // name of object

public:

  SpaceObject();

  SpaceObject(int,int);

  SpaceObject(std::string,int,int);

  // get coordinate
  int get(int);

  // object data to pretty string
  std::string toString();

  // set coordinate
  void set(int,int);

  ~SpaceObject();

};
