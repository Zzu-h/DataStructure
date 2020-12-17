#include<iostream>
#include<vector>
using namespace std;

class vertex {
public:
	int data;
	vector<vertex*> adj;
};
class edge {
public:
	int start;
	int destination;
};


#define Range 2000
class graph {
private:
	bool** edgeMatrix;
	vector<vertex*> vertices;
	int vertexN;
	int edgeN;
public:
	graph() {
		this->vertexN = 0;
		this->edgeN = 0;
		this->edgeMatrix = new bool* [Range];
		for (int i = 0; i < Range; i++) {
			this->edgeMatrix[i] = new bool[Range];
			for (int j = 0; j < Range; j++) {
				//각 공간을 NULL로 초기화
				edgeMatrix[i][j] = false;
			}
		}
	}
	vertex* findVertex(int data) {
		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i]->data == data)
				return vertices[i];
		}
		return nullptr;
	}
	void insertVertex(int data) {
		vertex* newVertex = new vertex;
		newVertex->data = data;
		this->vertices.push_back(newVertex);
		this->vertexN++;
	}
	void insertEdge(int start, int destination) {
		if (edgeMatrix[start][destination] && edgeMatrix[destination][start])
			cout << -1 << endl;
		else {
			vertex* startV = findVertex(start);
			vertex* destinationV = findVertex(destination);
			if (startV == nullptr || destinationV == nullptr)
				cout << -1 << endl;
			else {
				edgeMatrix[start][destination] = true;
				edgeMatrix[destination][start] = true;
				startV->adj.push_back(destinationV);
				destinationV->adj.push_back(startV);
				this->edgeN++;
			}
		}

	}
	void exEdge(int v1, int v2) {
		if (findVertex(v1) == nullptr || findVertex(v2) == nullptr)
			cout << -1 << endl;
		else
			cout << edgeMatrix[v1][v2] << endl;
	}
	void eraseVertex(int data) {}
	void eraseEdge(edge*) {}
	int getVertexSize() {
		return this->vertexN;
	}
	int getEdgeSize() {
		return this->edgeN;
	}
};

int main() {
	graph g;
	int N, M, K;
	cin >> N >> M >> K;
	while (N--) {
		int I;
		cin >> I;
		g.insertVertex(I);
	}
	while (M--) {
		int S, D;
		cin >> S >> D;
		g.insertEdge(S, D);
	}
	cout << g.getVertexSize() << " " << g.getEdgeSize() << endl;
	while (K--) {
		int S, D;
		cin >> S >> D;
		g.exEdge(S, D);
	}
	return 0;
}