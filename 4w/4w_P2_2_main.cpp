//이미지 참고
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
		//cout << f->data << endl;
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
	int front();
	int rear();
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

int LinkedQueue::front() {
	if (isEmpty() == true)
		cout << "Empty" << endl;
	else
		return S->front();
}
int LinkedQueue::rear() {
	if (isEmpty() == true)
		cout << "Empty" << endl;
	else
		return S->end();
}

void LinkedQueue::enqueue(int e) {
	n++;
	S->addEnd(e);
}

void LinkedQueue::dequeue() {
	if (isEmpty() == true)
		cout << "Empty" << endl;
	else {
		S->removeFront();
		n--;
	}
}

int main() {


	int T, n;
	cin >> T;
	int num;

	for (int k = 0; k < T; k++) {
		cin >> n;
		LinkedQueue X, Y;
		int x_num = 0, y_num = 0;
		//덱 입력
		int temp = 0;
		for (int i = 0; i < n; i++) {
			cin >> num;
			X.enqueue(num);
		}
		for (int i = 0; i < n; i++) {
			cin >> num;
			Y.enqueue(num);
		}
		//-------여기까지


		for (int i = 0; i < n; i++) {
			//본게임
			x_num += X.front();
			y_num += Y.front();

			temp = x_num - y_num;
		
			if (temp < 0) {
				temp *= -1;
				Y.point++;
				y_num = 0;
				x_num = temp - 1;
		
				// Y가 더 클 경우
			}
			else if (temp > 0) {
				X.point++;
				//X가 더 클 경우
				y_num = temp - 1;
				x_num = 0;
		
			}
			else {
				temp = 0;
				x_num = 0;
				y_num = 0;
			}
		
			X.dequeue();
			Y.dequeue();
		}
		
		if (X.point > Y.point)
			cout << 1 << endl;
		else if (X.point < Y.point)
			cout << 2 << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}