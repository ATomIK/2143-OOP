#pragma once

class SpaceObject {

protected:
  int coords[2]; // coordinates of the object

public:

  SpaceObject();

  // get coordinate
  int get(int);

  // set coordinate
  void set(int,int);

  ~SpaceObject();

};
