#include "asteroid.h"

/*
 * @DefaultConstructorName: Asteroid
 * @Description:
 *			Sets all Asteroid variables to 0
 * @Params:
 *			n/a
 * @Returns:
 *			n/a
 */

Asteroid::Asteroid(){
  setCoord(0,0);
  setCoord(0,1);
  weight = 0.0;
  scanned = false;
  collected = false;
  p = false;
}

/*
 * @ConstructorName: Asteroid
 * @Description:
 *			Creates an Asteroid object
 * @Params:
 *			n/a
 * @Returns:
 *			n/a
 */

Asteroid::Asteroid(int setx, int sety, double setw, bool setc, bool scanstat, bool precious){
  setCoord(setx,0);
  setCoord(sety,1);
  weight = setw;
  collected = setc;
  scanned = scanstat;
  p = precious;
}

/*
 * @CopyConstructorName: Asteroid
 * @Description:
 *			A copy constructor for an Asteroid object
 * @Params:
 *			n/a
 * @Returns:
 *			n/a
 */

Asteroid::Asteroid(const Asteroid &obj){
  int x = obj.coords[0], y = obj.coords[1];
  setCoord(x,0);
  setCoord(y,1);
  weight = obj.weight;
  collected = obj.collected;
  scanned = obj.scanned;
  p = obj.p;
}

/*
 * @MethodName: isCollected
 * @Description:
 *			Returns collected status of an Asteroid
 * @Params:
 *			n/a
 * @Returns:
 *			bool - whether an Asteroid is collected or not
 */

bool Asteroid::isCollected(){
  return collected;
}

/*
* @MethodName: isScanned
* @Description:
*			Returns scanned status of an Asteroid
* @Params:
*			n/a
* @Returns:
*			bool - whether an Asteroid is scanned or not
*/

bool Asteroid::isScanned() {
	return scanned;
}

/*
 * @MethodName: getWeight
 * @Description:
 *			Returns weight of an Asteroid
 * @Params:
 *			n/a
 * @Returns:
 *			double - weight
 */

double Asteroid::getWeight(){
  return weight;
}

/*
 * @MethodName: getPrecious
 * @Description:
 *			Returns if the Asteroid has precious metals
 * @Params:
 *			n/a
 * @Returns:
 *			bool - precious metals or not
 */

bool Asteroid::getPrecious(){
  return p;
}

/*
 * @MethodName: setCollected
 * @Description:
 *			Sets an Asteroid's collected status
 * @Params:
 *			bool v - collected or not
 * @Returns:
 *			void
 */

void Asteroid::setCollected(bool v){
  collected = v;
}

/*
* @MethodName: setScanned
* @Description:
*			Sets an Asteroid's scanned status
* @Params:
*			bool v - scanned or not
* @Returns:
*			void
*/

void Asteroid::setScanned(bool v) {
	scanned = v;
}

/*
 * @DestructorName: ~Asteroid
 * @Description:
 *			-
 * @Params:
 *			n/a
 * @Returns:
 *			n/a
 */

Asteroid::~Asteroid(){

}
