#pragma once
#include<iostream>
#include<string>
using namespace std;

class Array_Stack {
public:
	string* Stack;
	int capacity;
	int t;

	Array_Stack(int capacity) {
		this->capacity = capacity;
		this->Stack = new string[capacity];
		this->t = -1;
	}

	int size() {
		return t + 1;
	}

	bool empty() {
		return t == -1;
	}

	string top() {
		if (empty())
			return "-1";
		else
			return Stack[t];
	}

	void push(char e) {
		if (size() == capacity)
			cout << "Full" << endl;
		else
			Stack[++t] = e;
	}

	void push(int e) {
		string temp = std::to_string(e);
		if (size() == capacity)
			cout << "Full" << endl;
		else
			Stack[++t] = temp;
	}

	string pop() {
		if (empty())
			return "-1";
		return Stack[t--];
	}
};

