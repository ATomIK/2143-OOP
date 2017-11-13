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

typedef Starcraft *crafts[50];

// function prototypes
void getInput(fstream&,fstream&);
void generateField(vector<Asteroid>&,fstream&,Starship&);
void captainsLog(fstream&, Starship&, Starprobe&);
void endMission(fstream&, Starship, Starprobe, vector<Asteroid>);

int main(){

	fstream input, ships;
	Starcraft craft;
	int shipsNum, maxScan, maxMine, maxAsteroid;
	// Starship Ship;
	// Starprobe Probe;
	vector<Asteroid> asteroids;

	// prompt the user for input
	getInput(input, ships);
	ships >> shipsNum;
	ships >> maxScan;
	ships >> maxMine;
	ships >> maxAsteroid;
	//  discuss the flight plan with the captain (user)
	// Ship.flightPlan();
	// discuss the flight plan of the probe with the captain
	// Probe.flightPlan();

	// read input and generate Asteroid vector
	// generateField(asteroids,input,Ship);

	cout << "\n== [ Beginning mission ] ==\n";

	for(int i = 0; i < shipsNum; i++){
		char type;
		int xcoord,ycoord;
		ships >> type >> xcoord >> ycoord;

		if(type == 'P'){
			crafts[i] = new Starprobe(maxScan,xcoord,ycoord);
			cout << "Probe at (" << xcoord << ", " << ycoord << ").\n";
		}
		if(type == 'S'){
			crafts[i] = new Starship(maxMine,xcoord,ycoord);
			cout << "Ship at (" << xcoord << ", " << ycoord << ").\n";
		}

	}

	// loop until both hit their limit
	// launch both the probe and the star ship
	// while(Ship.getLimit() != Ship.getAsteroids()
	// 			|| Probe.getLimit() != Probe.getScanned()){
	//
	// 	int sindex, pindex;
	// 	double sdist, pdist;
	//
	// 	// find target
	// 	sindex = Ship.findClosest(asteroids,true);
	// 	pindex = Probe.findClosest(asteroids,false);
	//
	// 	// if the captain wants to collect more than the field, end mission.
	// 	// or if the probe is set to scan more than the field, end mission.
	// 	if(Ship.getAsteroids() == Ship.getDetected()
	// 			|| Probe.getScanned() == Ship.getDetected())
	// 		break;
	//
	// 	// ship moves to target
	// 	sdist = Ship.moveTo(sindex, asteroids);
	// 	// probe moves to target
	// 	pdist = Probe.moveTo(pindex, asteroids);
	//
	// 	// mine asteroid if ship hasnt reached its limit
	// 	if(!Ship.doAsteroid(sindex, asteroids, true, 9.0) && Ship.getLimit() != Ship.getAsteroids())
	// 		Ship.blAsteroid(sindex,asteroids);
	// 	// probe scans asteroid
	// 	Probe.doAsteroid(pindex, asteroids, false, 9.0);
	// }

	// close files and end program
	// endMission(input, Ship, Probe, asteroids);

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

void getInput(fstream &f, fstream &s){

	string input, ships;

	cout << "Name of input file ('def' for 'input.txt'): ";
	cin >> input;
	input = input == "def" ? "input.txt" : input;

	cout << "Name of ships file ('def' for 'Spacecraft.txt'): ";
	cin >> ships;
	ships = ships == "def" ? "Spacecraft.txt" : ships;

	f.open(input.c_str(), ios::in);
	s.open(ships.c_str(), ios::in);

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

void endMission(fstream &f, Starship S, Starprobe P, vector<Asteroid> vect){

	cout << "== [ Mission complete ] ==\n";

	cout << vect[4].toString();

	cout << "\nOur ship traveled: " << fixed << setprecision(2) << S.getDist() * 10 << " miles!\n"
			 << "Asteroids collected: " << S.getAsteroids() << "\n\n"
			 << " ID | Coords | Weight \n";

	for (std::vector<Asteroid>::size_type i = 0; i < vect.size(); i++) {
		if(vect[i].isCollected()){
			cout << setw(2) << right << i << setw(5) << "(" << vect[i].get(0) << ", " << vect[i].get(1)
					 << ")" << setw(6) << setprecision(2) << vect[i].getWeight() << "\n";
		}
	}

	cout << "\nOur probe traveled: " << P.getDist() * 10 << " miles!\n"
			 << "It found " << P.getPrecious() << " asteroids that contain "
			 "precious metals!\n\n"
			 << " ID | Coords | Weight \n";

	vector<Asteroid> db = P.getDb();
	for (vector<Asteroid>::size_type i = 0; i < db.size(); i++) {
		if(db[i].isCollected()){
			cout << setw(2) << right << i << setw(5) << "(" << db[i].get(0) << ", " << db[i].get(1)
					 << ")" << setw(6) << setprecision(2) << db[i].getWeight() << "\n";
		}
	}

	f.close();

}
