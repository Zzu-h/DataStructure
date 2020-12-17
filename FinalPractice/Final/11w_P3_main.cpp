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
	Node* Root;
	int size;
public:
	BST() {
		this->size = 0;
		this->Root = nullptr;
	}

	Node* findNode(int data) {
		Node* temp = nullptr;
		if (Root->data < data) {
			temp = Root->right;
			while(temp != nullptr){
				if (temp->data < data)
					temp = temp->right;
				else if (temp->data > data)
					temp = temp->left;
				else
					return temp;
			}
		}
		else if (Root->data > data) {
			temp = Root->left;
			while (temp != nullptr) {
				if (temp->data < data)
					temp = temp->right;
				else if (temp->data > data)
					temp = temp->left;
				else
					return temp;
			}
		}
		else
			return Root;
		return nullptr;
	}
	void printAll(int data) {
		if (size == 0) {
			cout << "Empty" << endl;
			return;
		}
		inOrder(Root);
		cout << endl;
	}
	void inOrder(Node* node) {
		if (node->left != nullptr)
			inOrder(node->left);
		cout << node->data << " ";
		if (node->right != nullptr)
			inOrder(node->right);
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
		if (size == 0)
			Root = newNode;
		else {
			if (data < Root->data) {
				if (Root->left == nullptr) {
					Root->left = newNode;
					newNode->par = Root;
				}
				else
					LeftInsert(Root->left, newNode);
			}
			else if (data > Root->data) {
				if (Root->right == nullptr) {
					Root->right = newNode;
					newNode->par = Root;
				}
				else
					RightInsert(Root->right, newNode);
			}
		}
		this->size++;
	}
	void LeftInsert(Node* L, Node* newNode) {
		if (newNode->data < L->data) {
			if (L->left == nullptr) {
				L->left = newNode;
				newNode->par = L;
			}
			else
				LeftInsert(L->left, newNode);
		}
		else if (newNode->data > L->data) {
			if (L->right == nullptr) {
				L->right = newNode;
				newNode->par = L;
			}
			else
				RightInsert(L->right, newNode);
		}
		
	}
	void RightInsert(Node* R, Node* newNode) {
		if (newNode->data < R->data) {
			if (R->left == nullptr) {
				R->left = newNode;
				newNode->par = R;
			}
			else
				LeftInsert(R->left, newNode);
		}
		else if (newNode->data > R->data) {
			if (R->right == nullptr) {
				R->right = newNode;
				newNode->par = R;
			}
			else
				RightInsert(R->right, newNode);
			
		}

	};

	
	void linkPar_Chi(Node* bechi, Node* delNode) {
		Node* par = delNode->par;
		if (par == nullptr);
		else if (par->left == delNode) 
			par->left = bechi;
		else if (par->right == delNode) 
			par->right = bechi;
		else {
			cout << "\n----------------\n예외 발생\n-------------" << endl;
		}
		/*if (bechi != nullptr)
			bechi->par = par;*/
	}
	
	/*void erase(int data) {
		Node* delNode = findNode(data);

		if (delNode == nullptr)
			return;

		int chiN = (bool)delNode->left + (bool)delNode->right;
		if(chiN== 0){
			if (delNode != Root) {
				if (delNode->par->data > data)
					delNode->par->left = nullptr;
				else
					delNode->par->right = nullptr;
			}
			else
				Root = nullptr;// 이거 아님
			size--;
			delete delNode;
		}
		else if(chiN == 1){
			if (delNode == Root) {
				if (delNode->left != nullptr)
					Root = delNode->left;
				else if(delNode->right != nullptr)
					Root = delNode->right;
			}
			else {
				Node* parent = delNode->par;
				Node* child = (delNode->left) ? delNode->left : delNode->right;

				if (parent->data > child->data)
					parent->left = child;
				else
					parent->right = child;
				child->par = parent;
			}
			size--;
			delete delNode;
				
		}
		else if(chiN == 2){
			Node* minNode = Left(delNode->right);
			int data = minNode->data;
			erase(minNode->data);
			delNode->data = data;//이거 주의
		}
	}*/


	void erase(int data) {
		Node* delNode = findNode(data);
		int chiN = (bool)delNode->left + (bool)delNode->right;
		if(chiN == 0){
			if (delNode == Root)
				Root = nullptr;
			else {
				if (delNode->par->data > data)
					delNode->par->left = nullptr;
				else
					delNode->par->right = nullptr;
			}
			size--;
			delete delNode;
		}
		else if (chiN == 1) {
			if (Root == delNode) {
				if (Root->left != nullptr)
					Root = Root->left;
				else
					Root = Root->right;
			}
			else {
				Node* parent = delNode->par;
				Node* child = (delNode->left) ? delNode->left : delNode->right;

				if (parent->data > child->data)
					parent->left = child;
				else
					parent->right = child;
				child->par = parent;
			}
			size--;
			delete delNode;
		}
		else if (chiN == 2) {
			Node* minNode = Left(delNode->right);
			int data = minNode->data;
			erase(minNode->data);
			delNode->data = data;
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
		cin >> P;
		while (P--) {
			cin >> N;
			t.erase(N);
		}
		t.printAll(0);
	}
	return 0;
}