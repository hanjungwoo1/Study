# 11장 스트링

스트링은 문자열을 나열한 것
- string.cpp

## 11.1 생성과 삭제


|메서드|예|
|----|--|
|디폴트|std::string str|
|C++ 스트링 복제|std::string str(oth)|
|C++ 스트링 이동|std::string str(std::move(oth))|
|C++ 스트링 범위|std::string(oth.begin(), oth.end())|
|C++ 스트링의 서브스트링|std::string(oth, otherIndex)|
|C++ 스트링의 서브스트링|std::string(oth, otherIndex, strlen)|
|C 스트링|std::string str("c-string")|
|C 배열|std::string str("c-array", len)|
|문자|std::string str(num, 'c')|
|이니셜라이저 리스트|std::string str({'a', 'b', 'c', 'd'})|
|서브스트링|str= outher.substring(3,10)|
|소멸자|str.~string()|

- stringConstructor.cpp

## 11.2 C++ 스트링과 C 스트링 간 변환

C 스트링을 C++ 스트링으로 변환하는 작업은 암묵적으로 처리되지만, C++ 스트링을 C 스트링으로 변환할 때는 명시적으로 메서드를 호출해야 한다. str.copy() 
- stringCversusC++.cpp

## 11.3 크기 vs 용량

str.size() &lt;= str.capacity() &lt;= str.max_size()

|메서드|설명|
|str.empty()|str에 원소가 있는지 검사|
|str.size(), str.length()|str에 담긴 원소 개수를 리턴|
|str.capacity()|str에 메모리를 다시 할당하지 않고 담을 수 있는 원소 개수를 리턴|
|str.max_size()|str의 최대 길이를 리턴|
|str.resize(n)|str의 길이를 n으로 변경|
|str.reverse(n)|최소한 n개의 원소가 들어갈 메모리 공간을 예약|
|str.shrink_to_fit()|스트링의 용량을 현재 크기로 맞춤|




## 11.4 비교

## 11.5 스트링 결합

## 11.6 원소 접근

## 11.7 입력과 출력

## 11.8 탐색

## 11.9 수정 연산

## 11.10 숫자 변환

