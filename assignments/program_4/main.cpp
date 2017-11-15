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

typedef Starcraft *Starcrafts[50];

// function prototypes
void getInput(fstream&);
void generateField(vector<Asteroid>&,fstream&);
void captainsLog(fstream&, Starship&, Starprobe&);
void endMission(fstream&, Starship, Starprobe, vector<Asteroid>);

int main(){

	fstream input;
	Starcraft craft;
	Starcrafts crafts;
	int shipsNum, maxScan, maxMine;
	double maxAsteroid;
	// Starship Ship;
	// Starprobe Probe;
	vector<Asteroid> asteroids;

	// prompt the user for input
	getInput(input);
	input >> shipsNum >> maxScan >> maxMine >> maxAsteroid;
	int a[4] = {maxScan,0,maxMine,0}; // set computer variables.
	Starcraft::setComputer(a); // get computer will return array for end mission.

	// render ships into space
	int p = 1,s = 1;
	for(int i = 0; i < shipsNum; i++){
		string name;
		char type;
		int xcoord,ycoord;
		input >> type >> xcoord >> ycoord;

		if(type == 'P'){
			name = "Starprobe #";
			name += to_string(p);
			crafts[i] = new Starprobe(name,xcoord,ycoord);
			p++;
		}
		if(type == 'S'){
			name = "Starship #";
			name += to_string(s);
			crafts[i] = new Starship(name,xcoord,ycoord);
			s++;
		}
	}

	// render asteroids into space
	generateField(asteroids,input);

	cout << "\n== [ Status report ] ==\n\n";
	for(int i = 0;i < shipsNum;i++){
		// if derived is a Starship,
		if(Starship* tempShip = dynamic_cast<Starship*>(crafts[i])){
			cout << tempShip->toString();
		} else { // derived is a Starprobe
			Starprobe* tempProbe = dynamic_cast<Starprobe*>(crafts[i]);
			cout << tempProbe->toString();
		}
	}

		cout << "\n== [ Beginning mission ] ==\n\n";

	// if probes' missions have not completed or if ships' missions have not
	// completed
	while(Starcraft::getComputer(1) != Starcraft::getComputer(0)
					|| Starcraft::getComputer(3) != Starcraft::getComputer(2)){
		// loop through all ships
		for(int i = 0;i < shipsNum;i++){
			int index;
			double traveled;

			// when the probes' mission is complete
			if(Starcraft::getComputer(0) == Starcraft::getComputer(1)){
				// as we're looping through crafts, only manipulate crafts that can mine
				if(Starship* tempShip = dynamic_cast<Starship*>(crafts[i])){
					// find the closest precious asteroid
					// passes in redundant asteroids vector
					index = tempShip->findClosest(asteroids,true);
					// move to that precious asteroid
					traveled = tempShip->moveTo(index,asteroids);
					// if precious asteroid is too big, blast it
					if(!tempShip->doAsteroid(index,asteroids,true,maxAsteroid,traveled)
							&& Starcraft::getComputer(2) != Starcraft::getComputer(3))
						tempShip->blAsteroid(index);
				}
			} else {
				// if scan mission isn't complete, execute commands on probes only
				if(Starprobe* tempProbe = dynamic_cast<Starprobe*>(crafts[i])){
					// go through asteroids vector for unscanned asteroids
					index = tempProbe->findClosest(asteroids,false);
					// move to unscanned asteroid
					traveled = tempProbe->moveTo(index,asteroids);
					// scan asteroid
					tempProbe->doAsteroid(index,asteroids,false,maxAsteroid,traveled);
				}
			}
		}
	}
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

void generateField(vector<Asteroid> &v, fstream &f){

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
	// S.setDetected(count);

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
