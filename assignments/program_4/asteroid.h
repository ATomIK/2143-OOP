// asteroid.h

#pragma once
#include <fstream>
#include <vector>
#include "spaceobject.h"

class Asteroid : public SpaceObject {

protected:
	// weight of Asteroid
	double weight;
	// collected status, scanned status, and contains precious metals
	bool collected, scanned, p;

public:
	// default constructor
	Asteroid();
	// parameterized constructor
	Asteroid(int, int, double, bool, bool, bool);
	// copy constructor
	Asteroid(const Asteroid &);

	// overloaded = operator
	void operator= (Asteroid);

	// return collection status
	bool isCollected();

	// return scanned status
	bool isScanned();

	// return precious status
	bool isPrecious();

	// object data to pretty string
	std::string toString();

	// return weight of asteroid
	double getWeight();

	// sets collected status
	void setCollected(bool);

	// sets scanned status
	void setScanned(bool);

	// default destructor
	~Asteroid();

};
