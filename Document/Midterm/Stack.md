# Stack
### ADT?    
데이터 구조를 추상화 하는 것    
실제 존재하는 데이터 구조가 아니지만 데이터가 어떻게 존재하고 사용하는지를 구조화 하여 사용하는 데이터 타입    
* 세부내용은 숨기고 사용하는 방법을 제공
****
## The Stack ADT
* 삭제 삽입은 last in first out(LIFO)를 따른다.
* Stack 기능
    * push: 삽입
    * pop: 삭제
    * top / peek: 가장 마지막에 삽입된 요소를 제거 없이 확인하는 기능
    * size: 저장된 요소의 수를 제공
    * empty: 비어있는지 check
* Stack 응용
    * `System Stack`
        * 이를 이용하여 재귀함수를 사용가능하게 한다.
    * `산술 연산의 괄호`
    * ctrl + z
    * 웹브라우저 뒤로가기
    * etc..
* Stack Interface
```c++
template<typename E>
class Stack{
public:
    int size() const;
    bool empty() const;
    const E& const
        throw(StackEmpty);
    void push(const E& e);
    E& pop() throw(StackEmpty);
}
```
`시험 포인트`    
> Stack to Queue or Queue to Stack    
> Queue에서 확인
### Array-based Stack
각 연산은 `Time Cost: O(1)`이다.    
`Space Cost: O(Maximum size)`
```c++
class Stack<E>{
private:
    E S[MAX];
    int t = -1;
public:
    void push(E);
    E pop();
    E peek();
}
void push(E element){
    if(size()>=MAX)
        throw StackFull;
    t = t + 1;
    S[t] = element;
}
E pop(){
    if(empty())
        throw StackFull;
    t = t - 1;
    return S[t + 1];
}
E peek(){
    return S[t];
}
bool empty(){
    return (t == -1);
}
```
배열 기반의 Stack의 단점
* 고정된 배열 사이즈를 선언해야 하므로 메모리 낭비가 될 수 있다.    
이를 보완하여 LinkedLIst로 구현
### Linked List Stack
단순히 단일 링크드 리스트로 구현할 수 있다.    
요소 삽입/삭제를 **head**에 수행한다.
```c++
class Stack{
    LinkedList *L = new LnkedList<E>;
public:
    E peek(){
        return L->head->elem;
    }
    E pop(){
        E top = L->head->elem;
        L->removeFront();
        return top;
    }
    void push(E new_elem){
        L->addFront(new_elem);
    }
}
```
각 연산의 `Time Cost: O(1)`    
`Space Cost: O(n)`이다.    
* 이론적으로 array 기반 스택보다 좋지만 memory random access에 기반하여 Linked List가 구현되므로 연속적으로 접근 가능한 Array 배열보다 비효율적이다.
## 괄호 매치 알고리즘(Parentheses Matching Algorithm)
```c++
Algorithm ParenMatch(X,n):
Input: n개의 배열(연산식)
Output: bool형식(괄호 매치 됨 ? true : false)
Let S be an empty stack
for i = 0 to n-1
    if X[i]가 열린 괄호라면
        S.push(X[i])
    else if X[i]가 닫힌 괄호라면
        if S.empty()
            return false
        if S.pop() X[i]의 닫힌 괄호와 매치가 안될 경우
            return false
if S.empty()
    return true
else
    return false
```
`Time Cost: O(n)  `  
push와 pop이 n번을 돈다.    
이 외 비교 연산 또한 n번이다.    
`Space Cost: O(n)`    
n개의 배열을 삽입하므로 기본적으로 n개의 공간을 차지함
* auxilary space: 알고리즘이 사용하는데 필요한 임시 공간
* in-place: space complexity가 상수
