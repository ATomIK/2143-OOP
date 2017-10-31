#include <iostream>
#include <iomanip>

#ifdef __linux__
  #include <unistd.h>
#else
  #include <windows.h>
#endif

#include "starship.h"

/*
 * @DefaultConstructorName: Starship
 * @Description:
 *			Sets all Starship variables to 0
 * @Params:
 *			n/a
 * @Returns:
 *			n/a
 */

Starship::Starship() : Starcraft(){
  current = 0;
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

int Starship::getAsteroids(){ return current; }

/*
 * @MethodName: flightPlan
 * @Description:
 *			Prompts the user for initial warp coordinates and asteroid collection
 * @Params:
 *			n/a
 * @Returns:
 *			void
 */

void Starship::flightPlan(){

  // warp using pre-defined or manually defined coords?
  int choice;
  std::cout << "\nWould you like to warp using "
					"pre-defined coordinates?\n\n1. Yes\n2. No.\n";
	std::cin >> choice;

  // if manually defined, set x and y
	if(choice == 2){
		std::cout << "\nPlease enter an x coordinate followed by a y coordinate\n "
		"for the ship to warp to. ( Example: 5 25 ):";
		std::cin >> coords[0] >> coords[1];
	}
  std::cout << "\nWarping to (" << coords[0] << "," << coords[1] << ")...\n\n";

  // set the limit of the ship's mission
	std::cout << "\nHow many asteroids <9 tons would you like to collect before\n "
					"returning to earth? (integer): ";
	std::cin >> limit;
  std::cout << "\n";

}

/*
 * @MethodName: blAsteroid
 * @Description:
 *			Randomly generates number of pieces from 0 - 5. The weight of those
 *      pieces is equal to the original asteroid. The pieces are added onto the
 *      Asteroid vector and dispersed throughout the 100x100 field randomly. If
 *      a piece is dispersed directly into the ship, the ship will be damaged
 *      and will have to wait 3 seconds until repaired to complete the mission.
 *      ** UPDATE **
 *      If the original asteroid has precious metals, the pieces will also
 *      contain precious metals.
 * @Params:
 *			n/a
 * @Returns:
 *			void
 */

void Starship::blAsteroid(int index, std::vector<Asteroid> &asts){
  int pieces;
  double weight;

  // prompt the user for a choice
  int choice;
  std::cout << "\nUh-oh, you've encountered an asteroid too large for our drill!"
    << "\nWould you like to blast it?\n1. Yes\n2. No\n";
  std::cin >> choice;
  std::cout << "\n";

  // User chose not to blast it, ignoring it.
  if (choice == 2) {
    asts.erase(asts.begin() + index); // delete asteroid from field

    std::cout << "Ignoring asteroid...\n\n";
  } else {

    srand((unsigned int)time(NULL));

    pieces = rand() % 5;

    weight = asts[index].getWeight()/pieces;

    std::cout << "Asteroid exploded.\n";

    // if pieces is 0
    if(!pieces)
      std::cout << "You vaporized that asteroid! Woops..\n";

    // loop will only work if pieces is > 0.
    for (int j = 0;j < pieces;j++){

      // generate random coordinates
      int x = rand()%100, y = rand()%100;

      // created asteroid and add it to the vector
      bool precious = false;
      if(asts[index].isPrecious())
        precious = true;
      Asteroid temp = Asteroid(x, y, weight, 0, 0, precious);
      asts.push_back(temp);

      // A piece flew into the ship if its coordinates equal the ship's coordinates
      if(x == coords[0] && y == coords[1]){
        // Captain is alerted and repait bots are called
        std::cout << "A piece flew into your ship. Repair bots are on the way\n";
        // Repair bots are repairing the ship...
        #ifdef __linux__
          usleep(3000000);
        #else
          Sleep(3000);
        #endif
        std::cout << "Repaired!\n";
      } else
        std::cout << "A piece flew to: (" << x << ", " << y << ")\n";

    }

  }

  std::cout << "\n";

  asts.erase(asts.begin() + index); // asteroid blows up

}

/*
 * @DestructorName: ~Starship
 * @Description:
 *			-
 * @Params:
 *			n/a
 * @Returns:
 *			n/a
 */

Starship::~Starship(){

}
