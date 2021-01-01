#include<iostream>
using namespace std;


class MyHash {
private:
	int* arr;
	int p;
	int size;
public:
	MyHash(int s) {
		this->arr = new int[s];
		this->p = s;
		this->size = 0;
		for (int i = 0; i < s; i++)
			arr[i] = -1;
	}
	void insert(int key) {
		int h = hashfunc(key);
		while (arr[h] != -1) {
			h = ((h + 1) % p);
		}
		arr[h] = key;
		this->size++;
	}
	int hashfunc(int key) {
		return (key % p);
	}

	void erase(int key) {
		this->size--;
		int h = hashfunc(key);
		while (arr[h] != -1) {
			if (arr[h] == key) {
				arr[h] = 0;
				return;
			}
			h = ((h + 1) % p);
		}
	}
	void print() {
		for (int i = 0; i < p; i++)
			cout<<arr[i] <<" ";
		cout << endl;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int P;
		cin >> P;
		MyHash h(P);
		int Q;
		cin >> Q;
		while (Q--) {
			int k;
			cin >> k;
			h.insert(k);
		}
		cin >> Q;
		while (Q--) {
			int k;
			cin >> k;
			h.erase(k);
		}
		h.print();
	}
	return 0;
}