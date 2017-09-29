#include <iostream>
#include <string>
#include "asteroid.h"

Asteroid::Asteroid(){

}

Asteroid::Asteroid(int setx, int sety, double setw, bool setc){
  x = setx;
  y = sety;
  weight = setw;
  collected = setc;
}

bool Asteroid::isCollected(){
  return collected;
}

double Asteroid::getWeight(){
  return weight;
}

// void Asteroid::generateRoids(std::string input){
//   // .c_str() converts the string var to const chars.
//   infile.open(input.c_str());
//
//   int getx,gety;
//   double getw;
//   bool c = false;
//
//   asteroids.reserve(getLines());
//
//   infile >> getx >> gety >> getw;
//   while(!infile.eof()){
//     Asteroid *temp = new Asteroid(getx,gety,getw,c);
//     asteroids.push_back(temp);
//     infile >> getx >> gety >> getw;
//   }
// }
//
// int Asteroid::getLines(){
//   int ct = 0;
//   std::string line;
//
//   while(getline(infile,line))
//     ct++;
//
//   // clear infile
//   infile.clear();
//   // seek to beginning of file
//   infile.seekg(0, std::ios::beg);
//
//   return ct;
// }

Asteroid::~Asteroid(){

}
