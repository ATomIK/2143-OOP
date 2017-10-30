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
  coords[0] = 0;
  coords[1] = 0;
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
  coords[0] = setx;
  coords[1] = sety;
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
  coords[0] = obj.coords[0];
  coords[1] = obj.coords[1];
  weight = obj.weight;
  collected = obj.collected;
  scanned = obj.scanned;
  p = obj.p;
}

/*
 * @MethodName: isCollected
 * @Description:
 *			Return collection status
 * @Params:
 *			n/a
 * @Returns:
 *			int - collected
 */

int Asteroid::isCollected(){ return collected; }

/*
 * @MethodName: isScanned
 * @Description:
 *			Return scanned status
 * @Params:
 *			n/a
 * @Returns:
 *			int - scanned
 */

int Asteroid::isScanned(){ return scanned; }

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
