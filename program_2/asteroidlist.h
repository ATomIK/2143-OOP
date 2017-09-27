#pragma once
#include <iostream>
#include <fstream>

class AsteroidList {

private:
  std::ifstream infile;
  int ast_limit;
  int line_count;
  int asts;

public:

  AsteroidList();

  void generateRoids(int);

};
