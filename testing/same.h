#include <vector>

class Same {

private:
	std::vector<Same> listofsames;
	int x;

public:
	Same();

	void insert(int);

	void print();

};
