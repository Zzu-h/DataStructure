# Maps
Map은 key-value 항목의 검색가능한 컬렉션이다.    
Operations
- searching
- inserting
- deleting

`같은 key`를 가진 중복 항목은 **허용되지 않는다.**

# Dictionary
`같은 key`를 가진 중복 항목이 **허용된다.**

## Dictionary Problem
Given a collection of (key, value) paris, How to design a data structure on the collection that provides (insertion, deletion, serach) operations.

### 두 가지의 주요 solution
- a search tree
    - a binary search tree(BST)
        - red-black tree
        - AVL-tree
    - B-tree, (B+)-tree: DB에서 사용
- a hash table


## Maps & Dictionary 제공 메소드
- `pair`(Map&Dictionary)가 제공하는 메소드
    - key(): key값을 return 한다.
    - vlaue(): value값을 return 한다.
    - setKey(k): key값을 k로 설정한다. 
    - setValue(v): value값을 v로 설정한다.

- `Map & Dictionary`에서 제공하는 메소드
    - find(k): k의 키값을 가지고 이는 요소를 찾는다.
        - key가 있을 경우 포인터를 return.
    - put(k, v): key 값 k에 value v를 삽입한다.
    - erase(k): k의 key값을 가지고 있는 요소를 삭제한다.
    - size, empty, begin, end 등 기본 메소드 제공
- **Dictionary에서만** 제공하는 메소드
    - findAll(k): 키 값 k를 가지고 있는 모든 요소의 포인터를 return한다.

### find 메소드 알고리즘 (Map)
```c++
Algorithm find(k):
for each p in [S.begin(), S.end()) do
if p->key() = k then
return p
return S.end() //{there is no entry with key equal to k}
```

### put 메소드 알고리즘 (Map)
```c++
Algorithm put(k,v):
for each p in [S.begin(), S.end()) do
if p->key() = k then
p->setValue(v)
return p
p = S.insertBack((k,v)) //{there is no entry with key k}
n = n + 1 //{increment number of entries}
return p
```

### erase 메소드 알고리즘(Map)
```c++
Algorithm erase(k):
for each p in [S.begin(), S.end()) do
if p.key() = k then
S.erase(p)
n = n – 1 
```

전체적으로 find, put, erase의 time complexity는 O(n) Time이 걸린다.