#pragma once

class SpaceObject {

protected:
  int coords[2]; // coordinates of the object

private:


public:

  SpaceObject();

  // return x coordinate
  int getX();
  // return y coordinate
  int getY();

  ~SpaceObject();

};
