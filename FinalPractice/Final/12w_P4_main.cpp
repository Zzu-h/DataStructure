#include<iostream>
using namespace std;

class MyHash {
	int* arr;
	int arrSize;
	int size;
public:
	MyHash(int p) {

		this->arr = new int[p];
		this->arrSize = p;
		this->size = 0;
		for (int i = 0; i < p; i++)
			arr[i] = -1;
	}

	void insert(int k) {
		int key = hashfunc(k);

		while (arr[key] != -1)
			key = ((key + 1) % arrSize);

		arr[key] = k;
		this->size++;
	}
	int hashfunc(int k) {
		return (k % arrSize);
	}
	void find(int key) {
		int h = hashfunc(key);
		int i = 0;
		bool f = false;
		for (i = 0; i < arrSize; i++) {
			if (arr[h] == -1)
				break;
			else if (arr[h] == key) {
				f = true;
				break;
			}
			h = (h + 1) % arrSize;
		}
		if (f)
			cout << "True " << ++i;
		else
			cout << "False " << ++i;
		cout << endl;
	}
	void print() {
		for (int i = 0; i < arrSize; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int P, Q;
		cin >> P >> Q;
		MyHash h(P);
		while (Q--) {
			int k;
			cin >> k;
			h.insert(k);
		}
		cin >> Q;
		while (Q--) {
			int k;
			cin >> k;
			h.find(k);
		}
	}

	return 0;
}