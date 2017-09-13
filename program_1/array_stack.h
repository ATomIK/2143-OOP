/*
	Tom Johnson
	2143 - Object Oriented Programming
	Dr. Stringfellow
	Program 1 - Palindromes
	09/13/2017
*/

#pragma once

/*
 * @ClassName: Stack
 * @Description:
 *			Creates a stack data type.
 */

class Stack {

private:
	char *S;
	int top;
	int size;

public:
	Stack(int);

	void push(char);
	char pop();
	void print();
	bool full();
	bool empty();

};