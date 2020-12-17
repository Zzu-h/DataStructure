#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class vertex {
public:
	int data;
	string str_data;
	vector<vertex*> adj;
	bool vistit = false;
};
class edge {
public:
	vertex* start;
	vertex* destination;
	string str_data;
};


#define Range 2000
class graph {
private:
	edge*** edgeMatrix;
	vector<vertex*> vertices;
	vector<edge*> edgeList;
	int vertexN;
	int edgeN;
	queue<vertex*> Q;
public:
	graph() {
		this->vertexN = 0;
		this->edgeN = 0;
		this->edgeMatrix = new edge * *[Range];
		for (int i = 0; i < Range; i++) {
			this->edgeMatrix[i] = new edge * [Range];
			for (int j = 0; j < Range; j++) {
				//각 공간을 NULL로 초기화
				edgeMatrix[i][j] = nullptr;
			}
		}
	}
	void insertVertex(int idx, string data) {
		vertex* newV = new vertex();
		newV->data = idx;
		newV->str_data = data;

		vertices.push_back(newV);
		vertexN++;
	}
	void insertEdge(int vertex1, int vertex2, string data) {
		vertex* v1 = findVertex(vertex1);
		vertex* v2 = findVertex(vertex2);

		if ((v1 == nullptr) || (v2 == nullptr)) {
			cout << -1 << endl;
			return;
		}
		else if (edgeMatrix[vertex1][vertex2] != nullptr || edgeMatrix[vertex2][vertex1] != nullptr) {
			cout << -1 << endl;
			return;
		}
		edge* newE = new edge();
		newE->start = v1;
		newE->destination = v2;
		newE->str_data = data;

		edgeMatrix[vertex1][vertex2] = newE;
		edgeMatrix[vertex2][vertex1] = newE;

		v1->adj.push_back(v2);
		v2->adj.push_back(v1);

		edgeN++;
	}

	vertex* findVertex(int v) {
		for (int i = 0; i < vertexN; i++)
			if (vertices[i]->data == v)
				return vertices[i];
		return nullptr;
	}

	void DFS(vertex* v) {
		v->vistit = true;
		cout << v->data << " ";
		for (int i = 0; i < v->adj.size(); i++)
			if (v->adj[i]->vistit == false)
				DFS(v->adj[i]);
	}

	void BFS(vertex* v) {
		Q.push(v);
		v->vistit = true;
		while (!Q.empty()){
			vertex* w = Q.front();
			Q.pop();
			cout << w->data << " ";
			for (int i = 0; i < w->adj.size(); i++) {
				if (w->adj[i]->vistit == false) {
					Q.push(w->adj[i]);
					w->adj[i]->vistit = true;
				}
			}
		}
	}
};

int main() {
	graph g;
	int N, M, K;
	cin >> N >> M >> K;
	while (N--) {
		int I;
		string data = "";
		cin >> I;
		g.insertVertex(I, data);
	}
	while (M--) {
		int S, D;
		string data = "";
		cin >> S >> D;
		g.insertEdge(S, D, data);
	}
	g.BFS(g.findVertex(K));
	cout << endl;
	return 0;
}