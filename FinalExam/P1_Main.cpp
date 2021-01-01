#include<iostream>
#include<vector>
using namespace std;

#define Max 1
#define Min -1
class Heap {
private:
	vector<int> arr;
	int flag;
public:
	Heap(int flag) {
		arr.push_back(10000000);
		this->flag = flag;
	}
	bool isEmpty() {
		if (arr.size() == 1)
			return true;
		else
			return false;
	}
	void swap(int idx1, int idx2) {
		int temp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = temp;
	}
	int findidx(int data) {
		for (int i = 1; i < arr.size(); i++)
			if (arr[i] == data)
				return i;
		return -1;
	}
	void UpHeap(int idx) {
		if (idx == 0)
			return;
		int paridx = idx / 2;
		if (arr[paridx] < arr[idx]) {
			swap(idx, paridx);
			UpHeap(idx / 2);
		}
		else
			return;
	}
	void downHeap(int idx) {
		int idx1 = (idx * 2);
		int idx2 = ((idx * 2) + 1);
		if (idx2 < arr.size()) {
			if (arr[idx1] > arr[idx2]) {
				if (arr[idx1] > arr[idx]) {
					swap(idx1, idx);
					downHeap(idx1);
				}
				else {
					//idx2<idx1<idx
				}
			}
			else {
				if (arr[idx2] > arr[idx]) {
					swap(idx2, idx);
					downHeap(idx2);
				}
				else {
					//idx1<idx2<idx
				}
			}
		}
		else if (idx1 < arr.size()) {
			if (arr[idx1] > arr[idx]) {
				swap(idx1, idx);
				downHeap(idx1);
			}
			else {
				//idx2<idx1<idx
			}
		}
		else
			return;
	}
	void insert(int data) {
		arr.push_back(data * flag);
		UpHeap(arr.size()-1);
	}
	void erase(int data) {
		if (isEmpty())
			return;
		int delData = data * flag;
		int dataIdx = findidx(delData);
		if (dataIdx == -1)
			return;
		swap(dataIdx, arr.size()-1);
		arr.pop_back();
		downHeap(dataIdx);
	}
	void pop() {
		swap(1, arr.size() - 1);
		arr.pop_back();
		downHeap(1);
	}
	int top() {
		return (arr[1]*flag);
	}
	void print() {
		if (isEmpty()) {
			cout << "Empty" << endl;
			return;
		}
		for (int i = 1; i < arr.size(); i++)
			cout << (arr[i] * flag) << " ";
		cout << endl;
	}
	int getSize() {
		return (this->arr.size() - 1);
	}
};

int main() {
	
	int T;
	cin >> T;
	while (T--) {
		Heap h(Min);
		int N;
		cin >> N;
		while (N--) {
			int k;
			cin >> k;
			h.insert(k);
		}
		cin >> N;
		while (!h.isEmpty()) {
			if (h.top() == N) {
				h.pop();
				break;
			}
			h.pop();
		}
		//h.erase(N);
		h.print();
	}
	return 0;
}