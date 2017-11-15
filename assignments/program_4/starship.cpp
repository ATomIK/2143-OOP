// starship.cpp

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "starship.h"

#ifdef __linux__
	#include <unistd.h>
#else
	#include <windows.h>
#endif

/*
 * @DefaultConstructorName: Starship
 * @Description:
 *			Sets all Starship variables to 0
 * @Params:
 *			n/a
 * @Returns:
 *			n/a
 */

Starship::Starship() : Starcraft() {
	cargoWeight = 0.0;
}

/*
* @ParameterizedConstructorName: Starship
* @Description:
*			Sets name and coordinates
* @Params:
*			std::string n - name of starship
*			int x - x coordinate
*			int y - y coordinate
* @Returns:
*			n/a
*/

Starship::Starship(std::string n, int x, int y) : Starcraft(n, x, y) {
	cargoWeight = 0.0;
}

/*
* @MethodName: getAsteroids
* @Description:
*			Returns number of asteroids collected
* @Params:
*			n/a
* @Returns:
*			int - number of asteroids
*/

int Starship::getAsteroids() { return current; }

/*
 * @MethodName: toString
 * @Description:
 *			Returns string of pretty object data
 * @Params:
 *			n/a
 * @Returns:
 *			string - pretty object data
 */

std::string Starship::toString() {
	std::string result = name; // name of starship
	result += " at (";
	result += std::to_string(coords[0]);
	result += ", "; // coordinates
	result += std::to_string(coords[1]);
	result += "). Total distance: ";
	std::stringstream dbl;
	dbl << std::fixed << std::setprecision(2) << distance;
	std::string s = dbl.str(); // double distance conversion
	result += s;
	result += ". Cargo bay: ";
	std::stringstream db; // double cargo weight conversion
	db << std::fixed << std::setprecision(2) << cargoWeight;
	std::string l = db.str();
	result += l;
	result += " kilotons. Mined asteroids: ";
	result += std::to_string(current); // total mined asteroids
	result += ".\n";
	return result;
}

/*
 * @MethodName: blAsteroid
 * @Description:
 *			Randomly generates number of pieces from 0 - 5. The weight of those
 *			pieces is equal to the original asteroid. The pieces are added onto the
 *			Asteroid vector and dispersed throughout the 100x100 field randomly. If
 *			a piece is dispersed directly into the ship, the ship will be damaged
 *		    and will have to wait 3 seconds until repaired to complete the mission.
 *			** UPDATE **
 *		    If the original asteroid has precious metals, the pieces will also
 *		    contain precious metals.
 *			** UPDATE **
 *			Only runs if the ships' missions are not completed.
 * @Params:
 *			n/a
 * @Returns:
 *			void
 */

void Starship::blAsteroid(int index) {

	// if ships' missions are not completed
	if (computer[2] != computer[3]) {

		int pieces;
		double weight;

		#ifdef __linux__
			usleep(1000000);
		#else
			Sleep(1000);
		#endif

		// prompt the user to blast it or ignore it
		int choice;
		std::cout << "\n" << name << " encountered an asteroid too large for its drill!"
			<< "\nBlast it?\n1. Yes\n2. No\n";
		std::cin >> choice;
		std::cout << "\n";

		// user chose not to blast it, ignoring it.
		if (choice == 2) {
			database.erase(database.begin() + index);

			std::cout << "Ignoring asteroid...\n\n";
		}
		else {

			// randomizing pieces of blast
			srand((unsigned int)time(NULL));

			pieces = rand() % 5;

			weight = database[index].getWeight() / pieces;

			std::cout << "Asteroid exploded.\n";

			// if pieces is 0
			if (!pieces)
				std::cout << name << " used too much power! It vaporized the asteroid..\n";

			// loop will only work if pieces is > 0.
			for (int j = 0; j < pieces; j++) {

				// generate random coordinates
				int x = rand() % 100, y = rand() % 100;

				// created asteroid and add it to the vector
				bool precious = true;

				Asteroid temp = Asteroid(x, y, weight, 0, 0, precious);

				database.push_back(temp);

				// A piece flew into the ship if its coordinates equal the ship's coordinates
				// RARE. SCREENSHOT IF IT OCCURS PLS
				if (x == coords[0] && y == coords[1]) {
					// Captain is alerted and repait bots are called
					std::cout << "WOAH! A piece flew into " << name << ". Repair bots are on the way\n";
					// Repair bots are repairing the ship...
					#ifdef __linux__
						usleep(3000000);
					#else
						Sleep(3000);
					#endif
					std::cout << "Repaired!\n";
				}
				else
					std::cout << "A piece flew to: (" << x << ", " << y << ")\n";

			}

		}

		#ifdef __linux__
			usleep(1000000);
		#else
			Sleep(1000);
		#endif

		std::cout << "\n";

		database.erase(database.begin() + index); // initial asteroid explodes
	}

}

Starship::~Starship() {

}
