#pragma once
#include <vector>
#include "spacecraft.h"
#include "asteroid.h"

class SpaceProbe : public SpaceCraft {

private:
  vector<Asteroid> preciousRoids;

protected:

public:

  SpaceProbe();



  ~SpaceProbe();

};
