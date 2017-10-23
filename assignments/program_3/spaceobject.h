#pragma once

class SpaceObject {

private:
  int coords[2]; // coordinates of the object

protected:

public:

  SpaceObject();

  // returns coordinate
  int getCoord(int);
  // sets coordinate
  void setCoord(int,int);

  ~SpaceObject();

};
