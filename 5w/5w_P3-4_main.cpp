#include <iostream>
using namespace std;

class SequenceList
{
private:
	struct  Node
	{
		int e = 0;
		Node* prev;
		Node* next;
	};

public:
	class Iterator {													//�ݺ��� Ŭ����
	private:
		Node* v;														//�ݺ��ڰ� ����Ű�� ��带 �����ϱ� ���� ������ ����
		Iterator(Node* u);										//�ݺ��� ������
	public:
		int& operator*();											//�ݺ��ڰ� ����Ű�� �ִ� ��尡 ������ �ִ� ���� ���� ��ȯ�ϴ� ������
		bool operator==(const Iterator& p)const;	//���� ���� �ݺ��ڰ� ����Ű���ִ� ��� p�� ��ġ�ϴ��� Ȯ���ϴ� ������
		bool operator!=(const Iterator& p)const;		//���� ���� �ݺ��ڰ� ����Ű���ִ� ��� p�� ����ġ�ϴ��� Ȯ���ϴ� ������
		Iterator& operator++();								//���� ���� �ݺ��ڸ� �̵���Ű�� ������
		Iterator& operator--();									//���� ���� �ݺ��ڸ� �̵���Ű�� ������

		friend class SequenceList;							//SequenceList Ŭ������ Iterator Ŭ������ ������ �� �ֵ��� �����ϴ� friend ����
	};

private:
	int n;																//����Ʈ�� ũ��
	Node* header;													//header ��Ƽ�� ���
	Node* trailer;													//trailer ��Ƽ�� ���

public:
	SequenceList();													//������
	int size() const;													//����Ʈ�� ���� ũ�� ��ȯ
	bool empty() const;											//����Ʈ�� �������
	Iterator begin() const;										//�ݺ��ڸ� ��ó�� ���� ��ġ
	Iterator end() const;											//�ݺ��ڸ� trailer ��Ƽ�� ��忡 ��ġ
	void insertFront(const int& e);						//���� e�� ����Ʈ�� header ��Ƽ�� ������ ���� ��Ű�� �Լ�
	void insertBack(const int& e);							//���� e�� ����Ʈ�� trailer ��Ƽ�� �տ� ���� ��Ű�� �Լ�
	void insert(const Iterator& p, const int& e);	//��ġ p �ڿ� ���� e�� ������ ��带 �����ϴ� �Լ�
	void eraseFront();												//����Ʈ�� header ��Ƽ�� ������ �ִ� ��带 �����ϴ� �Լ�
	void eraseBack();												//����Ʈ�� trailer ��Ƽ�� �տ� �ִ� ��带 �����ϴ� �Լ�
	void erase(const Iterator& p);							//��ġ p�� �����ϴ� ��带 ����
	void eraseAll();							//��ġ p�� �����ϴ� ��带 ����
	void calculateMax();
	void calculateMin();

	Iterator atIndex(int i)const;								//�ε��� i�� ���� ������ ��ġ�� ��ȯ
	int indexOf(const Iterator& p)const;				//��ġ p�� �ִ� ������ �ε����� ��ȯ
	void reset();
};

SequenceList::SequenceList() {
	n = 0;
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
}

void SequenceList::insert(const SequenceList::Iterator& p, const int& e) {
	Node* w = p.v;
	Node* u = w->prev;
	Node* v = new Node;
	v->e = e;
	v->next = w;		w->prev = v;
	v->prev = u;		u->next = v;
	this->n++;
}

void SequenceList::insertFront(const int& e) {
	insert(begin(), e);
}

void SequenceList::insertBack(const int& e) {
	insert(end(), e);
}

void SequenceList::eraseAll() {
	int count = n;
	while (count--) {
		eraseBack();
	}
	n = 0;
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
}

//���� �ڵ�
void SequenceList::erase(const Iterator& p) {
	if (empty()) cout << "Empty" << "\n";
	else {
		Node* tmp = p.v;
		Node* w = tmp->next;
		Node* u = tmp->prev;
		u->next = w;
		w->prev = u;

		delete tmp;
		this->n--;
	}
}

void SequenceList::eraseFront() {
	erase(begin());
}
void SequenceList::eraseBack() {
	erase(--end());
}

int SequenceList::size() const {
	return n;
}

bool SequenceList::empty() const {
	return (n == 0);
}

SequenceList::Iterator::Iterator(Node* u) {
	v = u;
}

SequenceList::Iterator SequenceList::begin()const {
	return Iterator(header->next);
}

SequenceList::Iterator SequenceList::end()const {
	return Iterator(trailer);
}

int& SequenceList::Iterator::operator*() {
	return v->e;
}

bool SequenceList::Iterator::operator==(const Iterator& p)const {
	return v == p.v;
}

bool SequenceList::Iterator::operator!=(const Iterator& p)const {
	return v != p.v;
}

SequenceList::Iterator& SequenceList::Iterator::operator++() {
	v = v->next;
	return *this;
}

SequenceList::Iterator& SequenceList::Iterator::operator--() {
	v = v->prev;
	return *this;
}

SequenceList::Iterator SequenceList::atIndex(int i)const {
	Iterator p = begin();
	for (int j = 0; j < i; j++)
		++p;
	return p;
}

int SequenceList::indexOf(const Iterator& p)const {
	Iterator q = begin();
	int j = 0;
	while (q != p) {
		++q;
		++j;
	}
	return j;
}

void SequenceList::reset() {
	delete header;
	delete trailer;
	n = 0;
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
}

void SequenceList::calculateMax() {
	int count = n;
	int sum = 0, max = 0;

	Iterator I = begin();
	while (count--) {
		sum = sum + *I;
		if (max < *I)
			max = *I;
		++I;
	}
	cout << sum / n << " " << max << endl;
}
void SequenceList::calculateMin() {
	int count = n;
	int sum = 0, min = 1000;

	Iterator I = begin();
	while (count--) {
		sum = sum + *I;
		if (min > * I)
			min = *I;
		++I;
	}
	cout << sum / n << " " << min << endl;
}

//practice 1
void print(const SequenceList& T) {
	SequenceList::Iterator temp = T.begin();
	if (T.empty())
		cout << "Empty";
	else {
		//cout << *temp << "  testing" << endl;
		while (true) {
			if (temp == T.end()) {
				break;
			}
			else {
				cout << *temp << " ";
				++temp;
			}
		}
	}
	cout << endl;
}

//practice 2
void reversePrint(const SequenceList& T) {
	SequenceList::Iterator temp = T.end();
	if (T.empty())
		cout << "Empty";
	else {
		while (true) {
			if (temp == T.begin()) {
				break;
			}
			else {
				--temp;
				cout << *temp << " ";

			}
		}
	}
	cout << endl;
}

int main() {
	SequenceList T;
	SequenceList::Iterator iter(T.begin());

	int n = 0;
	int m = 0;
	int data = 0;
	string str;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		while (m--) {
			cin >> data;
			T.insertBack(data);
		}
		//T.calculateMax();
		T.calculateMin();
		T.eraseAll();
		cout << endl;
	}
	return 0;
}