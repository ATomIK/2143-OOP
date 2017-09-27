#include <iostream>
#include "asteroid.h"

Asteroid::Asteroid(){

}

Asteroid::Asteroid(int setx, int sety, double setw, bool setc){
  x = setx;
  y = sety;
  weight = setw;
  c = setc;
}

bool Asteroid::isCollected(){
  return c;
}

double Asteroid::getWeight(){
  return weight;
}

Asteroid::~Asteroid(){

}
