# 반복자

반복자 : 컨테이너 내부의 위치를 표현하는 포인터를 일반화

- *: 현재 위치에 있는 원소를 리턴
- ==, !=: 두 위치를 비교
- =: 반복자에 값을 새로 대입

## 7.1 카테고리

C++에서 제공하는 반복자는 정방향, 양방향, 임의 접근

- 정방향 : 앞부분부터 뒤를 향해 진행
- 양방향 : 정방향 과 역방향으로 모두 진행
- 임의 접근 : 원하는 원소에 곧바로 접근

|반복자의 종류|속성|컨테이너|
|----------|---|------|
|정방향 반복자|++It, It++, *It, It==It2, It!=It2|비정렬 연관 컨테이너, std::forward_list|
|양방향 반복자|--It, It--|정렬 연관 컨테이너, std::list|
|임의 접근 반복자|It[i], It+=n, It-=n, It + n, It - n, n+ It, It - It2, I&gt;IT2, IT&gt;=It2, It&lt;It2, It&lt;=It2|std::array, std::vector, std::deque, std::string|

## 7.2 반복자 만들기

- 반복자는 컨테이너마다 적합한 형태로 생성
- auto를 주로 사용
- iteratorCreation.cpp

## 7.3 유용한 함수

|글로벌 함수|설명|
|---------|---|
|std::begin(cont)|cont 컨테이너에 대한 시작 반복자를 리턴|
|std::end(cont)|cont 컨테이너에 대한 끝 반복자를 리턴|
|std::rbegin(cont)|cont 컨테이너에 대한 역방향 시작 반복자를 리턴|
|std::rend(cont)|cont 컨테이너에 대한 역방향 끝 반복자를 리턴|
|std::cbegin(cont)|cont 컨테이너에 대한 상수 시작 반복자를 리턴|
|std::cend(cont)|cont 컨테이너에 대한 상수 끝 반복자를 리턴|
|std::crbegin(cont)|cont 컨테이너에 대한 역방향 상수 시작 반복자를 리턴|
|std::crend(cont)|cont 컨테이너에 대한 역방향 상수 끝 반복자를 리턴|
|std::prev(it)|it 바로 앞 지점을 가리키는 반복자를 리턴|
|std::next(it)|it 바로 뒤 지점을 가리키는 반복자를 리턴|
|std::distance(fir,sec)|fir과 sec 사이의 원소 개수를 리턴|
|std::advance(it, n)|it 반복자를 n만큼 뒤로 옮김|

- iteratorUtilities.cpp


## 7.4 어댑터

반복자 어댑터를 이용하면 반복자를 추가 모드로 사용하거나 스트림에서 사용, 어댑터도 &gt;iterator&lt;

### 7.4.1 추가 반복자

