# 4장 순차 컨테이너

|기준|배열|벡터|덱|리스트|포워드 리스트|
|-----|----|----|----|----|----|
|크기|정적|동적|동적|동적|동적|
|구현|정적 배열|동적 배열|배열 시퀀스|이중 연결 리스트|단일 연결 리스트|
|접근 방식|임의 접근|입의 접근|임의 접근|정방향과 역방향|정방향|
|추가/삭제의 최적화 지점||끝 : O(1)|시작과 끝 : O(1)|시작과 끝 : O(1) 임의 : O(1)|시작 : O(1) 임의 : O(1)|
|메모리 예약||있음|없음|없음|없음|
|메모리 해제||shrink_to_fit|shrink_to_fit|항상|항상|
|장점|메모리 할당 없음, 메모리 사용량 최소|95% 솔루션|시작과 끝에 추가와 삭제|임의의 지점에 추가와 삭제|빠른 추가/삭제:최소 메모리 요구 사항|
|단점|동적 메모리 할당 없음|임의의 지점에 추가/삭제:O(n)|임의의 지점에 추가/삭제:O(n)|임의 접근 불가능|임의 접근 불가능|

## 4.1 배열

- 길이가 고정된 동형(homogeneous)
- 헤더 : &lt;array&gt;
- 메모리와 실행은 C의 배열, 인터페이스는 vector
```C++
std::array<int, 10> arr // 원소 열 개가 초기화 되지 않음
std::array<int, 10> arr{} // 원소 열 개가 디폴트 값으로 초기화
std::array<int, 10> arr{1, 2, 3, 4, 5} // 나머지 원소는 디폴트 값으로 초기화

// 인덱스 방식
arr[n];
arr.at(n); // 경계 벗어나면 std::range-error 익셉션
std::get<n>(arr); 
```

## 4.2 벡터
- 실행 시간에 길이 조정 가능
- std:vector

```C++
std::vector<int> vec(10); // 열개
std::vector<int> vec(10, 2023); // 2023 열개
std::vector<int> vec{10, 2023}; // 10과 2023
```

### 4.2.1 크기 vs 용량

|메서드|설명|
|------|---|
|vec.size()|vec 원소 개수|
|vec.capacity()|vec에 대한 메모리를 더 할당받지 않고 가질 수 있는 원소의 개수|
|vec.resize(n)|vec의 원소 개수가 n개로 증가|
|vec.reverse(n)|원소를 최소한 n개 담는 데 필요한 메모리를 예약|
|vec.shrink_to_fit()|vec의 용량을 크기에 맞게 줄인다|

- vector.cpp

|메서드|설명|
|------|---|
|vec.assing(...)|한 개 이상의 원소, 범위, 이니셜라이저 리스트를 대입|
|vec.clear()|vec에 담긴 원소를 모두 삭제|
|vec.emplace(pos, args ...)|pos 지점 바로 앞에 args로 지정한 원소를 vec에 새로 만들고, 생성된 원소의 위치를 리턴|
|vec.emplace_back(args ...)|vec에 args로 지정한 원소를 새로 만든다|
|vec.erase(...)|원소나 범위를 삭제하고 다음 위치를 리턴|
|vec.insert(pos, ...)|원소, 범위, 이니셜라이저 리스트를 한 개 이상 추가하고, 그 위치를 리턴|
|vec.pop_back()|마지막 원소를 삭제|
|vec.push_back(elem)|elem의 복제본을 vec의 끝에 추가|

## 4.3 덱

- std::deque
- deque.cpp

## 4.4 리스트

- std::list
- 임의 접근(random access)을 지원하지 않음
- 임의 접근 속도가 느림, 최악의 경우 원소 개수
- 원소를 추가하거나 삭제 속도 빠름, 반복자가 해당 지점을 가르킬 경우
- 원소를 추가하거나 삭제 할때마다 위치 조정
- list.cpp

|메서드|설명|
|------|---|
|lis.merge(c)|정렬된 리스트 c를 정렬된 리스트 lis와 합친다. 따라서 lis는 정렬된 상태를 유지|
|lis.merge(c, op)|정렬된 리스트 c를 정렬된 리스트 lis와 합친다. 따라서 lis는 정렬된 상태를 유지, op를 정렬 기준으로 사용|
|lis.remove(val)|lis에서 값이 val인 원소를 모두 삭제|
|lis.remove_if(pre)|lis에서 pre라는 프레디케이트를 만족하는 원소를 모두 삭제|
|lis.splice(pos, ...)|lis에서 pos 지점 앞에서 원소들을 나눈다. 이때 원소는 단일 원소일 수도 있고, 범위일 수도 있고, 리스트일 수도 있다|
|lis.unique()|값이 같으면서 연달아 나온 원소를 제거|
|lis.unique(pre)|pre 프레디케이트를 만족하면서 연달아 나온 원소를 제거|

## 4.5 포워드 리스트

- std::forward_list, 단일 연결 리스트
- 메모리 사용 최소화
- 반복자는 정방향으로만 진행, 역방향 불가능
- 순차 컨테이너 중 유일하게 크기를 알 수 없음
- forwardList.cpp

|메서드|설명|
|------|---|
|forw.before_begin()|첫 번째 원소 앞을 기리키는 반복자를 리턴|
|forw.emplace_after(pos, args ...)|pos 지점 바로 뒤에 args로 지정한 원소를 생성|
|forw.emplace_front(args ...)|forw의 시작점에 args로 지정한 원소를 생성|
|forw.erase_after(pos, ...)|forw에서 pos 지점에 있는 원소나 pos에서 시작하는 범위를 삭제|
|forw.insert_after(pos, ...)|pos 지점 뒤에 새 원소를 추가, 추가되는 원소는 하나 일 수도 있고 범위로 지정 가능, 이니셜라이저 리스트|
|forw.merge(c)|정렬된 포워드 리스트 c를 정렬된 포워드 리스트 forw와 합친다. forw는 정렬된 상태를 유지|
|forw.merge(c, op)|정렬된 포워드 리스트 c를 정렬된 포워드 리스트 forw와 합친다. op를 정렬 기준으로 사용|
|forw.splice_after(pos, ...)|forw의 원소를 pos 지점을 기준으로 나눈다. 단일 원소일 수 도 있고, 범위 일 수도 있고, 리스트|
|forw.unique()|인정한 원소 중에서 값이 같은 것을 제거|
|forw.unique(pre)|프리디케이트 pre를 만족하는 입전한 원소를 제거|
