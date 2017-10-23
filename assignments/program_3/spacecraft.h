#pragma once

class SpaceCraft : public SpaceObject {

private:

protected:

public:
  SpaceCraft() : SpaceObject();

  // updates the SpaceObject's coordinates (moves to an asteroid)
  void moveTo(int,std::vector<Asteroid>&);

  // calculates the closest asteroid
  int findClosest(std::vector<Asteroid>&);

  ~SpaceCraft() : ~SpaceObject();

};
