#include<iostream>
using namespace  std;

class MyHash {
private:
	int size;
	int* arr;
	int P;
public:
	MyHash(int S) {
		this->P = S;
		this->size = 0;
		this->arr = new int[P];
		for (int i = 0; i < S; i++)
			arr[i] = -1;
	}
	int hashfunc1(int key) {
		return (key % P);
	}
	int hashfunc2(int key) {
		return (17 - (key % 17));
	}

	void insert(int key) {
		int h = hashfunc1(key);
		int h2 = hashfunc2(key);
		int i = 0;
		while (arr[h] != -1) {
			i++;
			h = (h+i*h2)%P;
		}
		arr[h] = key;
		this->size++;
	}
	void print() {
		for (int i = 0; i < P; i++)
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
		h.print();
	}

	return 0;
}