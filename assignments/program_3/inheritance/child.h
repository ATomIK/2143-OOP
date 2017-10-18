#pragma once
#include "parent.h"

class Child : private Parent {
private:

public:
  Child();

  void setCoords(int,int);

  void echoCoords();

};
