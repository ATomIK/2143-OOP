/*
	Tom Johnson
	2143 - Object Oriented Programming
	Dr. Stringfellow
	Program 1 - Palindromes
	09/13/2017
*/

#pragma once
#include <iostream>
#include "palindromes.h"

using namespace std;

/*
 * @FunctionName: Palindromes
 * @Description:
 *			Constructor that initializes the Palindromes class
 *			and opens the output file.
 * @Params:
 *			n/a
 * @Returns:
 *			n/a
 */

Palindromes::Palindromes() {
	output.open("output.txt");
}

/*
 * @FunctionName: init
 * @Description:
 *			Creates an instance of a stack and reads in string from file.
 * @Params:
 *			n/a
 * @Returns:
 *			void
 */

void Palindromes::init() {
	string ifile;
	char in;

	cout << "Type in the name of your input file: ";
	cin >> ifile;

	output << "Input file: input.txt" << "\n\n";

	input.open(ifile);
	cout << "Checking balance..." << endl;

	while (!input.eof()) {
		bool bal = true;
		S = new Stack(30);
		while (input.get(in)) {
			if (in == '(')
				S->push(in);
			if (in == ')') {
				if (!S->empty())
					S->pop();
				else
					bal = false;
			}
			if (in == '\n')
				break;
		}
		if (!bal)
			printBalance(bal);
		else
			printBalance(S->empty());
		S = NULL;
		bal = NULL;
		in = NULL;
	}
}

/*
 * @FunctionName: printBalance
 * @Description:
 *			Prints balance both to console and output file 
 * @Params:
 *			bool bal
 * @Returns:
 * 			void
 */

void Palindromes::printBalance(bool bal) {
	string out;
	if (bal)
		out = "Balanced!";
	else
		out = "Not balanced.";
	cout << out << endl;
	output << out << endl;
}
