#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
	int data;
	Node* next;
};

class LinkedList {
public:
	Node* f;
	Node* r;
	LinkedList();
	int front();
	int end();
	void addEnd(int data);
	int removeFront();
};

LinkedList::LinkedList() {
	this->f = NULL;
	this->r = NULL;
}
int LinkedList::front() {
	return f->data;
}

int LinkedList::end() {
	return r->data;
}
void LinkedList::addEnd(int data) {
	Node* newNode = new Node(data);
	if (f == NULL) {
		f = r = newNode;
	}
	else {
		r->next = newNode;
		r = newNode;
	}
}

int LinkedList::removeFront() {
	if (f != NULL) {
		Node* tmp = f;
		int tmp_int = f->data;
		f = f->next;
		delete tmp;
		return tmp_int;
	}
	return -1;
}

class LinkedQueue {
public:
	LinkedList* S;
	int n;
	int point;
	LinkedQueue();
	int size();
	int isEmpty();
	void front();
	void rear();
	void enqueue(int e);
	void dequeue();
};

LinkedQueue::LinkedQueue() {
	this->S = new LinkedList();
	this->n = 0;
	this->point = 0;
}
int LinkedQueue::size() {
	return n;
}
int LinkedQueue::isEmpty() {
	if (n == 0)
		return 1;
	else
		return 0;
}

void LinkedQueue::front() {
	if (isEmpty() == true)
		cout << "Empty" << endl;
	else
		cout << S->front() << endl;
}
void LinkedQueue::rear() {
	if (isEmpty() == true)
		cout << "Empty" << endl;
	else
		cout << S->end() << endl;
}

void LinkedQueue::enqueue(int e) {
	n++;
	S->addEnd(e);
}

void LinkedQueue::dequeue() {
	if (isEmpty() == true)
		cout << "Empty" << endl;
	else {
		cout << S->removeFront() << endl;
		n--;
	}
}

int main() {
	LinkedQueue Q;
	int n, max;
	cin >> max >> n;
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "enqueue") {
			int input;
			cin >> input;
			if (Q.size() >= max)
				cout << "Full" << endl;
			else
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
