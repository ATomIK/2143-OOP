#pragma once

class SpaceCraft : public SpaceObject {

private:


public:
  SpaceCraft() : SpaceObject();

  void moveTo(int,std::vector<Asteroid>&);

  int findClosest(std::vector<Asteroid>&);

  ~SpaceCraft() : ~SpaceObject();

};
