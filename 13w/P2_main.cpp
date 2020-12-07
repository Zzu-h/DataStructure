#include<string>
#include<iostream>
using namespace std;

#define MappingSize 501
class vertex {
public:
	vertex* prev;
	vertex* next;
	int degree;
	int data;
	vertex(int data) {
		this->degree = 0;
		this->data = data;
	}
	void increase_degree() {
		this->degree++;
	}
	void decrease_degree() {
		this->degree--;
	}
};

class edge {
public:
	edge* prev;
	edge* next;
	vertex* source;
	vertex* destination;
	string data;
	edge(vertex* a, vertex* b, string data) {
		this->source = a;
		this->destination = b;
		this->data = data;
	}
};

class DoublyVertexLinkedList {
public:
	vertex* head;
	vertex* tail;
	DoublyVertexLinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}
	void insert(vertex* insertVertex) {
		if (this->head == NULL) {
			head = insertVertex;
			tail = insertVertex;
		}
		else {
			tail->next = insertVertex;
			insertVertex->prev = tail;
			tail = insertVertex;
		}
	}
	void remove(vertex* delVertex) {
		if (delVertex == head || delVertex == tail) {
			if (delVertex == head && delVertex != tail) {
				vertex* temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
			}
			else if (delVertex == tail && delVertex != head) {
				vertex* temp = tail;
				tail = tail->next;
				tail->prev = NULL;
				delete temp;
			}
			else { head = tail = NULL; }
		}
		else {
			delVertex->prev->next = delVertex->next;
			delVertex->next->prev = delVertex->prev;
			delete delVertex;
		}
	}
};

class DoublyEdgeLinkedList {
public:
	edge* head;
	edge* tail;
	int size;
	DoublyEdgeLinkedList() {
		this->head = NULL;
		this->tail = NULL;
		this->size = 0;
	}
	void insert(edge* insertedge) {
		if (this->head == NULL) {
			head = insertedge;
			tail = insertedge;
		}
		else {
			tail->next = insertedge;
			insertedge->prev = tail;
			tail = insertedge;
		}
		this->size++;
	}
	void remove(edge* deledge) {
		if (deledge == head || deledge == tail) {
			if (deledge == head && deledge != tail) {
				edge* temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
			}
			else if (deledge == tail && deledge != head) {
				edge* temp = tail;
				tail = tail->next;
				tail->prev = NULL;
				delete temp;
			}
			else { head = tail = NULL; }
		}
		else {
			deledge->prev->next = deledge->next;
			deledge->next->prev = deledge->prev;
			delete deledge;
		}
		this->size--;
	}
	
};

class graph {
public:
	edge*** edgeMatrix;
	DoublyVertexLinkedList* VertexList;
	DoublyEdgeLinkedList* EdgeList;
	int vertexSize;
	int edgeSize;
	int mappingTable[MappingSize];

	graph() {
		this->VertexList = new DoublyVertexLinkedList();
		this->EdgeList = new DoublyEdgeLinkedList();
		this->vertexSize = 0;
		this->edgeSize = 0;
		for (int i = 0; i < MappingSize; i++)
			mappingTable[i] = -1;
		this->edgeMatrix = new edge * *[1];
		this->edgeMatrix[0] = new edge * [1];
		this->edgeMatrix[0][0] = NULL;
	}
	bool isfindVertex(int n) {
		bool flag = false;
		vertex* temp = VertexList->head;
		while (temp != NULL) {
			if (temp->data == n) {
				flag = true;
				break;
			}
			temp = temp->next;
		}
		return flag;
	}
	vertex* findVertex(int n) {
		vertex* temp = VertexList->head;
		while (temp != NULL) {
			if (temp->data == n)
				break;
			temp = temp->next;
		}
		return temp;
	}
	void insert_vetex(int n) {
		if (isfindVertex(n) == true)
			return;
		else {
			edge*** tempMatrix = new edge * *[vertexSize + 1];
			for (int i = 0; i < vertexSize + 1; i++) {
				tempMatrix[i] = new edge * [vertexSize + 1];
				for (int j = 0; j < vertexSize + 1; j++)
					tempMatrix[i][j] = NULL;
			}
			for (int i = 0; i < vertexSize; i++)
				for (int j = 0; j < vertexSize; j++)
					tempMatrix[i][j] = this->edgeMatrix[i][j];

			this->edgeMatrix = tempMatrix;

			vertex* newVertex = new vertex(n);
			VertexList->insert(newVertex);
			this->vertexSize++;
			mappingTable[vertexSize - 1] = n;
		}
	}
	void erase_vertex(int n) {
		if (vertexSize == 0 || isfindVertex(n) == false) {
			cout << -1 << endl;
			return;
		}
		else {
			edge*** tempMatrix = new edge * *[vertexSize - 1];
			for (int i = 0; i < vertexSize - 1; i++) {
				tempMatrix[i] = new edge * [vertexSize - 1];
				for (int j = 0; j < vertexSize - 1; j++)
					tempMatrix[i][j] = NULL;
			}
			int middleidx = 0;
			for (int i = 0; i < vertexSize; i++)
				if (mappingTable[i] == n)
					middleidx = i;
			for (int i = 0; i < vertexSize; i++)
				mappingTable[i] = mappingTable[i + 1];
			for (int i = 0; i < vertexSize; i++)
				if (this->edgeMatrix[middleidx][i] != NULL)
					EdgeList->remove(this->edgeMatrix[middleidx][i]);
			
			cout<< this->EdgeList->size << " ";
			edge* temp = EdgeList->head;
			while (temp != EdgeList->tail) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << temp->data << endl;
		}
	}

	void insert_edge(int indirectSource, int indirectDestination, string data) {
		if (isfindVertex(indirectSource) == false || isfindVertex(indirectDestination) == false) {
			cout << -1 << endl;
			return;
		}

		int destination = -1;
		int source = -1;
		for (int i = 0; i <= vertexSize; i++) {
			if (mappingTable[i] == indirectDestination)
				destination = i;
			if (mappingTable[i] == indirectSource)
				source = i;
			if (source != -1 && destination != -1)
				break;
		}

		if (edgeMatrix[source][destination] != NULL|| edgeMatrix[destination][source]!=NULL) {
			cout << -1 << endl;
			return;
		}

		edge* newEdge = new edge(findVertex(indirectSource), findVertex(indirectDestination), data);
		edgeMatrix[source][destination] = newEdge;
		edgeMatrix[destination][source] = newEdge;

		findVertex(indirectSource)->increase_degree();
		findVertex(indirectDestination)->increase_degree();

		EdgeList->insert(newEdge);
		this->edgeSize++;
	}

	void erase_edge(int indirectSource, int indirectDestination) {
		/*if (isfindVertex(indirectSource) == false || isfindVertex(indirectDestination) == false) {
			cout << -1 << endl;
			return;
		}*/

		int destination = -1;
		int source = -1;
		for (int i = 0; i <= vertexSize; i++) {
			if (mappingTable[i] == indirectDestination)
				destination = i;
			if (mappingTable[i] == indirectSource)
				source = i;
			if (source != -1 && destination != -1)
				break;
		}

		if (edgeMatrix[source][destination] == NULL || edgeMatrix[destination][source] == NULL) {
			/*cout << -1 << endl;*/
			return;
		}

		findVertex(indirectSource)->decrease_degree();
		findVertex(indirectDestination)->decrease_degree();
		
		edge* delEdge = edgeMatrix[source][destination];
		EdgeList->remove(delEdge);

		edgeMatrix[source][destination] = NULL;
		edgeMatrix[destination][source] = NULL;
	}
};

int main() {
	graph g;
	int n, m, k, i, s, d, l;
	string str;
	cin >> n >> m >> k;
	while (n--) {
		//vertex
		cin >> i;
		g.insert_vetex(i);
	}
	while (m--) {
		//edge
		cin >> s >> d >> str;
		g.insert_edge(s, d, str);
	}
	cout << g.vertexSize << " "<<g.edgeSize<<endl;
	while (k--) {
		//erase vertex
		cin >> l;
		g.erase_vertex(l);
	}

	return 0;
}