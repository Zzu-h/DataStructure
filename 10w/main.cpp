#include"Heap.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum direction { MIN = 1, MAX = -1 };
//#define 의 열거형? 배열?

int static_count = 0;

int main() {
	
	int n;
	string cmd;
	cin >> n;
	while (n--) {
		Heap PQ(MIN);
		//1번문제
		/*cin >> cmd;
		if (cmd == "isEmpty") {
			if (PQ.isEmpty() == true)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (cmd == "insert") {
			int e;
			cin >> e;

			PQ.insert(e);
		}
		else if (cmd == "size") {
			cout << PQ.size() << endl;
		}.
		else if (cmd == "pop") {
			if (PQ.isEmpty())
				cout << -1 << endl;
			else
				cout << PQ.pop() << endl;
		}
		else if (cmd == "top") {
			if (PQ.isEmpty())
				cout << -1 << endl;
			else
				cout << PQ.top() << endl;
		}
		else if (cmd == "print") {
			PQ.print();
		}
		else
			continue;*/

		//2번문제
		int num, idx, e;
		cin >> num >> idx;
		while (num--) {
			cin >> e;
			PQ.insert(e);
		}
		PQ.print();
		cout << PQ.find(idx) << endl;
		for (int i = 1; i < idx; i++)
			PQ.pop();
		cout << PQ.pop() << endl;
		static_count += PQ.getCount();
		cout << static_count << endl;
		
	}
	
	return 0;
}