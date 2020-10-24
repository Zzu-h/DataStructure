#include<iostream>
#include<string>
using namespace std;

class arrQueue
{
public:
	arrQueue(int size);
	int size();
	bool isEmpty();
	void front();
	void rear();
	void enqueue(int data);
	void dequeue();
	int* Q;
	int capacity;
	int f;
	int r;
};

arrQueue::arrQueue(int size) {
	this->Q = new int[size];
	this->capacity = size;
	this->f = 0;
	this->r = -1;
	for (int i = 0; i <= size; i++) {
		Q[i] = 0;
	}
}

int arrQueue::size() {
	return (r - f + 1 + capacity) % capacity;
}

bool arrQueue::isEmpty() {
	if ((r + 1) % capacity == f)
		return true;
	else
		return false;
}

void arrQueue::front() {
	if (isEmpty())
		cout << "Empty" << endl;
	else
		cout << Q[f] << endl;
}

void arrQueue::rear() {
	if (isEmpty())
		cout << "Empty" << endl;
	else
		cout << Q[r] << endl;
}

void arrQueue::enqueue(int data) {
	if (size() == capacity - 1)
		cout << "Full" << endl;
	else {
		r = (r + 1) % capacity;
		Q[r] = data;
	}
}

void arrQueue::dequeue() {
	if (isEmpty() == true)
		cout << "Empty" << endl;
	else
	{
		cout << Q[f] << endl;
		Q[f] = 0;
		f = (f + 1) % capacity;
	}
}

int main() {
	int n, max;
	cin >> max >> n;
	arrQueue Q(max + 1);
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "enqueue") {
			int input;
			cin >> input;
			Q.enqueue(input);
		}
		else if (cmd == "dequeue") {
			Q.dequeue();
		}
		else if (cmd == "size") {
			cout << Q.size() << endl;
		}
		else if (cmd == "isEmpty") {
			cout << (Q.isEmpty() ? 1 : 0) << endl;
		}
		else if (cmd == "front") {
			Q.front();
		}
		else if (cmd == "rear") {
			Q.rear();
		}
		else
			continue;
	}
	return 0;
}
