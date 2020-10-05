# Chapter 10 예외 처리
## 핵심 개념
1. 예외 처리 기본: try, throw, catch문을 중심으로 예외 처리를 구성하는 방법
2. 스택 풀기: 스택 메모리에 불필요한 데이터가 쌓이지 않게 하려는 예외 처리 구조
3. 메모리 예외 처리: 객체가 생성 혹은 소멸하는 과정에서 발생하는 예외
## 학습 목표
1.	예외 처리의 중요성과 기본 구조를 정확하게 이해
2.	함수 실행에서 발생하는 상황에 대처하는 스택 풀기 이해
3.	객체 생성과 소멸에서 발생하는 상황에 대처하는 메모리 예외 처리 방법
--------------
<br><br>

## 1. try, throw, catch문
-  구조화된 예외 처리: 함수 호출로 변경된 것들을 한 번에 되돌릴 수 있는 방법
    - 스택을 본래 형태로 돌리는 것<br>
1. 기본 활용 방법
```
try
{
    .... //작업
    if(error 발생)
        throw errocode;
    if(error 발생)
        throw errocode;
}
catch(int nExp)
{
    ...
}
```
- goto문: statement label를 명시해준 곳으로 점프한다. 

```
tryAgain: 
    // this is a statement label
    std::cout << "Enter a non-negative number"; 
    std::cin >> x;
    if (x < 0.0)
        goto tryAgain;
    // this is the goto statement
```
- 
    * c++ 에서는 적절하지 않은 명령이다.
    + 
    - test
        - tstet
            - tasdt
