#include "graph.h"

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
		//�� vertex���� edge�� ���� ���
		return NULL;
	}
	else {
		return edgeMatrix[_src][_dst];
	}
}

void graph::insert_vertex(int n, string str) {
	if (findvertex(n) != NULL) {
		//�ߺ��Ǵ� ���� �������� ����
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

	// vertex �� �� �ϳ��� ���� ���� ��� �ǳ�?

	if (findedge(source, destination) == NULL) {
		// �̹� ����� edge�� ���� ���
		edge* new_e = new edge(src, dst);
		new_e->data = edge_list.size();
		edge_list.push_back(new_e);
		edgeMatrix[_src][_dst] = new_e;
		edgeMatrix[_dst][_src] = new_e;

		//�ڽ��� �̿��� �����Ѵ�.
		src->adj_list.push_back(dst);
		dst->adj_list.push_back(src);
	}
	else {
		//�̹� edge�� ������ ��� ���� �������� �ʰ� ������.
		cout << -1 << endl;
		return;
	}
	// edge���忡 �����ߴ�.
	// ���� ����� edge�� ���� degree�� �����Ѵ�.
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
	for (int i = 0; i < edge_list.size(); i++) {
		if (edge_list[i]->edge_stat == DISCOVERY)
			cout << edge_list[i]->data;
	}
	cout << "\n";
	for (int i = 0; i < edge_list.size(); i++) {
		if (edge_list[i]->edge_stat == BACK)
			cout << edge_list[i]->data;
	}
}

void graph::BFS(vertex* curV) {
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