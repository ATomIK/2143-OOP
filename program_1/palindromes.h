/*
	Tom Johnson
	2143 - Object Oriented Programming
	Dr. Stringfellow
	Program 1 - Palindromes
	09/13/2017
*/

#pragma once
#include "array_stack.h"
#include <fstream>
#include <string>

using namespace std;


/*
 * @ClassName: Palindromes
 * @Description:
 *			Uses a stack to check the balance of
 *			parenthesis in a string.
 */

class Palindromes {
private:
	Stack* S;
	ifstream input;
	ofstream output;
public:
	Palindromes();

	void init();
	void printBalance(bool);

};
