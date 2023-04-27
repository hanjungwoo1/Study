# 5장 연관 컨테이너

- 정렬 연관 컨테이너 : std::set, std::map, std::multiset, std::multimap
- 비정렬 연관 컨테이너 : std:unordered_set, std::unordered_map, std::unordered_multiset, std::unordered_multimap
- '3장 컨테이너 인터페이스' 모두 지원

## 5.1 개요

- 키 정렬 여부
- 키에 연관된 값의 존재 여부
- 키 중복 허용 여부

|연관 컨테이너|정렬|키에 연관된 값|키 중복|접근 시간|
|-----|----|----|----|----|
|std::set|O|없음|불가능|로그|
|std::unordered_set|X|없음|불가능|상수|
|std::map|O|있음|불가능|로그|
|std::unordered_map|X|있음|불가능|상수|
|std::multiset|O|없음|가능|로그|
|std::unordered_multiset|X|없음|가능|상수|
|std::multimap|O|있음|가능|로그|
|std::unordered_multimap|X|있음|가능|상수|

- C++98 : 정렬 연관 컨테이너 추가
- C+11 : 비정렬 연관 컨테이너 추가
- orderedUnorderedComparison.cpp

### 5.1.1 원소의 추가와 삭제

- 원소 추가 : insert, emplace
- 원소 삭제 : erace

## 5.2 정렬 연관 컨테이너

### 5.2.1 개요

- std::map과 std::multimap은 키와 값을 연결, &gt;map&lt; 헤더에 정의
- std::set과 std::multiset은 &gt;set&lt; 헤더에 정의

### 5.2.2 키와 값

키
- 정렬 가능(디폴트 비교 기준은 &gt;)
- 복제와 이동이 가능

값
- 디폴트 생성을 지원
- 복제와 이동이 가능

### 5.2.3 비교 기준

정렬 연관 컨테이너에서 디폴트 비교 기준 - std::less