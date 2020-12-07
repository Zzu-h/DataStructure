# Binary Search Tree
a binary tree, T, satisfying the following property:    
let u,v, and w be three nodes in T S.T. u ∈ v's left subtree and w ∈ v's right subtree then, key(u) ≤ key(v) ≤ key(w)    
<br>
이진 탐색 트리는 다음을 만족하는 tree이다.    
T에서 3개의 노드 u,v,w가 있다고 하자.    
s는 v의 왼쪽 트리의 속하는 노드이고, w는 v의 오른쪽 트리의 속하는 노드라면, **key(u) ≤ key(v) ≤ key(w)** 를 만족한다.

* binary search tree는 hash table과 다르게 찾는 key값이 없다면, **근삿값**을 제공한다.

## 제공 메소드
- lookup(k): (search)
    - Algorithm
        ```c++
        lookup(k){
            v<-root(T)
            while(v is not null){
                if v.key() == k
                    then return v;
                else if v.key() > k
                    then v <- v.left();
                else if v.key() < k
                    then v <- v.right();    
            }
            if v is null
                then return v.parent();
            else
                return v;
        }
        ```
    - Time Complexity: O(h)
        - root Node부터 leaf Node까지 h만큼 내려간다. 따라서 O(h) time이 걸린다.
    - linear recursion인가?
        - 각 case는 다른 case와 무관하게 재귀함수가 있으므로 한번의 재귀함수마다 한번의 재귀호출이 있으므로 Linear Recursion 입니다.
- insertion(k, v): (insert)
    - Algorithm
        ```c++
        insertion(k, v){
            u <- lookup(k)
            if u.key() > k
                then create the left child
            else if u.key() < k
                then create the right child
        }
        ```
    - Time Complexity: O(h)
        - lookup 메소드 때문에 O(h) time이 걸린다.
- deletion(k): (delete)
    - Algorithm
        ```c++
        u <- lookup(k);
        if u is null
            then return;
        else{
            if u is a leaf node
                then remove u from T;
            else if u is a non-leaf node{
                if u has only a single child w
                then move w to u's position.
                else if u has two children{
                    1. Find v that follows in an in-order traversal
                    2. delete u, move v to u's node position
                    3. move w to v's position
                }
            }
        }
        ```
        - `leaf node`일 경우 그냥 삭제만 하면 된다.
        - 자식이 `하나` 있을 경우
            - 단순히 자식을 자신의 자리에 올려준다.
        - 자식이 `둘` 있을 경우
            - in-order 순서에 맞게 자신의 노드와 가장 인접한 노드를 찾는다. 그 노드를 u라 하자.
            - u를 삭제할 노드의 위치시키고, 노드를 삭제한다.
            - in-order 순서에 지장 없이 삭제가 되었다.
    - Time Complexity: O(h)
        - 처음 lookup함수에서 O(h)가 들었고, 자식이 둘 있을 case에서 인접한 노드를 찾는 case에서 O(h)가 들었다. 총 Complexity는 O(h)이다.
