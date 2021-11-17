# Hash Tables
An array of `buckets`     
buckets: element 같은 것
    

hash table은 key값으로 유도된 hash value h와 테이블이라고 불리는 N사이즈의 배열로 구성되어 있다.

## Hash tables Algorthm in JAVA
```JAVA
public int hashCode(){
    int h = hash;
    if(h == 0 && count >0){
        int off = offset;
        char val[] = value;
        int len = count;
        for(int i = 0; i < len; i++)
            h = 31*h+val[off++];
        hash = h;
    }
}
```

## Hash Tabels의 메소드
- find(k): k에 해당하는 value를 반환한다.
    - Algorithm
        ```c++
        Algorithm find(k)
            i <- h(k)
            p <- 0
            repeat
            c <- A[i]
            if c = null
            r   eturn null
            else if c.key () = k
                return c.value()
            else
                i <- (i + 1) mod N
                p <- p + 1
            until p = N
            return null
        ```
- erase(k):key k를 찾아 삭제한다.
    - 삭제한 후 특별한 값 ***AVAILABLE***같은 값을 넣어준다.
    - Hash 값이 중복되어 다른 공간에 저장한 정보를 find 할 수 있게 하기 위함
- put(k, obj): k **hash function**으로 인한 값에 obj를 삽입한다.
## Hash Functions
*key값*을 배열에 삽입할 `정수로 변환`하는 함수    
기본적으로 두 번의 변환이 필요하다.
1. **Hash Code**: keys -> integers
    - Integer cast
        - 정수 같은 키의 비트 수를 정수로 사용
        - 예를 들어 아스키 코드 같이 문자에 해당하는 정수를 그대로 사용하는 것
    - Component sum
        - 문자에 해당하는 정수값들을 모두 합쳐서 사용함
        - overflow를 무시함
    - polynomial accumulation
        - 고정된 z에 대해, 거듭 제곱을 곱해서 더함
        - 예를 들면 "abcd"문자열이 있다고 하자
        - 'a'*z^0 + 'b'*z^1 + 'c'*z^2 + 'd'*z^3
        - 모두 계산하여 그 값을 사용
2. **Compression funciton**: integers -> [0, N-1]
    - Division: y mod N
        - hash table의 사이즈인 N은 일반적으로 소수로 잡는다.
        - N이 소수가 아니라면, 약수에 index가 몰리는 현상이 발생한다.
    - Multiply, Add and Divide: (ay+b) mod N
        - a, b는 N으로 나누어지지 않는 음이아닌 정수이다.

하지만, hash table은 종종 collision을 일으키기도 한다.

## Collision
Given two keys k1 & k2, S.T. k1 != k2, h(k1) = h(k2)
### 충돌 처리
1. Separate chaining: `open hashing`
    - 같은 hash 값을 가질 때 해당 hash bucket의 연결 리스트로 각각 연결해서 이어나감
2. Open Addressing: `closed hashing`
    - linear probing
        - index가 하나씩 증가한 위치에 probe
        - collision이 발생한 위치가 i라면, i <- i+1 위치에 삽입을 해 나간다.
    - Quadratic probing
        - n^2 으로 hash 값을 만들어 index 위치에 probe
        - (h(x) + n^2) mod N을 수행한다.
    - double hashing
        - hash function이 2개이다.
        - h(k)에서 collision이 발생하면, h'(k)를 구하고, `(h(k)+j*h'(k)) mod N`를 수행한다.
        - j는 충돌 횟수이다.
        - 충돌 없이 바로 삽입 될 경우 h(k)에 삽입되지만, 충돌 j회 발생했을 때, 위 식을 사용하여 삽입을 이어간다.

## Rehash
hash table에서 삽입 삭제가 계속 이루어 졌을 때, find 메소드나 삽입 삭제의 속도가 점점 느려져 간다.    
이유는 충돌처리로 인해 hash값을 찾아가는데 점점 더 기본값에서 멀어지기 때문에 찾는 시간이 오래걸리기 때문이다.    
<br>

#### Time to rehash
- When the table is getting full, the operations are getting slow
- For quadratic probing, insertions might fail when the table is more than half full

### Rehash operation
- 기존 hash table의 사이즈가 약 두 배 큰 또다른 hash table을 만든다.
- 그와 동시에 새로운 hash function을 같이 만든다.
- 기존 table을 스캔하고 각각의 요소들을 새로운 hash function으로 재삽입을 진행한다.


## Time Complexity
- Worst case인 경우 O(n) Time이 걸린다.
- 하지만, 기대되는 Expected running time은 O(1)이다.
    - 배열로 접근하기 때문에 하나씩 접근할 필요 없이 index로 direct하게 접근한다.

## 이상적인 해쉬 함수 A simple uniform hashing
`collisoion이 없는 함수`    
모든 데이터 값 x에 대해 (x ∈ [1, n]),    
모든 해쉬 값 j 에 대해 (j ∈ [0, N-1])    
Pr[h(x_i) = j] = 1/N 이다.
- X_ij
    - if h(x_i) = j then, 1
    - else, 0
- E[X_ij] = Pr[h(x_i) = j] * 1 = 1/N
- L_j = Sum of X_ij, i [1, n]
- E[L_j] = n / N
- O(1 + n/N), n/N is constant
- O(1) Time complexity in insertion, deletion, and search
### 실제론 Universal Hashing
