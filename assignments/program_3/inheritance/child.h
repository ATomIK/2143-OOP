#pragma once
#include "parent.h"

class Child : protected Parent {
private:

public:
  void setCoords(int,int);

  int getX();
  int getY();

};
