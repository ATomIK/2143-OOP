#pragma once
#include <vector>
#include <cmath>
#include "asteroid.h"
#include "starcraft.h"

class Starship : public Starcraft {

private:
  // asteroids currently collected
  int asteroids;

public:

  Starship();

  // method to set limit and coordinates
  void flightPlan();
  // gets amount of asteroids collected
  int getAsteroidCount();


  // "mines" an asteroid
  void mineAsteroid(int, std::vector<Asteroid>&);
  // "blasts" an asteroid
  void blAsteroid(int, std::vector<Asteroid>&);

  // formats output
  //void transmitData(int, std::vector<Asteroid>&, double, std::fstream&);

  ~Starship();

};
