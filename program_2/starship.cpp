#include <iostream>
#include "starship.h"

Starship::Starship(){

}

void Starship::captainsLog(std::string &input,std::string &output){

  int choice;

  std::cout << "Would you like to warp using "
					"pre-defined coordinates?\n\n1. Yes\n2. No.\n";
	std::cin >> choice;

	if(choice == 1)
		std::cout << "\nWarping to (0,0)...\n\n";
	else {
		int x = 0, y = 0;
		std::cout << "Please enter an x coordinate followed by a y coordinate\n "
		"for the ship to warp to. (Example: 5 25):";
		std::cin >> x >> y;

		std::cout << "\nWarping to (" << x << "," << y << ")...\n\n";
	}

	std::cout << "How many asteroids would you like to collect before "
					"returning to earth? (integer): ";
	std::cin >> limit;

	std::cout << "What's the name of your input file? ('def' for 'input.txt'): ";
	std::cin >> input;
	input = input == "def" ? "input.txt" : input;

	std::cout << "What's the name of your output file? ('def' for 'output.txt'): ";
	std::cin >> output;

	output = output == "def" ? "output.txt" : output;

}
