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
  x = 0;
  y = 0;
  weight = 0.0;
  collected = false;
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

Asteroid::Asteroid(int setx, int sety, double setw, bool setc){
  x = setx;
  y = sety;
  weight = setw;
  collected = setc;
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
  x = obj.x;
  y = obj.y;
  weight = obj.weight;
  collected = obj.collected;
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
 * @MethodName: getX
 * @Description:
 *			Returns x coordinate of Asteroid
 * @Params:
 *			n/a
 * @Returns:
 *			int - x coordinate
 */

int Asteroid::getX(){
  return x;
}

/*
 * @MethodName: getY
 * @Description:
 *			Returns y coordinate of Asteroid
 * @Params:
 *			n/a
 * @Returns:
 *			int - y coordinate
 */

int Asteroid::getY(){
  return y;
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
