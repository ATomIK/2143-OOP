/*
	Tom Johnson
	2143 - Object Oriented Programming
	Dr. Stringfellow
	Program 1 - Palindromes
	09/13/2017
*/

#pragma once
#include <iostream>
#include "array_stack.h"

using namespace std;

/*
 * @FunctionName: Stack
 * @Description:
 *			Constructor that initializes the Stack class.
 * @Params:
 *			int s - the size the stack should be
 * @Returns:
 *			n/a
 */

Stack::Stack(int s) {
	size = s;
	top = -1;
	S = new char[size];
}

/*
 * @FunctionName: push
 * @Description:
 *			Pushes a character onto the stack
 * @Params:
 *			char x
 * @Returns:
 *			void
 */

void Stack::push(char x) {
	if (!full())
		S[++top] = x;
	else
		cout << "array_stack overflow.";
}

/*
 * @FunctionName: pop
 * @Description:
 *			Removes the top character from the stack.
 * @Params:
 *			n/a
 * @Returns:
 *			char
 */

char Stack::pop() {
	if (!empty())
		return S[top--];
	else
		return 'x';
}

/*
 * @FunctionName: print
 * @Description:
 *			Prints out what's in the stack
 * @Params:
 *			n/a
 * @Returns:
 *			void
 */

void Stack::print() {
	for (int i = top; i >= 0; i--)
		cout << S[i] << " ";
	cout << endl;
}

/*
 * @FunctionName: full
 * @Description:
 *			Returns true if the stack is full
 * @Params:
 *			n/a
 * @Returns:
 *			bool
 */

bool Stack::full() {
	return top == size - 1;
}

/*
 * @FunctionName: empty
 * @Description:
 *			Returns true if the stack is empty
 * @Params:
 *			n/a
 * @Returns:
 *			bool
 */

bool Stack::empty() {
	return top == -1;
}
