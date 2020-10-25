# Recursion
자기 자신을 호출하는 함수    
Recursion 함수는 base case와 recursive 호출이 있어야 완성이 된다.
### factorial 함수를 통해 비교해보자
* Iterative Factorial
    * Time Cost: O(n)
    * Space Cost: O(1)
    * 가독성이 떨어진다.
```c++
int IterativeFact(int n){
    int m = n;
    int fact = 1;
    while(m>0){
        fact *= m;
        m--;
    }
    return fact;
}
```
* Recursive Factorial
    * 함수 자체만 보았을 때
        * Time Cost: O(1)
        * Space Cost: O(1)
    * 실질적으로
        * Time Cost: O(n)
        * Space Cost: O(n)
```c++
int RecursiveFact(int n){
    if(n == 0) //basis case
        return 1; 
    else //recursive case
        return n * RecursiveFact(n-1);
}
```
***
## Recursion종류
1. Linear Recursion
    * 한 함수에 한 번의 recursive 호출이 있어야 한다.
    * Example: Reversing an Array
```c++
Algorithm ReverseArray(A, i, j):
    Input: An array A and nonnegative integer indices i and j
    Output: The reversal of the elements in A starting at index i and ending at j
    if(i < j){ //recursive case
        Swap(A[i], A[j])
        ReverseArray(A, i+1, j-1)
    }
    else if(i >= j)//base case
        return
    return
```

2. Tail Recursion
    * Linear Recursion의 한 종류
    * 재귀 함수에서 다른 명령을 실행하고 마지막 단계에서 재귀함수 호출이 이루어져야 함
    * 위 factorial 함수가 대표적 예
3. Binary Recursion
    * 재귀 함수가 호출이 두 번 발생하는 함수
    * BinarySum 알고리즘과 LinearSum 알고리즘 비교
    ```c++
    Algorithm LinearSum(A, n):
        Input: A integer array A and an integer n = 1, such that A has at least n elements
        Output: The sum of the first n integers in A
        if n = 1 then
            return A[0]
        else
            return LinearSum(A, n - 1) + A[n - 1]
    ```
    > `Time Cost: O(n)`   
    > `Space Cost: O(n)`
    ```c++
    Algorithm BinarySum(A, i, n):
        Input: An array A and integers i and n
        Output: The sum of the n integers in A starting at index i
        if n = 1 then
        return A[i]
        return BinarySum(A, i, n/2) +  BinarySum(A, i + n/2, n/2)
    ```
    > `Time Cost: O(n)`   
    > `Space Cost: O(logn)`
***
## Fibonacci 알고리즘
피보나치 알고리즘을 수학적 definition을 통해 그대로 적용하면 Binary Recursion 함수가 된다.    
다음을 통해 확인하자.
* Binary Fibonacci
```c++
Algorithm BinaryFib(k):
    Input: Nonnegative integer k
    Output: The k_th Fibonacci number F_k
    if k ≤ 1 then
        return k
    else
        return BinaryFib(k - 1) + BinaryFib(k - 2)
```
```
T(n) = T(n-1) + T(n-2) + C
    >= T(n-2) + T(n-2) = 2T(n-2)
    >= 2*2T(n-4)
    >= 2*2*2T(n-6)
    ...
    >= (2^i)*T(n-2i)
    >= (2^k)*T(0)
    
=> T(n) >= (2^k)
Time: O(2^k)
```
> `Time Cost: O(2^n)`   
> `Space Cost: O(n)`

Time complexity가 2^n으로 나온다.    
상당히 비효율적이다.    
Linear Fibonacci를 통해 위 Time Complexity를 더 낮춰보자.
* Linear Fibonacci
```c++
Algorithm LinearFibonacci(k):
    Input: A nonnegative integer k
    Output: Pair of Fibonacci numbers (F_k , F_k-1)
    if k = 1 then
        return (k, 0)
    else
        (i, j) = LinearFibonacci(k-1)
    return (i + j, i)
```
> `Time Cost: O(n)`   
> `Space Cost: O(n)`

선형 피보나치는 연속된 ***두 요소를 pair***로 하여 return 한다.    
리턴 받은 함수에서 두 요소를 더하는 명령을 실행하기 위함이다.
