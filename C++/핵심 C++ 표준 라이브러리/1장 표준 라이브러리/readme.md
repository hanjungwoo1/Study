# 1장 표준 라이브러리

## 1.1 역사

- C11 : TR1의 표준화와 함께 멀티스레딩 라이브러리
- C14 : 스마트 포인터, 튜플, 타입 트레이트, 멀티스레딩에 대한 기존 라이브러리 몇 가지 개선
- c17 : std::any, std::optional 데이터 타입 추가
- c20 : 네트워크 프로그래밍 라이브러리, 템플릿 매개변수에 대한 타입 시스템 추가, 멀테스레딩 지원 향상

## 1.2 개요
### 1.2.1 유틸리티

- 여러 문맥에 활용할 수 있는 **범용 기능**
    - 최대, 최소, 값을 교체
- std:function, std::bind : 기존 함수를 토대로 새로운 함수
- std::pair, std::tuple 임의의 길이로 된 이형 페어나 튜플을 생성
- std::ref, std::cref : 래퍼런스 래퍼
- 스마트 포인터
    - std::unique_ptr : 단독 소유권
    - std::shared_ptr : 공유 소유권, 래퍼런스 수를 세는 방식(래퍼런스 카운팅)으로 관리
    - std::weak_ptr : 순환 의존성을 깨는 데 도움
- 타입 트레이트(type trait) : 컴파일 시간에 대한 정보를 검사, 비교, 조작
- 시간(time) : 멀티스레딩 기능에 중요한 역할, 성능 측정에 유용

### 1.2.2 표준 템플릿 라이브러리

1. 컨테이터
2. 알고리즘 : 컨테이너에 대해 실행되는
3. 반복자 : 컨테이너와 알고리즘을 연결하는

- 순차 컨테이너 
    - std::vector : 가장 성능이 좋음
    - std::array : 순차 컨테이너 중 유일하게 크기를 실행 시간이 조절 불가능
    - std::deque : 덱
    - std::list : 이중 연결 리스트
    - std::forward_list : 단일 연결 리스트
- 연관 컨테이너 : 키-값
    - 정렬 연관 컨테이너 : 키를 기준으로 정렬
        - std::set : 키에 연관된 값 없음
        - std::map : 키 고유값
        - std::multiset : 키 중복 가능
        - std::multimap
    - 비정렬 연관 컨테이너
        - std::unordered_set
        - std::unordered_map
        - std::unordered_multiset
        - std::unordered_multimap
- 컨테이너 어댑터
    - std::stack
    - std::deque
    - std::priority_queue
- 반복자 : 컨테이너 알고리즘을 연결
    - 컨테이너에 대한 반복문을 임의의 위치를 기준으로 정방향 또는 역방향으로 진행하는 데 사용
- 알고리즘 : 정렬, 순열, 분할, 콜러블, 오브젝트, 람다 등

### 1.2.3 수치 연산
- 무작위수 생성기(난수 생성기) : 최대, 최소 사이에 일련의 무작위수를 생성
- 생성된 무작위수 분포
- 로그 함수, 지수 함수, 삼각 함수 등

### 1.2.4 텍스트 처리
- std::string : STL알고리즘도 사용 가능
- std::string_vew : 복사 연산ㄱ이 가볍다, 비소유 레퍼런스
- 정규표현식

### 1.2.5 입력과 출력
- I/O 스트림 라이브러리
    - 추출 연산자 : >>
    - 추가 연산자 : <<

### 1.2.6 멀티 스레딩
- 어토믹 변수, 스레드 , 락 등
- **TODO 34p** 

## 1.3 라이브러리 활용
1. #include
2. std 네임스페이스 지정, 글로벌 네임스페이스
3. 실행 파일 생성을 위해 링커에게 라이브러리

### 1.3.1 헤더 파일 인클루드하기
```Cpp
#include <iostream>
#include <vector>
```
### 1.3.2 네임스페이스 지정하기
- 네임스페이스 스포크 지정 연산자 ::

```Cpp
#include <iostream>
#include <chrono>
...
std::cout << "Hello world:" << std:: endl;
auto timeNow= std::chrono::system_clock:now();
```
#### 짧은 이름 사용하기
C++ 에서는 using 선언과 using 디렉티브로 이름을 사용할 수 있다

#### using 선언
using 선언을 사용하면 그 선언문에 적용된 스코프에 이름이 추가 된다.

```cpp
#include <iostream>
#include <chrono>
...
using std::cout:
using std::endl;
using std::chrono::system_clock;
...
cout << "Hello world:" << endl; // 비공식 이름
auto timeNow= now(); // 비공식 이름
```
using 선언을 하면 다음과 같은 현상이 발생
- 한 스코프에 같은 이름을 선언하면 모호한 룩업(lookup)과 이에 따른 컴파일 에러가 발생
- 상위 스코프에 같은 이름이 선언돼 있으면 using 선언에 의해 가려짐

#### using 디렉티브
using 디렉티브를 이용하면 네임스페이스 이름을 짧게 사용

```cpp
#include <iostream>
#include <chrono>
...
using namespace std
...
cout << "Hello world:" << endl; // 비공식 이름
auto timeNow= chrono::system_clock::now(); // 부분 공식 이름
```
- 한 스코프에 같은 이름을 선언하면 모호한 룩업과 이에 따른 컴파일 에러가 발생
- 상위 스코프에 같은 이름이 선언돼 있으면 using선언에 의해 가려짐
- 다른 네임스페이스에 동일한 이름이 있거나 네임스페이스에 있는 이름이 글로벌 스코프에 있는 이름을 가리면, 모호한 룩업과 이에 따른 컴파일 에러가 발생

**warning**
- 본의 아니게 로컬에 있는 이름이나 상위 네임스페이스 가림
- 헤더 파일에서는 using 디렉티브 사용하면 안된다, std에 속한 이름이 모두 드러남

### 1.3.3 실행 파일 생성하기
g++ -std=c++14 thread.cpp -o thread -pthread