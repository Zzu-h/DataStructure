# Arrays & Linked List
## Array
 A orderd sequence of elements of the `same type`
* array는 index로 각 element를 호출한다.
* 하지만 고정된 사이즈로 불편함
* 특정 순서에 따라 어떤 것을 저장하는데 용이하다.
### Array 기능
* insertion
    * 저장하고자 하는 index 앞에 삽입을 하고 그 뒤로 shifting 진행
    * Algorithm
        * index를 통해 위치를 탐색
        * 크기 순서를 고려하여 삽입
        * 기존 배열을 삽입할 i번째 후 부터 뒤로 `shifting`
        * i 번째 배열에 새 요소를 삽입
    * Cost: O(n)
* deletion
    * Algorithm
        * i 번째 요소를 삭제
        * 삭제된 요소 뒤를 왼쪽으로 `shifting`
    * Cost: O(n)
* search
    * index를 통해 원하는 요소를 탐색할 수 있다.    

### Dynamic Array
고정된 사이즈의 배열 한계를 늘리는 것 .   
일반적으로 배열 사이즈의 2^n으로 늘어난다.    
ex) **vector** in c++, **ArrayList** in java, **list** in python
***
## Linked List
Linked List는 각 요소가 노드로 구성된 데이터 구조    
Singly / Doubly Linked List

### **Singly Linked list**
Singly Linked List는 `일련의 노드`로 구성된 data structure이다.

* Node가 가지고 있는 데이터
    * element
    * 다음의 노드 주소
```c++
class Node{
    int data;
    Node * next;
}
```

* 가지고 있는 요소
    * head / tail Node
    * size
```c++
class LinkedList{
    Node *head;
    Node *tail;
    function...
}
```
* 기능
    * Inserting
        * 넣고자 하는 위치로 간다.
        * 그 위치 이전 노드의 next node에 새 노드 주소를 저장
        * 새 노드 next에 현 위치 node 주소를 저장
    * Deleting
        * 삭제하고자 하는 위치로 간다.
        * 그 위치 이전 노드의 next node에 현 위치 next 주소를 저장
        * 현 위치 노드를 삭제(De-allocating)
* Insert / Delete at **head**
    * Insert at head
        * Creat a new node
        * Input v new data in the node
        * set next to point to the current head
         * set head to point to the new node
         * Cost: O(1)
    * Delete at head
        * Save the current head
        * change head to point to the next of the current head
        * Deallocate the old head
        * Cost: O(1)
```c++
void addFront(int new_data){
    Node *v = new Node;
    v->data = new_data;
    v->next = head;
    head = v;
}

void removeFront(){
    Node *del = head;
    head = head->next;
    // or head = del->next;
    delete del;
}
```
* Insert / Delete at **tail**
```c++
void addtail(int new_data){
    Node *v = new Node;
    v->data = new_data;
    v->next = null;
    tail->next = v;
    tail = v;
}

void removetail(){
    Node *del = tail;
    //Find the (n-1)th element
    //this node called prev
    prev->next = null;
    tail = prev;
    delete del;
}
```
### **Doubly Linked list**
Doybly Linked List는 더 효율적인 수행을 제공하기 위해 구성    
Node 구성이 next 뿐만 아니라 이전 주소를 저장하는 노드가 추가된다.

* Node가 가지고 있는 데이터
    * element
    * 다음의 노드 주소
    * 이전의 노드 주소
```c++
class Node{
    int elem;
    Node *next;
    Node *prev;
}
```
* 가지고 있는 요소
    * size
    * header / trailer Node
        * 이때 header와 trailer 노드는 더미노드이다.
        * 데이터를 저장하지 않고 기준을 잡는 노드임을 알자
```c++
class DLinkedList{
    Node *header;
    node *trailer;
    function...
}
```
* `Initial state` of Dlinked List
    * header의 next는 trailer를 가리킨다.
    * trailer의 prev는 header를 가리킨다.
    * 생성자에서 지시
* 기능
    * Inserting
        * 넣고자 하는 위치로 이동
        * 새 노드를 생성
        * 새 노드의 prev에 현 위치 prev 주소를 저장
        * 새 노드의 next에 현 위치 주소를 저장
        * 현 위치의 이전 노드의 next 노드에 새 노드 주소를 저장
        * 현 위치의 prev 노드에 새 노드 주소를 저장
    * Deleting
        * 삭제하고자 하는 위치로 이동
        * 삭제할 노드의 next를 이전 노드의 next에 저장
        * 삭제할 노드의 prev를 다음 노드의 prev에 저장
        * 삭제할 노드를 삭제 (De-allocate)
```c++
void add(Node *p, int elem){
    /*Create a new node& insert elem into the node*/
    //Node p is position of inserting
    Node *v = new Node;
    v->elem = elem;
    p->prev->next= v;
    v->prev = p->prev;
    p->prev = a;
    a->next = p;
}

void remove(Node *p){
    //Node p is position of deleting
    Node *u = p->prev;
    Node *w = p->next;
    u->next = w;
    w->prev = u;
    delete p;
}
```
* Inserting / deleting at header / trailer
```c++
void addFront(element) {
    add(header -> next, element);
}
void addTail(element) {
    add(Trailer, element);
}
void removeFront() {
    remove(header -> next);
}
void removeTail() {
    remove(trailer -> prev);
}
```
***
