// starprobe.h

#pragma once
#include <vector>
#include "starcraft.h"
#include "asteroid.h"

class Starprobe : public Starcraft {

protected:
	int preciousRoids;

public:

	Starprobe();

	Starprobe(std::string, int, int);

	// return number of precious asteroids
	int getPrecious();

	// object data to pretty string
	std::string toString();

	// override base class' doAsteroid method
	bool doAsteroid(int, std::vector<Asteroid>&, bool, double, double);

	~Starprobe();

};
