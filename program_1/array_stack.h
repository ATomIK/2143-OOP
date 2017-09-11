#pragma once

using namespace std;

class Stack {

private:
	char *S;
	int top;
	int size;

public:
	Stack(int s) {
		size = s;
		top = -1;
		S = new char[size];
	}

	void push(char x) {
		if (!full())
			S[++top] = x;
		else
			cout << "array_stack push overflow.";
	}

	char pop() {
		if (!empty())
			return S[top--];
		else
			return -1;
	}

	void print() {
		for (int i = top; i >= 0; i--)
			cout << S[i] << " ";
		cout << endl;
	}

	bool full() {
		return top == size - 1;
	}

	bool empty() {
		return top == -1;
	}

	int count() {
		int count = top;
		return count;
	}

};