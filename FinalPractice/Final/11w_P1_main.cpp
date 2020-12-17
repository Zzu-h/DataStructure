#include<iostream>
#include<vector>
using namespace std;


class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int n){
		this->data = n;
		this->left = nullptr;
		this->right = nullptr;
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
					Left(Root->left, newNode);
			}
			else if (data > Root->data) {
				if (Root->right == nullptr)
					Root->right = newNode;
				else
					Right(Root->right, newNode);
			}
		}
		this->size++;
	}
	Node* findNode(int data) {
		for (int i = 0; i < NodeList.size(); i++)
			if (NodeList[i]->data == data)
				return NodeList[i];
		return nullptr;
	}
	void printAll(int data) {
		Node* A = findNode(data);
		/*for (int i = 0; i < NodeList.size(); i++)
			cout << NodeList[i]->data << " ";
		cout << endl;*/

		int Lm;
		int Rm;

		if (A->left == nullptr)
			Lm = A->data;
		else
			Lm = RightPrint(A->left)->data;

		if (A->right == nullptr)
			Rm = A->data;
		else
			Rm = LeftPrint(A->right)->data;
		cout << Lm << " " << Rm << endl;
	}
	Node* LeftPrint(Node* L) {
		if (L->left == nullptr)
			return L;
		else
			return LeftPrint(L->left);
	}
	Node* RightPrint(Node* R) {
		if (R->right == nullptr)
			return R;
		else
			return RightPrint(R->right);
	}

	void Left(Node* L, Node* newNode) {
		if (newNode->data < L->data) {
			if (L->left == nullptr)
				L->left = newNode;
			else
				Left(L->left, newNode);
		}
		else if (newNode->data > L->data) {
			if (L->right == nullptr)
				L->right = newNode;
			else
				Right(L->right, newNode);
		}
	}
	void Right(Node* R, Node* newNode) {
		if (newNode->data < R->data) {
			if (R->left == nullptr)
				R->left = newNode;
			else
				Left(R->left, newNode);
		}
		else if (newNode->data > R->data) {
			if (R->right == nullptr)
				R->right = newNode;
			else
				Right(R->right, newNode);
		}
	};
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