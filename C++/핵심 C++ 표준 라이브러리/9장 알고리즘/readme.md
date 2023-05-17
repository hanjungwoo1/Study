# 9장 알고리즘

컨테이너는 STL 알고리즘을 적용 가능

## 9.1 사용법

- &lt;algorithm&gt; : 범용 알고리즘이 정의돼 있다.
- &lt;numeric&gt; : 수치 알고리즘이 정의돼 있다.
- _if : 프레디케이트를 매겨변수로 지정할 수 있는 알고리즘
- _copy : 원소를 다른 범위로 복제할 수 있는 알고리즘

STL 알고리즘을 위한 명명 규칙

|이름|설명|
|---|---|
|InIt|입력 반복자(Input Iterator)|
|FwdIt|정방향 반복자(Forward Iterator)|
|BiIt|양방향 반복자(Bidirectinal Iterator)|
|UnFunc|단항 콜러블(Unary Callable)|
|BiFunc|이항 콜러블(Binary Callable)|
|UnPre|단항 프레디케이트(Unary Predicate)|
|BiPre|이항 프레디케이트(Binary Predicate)|
|Search|탐색 알고리즘을 캡슐화하는 탐색기(searcher)|
|ValType|입력 범위로부터 값 타입을 자동으로 추론|
|ExePol|실행 정책(Execution Policy)|

## 9.2 반복자

반복자(Iterator)는 알고리즘의 실행 대상이 되는 컨테이너의 범위를 정의

- begin() : 반복자로 시작 시점
- end() : 반복자로 끝 지점
- std::rotate : 정방향 반복자 필요
- std::reverse : 양방향 반복자 필요

## 9.3 순차, 병렬 실행 또는 벡터화를 적용한 병렬 실행

C++17부터 도입된 실행 정책을 이용하면 STL 알고리즘을 순차적으로 실행할지, 병렬로 실행할지 아니면 벡터화를 이용하여 병렬로 실행할지를 지정할 수 있음

### 9.3.1 실행 정책

정책 태그를 이용하면 STL 알고리즘을 순차적으로 실행할지, 병렬, 벡터화로 실행할지 지정 가능

- std::execution::seq: 알고리즘을 순차적으로 실행
- std::execution::par: 알고리즘을 여러 스레드를 이용해 병렬로 실행
- std::execution::par_unseq: 알고리즘을 여러 스레드로 이용해 병렬로 실행, 개별 루프가 교차 실행(SIMD, Single Instruction Multiple Data) 이용한 벡터화 가능

```C++
std::vector<int> v = {1,2,3,4,5,6,7,8,9};

// 표준 순차 정렬
std::sort(v.begin(), v.end());

// 순차 실행
std::sort(std::execution::seq, v.begin(), v.end())

// 병렬 실행
std::sort(std::execution::par, v.begin(), v.end())

// 병렬 및 벡터화 실행
std::sort(std::execution::par_unseq, v.begin(), v.end())
```
- 156p, 어셈블러 인스트럭션

### 9.3.2 병렬 실행을 지원하는 알고리즘

- 158p

## 9.4 for_each

std::for_each는 지정한 범위 안에 있는 원소마다 단항 콜러블을 적용

```C++
UnFunc std::for_each(InpIt first, InpIt second, UnFunc func)
void std::for_each(ExePol pol, PwdIt first, FwdIt second, UnFUnc func)
```

```C++
InpIt std::for_each_n(InpIt first, Size n, UnFunc func)
FwdIt std::for_each_n(ExePol pol, PwdIt first, Size n, UnFUnc func)
```

## 9.5 원소를 수정하지 않는 알고리즘

원소를 탐색하거나 원소의 개수를 세는 알고리즘

- 범위의 속성을 검사하거나 범위를 비교하거나 여러 범위 중에서 특정한 범위를 탐색하는데 사용

### 9.5.1 원소 탐색

- find.cpp



## 9.6 원소를 수정하는 알고리즘


## 9.7 분할


## 9.8 정렬


## 9.9 이진 탐색


## 9.10 합병 연산


## 9.11 힙


## 9.12 최대 최소


## 9.13 순열


## 9.14 수치 알고리즘


## 9.15 C++17부터 추가된 알고리즘


## 9.16 C++20부터 추가된 알고리즘