

# [Live]C++ Programming

## 2023.03.27~03.31 

1. 오버로딩 전반
    - 7p
    - 함수명은 같고 parameter list 부분이 달라야 함
    - parameter 개수, parameter의 type, 배치 순서
    - const 포인터와 일반 포인터는 다른 type
    - 하나의 함수명으로 다양한 type 처리에 유용
    - 자동형변환에 의한 호출(char -> int, float -> double)
2. Default Parameter
    - 10p
    - default Parameter를 지정하면 그 이후 parameter는 모두 default Parameter
3. reference 문법
    - 15p
    - 다른 변수에 대한 별명(alias)
    - 실제 변수에 반영됨, (like, call by pointer)
    - 함수 / 메서드(멤버 함수)의 parameter나 return type으로도 사용 가능
    - 참조 변수는 선언과 동시에 참고하고자 하는 변수로 초기화 해야함
    - 포인터와의 차이점
        - 참조 변수의 주소를 출력하면 참조 대상의 주소가 나옴
        - 초기화 이후에는 참조 대상을 변경할 수 없음
    - 참조 포인터 변수 : 포인터 변수의 참조형
```cpp
data-type * 포이터 변수 명;
data-type * &참조 변수 명 = 포인터 변수 명;
```
    - 참조 배열 : 배열의 참조형
```cpp
data-type 배열 명[n];
data-type (&참조 배열 명)[n] = 배열 명; // 거의 사용 X, 크기 지정해야 함
```
4. 동적 Memory 할당 기법
    - 27p
    - new, delete, new[], delete[]
    - 28p 문제
5. 네임 스페이스
    - 22p
    - 여러 가지 식별자들을 이름이 있는 범위로 그룹화하는 기법
    - 식별자들의 종류
        - 변수, 함수, 구조체, 클래스, 공용체, typedef 등
    - **using** : namespace안의 식별자를 namespace명 없이 사용하기 위한 명령어
    - 중첩 사용 : 가까운 함수 호출
6. 인라인함수
    - 29p
    - 함수 몸체를 호출한 곳에 삽입
    - 일반 함수보다 약간 빠르지만, 메모리 사용
    - 매크로 함수 대신에 사용
        - 매크로 = 전처리기, 인라인 함수 = 컴파일러
7. this Pointer
    - 39p
    - 클래스의 모든 멤버 함수는 묵시적 전달인자로 this 포인터를 가짐
    - 멤버 함수를 호출한 객체의 주소가 this 포인터에 저장
    - 컴파일 타임에 추가
    - 숨겨져 있음, 꼭 해야하는 경우 : 같은 변수 명
8. 생성자
    - 41p
    - 생성자 : 클래스 객체를 선언하여 메모리가 할당될 때 자동으로 호출되는 클래스 멤버 함수
9. 멤버 초기화 List
    - : ~~~
10. 복사 생성자
11. Static Member, Const Member
12. 연산자 오버로딩 전반
13. 대입 연산자
14. freind 기법
15. 함수 오버라이딩
16. 바인딩
17. Virtual 키워드
18. 순수가상함수
19. 추상 Class