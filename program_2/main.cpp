#include <iostream>

#include "asteroid.h"
// #include "asteroidlist.h"
#include "starship.h"

using namespace std;

int getInputLines();

int main(){

	Starship Ship;
	Asteroid Roid;

	ifstream infile;
	ofstream outfile;

	Ship.captainsLog();

	string input;
	cout << "What's the name of your input file? ('def' for 'input.txt'): ";
	cin >> input;
	input = input == "def" ? "input.txt" : input;

	infile.open(input.c_str());

  int getx,gety;
  double getw;
  bool c = false;

  infile >> getx >> gety >> getw;
  while(!infile.eof()){
    Roid.asteroids.push_back(Asteroid(getx,gety,getw,c));
    infile >> getx >> gety >> getw;
  }

	string output;
	cout << "What's the name of your output file? ('def' for 'output.txt'): ";
	cin >> output;

	output = output == "def" ? "output.txt" : output;

	// generate asteroids from input file
	// Roid.generateRoids(input);
	generateAsteroidField(input,&Roid);

	// loop <RoidList.maxRoids()> times

		// find target

		// mine asteroid
				// asteroid > ship ? explode
				// else collect()

	// endloop

	cout << "\nRan\n";

	return 0;
}

void generateAsteroidField(string input, Asteroid* asteroid){

	ifstream infile;
	infile.open(input.c_str());

  int getx,gety;
  double getw;
  bool c = false;

  infile >> getx >> gety >> getw;
  while(!infile.eof()){
    asteroid.push_back(Asteroid(getx,gety,getw,c));
    infile >> getx >> gety >> getw;
  }

}

int getInputLines(string infile) {

	int ct = 0;
  string line;

  while(getline(infile,line))
    ct++;

  // clear infile
  infile.clear();
  // seek to beginning of file
  infile.seekg(0, ios::beg);

  return ct;

}
