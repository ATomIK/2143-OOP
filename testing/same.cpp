#include <iostream>
#include <fstream>
#include <vector>
#include "same.h"

Same::Same(){

}

void Same::insert(int x){

	std::vector<Same> sames;

	std::ifstream infile("input.txt");

	int a;

	infile >> a;

	while(!infile.eof()){

		Same *temp = new Same;
		temp->x = a;
		temp->g = a+1;
		sames.push_back(*temp);

		infile >> a;

	}
}

void Same::print(){
	std::vector<Same>::iterator it;
	for(it = listofsames.begin();it != listofsames.end();++it){
		std::cout << it->x << " " << it->g;
	}
}
