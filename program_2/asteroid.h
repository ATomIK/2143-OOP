#pragma once

class Asteroid {

private:
  int x, y;
  double weight;
  bool c;

public:
  Asteroid();
  Asteroid(int,int,double,bool);
  //Asteroid();

  bool isCollected();
  double getWeight();

  ~Asteroid();

};
