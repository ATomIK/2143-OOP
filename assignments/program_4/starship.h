// starship.h

#pragma once
#include <vector>
#include <cmath>
#include "asteroid.h"
#include "starcraft.h"

class Starship : public Starcraft {

public:

	Starship();

	Starship(std::string, int, int);

	// returns number of asteroids collected
	int getAsteroids();
	// object data to pretty string
	std::string toString();
	// "blasts" an asteroid
	void blAsteroid(int);

	~Starship();

};
