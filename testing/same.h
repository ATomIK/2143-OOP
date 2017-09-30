#pragma once
#include <vector>

class Same {

private:
	std::vector<Same> listofsames;
	int x;
	int g;

public:
	Same();

	void insert(int);

	void print();

};
