#pragma once
#include "array_stack.h"
#include <string>
#include <fstream>

class Balance {
private:
	Stack* L;
	Stack* R;
	ofstream output;
public:
	Balance() {
		L = new Stack(30);
		R = new Stack(30);
		output.open("output.txt");
	}

	void checkBalance() {
		string input;
		for (int i = 0; i < 10; i++) {
			cin >> input;
			for (int j = 0; j < input.length(); j++) {
				char letter = input[j];
				if (letter == '(')
					L->push(letter);
				else if (letter == ')') {
					R->push(letter);
				}
			}
			output << input << endl;
			printBalance();
		}
	}

	void printBalance() {
		string out;
		if (L->count() == R->count())
			out = "Balanced!";
		else
			out = "Not balanced.";
		cout << out << endl;
		output << out << endl;
	}

};