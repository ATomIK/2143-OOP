#include <iostream>
#include <string>
#include "asteroidlist.h"
#include "asteroid.h"

// default constructor
AsteroidList::AsteroidList(){

}

int AsteroidList::getLines(){
  int ct = 0;
  std::string line;

  while(getline(infile,line))
    ct++;

  // clear infile
  infile.clear();
  // seek to beginning of file
  infile.seekg(0, std::ios::beg);

  return ct;
}

void AsteroidList::generateRoids(std::string input){
  infile.open(input.c_str());

  int ct = 0;

  int x,y;
  double w;
  bool c = false;

  infile >> x >> y >> w;
  while(!infile.eof()){
    asteroids.push_back(Asteroid(x,y,w,c));
    infile >> x >> y >> w;
  }
}
