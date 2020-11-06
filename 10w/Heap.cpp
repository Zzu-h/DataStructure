#include "Heap.h"
void Heap::swap(int idx1, int idx2) {
	v[0] = v[idx1];
	v[idx1] = v[idx2];
	v[idx2] = v[0];
}

void Heap::upHeap(int idx) {
	upCount++;
	if (idx == root_index)
		return;
	else {
		int parent = idx / 2;
		if (v[parent] * direction > v[idx] * direction) {
			swap(parent, idx);
			upHeap(parent);
		}
	}
}

void Heap::downHeap(int idx) {
	int left = idx * 2;
	int right = idx * 2 + 1;
	if (right <= heap_size) {
		if (v[left] * direction <= v[right] * direction) {
			if (v[left] * direction < v[idx] * direction) {
				swap(left, idx);
				downHeap(left);
			}
			else return;
		}
		else {
			if (v[right] * direction < v[idx] * direction) {
				swap(right, idx);
				downHeap(right);
			}
			else return;
		}
	}
	else if (left <= heap_size) {
		if (v[left] * direction < v[idx] * direction) {
			swap(left, idx);
			downHeap(left);
		}
		else return;
	}
	else return;
}

void Heap::insert(int e) {
	v.push_back(e);
	heap_size++;
	upHeap(heap_size);
}

int Heap::pop() {
	int top = v[root_index];
	v[root_index] = v[heap_size];
	heap_size--;
	v.pop_back();
	downHeap(root_index);
	return top;
}

int Heap::top() {
	if (isEmpty())
		return -1;

	return v[root_index];
}
int Heap::size() {
	if (isEmpty())
		return -1;

	return heap_size;
}
bool Heap::isEmpty() {
	if (heap_size == 0)
		return true;
	else
		return false;
}
void Heap::print() {
	if (isEmpty() == false) {
		for (int i = root_index; i < heap_size; i++) {
			cout << v[i] << " ";
		}
		cout << v[heap_size] << endl;
	}
	else
		cout << -1 << endl;
}
int Heap::find(int x) {
	if (isEmpty() == false)
		return v.at(x);
	return -1;
}