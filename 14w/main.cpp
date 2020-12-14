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

vertex* graph::findvertex(int data) {
	vertex* v = NULL;
	for (int i = 0; i < vertex_list.size(); i++) {
		if (vertex_list[i]->data == data) {
			v = vertex_list[i];
			break;
		}
	}
	return v;
}
edge* graph::findedge(int src, int dst) {
	int _src = NULL, _dst = NULL;
	for (int i = 0; i < vertex_list.size(); i++) {
		if (vertex_list[i]->data == src) {
			_src = i;
		}
		if (vertex_list[i]->data == dst) {
			_dst = i;
		}
	}
	if (edgeMatrix[_src][_dst] == NULL) {
		//두 vertex간에 edge가 없을 경우
		return NULL;
	}
	else {
		return edgeMatrix[_src][_dst];
	}
}

void graph::insert_vertex(int n, string str) {
	if (findvertex(n) != NULL) {
		//중복되는 값을 저장하지 않음
		return;
	}
	else {
		//int size = vertex_list.size();
		vertex* newVertex = new vertex(n, str);
		vertex_list.push_back(newVertex);
	}
}

void graph::insert_edge(int source, int destination) {
	vertex* src = findvertex(source);
	vertex* dst = findvertex(destination);
	int _src = NULL, _dst = NULL;
	for (int i = 0; i < vertex_list.size(); i++) {
		if (vertex_list[i]->data == source) {
			_src = i;
		}
		if (vertex_list[i]->data == destination) {
			_dst = i;
		}
	}

	// vertex 둘 중 하나라도 없을 경우는 어떻게 되냐?

	if (findedge(source, destination) == NULL) {
		// 이미 저장된 edge가 없을 경우
		edge* new_e = new edge(src, dst);
		new_e->data = edge_list.size();
		edge_list.push_back(new_e);
		edgeMatrix[_src][_dst] = new_e;
		edgeMatrix[_dst][_src] = new_e;

		//자신의 이웃을 저장한다.
		src->adj_list.push_back(dst);
		dst->adj_list.push_back(src);
	}
	else {
		//이미 edge가 존재할 경우 새로 저장하지 않고 끝낸다.
		cout << -1 << endl;
		return;
	}
	// edge저장에 성공했다.
	// 현재 연결된 edge의 갯수 degree를 증가한다.
	src->degree++;
	dst->degree++;
}

void graph::sortVertex(vector<vertex*>& T) {
	for (int i = 0; i < T.size(); i++) {
		for (int k = i + 1; k < T.size(); k++) {
			if (T[i]->data > T[k]->data) {
				vertex* temp = T[i];
				T[i] = T[k];
				T[k] = temp;
			}
		}
	}
}

void graph::Q1_DFS(vertex* curV) {
	cout << curV->str_data;
	curV->visited = true;
	int size = curV->adj_list.size();
	for (int i = 0; i < size; i++) {
		if (!curV->adj_list[i]->visited)
			Q1_DFS(curV->adj_list[i]);
	}
}
void graph::Q2_DFS(vertex* curV) {
	curV->visited = true;
	cout << curV->data << " ";
	int size = curV->adj_list.size();
	for (int i = 0; i < size; i++) {
		vertex* temp = curV->adj_list[i];
		edge* temp_edge = findedge(curV->data, temp->data);
		if (!temp->visited) {
			temp_edge->edge_stat = DISCOVERY;
			Q2_DFS(temp);
		}
		else {
			if (temp_edge->edge_stat == DISCOVERY);
			else
				temp_edge->edge_stat = BACK;
		}
	}
}

void graph::Q1_print(int n) {
	for (int i = 0; i < vertex_list.size(); i++) {
		sortVertex(vertex_list[i]->adj_list);
	}
	Q1_DFS(findvertex(n));
}
void graph::Q2_print(int n) {
	Q2_DFS(findvertex(n));
}

void graph::BFS(vertex* curV) {
	curV->visited = true;
	BFS_Q.push(curV);
	Q.push(curV);
	while (!BFS_Q.empty()) {
		vertex* v = BFS_Q.front();
		BFS_Q.pop();
		for (int i = 0; i < v->adj_list.size(); i++) {
			vertex* temp = v->adj_list[i];
			edge* temp_edge = findedge(v->data, temp->data);
			if (!temp->visited) {
				temp_edge->edge_stat = DISCOVERY;
				temp->visited = true;
				Q.push(temp);
				BFS_Q.push(temp);
			}
			else {
				if (temp_edge->edge_stat == DISCOVERY);
				else
					temp_edge->edge_stat = BACK;
			}
		}
	}
}
void graph::BFS_print(int n) {

	BFS(findvertex(n));
	while (!Q.empty()) {
		cout << Q.front()->data << " ";
		Q.pop();
	}

	cout << "\n";

}

int main() {
	//1-2
	/*graph g;
	int n, m, k;

	cin >> n >> m >> k;

	string c = "";
	while (n--) {
		int i;
		string c;
		cin >> i >> c;
		g.insert_vertex(i, c);
	}
	while (m--) {
		int s, d;
		cin >> s >> d;
		g.insert_edge(s, d);
	}
	g.Q1_print(k);
	cout << endl;*/

	//2
	graph g;
	int n, m, k;

	cin >> n >> m >> k;

	string c = "";
	while (n--) {
		int i;
		//string c;
		cin >> i;
		g.insert_vertex(i, c);
	}
	while (m--) {
		int s, d;
		cin >> s >> d;
		g.insert_edge(s, d);
	}
	g.BFS_print(k);
	cout << endl;
	return 0;
}
