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
#include "spaceprobe.h"

using namespace std;

// function prototypes
void openFile(fstream&);
void generateAsteroidField(vector<Asteroid>&,fstream&,Starship&);
void endMission(fstream&, Starship&, SpaceProbe&);

int main(){

	fstream ifile;
	Starship Ship;
	SpaceProbe Probe;
	vector<Asteroid> asteroids;
	vector<Asteroid> preciousRoids;

	// prompt the user for input/output
	openFile(ifile);
	//  discuss flight plans with the captain (user)
	Ship.captainsLog();
	// discuss flight plans of the space probe
	Probe.plans();

	// generate asteroids from input file & allow the ship to scan
	generateAsteroidField(asteroids,ifile,Ship);

	// loops until the captain gets as many asteroids as he wants
	// launch both the probe and the star ship
	while(Ship.getLimit() != Ship.getAsteroidCount() || Probe.getLimit() != Probe.getScannedCount()){

		int index, probei;
		double distance, probedist;

		// find target
		index = Ship.findClosest(asteroids);
		probei = Probe.findClosest(asteroids);

		// if the captain wants to collect more than the field, end mission.
		// or if the probe is set to scan more than the field, end mission.
		if(Ship.getAsteroidCount() == Ship.getDetectedAsteroids() || Probe.getScannedCount() == Ship.getDetectedAsteroids())
			break;

		// ship moves to target
		distance = Ship.moveTo(index, asteroids);
		// probe moves to target
		probedist = Probe.moveTo(probei, asteroids);

		// mine asteroid
		Ship.mineAsteroid(index, asteroids);
		// probe scans asteroid
		Probe.scanAsteroid(probei, asteroids);

		// send mission data back to earth
		// if(mined)
			// Ship.transmitData(index, asteroids, distance);
	}

	// close files and end program
	endMission(ifile, Ship, Probe);

	return 0;
}

/*
 * @FunctionName: openFiles
 * @Description:
 *			Prompts the user for input & output files
 * @Params:
 *			fstream &ifile - fstream set to ios::in
 *			fstream &ofile - fstream set to ios::out
 * @Returns:
 *			void
 */

void openFile(fstream &ifile){

	string input;

	cout << "Name of input file ('def' for 'input.txt'): ";
	cin >> input;
	input = input == "def" ? "input.txt" : input;

	ifile.open(input.c_str(), ios::in);

}

/*
 * @FunctionName: generateAsteroidField
 * @Description:
 *			Loops through input file and generates a vector of type Asteroid
 * @Params:
 *			vector<Asteroid> &vect - the vector used to store Asteroids
 *			fstream &ifile - the input file to read from
 *			Starship &Ship - Ship is passed in to know how big the field is
 * @Returns:
 *			void
 */

void generateAsteroidField(vector<Asteroid> &vect, fstream &ifile, Starship &Ship){

  int getx,gety;
  double getw;
	char precious;
  bool c = false, p = false;

	int count = 1;

  ifile >> getx >> gety >> getw >> precious;
  while(!ifile.eof()){
		p = precious == 'P' ? true : false;
		Asteroid temp(getx,gety,getw,c,0,p);
    vect.push_back(temp);
    ifile >> getx >> gety >> getw >> precious;
		count++;
  }

	Ship.setDetected(count);

}

/*
 * @FunctionName: endMission
 * @Description:
 *			Prompts the user for input & output files
 * @Params:
 *			fstream &ifile - input file
 *			fstream &ofile - output file
 *			Starship &Ship - passed in ship to prompt end results
 * @Returns:
 *			void
 */

void endMission(fstream &ifile, Starship& Ship, SpaceProbe& Probe){

	cout << "\nMission complete!\n"
			 << "Our ship traveled: " << Ship.getDistance() * 10 << " miles!\n"
			 << "Asteroids collected: " << Ship.getAsteroidCount() << "\n\n"
			 << "Our probe traveled: " << Probe.getDistance() * 10 << " miles!\n"
			 << "It found " << Probe.getPreciousRoids() << " asteroids that contain precious metals!\n";

	ifile.close();

}
