#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

#define NOT_EXPLORED 0
#define DISCOVERY 1
#define BACK 2
class vertex {
public:
	int data;
	int degree;
	bool visited;
	string str_data;
	vector <vertex*> adj_list;
	vertex(int data, string str_data) {
		this->str_data = str_data;
		this->data = data;
		this->degree = 0;
		this->visited = false;
	}
};

class edge {
public:
	vertex* src;
	vertex* dst;
	int data;
	int edge_stat;
	edge(vertex* src, vertex* dst) {
		this->src = src;
		this->dst = dst;
		this->edge_stat = NOT_EXPLORED;
	}
};

#define vertexRange 1000
class graph {
public:
	edge*** edgeMatrix;
	vector<vertex*> vertex_list;
	vector<edge*> edge_list;

	queue<vertex*> BFS_Q;
	queue<vertex*> Q;
	graph() {
		//전체 행을 생성함
		edgeMatrix = new edge * *[vertexRange];
		for (int i = 0; i < vertexRange; i++) {
			//각 행마다 열을 생성해줌
			edgeMatrix[i] = new edge * [vertexRange];
			for (int j = 0; j < vertexRange; j++) {
				//각 공간을 NULL로 초기화
				edgeMatrix[i][j] = NULL;
			}
		}
	}

	vertex* findvertex(int data);
	edge* findedge(int src, int dst);

	void insert_vertex(int n, string str);
	void insert_edge(int source, int destination);


	void Q1_DFS(vertex* curV);
	void Q1_print(int n);
	void Q2_DFS(vertex* curV);
	void Q2_print(int n);


	void sortVertex(vector<vertex*>& T);

	void BFS(vertex* curV);
	void BFS_print(int n);

};