#include "spaceobject.h"

SpaceObject::SpaceObject(){
  name = "Spaceobject";
  coords[0] = 0;
  coords[1] = 0;
}

SpaceObject::SpaceObject(int x, int y){
  name = "Spaceobject";
  coords[0] = x;
  coords[1] = y;
}

SpaceObject::SpaceObject(std::string n, int x, int y){
  name = n;
  coords[0] = x;
  coords[1] = y;
}

/*
 * @MethodName: get
 * @Description:
 *			Return specified coordinate
 * @Params:
 *			int t - 0 for x 1 for y
 * @Returns:
 *			int - specified coordinate
 */

int SpaceObject::get(int t){ return coords[t]; }

/*
 * @MethodName: toString
 * @Description:
 *			Returns string of pretty object data
 * @Params:
 *      n/a
 * @Returns:
 *			string - pretty object data
 */

std::string SpaceObject::toString(){
  std::string result = name;

  result += " at (";
  result += std::to_string(coords[0]);
  result += ", ";
  result += std::to_string(coords[1]);
  result += ")\n\n";
  
  return result;
}

/*
 * @MethodName: set
 * @Description:
 *			Sets specified coordinate
 * @Params:
 *			int t - 0 for x 1 for y
 *      int v - value of coordinate
 * @Returns:
 *			void
 */

void SpaceObject::set(int t,int v){ coords[t] = v; }

SpaceObject::~SpaceObject(){

}
