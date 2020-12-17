#include<iostream>
#include<vector>
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
		edgeList.push_back(newE);

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
		cout << v->str_data;
		for (int i = 0; i < v->adj.size(); i++)
			if (v->adj[i]->vistit == false)
				DFS(v->adj[i]);
	}
	void eraseVertex(int data) {
		vertex* delNode = findVertex(data);
		if (delNode == nullptr) {
			cout << -1 << endl;
			return;
		}

		for (int k = 0; k < Range; k++)
			if (edgeMatrix[data][k] != nullptr) {
				edge* delEdge = edgeMatrix[data][k];
				edgeMatrix[data][k] = nullptr;
				edgeMatrix[k][data] = nullptr;

				delEdgeVector(delEdge);
				delete delEdge;
			}

		delVertexVector(delNode);
		delete delNode;
		vertexN--;
		edgeN = edgeList.size();
		Q3print();
	}
	void delEdgeVector(edge* E) {
		for (int i = 0; i < edgeList.size(); i++)
			if (edgeList[i] == E) {
				edgeList.erase(edgeList.begin() + i);
				return;
			}
	}
	void delVertexVector(vertex* E) {
		for (int i = 0; i < edgeList.size(); i++)
			if (vertices[i] == E) {
				vertices.erase(vertices.begin() + i);
				return;
			}
	}

	void Q3print() {
		cout << edgeN;
		for (int i = 0; i < edgeN; i++)
			cout << " " << edgeList[i]->str_data;
		cout << endl;
	}

	int getVertexNum() {
		return this->vertexN;
	}
	int getEdgeNum() {
		return this->edgeN;
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
		cin >> S >> D >> data;
		g.insertEdge(S, D, data);
	}
	cout << g.getVertexNum() << " " << g.getEdgeNum() << endl;
	while (K--) {
		int L;
		cin >> L;
		g.eraseVertex(L);
	}
	return 0;
}