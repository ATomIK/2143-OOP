#pragma once
#include <fstream>
#include <vector>

class Asteroid {

private:
  std::ifstream infile;

  int x, y;
  double weight;
  bool collected;

public:

  int line_count;
  std::vector<Asteroid> asteroids;

  Asteroid();
  Asteroid(int,int,double,bool);
  //Asteroid();

  void generateRoids(std::string);

  bool isCollected();
  double getWeight();

  int getLines();

  ~Asteroid();

};
