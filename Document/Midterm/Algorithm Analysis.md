# Analysis of Algorithms
이 분석은 Time Complexity와 Space Complexity로 한다.
***
## Running Time
* 대부분의 알고리즘은 input object를 output object로 변환시킨다.
* 일반적으로 **Running Time**은 input size와 비례한다.
* **Running Time**은 `worst case`를 중점으로 본다.
***
## Pseudocode
알고리즘의 상위 기술 표현    
* 글 보다 더 구조적인 형태
* 프로그램보다 덜 세밀화 됨
* 코드 레벨이 디테일 한 부분은 숨김
***
## RAM Model
일종의 time complexity. 다른 모델도 존재한다.    
 T(n): # of basic operations, given n input element    
 * Primitive(basic) operation
    * 종류
        * memory access
        * arithmectic operations (+,-,*,/,%)
        * assignment (=)
        * return, allocate, de-allocate
        * comparison(>,<,= etc..)
    * 알고리즘에 의해 수행되는 기본 연산
    * pseudocode에서 식별가능해야 함
    * RAM 모델에서 일정 시간을 고려한다.
* EXAMPLE
```c++
Algorithm arrayMax(A, n)
    currentMax<-A[0] //operatin 2
    for i<-1 to n-1 do //operation 할당 및 비교 2n
        if A[i]>currentMax then //operation access 및 비교 2(n-1)
            currentMax<-A[i] //operation access 및 비교 2(n-1)
    {increment counter i} //operation 할당 및 비교 2(n-1)
    return currentMax //operation return 1
```
여기서 계산하여 big-O notation을 사용하여 표현한다.    
위 Example을 통해 총 연산 수는 8n-3이다.    
big-O 관점에서 O(n)이다.
***
## Big-Oh Notation
Time: O(# basic operations)    
Space: O(# words)    
what does words mean?    
-> 메모리와 cpu의 소통가능한 데이터 크기    
시간 복잡도에 관해선 내용을 넘기도록 함    <br>

### 공간 복잡도
* 총 공간 요구 = 고정 공간 요구 + 가변 공간 요구( S(P) = c + S_P(n) )    
    * 고정 공간: 입력과 출력의 횟수나 크기와 관계 없는 공간
        * 코드 저장 공간, 단순 변수, 고정 크기의 구조 변수, 상수 etc
    * 가변 공간: 해결하려는 문제의 특정 인스턴스에 의존하는 크기를 가진 구조화 변수들을 위해서 필요로 하는 공간
        * 동적으로 필요한 공간(함수가 순환 호출을 할 경우 요구되는 추가 공간)
#### Example 1
```c++
int factorial(int n)
{
    if(n > 1) return n * factorial(n - 1);
    else return 1;
}
```
여기서 factorial 함수는 총 n번 호출될 예정이다.    
그렇다면 호출스택에선 총 n만큼의 공간이 할당 되어진다.
#### Example 2
```c++
int factorial(int n)
{
    int i = 0;
    int fac = 1;
    for(i = 1; i <= n; i++)
    {
        fac = fac * i;
    }
    return fac;
}
```
여기서의 factorial 함수는 단 한번만 호출되어진다.    
여기서 호출 스택에서는 1번의 공간이 할당되고 단지 변수만 따로 고정 공간에 저장되어진다.    
즉, Example 1은 S(P) = 1 + S_P(n) / Example 2은 S(P) = 3 + S_P(1) 이 된다.    
따라서, `Example 1은 O(n)`, `Example 2은 O(1)`이 된다. 
***
## 개념   
* Big-Oh    
    * f(n) is `O(g(n))` if f(n) is asymptotically **less than or equal** to g(n)    
    * O(f(n)) `<=` O(g(n))
* big-Omega    
    * f(n) is `Omega(g(n))` if f(n) is asymptotically **greater than or equal** to g(n)    
    * Omega(f(n)) `>=` Omega(g(n))
* big-Theta   
    * f(n) is `Theta(g(n))` if f(n) is asymptotically **equal** to g(n)
    * Theta(f(n)) `==` Theta(g(n))
