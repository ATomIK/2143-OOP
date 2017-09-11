#pragma once
#include "array_stack.h"
#include <string>

class Balance {
private:
	Stack* L = new Stack(30);
	Stack* R = new Stack(30);
public:
	void checkBalance() {
		string input;
		//int bal;
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
			printBalance();
		}
	}

	void printBalance() {
		if (L->count() == R->count())
			cout << "Balanced!" << endl;
		else
			cout << "Not balanced." << endl;
	}

};