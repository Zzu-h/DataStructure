#include<iostream>
#include<vector>
using namespace std;
#define Max 1
#define Min -1

class Tree {
private:
	vector<int> NodeList;
	int flag;
public:
	Tree(int H) {
		this->NodeList.push_back(10000);
		this->flag = H;
	}
	void insert(int data) {
		NodeList.push_back(data * flag);
		UpHeap(NodeList.size() - 1);
	}
	void swap(int idx1, int idx2) {
		int temp = NodeList[idx1];
		NodeList[idx1] = NodeList[idx2];
		NodeList[idx2] = temp;
	}
	void UpHeap(int n) {
		if (n == 0)
			return;
		else {
			if (NodeList[n] > NodeList[n / 2]) {
				//swap
				swap(n, n / 2);
				//UpHeap 재귀함수
				UpHeap(n / 2);
			}
			else
				//더 이상 upHeap할 필요가 없을 경우
				return;
		}
	}
	void DownHeap(int n) {
		if (n >= NodeList.size())
			return;
		else {
			int odd = ((n * 2) + 1);
			int even = n * 2;
			if (odd <= size()) {
				//자식이 둘 다 있다.
				int temp = 0;
				if (NodeList[even] > NodeList[odd]) {
					if (NodeList[n] > NodeList[even]) {
						// odd < even < n
						return;
					}
					else if (NodeList[n] > NodeList[odd]) {
						// odd < n < even
						swap(n, even);
						DownHeap(even);
					}
					else {
						// n < odd < even
						swap(n, even);
						DownHeap(even);
					}
				}
				else {
					if (NodeList[n] > NodeList[odd]) {
						//  even < odd < n
						return;
					}
					else if (NodeList[n] < NodeList[even]) {
						// even < n < odd
						swap(n, odd);
						DownHeap(odd);
					}
					else {
						// n < even < odd
						swap(n, odd);
						DownHeap(odd);
					}
					
				}
				return;
			}
			else if (even <= size()) {
				//적어도 하나의 자식이 있다.
				if (NodeList[n] < NodeList[even]) {
					//swap
					swap(n, even);
					DownHeap(even);
				}
				return;
			}
			else
				//자식이 없다.
				return;
		}
	}

	int size() {
		return this->NodeList.size() - 1;
	}
	bool isEmpty() {
		if (this->NodeList.size() == 1)
			return true;
		else
			return false;
	}
	void print() {
		if (isEmpty())
			cout << -1;
		else	for (int i = 1; i < NodeList.size(); i++)
			cout << (NodeList[i] * flag) << " ";
		cout << endl;
	}

	void pop() {
		if (isEmpty())
			cout << -1 << endl;
		else {
			cout << (NodeList[1] * flag) << endl;
			swap(1, NodeList.size() - 1);
			NodeList.pop_back();
			DownHeap(1);
		}
	}
	int top() {
		if (isEmpty())
			return-1;
		else
			return (this->NodeList[1] * flag);
	}
};

int main() {
	Tree t(Min);
	int n;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		if (str == "isEmpty")
			cout << t.isEmpty() << endl;
		else if (str == "insert") {
			int data;
			cin >> data;
			t.insert(data);
		}
		else if (str == "size") {
			cout << t.size() << endl;
		}
		else if (str == "pop") {
			t.pop();
		}
		else if (str == "top") {
			cout << t.top() << endl;
		}
		else if (str == "print") {
			t.print();
		}
	}
	return 0;
}