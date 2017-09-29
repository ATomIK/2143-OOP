#include <iostream>
#include <vector>
#include "same.h"

Same::Same(){

}

void Same::insert(int a){
	Same *temp = new Same;
	temp->x = a;
	listofsames.push_back(*temp);
}

void Same::print(){
	std::vector<Same>::iterator it;
	for(it = listofsames.begin();it != listofsames.end();++it){
		std::cout << it->x;
	}
}
