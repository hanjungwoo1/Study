# 2장 유틸리티

## 2.1 유용한 함수들
### 2.1.1 std::min, std:max, std::minmax
- &lt;algorithm&gt; : std::min, std::max, std::minmax 값 또는 이니셜라이저 리스트를 입력받아서 결과를 리턴
- std::minmax : std::pair로 리턴, (최소, 최대)

### 2.1.2 std::move
- 컴파일러가 리소스를 이동할 수 있게 해주는 강력한 기능
- 컴파일러는 소스(arg)를 우측값 참조(rvalue reference)로 변환
- static_cast &lt; std::remove_reference(delctype(arg) &gt; ::type&&&lt;(arg))&gt;

```cpp
#include <utility>
...
std::vector<int> myBigVec(10000000, 2011);
std::vector<int> myVec;
myVec = myBigVec;            // 복제 의미론
myVec = std::move(myBigVec); // 이동 의미론
```

**warning**
- 이동이 복제보다 가볍다
    1. 메모리
    2. 스레드 락처럼 복제할 수 없는 오브젝트에 적용

### 2.1.3 std::forward
- 주어진 인수를 그대로 전달하는 함수 템플릿을 작성
- forward.cpp

**warning**
- std::forward를 가변 인수 템플릿과 조합하면 완벽한 제네릭 함수

### 2.1.4 std::swap
- 두 오브젝트를 맞바꾸는 작업을 쉽게 처리
    - std::move 함수를 사용하여 구현 됨

## 2.2 함수 어댑터
- bindAndFunction.cpp

### 2.2.1 std::bind
- 인수를 원하는 위치에 바인딩
- 인수의 순서를 바꿀수 있음
- 인수에 자리 표시자(placeholder)를 적용할 수 있음
- 함수의 일부분만 평가 가능
- 새로 생성된 함수를 호출하고, STL 알고리즘에서 활용하거나 std::function에 저장

### 2.2.2 std::function
- 콜러블 변수에 저장
- 다형 함수 래퍼
- dispatchTable.cpp

## 2.3 페어
- std::pair를 이용하면 원하는(임의의) 타입으로 구성된 쌍을 만듦
- 클래스 템플릿, &lt;utility&gt;, 복제 생성자와 이동 생성자를 디폴트로 제공
- 첫번째 원소 : p.first, std::get&lt;0&gt;(p)
- 두번째 원소 : p.second, std::get&lt;1&gt;(p)

### 2.3.1 std::make_pair
- 페어를 생성하기 위한 헬퍼 함수
- 타입을 지정하지 않아도 자동으로 추론
- pair.cpp

## 2.4 튜플
- 원하는 길이와 타입으로 튜플을 생성
- 원소가 두개인 Tuple = Pair
- std::get&lt;i&gt;(t) 로 참조 가능
- std::get&lt;type&gt;(t)를 이용하면 타입이 type인 원소를 직접 참조

### 2.4.1 std::make_tuple
- 튜플을 생성하는 데 헬퍼 함수 std::make_tuple 사용
- 타입을 따로 지정하지 않아도 컴파일러 자동으로 추론
- tuple.cpp

### 2.4.2 std::tie와 std::ignore
- std::tie 원소에 대한 레퍼런스로 튜플을 생성
- std::ignore 이용하면 튜플의 원소를 명시적으로 무시
- tupleTie.cpp

## 2.5 래퍼런스 래퍼
- type& 오브젝트에 대한 래퍼로서 **복제 생성 가능**, **복제 대입 가능**
    - 표준 템플릿 라이브러리에 있는 컨테이너에서 사용 가능
        - std::vector&lt;std::referece_wrapper&lt;int&gt;&gt; myIntRefVector
    - std::reference_wrapper 오브젝트를 가진 클래스 인스턴스를 복제, 일반 레퍼런스는 불가능
- referenceWrapperCallable.cpp

## 2.6 스마트 포인터
## 2.7 타임 트레이트
## 2.8 시간 라이브러리
## std::any, std::optional, std::variant