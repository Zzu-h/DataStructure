#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Heap {
private:
	vector<int> v;
	int heap_size;
	int root_index;
	int direction;
	int upCount;
public:
	Heap(int direction) {
		v.push_back(-1);
		this->heap_size = 0;
		this->root_index = 1;
		this->direction = direction;
		this->upCount = 0;
	}
	int getCount() {
		return upCount;
	}
	void swap(int idx1, int idx2);
	void upHeap(int idx);
	void downHeap(int idx);
	void insert(int e);
	int pop();
	int top();
	int size();
	bool isEmpty();
	void print();
	int find(int x);
};