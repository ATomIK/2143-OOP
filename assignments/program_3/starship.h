#pragma once
#include <vector>
#include <cmath>
#include "asteroid.h"

class Starship : public SpaceObject {

private:
  // asteroids in the field
  int detectedAsteroids;
  // limit of asteroids to collect
  int limit;

  // ship coordinates
  int coords[2];

  // asteroids currently collected
  int asteroids;
  // total weight of asteroids collected
  double cargoWeight;
  // total distance traveled
  double distance;

public:

  Starship();

  // method to set limit and coordinates
  void captainsLog();

  // sets detectedAsteroids
  void setDetected(int);
  // gets the ship's collection limit
  int getLimit();
  // gets the ship's current total distance traveled
  double getDistance();
  // gets amount of asteroids collected
  int getAsteroidCount();
  // gets total amount of asteroids within a field
  int getDetectedAsteroids();

  // method to calculate the closest asteroid
  int findClosest(std::vector<Asteroid>&);
  // method to update the ship's coordinates and move to an Asteroid
  double moveTo(int, std::vector<Asteroid>&);

  // "mines" an asteroid
  bool mineAsteroid(int, std::vector<Asteroid>&);
  // "blasts" an asteroid
  void blAsteroid(int, std::vector<Asteroid>&);

  // formats output
  void transmitData(int, std::vector<Asteroid>&, double, std::fstream&);

  ~Starship();

};
