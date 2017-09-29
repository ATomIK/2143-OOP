#pragma once
#include <fstream>
#include <vector>
#include "asteroid.h"

class AsteroidList {

private:
  std::ifstream infile;

  // int ast_limit;
  int line_count;
  std::vector<Asteroid> asteroids;

public:

  AsteroidList();

  int getLines();
  void generateRoids(std::string);

  // ~AsteroidList();

};
