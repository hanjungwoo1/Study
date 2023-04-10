# 2장 유틸리티

## 2.1 유용한 함수들
### 2.1.1 std::min, std:max, std::minmax
- <algorithm> : std::min, std::max, std::minmax 값 또는 이니셜라이저 리스트를 입력받아서 결과를 리턴
- std::minmax : std::pair로 리턴, (최소, 최대)

### 2.1.2 std::move
- 컴파일러가 리소스를 이동할 수 있게 해주는 강력한 기능
- 컴파일러는 소스(arg)를 우측값 참조(rvalue reference)로 변환
- static_cast < std::remove_reference(delctype(arg) > ::type&&>(arg))>

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

```C++
#include <initializer_list>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

struct MyData{
  MyData(){};
  MyData(int, double, char){};
};

template <typename T,  typename ... Args>
T createT(Args&&...args){
  return T(std::forward<Args>(args)...);
}

int main(){

  int a= createT<int>();
  int b= createT<int>(1);

  std::string s= createT<std::string>("Only for testing purpose.");

  MyData myData= createT<MyData>();
  MyData myData2= createT<MyData>(1, 3.19, 'a');

  typedef std::vector<int> IntVec;
  IntVec intVec= createT<IntVec>(std::initializer_list<int>({1, 2, 3, 4, 5}));
}
```

**warning**
- std::forward를 가변 인수 템플릿과 조합하면 완벽한 제네릭 함수

### 2.1.4 std::swap
- 두 오브젝트를 맞바꾸는 작업을 쉽게 처리
    - std::move 함수를 사용하여 구현 됨

## 2.2 함수 어댑터
## 2.3 페어
## 2.4 튜플
## 2.5 래퍼런스 래퍼
## 2.6 스마트 포인터
## 2.7 타임 트레이트
## 2.8 시간 라이브러리
## std::any, std::optional, std::variant