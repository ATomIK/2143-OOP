#include "iostream"
#include "child.h"

Child::Child(){
  coords[0] = 0;
  coords[1] = 1;
}

void Child::setCoords(int x, int y){

  coords[0] = x;
  coords[1] = y;

  std::cout << "Set: " << coords[0] << ", " << coords[1] << "\n";

}

void Child::echoCoords(){

  std::cout << getX() << ", " << getY() << "\n";

}
