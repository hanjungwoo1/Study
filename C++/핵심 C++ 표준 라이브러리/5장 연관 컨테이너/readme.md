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


### 5.2.4 탐색 함수

- 정렬 연관 컨테이너는 탐색에 최적화
- associativeContainerSearch.cpp

|탐색 함수|설명|
|-------|---|
|ordAssCont.count(key)|주어진 key에 연관된 값의 개수를 리턴|
|ordAssCont.find(key)|ordAssCont에 주어진 key에 대한 반복자를 리턴, ordAssCont에 해당 key가 없다면 ordAssCont.end()를 리턴|
|ordAssCont.lower_bound(key)|key를 추가할 ordAssCont에서 첫 번째 key에 대한 반복자를 리턴|
|ordAssCont.upper_bound(key)|key를 추가할 ordAssCont에서 마지막 key의 위치를 리턴|
|ordAssCont.equal_range(key)|ordAssCont.lower_bound(key)와 ordAssCont.upper_bound(key) 사이의 범위를 std::pair형태로 리턴|


### 5.2.5 std::map

- 가장 많이 사용되는 연관 컨테이너
- 인덱스로 접근 가능
- at 메서드 : std::out_of_range 익셉션 발생

## 5.3 비정렬 연관 컨테이너

### 5.3.1 개요

- 정렬 연관 컨테이너보다, 인터페이스가 더 풍부하고 키가 정렬되지 않음
- 두 가지 필요
    - 키의 해시 값을 제공 : std::has&gt;key&lt;
    - 키가 같은지를 비교 : std::equal_to&gt;key&lt;

### 5.3.2 키와 값

키
- 동등 여부를 비교
- 해시 값
- 복제와 이동이 가능

값
- 디폴트 생성을 지원
- 복제와 이동이 가능

### 5.3.3. 성능

- std::map VS std::unordered_map = 상수 VS 로그

### 5.3.4 해시 함수

- 불, 자연수, 부동소수점 수와 같은 기본 타입에 대해 기본적으로 제공
- std::string과 std::wstring에서도 사용 가능
- C 스트링인 const char 포인터 주소에 대해 해시 값을 생성
- 사용자 정의 데이터 타입에 대해 정의
- undorderedMapHash.cpp

### 5.3.5 세부 사항

- 비정렬 컨테이너는 인덱스를 버킷에 저장
- 인덱스가 어떤 버킷을 가르킬지는 해시 함수가 결정
- C++ 런타임은 로드 팩터가 1보다 클 때 버킷을 새로 만듦
