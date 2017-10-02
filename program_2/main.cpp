#include <iostream>
#include <string>

#include "asteroid.h"
#include "starship.h"

using namespace std;

void generateAsteroidField(vector<Asteroid>&,string);

// void printRoids(vector<Asteroid>&);

int main(){

	string input, output;
	vector<Asteroid> asteroids;

	Starship Ship;

	//  discuss flight plans with the captain (user)
	// in other words, prompting the user for input/output
	Ship.captainsLog(input,output);

	// generate asteroids from input file
	generateAsteroidField(asteroids,input);

	// loop <RoidList.maxRoids()> times
	for(int i = 0;i < Ship.getLimit();i++){

		// find target
		int index;
		index = Ship.findClosest(asteroids);
		// ship moves to target
		Ship.moveTo(index, asteroids);

		// mine asteroid
		Ship.mineAsteroid(index, asteroids);
				// asteroid > ship ? blast()
				// else collect()
	}

	cout << "\nRan\n";

	return 0;
}

void generateAsteroidField(vector<Asteroid> &vect, string input){

	ifstream infile;
	infile.open(input.c_str());

  int getx,gety;
  double getw;
  bool c = false;

  infile >> getx >> gety >> getw;
  while(!infile.eof()){
		Asteroid temp(getx,gety,getw,c);
    vect.push_back(temp);
    infile >> getx >> gety >> getw;
  }

}
//
// void printRoids(vector<Asteroid> &vect){
//
// 	for(int i = 0;i<vect.size();i++){
//
// 		cout << vect[i].getWeight() << " ";
//
// 	}
//
// }
