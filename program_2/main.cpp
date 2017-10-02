#include <iostream>
#include <string>

#include "asteroid.h"
#include "starship.h"

using namespace std;

void openFiles(fstream&,fstream&);

void generateAsteroidField(vector<Asteroid>&,fstream&);

int main(){

	fstream ifile, ofile;
	Starship Ship;
	vector<Asteroid> asteroids;

	// prompt the user for input/output
	openFiles(ifile,ofile);
	//  discuss flight plans with the captain (user)
	Ship.captainsLog();

	// generate asteroids from input file
	generateAsteroidField(asteroids,ifile);

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

void openFiles(fstream &ifile, fstream &ofile){

	string input, output;

	cout << "Name of input file ('def' for 'input.txt'): ";
	cin >> input;
	input = input == "def" ? "input.txt" : input;

	ifile.open(input.c_str(), ios::in);

	cout << "Name of output file ('def' for 'output.txt'): ";
	cin >> output;
	output = output == "def" ? "output.txt" : output;

	ofile.open(output.c_str(), ios::out);

}

void generateAsteroidField(vector<Asteroid> &vect, fstream &ifile){

  int getx,gety;
  double getw;
  bool c = false;

  ifile >> getx >> gety >> getw;
  while(!ifile.eof()){
		Asteroid temp(getx,gety,getw,c);
    vect.push_back(temp);
    ifile >> getx >> gety >> getw;
  }

}
