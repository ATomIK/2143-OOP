#include <iostream>
#include <iomanip>
#include "asteroid.h"
#include <sstream>

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
 * @MethodName: operator =
 * @Description:
 *			Copy over an asteroid's values into another asteroid object
 * @Params:
 *			Asteroid obj - the asteroid to copy values from
 * @Returns:
 *			void
 */

void Asteroid::operator= (Asteroid obj){
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
 *			bool - collected
 */

bool Asteroid::isCollected(){ return collected; }

/*
 * @MethodName: isScanned
 * @Description:
 *			Return scanned status
 * @Params:
 *			n/a
 * @Returns:
 *			bool - scanned
 */

bool Asteroid::isScanned(){ return scanned; }

/*
 * @MethodName: isPrecious
 * @Description:
 *			Return precious status
 * @Params:
 *			n/a
 * @Returns:
 *			bool - precious
 */

bool Asteroid::isPrecious(){ return p; }

/*
 * @MethodName: getWeight
 * @Description:
 *			Return weight of asteroid
 * @Params:
 *			n/a
 * @Returns:
 *			double - weight
 */

double Asteroid::getWeight(){ return weight; }

/*
 * @MethodName: toString
 * @Description:
 *			Returns string of pretty object data
 * @Params:
 *      n/a
 * @Returns:
 *			string - pretty object data
 */

std::string Asteroid::toString(){
  std::string result = "\nAsteroid weighs: ";
  std::stringstream dbl;
  dbl << std::fixed << std::setprecision(2) << weight;
  std::string s = dbl.str();
  result += s;
  result += ". Collected: ";
  result += std::to_string(collected);
  result += ". Scanned: ";
  result += std::to_string(scanned);
  result += ". Precious: ";
  result += std::to_string(p);
  result += ".\n\n";
  return result;
}

/*
 * @MethodName: setCollected
 * @Description:
 *			Sets collected status
 * @Params:
 *			bool - collected
 * @Returns:
 *			void
 */

void Asteroid::setCollected(bool c){ collected = c; }

/*
 * @MethodName: setScanned
 * @Description:
 *			Sets scanned status
 * @Params:
 *			bool - scanned
 * @Returns:
 *			void
 */

void Asteroid::setScanned(bool s){ scanned = s; }

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