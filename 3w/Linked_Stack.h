#pragma once
#include"S_LinkedList.h"

class Linked_Stack {
public:
	int n;
	S_LinkedList* Stack;
	Linked_Stack() {
		this->Stack = new S_LinkedList();
		this->n = 0;
	}
	int size() {
		return n;
	}
	bool empty() {
		return n == 0;
	}
	int top() {
		if (empty())
			return -1;
		else
			return Stack->Peek();
	}
	void push(int e) {
		n++;
		Stack->Append(e);
	}
	int pop() {
		if (empty())
			return -1;
		else {
			n--;
			return Stack->Delete();
		}
	}
};

