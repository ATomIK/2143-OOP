#include "child.h"

void Child::setCoords(int x, int y){

  coords[0] = x;
  coords[1] = y;

}

int Child::getX(){

  return coords[0];

}

int Child::getY(){

  return coords[1];

}
