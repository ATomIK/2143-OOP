#pragma once
#include <vector>
#include <cmath>
#include "asteroid.h"

class Starship {

private:
  int detectedAsteroids;
  int limit;

  int coords[2];

  int asteroids;
  double cargoWeight;
  double distance;

public:
  Starship();

  void captainsLog();

  void setDetected(int);
  int getLimit();
  int getDistance();
  int getAsteroidCount();
  int getDetectedAsteroids();

  int findClosest(std::vector<Asteroid>&);
  void moveTo(int, std::vector<Asteroid>&);

  void mineAsteroid(int, std::vector<Asteroid>&);
  void blAsteroid(int, std::vector<Asteroid>&);

};
