#include"Linked_Stack.h"

int main() {

	Linked_Stack A_Stack;
	int n;
	string order;
	int X;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> order;

		if (order == "empty") {
			cout << A_Stack.empty() << endl;
		}

		else if (order == "top") {
			cout << A_Stack.top() << endl;
		}
		else if (order == "pop") {
			cout << A_Stack.pop() << endl;
		}
		else if (order == "push") {
			cin >> X;
			A_Stack.push(X);
		}
		else if (order == "size") {
			cout << A_Stack.size() << endl;
		}
	}

	return 0;
}
