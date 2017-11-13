#include "spaceobject.h"

SpaceObject::SpaceObject(){

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
  result += " is currently at coords [";
  result += coords[0];
  result += ", ";
  result += coords[1];
  result += "]\n\n";
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
