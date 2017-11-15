// starcraft.h

#pragma once
#include <vector>
#include <string>
#include "asteroid.h"
#include "spaceobject.h"

class Starcraft : public SpaceObject {

protected:
	// all asteroids in the field
	int detectedAsteroids;
	// limit of asteroids to collect/visit
	int limit;
	// current number of asteroids scanned/collected
	int current;
	// total weight of asteroids collected
	double cargoWeight;
	// total distance traveled
	double distance;
	// database of asteroids with precious metals
	static std::vector<Asteroid> database;
	// static data
	/* spacecraft computer
	  [0] = asteroids to scan
	  [1] = asteroids scanned
	  [2] = asteroids to mine
	  [3] = asteroids mined
	*/
	static int computer[4];

public:

	Starcraft();

	Starcraft(std::string, int, int);

	// return database of scanned asteroids
	std::vector<Asteroid> getDb();

	// return the craft's visitation/collection limit
	int getLimit();

	// return detected asteroids in a field
	int getDetected();

	// return total distance traveled
	double getDist();

	// object data to pretty string
	std::string toString();

	// getlist returns an array of strings of precious asteroids to print out
	void getlist(std::vector<std::string>&);

	// sets static variables in the beginning
	static void setComputer(int[]);

	// gets certain static variable
	static int getComputer(int);

	// set detected asteroids in a field
	void setDetected(int);

	// calculates hypotenuse of two x,y coordinates
	double computeDistance(int, std::vector<Asteroid>&, bool);

	// updates the SpaceObject's coordinates (moves to an asteroid) and returns distance
	double moveTo(int, std::vector<Asteroid>&);

	// calculates the closest asteroid
	// bool if ship else probe
	int findClosest(std::vector<Asteroid>&, bool);

	// perferms action on the asteroid depending on ship type
	// bool if ship else probe
	virtual bool doAsteroid(int, std::vector<Asteroid>&, bool, double, double);

	~Starcraft();

};
