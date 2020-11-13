#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* leftChild;
	Node* rightChild;
	Node* parent;

	Node() {
		this->leftChild = NULL;
		this->rightChild = NULL;
		this->parent = NULL;
	}
	Node(int data) {
		this->data = data;
		this->leftChild = NULL;
		this->rightChild = NULL;
		this->parent = NULL;
	}
};
class binarySearchTree
{
private:
	Node* root;
	int count;
public:
	binarySearchTree() {
		this->root = NULL;
		this->count = 0;
	}
	void insert(int inputData) {
		Node* newNode = new Node(inputData);
		Node* saveNode = NULL;

		if (root == NULL) {
			root = newNode;
		}
		else
		{
			Node* curNode = root;
			while (curNode != NULL) {
				saveNode = curNode;
				if (curNode->data == inputData) {
					cout << "Duplication" << endl;
					return;
				}
				else if (curNode->data > inputData) {
					curNode = curNode->leftChild;
				}
				else {
					curNode = curNode->rightChild;
				}
			}
			if (saveNode->data > inputData) {
				newNode->parent = saveNode;
				saveNode->leftChild = newNode;
			}
			else
			{
				newNode->parent = saveNode;
				saveNode->rightChild = newNode;
			}
		}
		count++;
	}

	Node* find(int inputData) {
		Node* curNode = root;

		while (curNode != NULL) {
			if (curNode->data == inputData) {
				return curNode;
			}
			else if (curNode->data > inputData) {
				curNode = curNode->leftChild;
			}
			else {
				curNode = curNode->rightChild;
			}
		}
		return NULL;
	}

	Node* min_findNode(Node* _Node) {
		Node* curNode = _Node;
		Node* saveNode = NULL;
		while (curNode != NULL) {
			saveNode = curNode;
			curNode = curNode->leftChild;
		}
		return saveNode;
	}
	Node* max_findNode(Node* _Node) {
		Node* curNode = _Node;
		Node* saveNode = NULL;
		while (curNode != NULL) {
			saveNode = curNode;
			curNode = curNode->rightChild;
		}
		return saveNode;
	}

	void erase(int data) {
		Node* curNode = find(data);
		int numOfchild = bool(curNode->leftChild) + bool(curNode->rightChild);

		if (numOfchild == 0) {
			if (curNode == root) {
				root = NULL;
				count--;
			}
			else {
				if (curNode->parent->data > curNode->data) {
					curNode->parent->leftChild = NULL;
					count--;
				}
				else {
					curNode->parent->rightChild = NULL;
					count--;
				}
			}
			delete curNode;
		}
		else if (numOfchild == 2) {
			Node* minNode = min_findNode(curNode->rightChild);
			int data = minNode->data;
			erase(minNode->data);
			curNode->data = data;
		}
		else if (numOfchild == 1) {
			if (curNode == root) {
				if (curNode->leftChild != NULL) {
					count--;
					root = curNode->leftChild;
				}
				else {

					count--;
					root = curNode->rightChild;
				}
			}
			else {
				Node* curParent = curNode->parent;
				Node* child = (curNode->leftChild) ? curNode->leftChild : curNode->rightChild;

				if (curParent->data > child->data) {

					count--;
					curParent->leftChild = child;
					child->parent = curParent;
				}
				else {

					count--;
					curParent->rightChild = child;
					child->parent = curParent;
				}
			}
			delete curNode;
		}
		//cout << " [" << count << "]" << endl;
	}

	void preorderPrint(Node* curNode) {
		if (curNode != NULL) {
			cout << curNode->data << " ";
			preorderPrint(curNode->leftChild);
			preorderPrint(curNode->rightChild);
		}
	}
	void preorder() {
		preorderPrint(root);
		cout << endl;
	}

	void inorderPrint(Node* curNode) {
		if (curNode != NULL) {
			inorderPrint(curNode->leftChild);
			cout << curNode->data << " ";
			inorderPrint(curNode->rightChild);
		}
	}
	void inorder() {
		if (count == 0)
			cout << "Empty" << endl;
		else {
			inorderPrint(root);
			cout << endl;
		}
	}


	void printMaxMin(int data) {
		Node* tempNode = find(data);

		if (tempNode->leftChild == NULL) {
			if (tempNode->rightChild == NULL) {
				//leafNode 일 경우
				cout << tempNode->data << " ";
				cout << tempNode->data << endl;
			}
			else {
				//오른쪽 자식만 있을경우
				cout << tempNode->data << " ";
				cout << min_findNode(tempNode->rightChild)->data << endl;
			}
		}
		else {
			if (tempNode->rightChild == NULL) {
				//왼쪽 자식만 있을 경우
				cout << max_findNode(tempNode->leftChild)->data << " ";
				cout << tempNode->data << endl;
			}
			else {
				//양쪽 모든 자식이 있을 경우
				cout << max_findNode(tempNode->leftChild)->data << " ";
				cout << min_findNode(tempNode->rightChild)->data << endl;
			}
		}
	}
};


int main() {
	int a, b, c, d, e;
	cin >> a;

	//1번
	/*while (a--) {
		cin >> b;
		binarySearchTree t;
		while (b--) {
			cin >> c;
			t.insert(c);
		}
		cin >> d;
		t.printMaxMin(d);
	}*/

	//2번
	while (a--) {
		cin >> b;
		binarySearchTree t;
		while (b--) {
			cin >> c;
			t.insert(c);
		}
		cin >> d;
		while (d--) {
			cin >> e;
			t.erase(e);
		}
		t.inorder();
	}
}