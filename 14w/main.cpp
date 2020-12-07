#include<iostream>
#include"graph.h"
using namespace std;

int main() {
	//1-2
	//graph g;
	//int n, m, k;

	//cin >> n >> m >> k;

	//string c = "";
	//while (n--) {
	//	int i;
	//	//string c;
	//	cin >> i >> c;
	//	g.insert_vertex(i, c);
	//}
	//while (m--) {
	//	int s, d;
	//	cin >> s >> d;
	//	g.insert_edge(s, d);
	//}
	//g.Q1_print(k);
	//cout << endl;

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