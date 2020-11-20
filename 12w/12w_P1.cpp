#include <iostream>
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
using namespace std;

class cell {
public:
	int key;
	int value;
	int flag;
	cell() {
		key = -1;
		value = -1;
		flag = NOITEM;
	}
};

class LinearHashTable {
private:
	cell* hashArr;
	int arrSize;
	int curSize;
public:
	LinearHashTable(int size) {
		this->arrSize = size;
		hashArr = new cell[arrSize];
		curSize = 0;
	}
	int hashfunc(int key) {
		return key % arrSize;
	}

	void find(int key) {
		int probing = 1;
		int initial_idx = hashfunc(key) % arrSize;
		int curIdx = hashfunc(key) % arrSize;
		bool firstOpr = true;

		while (hashArr[curIdx].flag == ISITEM || hashArr[curIdx].flag == AVAILABLE) {
			if (hashArr[curIdx].key == key) {
				return;
			}
			else if (curIdx == initial_idx && !firstOpr) {
				return;
			}

			probing += 1;
			firstOpr = false;
			curIdx = (hashfunc(key) + probing - 1) % arrSize;
		}
	}
	void put(int key, int value) {
		int probing = 1;
		int initial_idx = hashfunc(key) % arrSize;
		int curIdx = hashfunc(key) % arrSize;
		bool firstOpr = true;

		if (isFull()) {
		}
		else {
			while (hashArr[curIdx].flag == ISITEM) {
				if (curIdx == initial_idx && !firstOpr) {
					break;
				}
				probing += 1;
				firstOpr = false;
				curIdx = (hashfunc(key) + probing - 1) % arrSize;
			}
			hashArr[curIdx].key = key;
			hashArr[curIdx].value = value;
			hashArr[curIdx].flag = ISITEM;
		}
		curSize++;
	}
	void erase(int key) {
		int probing = 1;
		int initial_idx = hashfunc(key) % arrSize;
		int curIdx = hashfunc(key) % arrSize;
		bool firstOpr = true;

		while (hashArr[curIdx].flag == ISITEM || hashArr[curIdx].flag == AVAILABLE) {
			if (hashArr[curIdx].key == key) {
				hashArr[curIdx].flag = AVAILABLE;
				hashArr[curIdx].key = -1;
				hashArr[curIdx].value = -1;
			}
			else if (curIdx == initial_idx && !firstOpr) {
				break;
			}

			probing += 1;
			firstOpr = false;
			curIdx = (hashfunc(key) + probing - 1) % arrSize;
		}
		curSize--;
	}
	bool isFull() {
		return (curSize == arrSize);
	}
	bool isEmpty() {
		return (curSize == 0);
	}
	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << hashArr[i].value << " ";
		}
		cout << endl;
	}
};


int main() {
	int Tn;
	cin >> Tn;
	while (Tn--) {
		int size, Q, e;
		cin >> size >> Q;
		LinearHashTable ht(size);
		while(Q--){
			cin >> e;
			ht.put(e ,e);
		}
		ht.print();
	}
}