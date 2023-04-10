# 3장 컨테이너 인터페이스
- 순차 컨테이너 VS 연관 컨테이너
- 컨테이너마다 할당자가 있다, std::vector&lt;int&gt; - std::vector&lt;int,std::allocator&lt;int&gt;&gt;

## 3.1 생성과 삭제
- clear() : 원소를 모두 삭제

|타입|예|
|------|---|
|디폴트|std::vector&lt;int&gt; vec1|
|범위|std::vector&lt;int&gt; vec(vec1.begin(), vec1.end())|
|복제|std::vector&lt;int&gt; vec3(vec2)|
|복제|std::vector&lt;int&gt; vec3= vec2|
|이동|std::vector&lt;int&gt; vec4&lt;std::move(vec3)&gt;|
|이동|std::vector&lt;int&gt; vec4= stdf::move(vec3)|
|순차(이니셜라이저 리스트)|std::vector&lt;int> vec5 {1,2,3,4,5}|
|순차(이니셜라이저 리스트)|std::vector&lt;int&gt; vec5= {1,2,3,4,5}|
|소멸자|vec5.~vector()|
|원소 삭제|vec5.clear()|

- std:array : 컴파일 시간에 생성되기 때문에 몇 가지 특별한 속성
    - 이동 생성자
        - range나 이니셜라이저 리스트로 생성할 수 없음
        - 묶음 초기화 가능
        - 원소 삭제 불가능
- containerConstructor.cpp    


### 3.1.1

## 3.2 크기

## 3.3 접근

## 3.4 대입과 맞바꾸기

## 3.5 비교