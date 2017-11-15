#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

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
  cargoWeight = 0.0;
  distance = 0.0;
  current = 0;
  limit = 0;
}

Starship::Starship(std::string n, int x, int y) : Starcraft(n,x,y){
  cargoWeight = 0.0;
  distance = 0.0;
  current = 0;
  limit = 0;
}

/*
 * @ParameterizedConstructorName: Starship
 * @Description:
 *			Sets ship details
 * @Params:
 *			n/a
 * @Returns:
 *			n/a
 */

// Starship::Starship() : Starcraft(){
//   coords[0] = 0;
//   coords[1] = 0;
//   cargoWeight = 0.0;
//   distance = 0.0;
//   current = 0;
//   limit = 0;
// }

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
 * @MethodName: toString
 * @Description:
 *			Returns string of pretty object data
 * @Params:
 *      n/a
 * @Returns:
 *			string - pretty object data
 */

std::string Starship::toString(){
  std::string result = name;
  result += " at (";
  result += std::to_string(coords[0]);
  result += ", ";
  result += std::to_string(coords[1]);
  result += "). Total distance: ";
  std::stringstream dbl;
  dbl << std::fixed << std::setprecision(2) << distance;
  std::string s = dbl.str();
  result += s;
  result += ". Cargo bay: ";
  std::stringstream db;
  db << std::fixed << std::setprecision(2) << cargoWeight;
  std::string l = db.str();
  result += l;
  result += " kilotons. Mined asteroids: ";
  result += std::to_string(current);
  result += ".\n";
  return result;
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

void Starship::blAsteroid(int index){
  int pieces;
  double weight;

  #ifdef __linux__
    usleep(2000000);
  #else
    Sleep(2000);
  #endif

  // prompt the user for a choice
  int choice;
  std::cout << "\n" << name << " encountered an asteroid too large for its drill!"
    << "\nBlast it?\n1. Yes\n2. No\n";
  std::cin >> choice;
  std::cout << "\n";

  // User chose not to blast it, ignoring it.
  if (choice == 2) {
    database.erase(database.begin() + index); // delete asteroid from field

    std::cout << "Ignoring asteroid...\n\n";
  } else {

    srand((unsigned int)time(NULL));

    pieces = rand() % 5;

    weight = database[index].getWeight()/pieces;

    std::cout << "Asteroid exploded.\n";

    // if pieces is 0
    if(!pieces)
      std::cout << name << " used too much power! It vaporized the asteroid..\n";

    // loop will only work if pieces is > 0.
    for (int j = 0;j < pieces;j++){

      // generate random coordinates
      int x = rand()%100, y = rand()%100;

      // created asteroid and add it to the vector
      bool precious = true;

      Asteroid temp = Asteroid(x, y, weight, 0, 0, precious);

      database.push_back(temp);

      // A piece flew into the ship if its coordinates equal the ship's coordinates
      if(x == coords[0] && y == coords[1]){
        // Captain is alerted and repait bots are called
        std::cout << "A piece flew into " << name <<". Repair bots are on the way\n";
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

  #ifdef __linux__
    usleep(1000000);
  #else
    Sleep(1000);
  #endif

  std::cout << "\n";

  database.erase(database.begin() + index); // asteroid blows up

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
