// main.cpp

/*
	Tom Johnson
	2143 - Object Oriented Programming
	Dr. Stringfellow
	Program 4 - Polymorphism and Overloading
	To apply polymorphism and overload an operator(=) [line 320 of starcraft.cpp];
		and to use static variables.
		Custom inputs created through a PHP script: http://thomasj.me/test1.php
	11/14/2017
*/

#include <iostream>
#include <iomanip>
#include <string>

#include "asteroid.h"
#include "starship.h"
#include "starprobe.h"

#ifdef __linux__
	#include <unistd.h>
#else
	#include <windows.h>
#endif

using namespace std;

// typedef array
typedef Starcraft *Starcrafts[50];

// function prototypes
void sleep(int);
void getInput(fstream&);
void generateField(vector<Asteroid>&, Starcrafts, fstream&);
void statusReport(int, Starcrafts);
void preciousPrint(Starcrafts);
void endMission(fstream&, Starcrafts);

int main() {

	fstream input;

	// typedef in action
	Starcrafts crafts;

	int shipsNum, maxScan, maxMine;
	double maxAsteroid;

	vector<Asteroid> asteroids;

	// prompt the user for file input
	getInput(input);
	input >> shipsNum >> maxScan >> maxMine >> maxAsteroid;
	int a[4] = { maxScan,0,maxMine,0 }; // used on line 76

	// render ships into space
	int p = 1, s = 1;
	for (int i = 0; i < shipsNum; i++) {
		string name;
		char type;
		int xcoord, ycoord;
		// read in ship
		input >> type >> xcoord >> ycoord;

		if (type == 'P') {
			name = "Starprobe #";
			name += to_string(p);
			crafts[i] = new Starprobe(name, xcoord, ycoord);
			p++;
		} else if (type == 'S') {
			name = "Starship #";
			name += to_string(s);
			crafts[i] = new Starship(name, xcoord, ycoord);
			s++;
		}
	}
	// sets Starcraft's static variables
	crafts[0]->setComputer(a);

	// render asteroids into space
	generateField(asteroids, crafts, input);

	// begin status report
	statusReport(shipsNum, crafts);

	sleep(1);

	cout << "\n== [ Beginning mission ] ==\n\n";

	sleep(1);

	// if neither ships or probes missions have been completed
	int turns = 1;
	while (Starcraft::getComputer(1) != Starcraft::getComputer(0)
		|| Starcraft::getComputer(3) != Starcraft::getComputer(2)) {
		// unnecessary but interesting turn tracker
		cout << "-- \"Asynchronous\" turn #" << turns << " --\n\n";
		// loop through all ships
		for (int i = 0; i < shipsNum; i++) {

			int index;
			double traveled;

			// if probes' missions are completed, start mining
			if (Starcraft::getComputer(0) == Starcraft::getComputer(1)) {
				// as we're looping through crafts, only manipulate crafts that can mine
				// attempt to cast crafts[i]; if crafts[i] is starship, then
				if (Starship* tempShip = dynamic_cast<Starship*>(crafts[i])) {
					// find the closest precious asteroid
					// passes in redundant asteroids vector; uses starcraft's static database
					index = tempShip->findClosest(asteroids, true);
					// move to that precious asteroid
					traveled = tempShip->moveTo(index, asteroids);
					// if precious asteroid is too big, blast it
					// if it can't mine, then either the asteroid is too big or
					// the mission is trying to make the ships mine more than known scanned precious asteroids
					if (!tempShip->doAsteroid(index, asteroids, true, maxAsteroid, traveled)) {
						if (Starcraft::getComputer(2) <= Starcraft::getComputer(0)) {
							tempShip->blAsteroid(index);
						} else {
							cout << "Can't mine more than what exists in the database... Continue to end of mission...\n";
							#ifdef __linux__
								usleep(5000000);
							#else
								system("pause");
							#endif
							// goto error label in order to break out of multidimensional loop
							goto error;
						}
					}
				}
			} else {
				// if probes' missions aren't complete, execute commands on probes only
				if (Starprobe* tempProbe = dynamic_cast<Starprobe*>(crafts[i])) {
					// go through asteroids vector for unscanned asteroids
					index = tempProbe->findClosest(asteroids, false);
					// move to unscanned asteroid
					traveled = tempProbe->moveTo(index, asteroids);
					// if probe can't scan, it means that the mission is impossible
					if (!tempProbe->doAsteroid(index, asteroids, false, maxAsteroid, traveled)
						&& tempProbe->getDetected() < Starcraft::getComputer(0)) {
						cout << "Can't scan more than what exists... Continue to end of mission...\n";
						#ifdef __linux__
							usleep(5000000);
						#else
							system("pause");
						#endif
						// goto error label in order to break out of multidimensional loop
						goto error;
					}
				}
			}
		}
		// increment unnecessary turns counter
		turns++;
	}

	cout << "\n== [ End of mission ] ==\n\n";

	// print out the probes' scanned precious metal asteroids
	preciousPrint(crafts);

	cout << "\nContinue to starcrafts' status report...\n";
	#ifdef __linux__
		usleep(3000000);
	#else
		system("pause");
	#endif

	// print out final status report of all ships
	statusReport(shipsNum, crafts);

	cout << "\nContinue to cargo bay and mission report...\n";
	#ifdef __linux__
		usleep(3000000);
	#else
		system("pause");
	#endif

// impossible mission / error goto
error:
	// print out combined cargo bays because why not
		// print out the 4 static variables (Starcraft::computer[])
		// close files
	endMission(input, crafts);

	return 0;
}

/*
* @FunctionName: sleep
* @Description:
*			Console delay depending on operating system.
* @Params:
*			int s - seconds to delay
* @Returns:
*			void
*/

void sleep(int s) {
	#ifdef __linux__
		usleep(s * 1000000);
	#else
		Sleep(s * 1000);
	#endif
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

void getInput(fstream &f) {

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
 *			Starcrafts crafts - passed in to set detected asteroids
 *			fstream &f - the input file
 * @Returns:
 *			void
 */

void generateField(vector<Asteroid> &v, Starcrafts crafts, fstream &f) {

	int x, y, count = 1;
	double weight;
	char precious;
	bool c = false, p = false;

	f >> x >> y >> weight >> precious;
	while (!f.eof()) {

		// if last char is P, asteroid is precious
		p = precious == 'P' ? true : false;
		// new Asteroid
		Asteroid temp(x, y, weight, c, 0, p);

		// push Asteroid onto field
		v.push_back(temp);

		f >> x >> y >> weight >> precious;

		// Starship is detecting Asteroid field
		count++;

	}

	// in order to prevent an impossible mission
	crafts[0]->setDetected(count);

}

/*
* @FunctionName: statusReport
* @Description:
*			Prints out a status report of all ships
* @Params:
*			int shipsNum - number of ships in array
*			Starcrafts crafts - array of starcrafts
* @Returns:
*			void
*/

void statusReport(int shipsNum, Starcrafts crafts) {
	cout << "\n== [ Status report ] ==\n\n";

	// need to dynamic_cast otherwise Starcraft's toString() is called
	for (int i = 0; i < shipsNum; i++) {
		// if derived is a Starship,
		if (Starship* tempShip = dynamic_cast<Starship*>(crafts[i]))
			cout << tempShip->toString();
		else if (Starprobe* tempProbe = dynamic_cast<Starprobe*>(crafts[i])) {
			cout << tempProbe->toString();
		}
		#ifdef __linux__
			usleep(300000);
		#else
			Sleep(300);
		#endif
	}
}

/*
* @FunctionName: preciousPrint
* @Description:
*			Per assignment, the non-member function in main that prints the probes'
*				combined visited precious metals.
* @Params:
*			Starcrafts crafts - passed in to execute getlist()
* @Returns:
*			void
*/

void preciousPrint(Starcrafts crafts) {

	// because i'm using vectors, getlist() renders tabular rows to this vector
	// permission by email
	vector<string> preciousList;

	cout << "[ Precious asteroids database ]\n\n";

	cout << left << setw(5) << "ID" << setw(13) << "Location" << setw(5) << "Size\n";

	// getlist method from starcraft
	crafts[0]->getlist(preciousList);
	for (std::vector<Asteroid>::size_type i = 0; i < preciousList.size(); i++) {
		cout << preciousList[i];
	}

}

/*
 * @FunctionName: endMission
 * @Description:
 *			Prompts the user with the stats of the mission
 * @Params:
 *			fstream &f - input file to close
 *			Starcrafts crafts - passed in to print out database of collected asteroids
 * @Returns:
 *			void
 */

void endMission(fstream &f, Starcrafts crafts) {

	cout << "\n[Starships' combined cargo bay]\n\n"
		<< left << setw(5) << "ID" << setw(13) << "Location" << setw(5) << "Size\n";

	// loop through and print asteroids from all cargo bays
	vector<Asteroid> temp = crafts[0]->getDb();
	for (vector<Asteroid>::size_type i = 0; i < temp.size(); i++) {
		if (temp[i].isCollected()) {
			cout << setw(4) << left << i << "(" << setfill('0') << setw(3) << right
				<< temp[i].get(0) << ", " << setfill('0') << setw(3) << right
				<< temp[i].get(1) << setfill(' ') << left << setw(5) << ")"
				<< setw(4) << left << setprecision(2) << fixed << temp[i].getWeight() << "\n";
		}
	}

	cout << "\n== [ Mission complete ] ==\n\n";

	cout << "Asteroids scanned: (" << Starcraft::getComputer(1) << "/" << Starcraft::getComputer(0)
		<< ").\nAsteroids collected: (" << Starcraft::getComputer(3) << "/" << Starcraft::getComputer(2)
		<< ").\n\n";

	f.close();

}
