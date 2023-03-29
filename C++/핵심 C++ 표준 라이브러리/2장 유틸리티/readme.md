# 2장 유틸리티

## 2.1 유용한 함수들
### 2.1.1 std::min, std:max, std::minmax
- <algorithm> : std::min, std::max, std::minmax 값 또는 이니셜라이저 리스트를 입력받아서 결과를 리턴
- std::minmax : std::pair로 리턴, (최소, 최대)

### 2.1.2 std::move
- 컴파일러가 리소스를 이동할 수 있게 해주는 강력한 기능
- 컴파일러는 소스(arg)를 우측값 참조(rvalue reference)로 변환
- static_cast<std::remove_reference(delctype(arg)>::type&&>(arg))>

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

## 2.2 함수 어댑터
## 2.3 페어
## 2.4 튜플
## 2.5 래퍼런스 래퍼
## 2.6 스마트 포인터
## 2.7 타임 트레이트
## 2.8 시간 라이브러리
## std::any, std::optional, std::variant