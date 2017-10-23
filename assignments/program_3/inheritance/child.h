#pragma once
#include "parent.h"

class Child : protected Parent {
private:

public:
  Child();

  void setCoords(int,int);

  void echoCoords();

};
