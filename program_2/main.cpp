#include <iostream>

#include "asteroid.h"
#include "asteroidlist.h"
#include "ship.h"

using namespace std;

int main(){

	Ship ship;
	ship.captainsLog();

	string input, output;
	cout << "What's the name of your input file? ";
	cin >> input;

	input = input == "def" ? "input.txt" : input;

	cout << "What's the name of your output file? ";
	cin >> output;

	output = output == "def" ? "output.txt" : output;

	// generate asteroids from input file
	AsteroidList RoidList;
	RoidList.generateRoids(input);

	// loop <RoidList.maxRoids()> times

		// find target

		// mine asteroid
				// asteroid > ship ? explode
				// else collect()

	// endloop

	cout << "\nRan\n";

	return 0;
}
