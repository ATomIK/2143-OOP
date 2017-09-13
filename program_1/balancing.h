#pragma once
#include "array_stack.h"
#include <string>
#include <fstream>

class Balance {
private:
	Stack* S;
	ifstream input;
	ofstream output;
public:
	Balance() {
		input.open("input.txt");
		output.open("output.txt");
	}

	void checkBalance() {
		char in;
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

	void printBalance(bool bal) {
		string out;
		if (bal)
			out = "Balanced!";
		else
			out = "Not balanced.";
		cout << out << endl;
		output << out << endl;
	}

	bool processBalance(char in) {
		if (in == '(')
			S->push(in);
		if (in == ')') {
			if (S->pop() == 'x')
				return false;
			//if (S->empty())
				//return false;
		}
		return S->empty();
	}

};