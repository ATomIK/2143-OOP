#pragma once
#include "asteroid.h"

class Starship {

private:
  int limit;
  double distance;

  int coords[2];
  int asteroids;
  double cargoWeight;

public:
  Starship();

  void captainsLog(std::string&,std::string&);
  int getLimit();

  int findClosest(std::vector<Asteroid>&);
  void moveTo(int, std::vector<Asteroid>&);
  void mineAsteroid(int, std::vector<Asteroid>&);

};
