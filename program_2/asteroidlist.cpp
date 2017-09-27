#include <iostream>
#include <string>
#include "asteroidlist.h"

AsteroidList::AsteroidList(){

  infile.open("input.txt");
  int count = 0;
  std::string line;

  while(getline(infile,line))
    count++;

  line_count = count;

}

void AsteroidList::generateRoids(int amount){
  std::cout << "Generating grid...\n\n";
  ast_limit = amount;
  asts = new Asteroid[line_count];

  int ct = 0;
  while(!infile.eof()){

    double x, y, w;
    infile >> x >> y >> w;

    asts[ct] = new Asteroid(x,y,x,0); // THIS LINE

    std::cout << "(" << x << "," << y << ") - " << w << "lbs\n";

    ct++;
  }
}
