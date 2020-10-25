# Queue
추상 데이터 타입이다.    
삽입 삭제는 first-in first-out`(FIFO)`을 따른다.
* 기능
    * enqueue: 삽입
    * dequeue: 삭제
    * front: 가장 앞에 있는 요소를 보여준다.
    * size: 현재 저장된 요소의 크기
    * empty: 현재 저장된 요소가 있는지 유무
* Queue의 응용
    * Waiting list
        * System 작동은 먼저 호출 된 프로세서가 먼저 실행해야함
    * 공유된 자원의 접근
    * 다중 프로그래밍
    * `Level-oreder traversal`
***
## Queue Interface
```c++
template<typename E>
class Qeuue{
public:
    int size() const;
    bool empty() const;
    const E& front() const
        throw(QueueEmpty);
    void enqueue(const E& e);
    E& dequeue()
        throw(QueueEmpyt);
}
```
***
## Array-based Queue
일반 배열로 구현하게 되면 이전에 사용하고 내보낸 공간을 사용이 불가능하게 된다.    
또는 dequeue할 때마다 전체 데이터를 한 칸씩 앞으로 당겨야 한다. 매우 비효율적이다.
* circular 형태로 queue 구현
    * 사용한 공간에 의해 더이상 사용할 공간이 없을 때 새로 추가하는 요소는 이전 사용했던 공간을 재활용한다.
```c++
enqueue(obj){
    n++;
    q[r] = obj;
    //r++; //삽입 요소는 배열 마지막에 추가 되므로 r이 한칸 뒤로 움직인다.
    r = (r + 1) % Array_size;
    //r이 뒤로 움직이나, 배열이 꽉 찼을 경우 앞에를 채움
    //이때, r은 array size + r + 1 이므로 위 연산을 수행한다.
}
dequeue(){
    n--;
    f++;
    //f++; //삭제 하면 f는 뒤로 움직인다.
    f = (f + 1) % Array_size;\
    // enqueue의 r 수행과 같음
}
```
각 Time/Space complexity는    
`Time Cost: O(1)`    
`Space Cost: O(n)`    
***
## Linked List Queue
Stack과 같이 singly linked list로 구현이 가능하다.     
Stack과 다른 점은 tail에 삽입이 되고 head가 삭제가 된다.
```c++
enqueue(obj){
    n++;
    L->addTail(obj);
}
dequeue(){
    n--;
    L->removeFront();
}
```
각 Time/Space complexity는    
`Time Cost: O(1)`    
`Space Cost: O(n)` 
***
## Queue to Stack
Question 1) 2개의 **Queue**가 주어졌을 때, **Stack**을 구현해라    
1. push중점
    * 데이터 저장 방식은 queue형태이다
        * 들어온 순서에 따라 저장된다.
    * 삭제할 때 데이터를 sub queue에 저장 후 마지막 요소를 삭제
    * 다시 sub queue에서 main queue로 복사한다.(swap)
```c++
push(obj){
    Q1.enqueue(obj);
}
obj pop(){
    //전체 데이터가 n개 있을 때
    //Q1의 n-1개 데이터를 Q2에 저장하고
    //남은 하나를 리턴한다.
    while(Q.size() > 1)
        Q2.enqueue(Q1.dequeue());
    front = Q1.dequeue();
    swap(Q1, Q2);

    return front;
}
```
push의 `Time Cost: O(1)`   
pop의 `Time Cost: O(n)`

2. pop중점
    * 데이터 저장 방식은 Stack이다.
        * 역순으로 저장된다.
    * 삽입할 때 데이터를 sub queue에 저장하고 main queue에 있는 요소를 sub queue에 모두 저장한다.
    * 다시 sub queue에서 main queue로 복사한다.(swap)
```c++
push(obj){
	Q2.enqueue(obj);
	move all elements from Q1 to Q2
	swap(Q1, Q2);
}

obj pop(){
	return Q1.dequeue();
}
```
push의 `Time Cost: O(n)`   
pop의 `Time Cost: O(1)`    
<br>
## Stack to Queue
Question 2) 2개의 **Stack을 이용**해서, **Queue**를 구현해라.
* enqueue 중점
    * 위 Question 1번 push 중점을 참고
```c++
enqueue (obj){
	S1.push(obj);
}

dequeue(obj){
	if(S2 is empty)
	{
		while(S1 is not empty)
			S2.push(S1.pop());
	}
	return S2.pop();

}
```
push의 `Time Cost: O(1)`   
pop의 `Time Cost: O(n)`
