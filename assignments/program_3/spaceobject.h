#pragma once

class SpaceObject {

private:

protected:
  int coords[2]; // coordinates of the object

public:

  SpaceObject();

  // returns coordinate
  int getCoord(int);
  // sets coordinate
  void setCoord(int,int);

  ~SpaceObject();

};
