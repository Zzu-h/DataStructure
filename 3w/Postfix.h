#pragma once
#include"Array_Stack.h"
#include"Linked_Stack.h"

class Postfix
{
private:
	int size;
	Array_Stack* Stacks;
	Linked_Stack* LStacks;
	string Str;
public:
	Postfix()
	{
		this->size = 1000;
		this->Stacks = new Array_Stack(size / 2);
		this->LStacks = new Linked_Stack();
		Str = "";
	}
	int calculate(char, int n1 = 0, int n2 = 0);
	int calPostfix(string);
	bool isOper(char);
	bool isNum(char);
	void oper(char);
	void setPostfix(string);
	void getPostfix();
	void clear();
};