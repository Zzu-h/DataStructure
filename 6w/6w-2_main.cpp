#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	int data;
	int depth;
	Node* par;
	vector<Node*> chi_v;

	Node(int data) {
		this->depth = 0;
		this->data = data;
		this->par = NULL;
	}
	~Node() {}

	void setParent(Node* parent) {
		this->par = parent;
	}

	void insertChild(Node* child) {
		this->chi_v.push_back(child);
	}

	void delChild(Node* child) {
		for (int i = 0; i < this->chi_v.size(); i++) {
			if (this->chi_v[i] == child) {
				this->chi_v.erase(this->chi_v.begin() + i);
			}
		}
	}
	void setdepth(int num) {
		this->depth = num + 1;
	}
	int getdepth() const {
		return depth;
	}

};

class Tree
{
private:
	Node* root;
	vector<Node*> node_list;

public:
	Tree(int);
	~Tree() {}
	int size();
	void insertNode(int, int);
	void delNode(int);
	void printChi(int);
	void printSib(int);
	void printDepth(int);
	void maxInDepth(int);
};

Tree::Tree(int data) {
	root = new Node(data);
	node_list.push_back(root); //이걸 넣어야 root리스트에 포함되는거 아냐?
}
int Tree::size() {
	return node_list.size();
}
void Tree::insertNode(int par_data, int data) {
	for (int i = 0; i < size(); i++)
		if (node_list[i]->data == par_data) {
			Node* node = new Node(data);
			node->setdepth(node_list[i]->getdepth());
			node->setParent(node_list[i]);
			node_list[i]->insertChild(node);
			node_list.push_back(node);
			return;
		}
}
void Tree::delNode(int data) {
	Node* nownode;
	Node* par;
	for (int i = 0; i < this->node_list.size(); i++) {
		if (this->node_list[i]->data == data) {
			nownode = node_list[i];
			if (nownode == root)
				return;
			par = nownode->par;
			for (Node*& child : nownode->chi_v) {
				par->insertChild(child);
				child->par = par;
			}
			par->delChild(nownode);
			this->node_list.erase(this->node_list.begin() + i);
			delete nownode;
			//return;
		}
	}
	return;
}
void Tree::printChi(int data) {
	for (int i = 0; i < size(); i++)
		if (node_list[i]->data == data) {
			if (node_list[i]->chi_v.size() == 0) {
				cout << "0" << endl;
				return;
			}
			for (int j = 0; j < node_list[i]->chi_v.size(); j++) {
				cout << node_list[i]->chi_v[j]->data << " ";
			}
			cout << endl;
			return;
		}
}
void Tree::printSib(int data) {
	for (int i = 0; i < size(); i++) {
		if (node_list[i]->data == data) {
			if (node_list[i]->par == NULL) {
				cout << data << endl;
				return;
			}
			else {
				Node* par_node = node_list[i]->par;
				for (int j = 0; j < par_node->chi_v.size(); j++)
					cout << par_node->chi_v[j]->data << " ";
				cout << endl;
				return;
			}
		}
	}
	cout << 0 << endl;
}

void Tree::printDepth(int data) {
	for (int i = 0; i < size(); i++) {
		if (node_list[i]->data == data) {
			cout << node_list[i]->getdepth() << endl;
			return;
		}
	}
	cout << 0 << endl;
}

void Tree::maxInDepth(int data) {
	int max = 0;
	for (int i = 0; i < size(); i++) {
		if (node_list[i]->getdepth() == data) {
			if (max < node_list[i]->data)
				max = node_list[i]->data;
		}
	}
	cout << max << endl;
}

int main() {
	//practice 6w-2
	//Node에 depth 변수를 추가한다.
	int n, m, data;
	cin >> n >> m;
	Tree t = Tree(1);
	//노드 추가
	while (n--) {
		int par, data;
		cin >> par >> data;
		t.insertNode(par, data);
	}
	//질문 수
	while (m--) {
		cin >> data;
		//3번 문제
		t.printDepth(data);
		//4번 
		//t.maxInDepth(data);
	}
	return 0;
}
