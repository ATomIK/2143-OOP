#pragma once
#include <vector>
#include <cmath>
#include "asteroid.h"
#include "spacecraft.h"

class Starship : public SpaceCraft {

private:
  // asteroids currently collected
  int asteroids;

public:

  Starship();

  // method to set limit and coordinates
  void captainsLog();
  // gets amount of asteroids collected
  int getAsteroidCount();


  // "mines" an asteroid
  bool mineAsteroid(int, std::vector<Asteroid>&);
  // "blasts" an asteroid
  void blAsteroid(int, std::vector<Asteroid>&);

  // formats output
  void transmitData(int, std::vector<Asteroid>&, double, std::fstream&);

  ~Starship();

};
