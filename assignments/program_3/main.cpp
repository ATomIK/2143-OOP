/*
	Tom Johnson
	2143 - Object Oriented Programming
	Dr. Stringfellow
	Program 3 - StarProbe
	10/04/2017
*/

#include <iostream>
#include <iomanip>
#include <string>

#include "asteroid.h"
#include "starship.h"
#include "starprobe.h"

using namespace std;

// function prototypes
void getInput(fstream&);
void generateField(vector<Asteroid>&,fstream&,Starship&);
void captainsLog(fstream&, Starship&, Starprobe&);
void endMission(fstream&, Starship&, Starprobe&);

int main(){

	fstream input;
	Starship Ship;
	Starprobe Probe;
	vector<Asteroid> asteroids;

	// prompt the user for input
	getInput(input);
	//  discuss the flight plan with the captain (user)
	Ship.flightPlan();
	// discuss the flight plan of the probe with the captain
	Probe.flightPlan();

	// read input and generate Asteroid vector
	generateField(asteroids,input,Ship);

	// loop until Ship's limit
	// launch both the probe and the star ship
	while(Ship.getLimit() != Ship.getAsteroids() || Probe.getLimit() != Probe.getScanned()){

		int index, probei;
		double distance, probedist;

		// find target
		index = Ship.findClosest(asteroids);
		probei = Probe.findClosest(asteroids);

		// if the captain wants to collect more than the field, end mission.
		// or if the probe is set to scan more than the field, end mission.
		if(Ship.getAsteroids() == Ship.getDetected() || Probe.getScanned() == Ship.getDetected())
			break;

		// ship moves to target
		distance = Ship.moveTo(index, asteroids);
		// probe moves to target
		probedist = Probe.moveTo(probei, asteroids);

		// mine asteroid
		Ship.mineAsteroid(index, asteroids);
		// probe scans asteroid
		Probe.scanAsteroid(probei, asteroids);
	}

	// close files and end program
	endMission(input, Ship, Probe);

	return 0;
}

/*
 * @FunctionName: getInput
 * @Description:
 *			Prompts the user to select an input file.
 * @Params:
 *			fstream &f - fstream set to ios::in
 * @Returns:
 *			void
 */

void getInput(fstream &f){

	string input;

	cout << "Name of input file ('def' for 'input.txt'): ";
	cin >> input;
	input = input == "def" ? "input.txt" : input;

	f.open(input.c_str(), ios::in);

}

/*
 * @FunctionName: generateField
 * @Description:
 *			Loops through input file and generates a vector of type Asteroid.
 * @Params:
 *			vector<Asteroid> &v - the vector of Asteroids
 *			fstream &f - the input file
 *			Starship &S - Ship is passed in to get size of field
 * @Returns:
 *			void
 */

void generateField(vector<Asteroid> &v, fstream &f, Starship &S){

  int x,y,count = 1;
  double weight;
	char precious;
  bool c = false, p = false;

  f >> x >> y >> weight >> precious;
  while(!f.eof()){

		// if last char is P, asteroid is precious
		p = precious == 'P' ? true : false;
		// new Asteroid
		Asteroid temp(x,y,weight,c,0,p);

		// push Asteroid onto field
    v.push_back(temp);

    f >> x >> y >> weight >> precious;

		// Starship is detecting Asteroid field
		count++;

  }

	// Starship scanned the field and now knows how many there are
	S.setDetected(count);

}

/*
 * @FunctionName: captainsLog
 * @Description:
 *			Prompts the user with the stats of the mission
 * @Params:
 *			fstream &f - input file to close
 *			Starship &S - passed in ship to get data
 *			SpaceProbe &P - passed in probe to get data
 * @Returns:
 *			void
 */

void endMission(fstream &f, Starship &S, Starprobe &P){

	cout << "\nMission complete!\n"
			 << "Our ship traveled: " << S.getDist() * 10 << " miles!\n"
			 << "Asteroids collected: " << S.getAsteroids() << "\n\n"
			 << "Our probe traveled: " << P.getDist() * 10 << " miles!\n"
			 << "It found " << P.getPrecious() << " asteroids that contain "
			 "precious metals!\n";

	f.close();

}
