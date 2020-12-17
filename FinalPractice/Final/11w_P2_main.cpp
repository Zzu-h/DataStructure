#include<iostream>
#include<vector>
using namespace std;


class Node {
public:
	int data;
	Node* par;
	Node* left;
	Node* right;
	Node(int n) {
		this->data = n;
		this->left = nullptr;
		this->right = nullptr;
		this->par = nullptr;
	}
};
class BST {
private:
	vector<Node*> NodeList;
	Node* Root;
	int size;
public:
	BST() {
		this->size = 0;
	}

	Node* findNode(int data) {
		for (int i = 0; i < NodeList.size(); i++)
			if (NodeList[i]->data == data)
				return NodeList[i];
		return nullptr;
	}
	void printAll(int data) {
		Node* A = findNode(data);
		int Lm;
		int Rm;

		if (A->left == nullptr)
			Lm = A->data;
		else
			Lm = Left(A->left)->data;

		if (A->right == nullptr)
			Rm = A->data;
		else
			Rm = Right(A->right)->data;
		cout << Lm << " " << Rm << endl;
	}
	Node* Left(Node* L) {
		if (L->left == nullptr)
			return L;
		else
			return Left(L->left);
	}
	Node* Right(Node* R) {
		if (R->right == nullptr)
			return R;
		else
			return Right(R->right);
	}

	void insert(int data) {
		Node* newNode = new Node(data);
		NodeList.push_back(newNode);
		if (size == 0)
			Root = newNode;
		else {
			if (data < Root->data) {
				if (Root->left == nullptr)
					Root->left = newNode;
				else
					LeftInsert(Root->left, newNode);
			}
			else if (data > Root->data) {
				if (Root->right == nullptr)
					Root->right = newNode;
				else
					RightInsert(Root->right, newNode);
			}
		}
		this->size++;
	}
	void LeftInsert(Node* L, Node* newNode) {
		if (newNode->data < L->data) {
			if (L->left == nullptr)
				L->left = newNode;
			else
				LeftInsert(L->left, newNode);
		}
		else if (newNode->data > L->data) {
			if (L->right == nullptr)
				L->right = newNode;
			else
				RightInsert(L->right, newNode);
		}
		newNode->par = L;
	}
	void RightInsert(Node* R, Node* newNode) {
		if (newNode->data < R->data) {
			if (R->left == nullptr)
				R->left = newNode;
			else
				LeftInsert(R->left, newNode);
		}
		else if (newNode->data > R->data) {
			if (R->right == nullptr)
				R->right = newNode;
			else
				RightInsert(R->right, newNode);
			newNode->par = R;
		}

	};

	int vectorIdx(Node* N){}
	void erase(int data) {
		Node* delNode = findNode(data);
		if (delNode->right == nullptr) {
			NodeList.erase(NodeList.begin() + vectorIdx(delNode));
			delete delNode;
		}
		else {
			Node* temp = Left(delNode->right);
			temp->left = delNode->left;
		}
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		BST t;
		int P, N, x;
		cin >> P;
		while (P--) {
			cin >> N;
			t.insert(N);
		}
		cin >> x;
		t.printAll(x);
	}
	return 0;
}