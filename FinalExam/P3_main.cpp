#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class vertex {
public:
	int data;
	bool visit;
	vector<vertex*> adj;
};
#define Range 20000
class graph {
private:
	bool** edgeMatrix;
	queue<vertex*> Q;
	vector<vertex*> vertices;
public:
	graph() {
		this->edgeMatrix = new bool*[Range];
		for (int i = 0; i < Range; i++)
			edgeMatrix[i] = new bool[Range];
		for (int i = 0; i < Range; i++)
			for (int j = 0; j < Range; j++)
				edgeMatrix[i][j] = false;
	}
	vertex* findVertex(int data) {
		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i]->data == data)
				return vertices[i];
		}
		return nullptr;
	}
	void BFS(int data) {
		vertex* v = findVertex(data);
		Q.push(v);
		v->visit = true;

		while (!Q.empty()) {
			vertex* w = Q.front();
			Q.pop();
			cout << w->data << " ";
			for (int i = 0; i < w->adj.size(); i++) {
				vertex* z = w->adj[i];
				if (!z->visit) {
					Q.push(z);
					z->visit = true;
				}
			}
		}

	}

	void insertVertex(int data) {
		vertex* newV = new vertex();
		newV->data = data;
		newV->visit = false;

		vertices.push_back(newV);
	}
	void insertEdge(int v1, int v2) {
		vertex* vertex1 = findVertex(v1);
		vertex* vertex2 = findVertex(v2);
		if ((vertex1 == nullptr) || (vertex2 == nullptr))
			return;
		if (edgeMatrix[v1][v2] == true || edgeMatrix[v2][v1] == true) {
			cout << -1 << endl;
			return;
		}
		else {
			edgeMatrix[v1][v2] = true;
			edgeMatrix[v2][v1] = true;

			vertex1->adj.push_back(vertex2);
			vertex2->adj.push_back(vertex1);
		}
	}

	void eraseVertex(int data) {
		vertex* delVertex = findVertex(data);
		if (delVertex == nullptr)
			return;
		for(int i = 0; i<Range;i++)
			if (edgeMatrix[data][i]) {
				edgeMatrix[data][i] = false;
				edgeMatrix[i][data] = false;
			}
		delete delVertex;
	}

	void print() {
		for (int i = 0; i < vertices.size(); i++)
			cout << vertices[i]->data << " ";
		cout << endl;
	}
};

int main() {
	graph g;
	int N, M, A;
	cin >> N >> M >> A;
	while (N--) {
		int v;
		cin >> v;
		g.insertVertex(v);
	}
	while (M--) {
		int w, z;
		cin >> w >> z;
		g.insertEdge(w, z);
	}
	//g.print();
	g.BFS(A);
	return 0;
}