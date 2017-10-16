#include <iostream>

#include "parent.h"
#include "child.h"

using namespace std;

int main(){

  Child child;

  child.setCoords(5,7);

  cout << child.getX() << "\n";

  cout << child.getY() << "\n";

  return 0;
}
