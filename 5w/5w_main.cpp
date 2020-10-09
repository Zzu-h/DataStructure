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
	class Iterator {													//반복자 클래스
	private:
		Node* v;														//반복자가 가리키는 노드를 저장하기 위한 포인터 변수
		Iterator(Node* u);										//반복자 생성자
	public:
		int& operator*();											//반복자가 가리키고 있는 노드가 가지고 있는 원소 값을 반환하는 연산자
		bool operator==(const Iterator& p)const;	//현재 노드와 반복자가 가리키고있는 노드 p와 일치하는지 확인하는 연산자
		bool operator!=(const Iterator& p)const;		//현재 노드와 반복자가 가리키고있는 노드 p와 불일치하는지 확인하는 연산자
		Iterator& operator++();								//다음 노드로 반복자를 이동시키는 연산자
		Iterator& operator--();									//이전 노드로 반복자를 이동시키는 연산자

		friend class SequenceList;							//SequenceList 클래스가 Iterator 클래스에 접근할 수 있도록 선언하는 friend 선언
	};

private:
	int n;																//리스트의 크기
	Node* header;													//header 센티널 노드
	Node* trailer;													//trailer 센티널 노드

public:
	SequenceList();													//생성자
	int size() const;													//리스트의 현재 크기 반환
	bool empty() const;											//리스트가 비었는지
	Iterator begin() const;										//반복자를 맨처음 노드로 위치
	Iterator end() const;											//반복자를 trailer 센티널 노드에 위치
	void insertFront(const int& e);						//원소 e를 리스트의 header 센티널 다음에 삽입 시키는 함수
	void insertBack(const int& e);							//원소 e를 리스트의 trailer 센티널 앞에 삽입 시키는 함수
	void insert(const Iterator& p, const int& e);	//위치 p 뒤에 원소 e를 가지는 노드를 삽입하는 함수
	void eraseFront();												//리스트의 header 센티널 다음에 있는 노드를 삭제하는 함수
	void eraseBack();												//리스트의 trailer 센티널 앞에 있는 노드를 삭제하는 함수
	void erase(const Iterator& p);							//위치 p에 존재하는 노드를 삭제

	Iterator atIndex(int i)const;								//인덱스 i를 갖는 원소의 위치를 반환
	int indexOf(const Iterator& p)const;				//위치 p에 있는 원소의 인덱스를 반환
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

//void SequenceList::erase(const Iterator& p) {
//	Node* v = p.v;
//	Node* w = v->next;
//	Node* u = v->prev;
//	u->next = w;		v->prev = u;
//	delete v;
//	this->n--;
//}

//혁이 코드
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
	string str;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "print")
			print(T);
		else if (str == "reversePrint")
			reversePrint(T);
		else if (str == "--") {
			if (iter == T.begin() || T.empty()) {
				continue;
			}
			else
				--iter;
		}
		else if (str == "++") {
			if (iter == T.end() || T.empty())
				continue;
			else
				++iter;
		}
		else if (str == "insert") {
			int input = 0;
			cin >> input;
			T.insert(iter, input);
		}
		else if (str == "erase") {
			/*if (T.empty()) {
				cout << "Empty" << endl;
				continue;
			}
			else*/ {
				T.erase(iter);
				/*if (T.empty()) {
					T.reset();
					iter = T.begin();
				}*/
			}
		}
		else if (str == "begin")
			iter = T.begin();
		else if (str == "end")
			iter = T.end();
		else if (str == "size")
			cout << T.size() << endl;
		else
			cout << "Your command is wrong, try again." << endl;
	}

	return 0;
}