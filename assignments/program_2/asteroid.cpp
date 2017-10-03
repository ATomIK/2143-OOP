#include "asteroid.h"

Asteroid::Asteroid(){

}

Asteroid::Asteroid(int setx, int sety, double setw, bool setc){
  x = setx;
  y = sety;
  weight = setw;
  collected = setc;
}

Asteroid::Asteroid(const Asteroid &obj){
  x = obj.x;
  y = obj.y;
  weight = obj.weight;
  collected = obj.collected;
}

bool Asteroid::isCollected(){
  return collected;
}

double Asteroid::getWeight(){
  return weight;
}

int Asteroid::getX(){
  return x;
}

int Asteroid::getY(){
  return y;
}

void Asteroid::setCollected(bool v){
  collected = v;
}

Asteroid::~Asteroid(){

}
