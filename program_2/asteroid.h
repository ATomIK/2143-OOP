#pragma once
#include <fstream>
#include <vector>

class Asteroid {

private:
  int x, y;
  double weight;
  bool collected;

public:

  Asteroid();
  Asteroid(int,int,double,bool);

  Asteroid(const Asteroid &);
  //Asteroid();

  bool isCollected();
  double getWeight();

  ~Asteroid();

};
