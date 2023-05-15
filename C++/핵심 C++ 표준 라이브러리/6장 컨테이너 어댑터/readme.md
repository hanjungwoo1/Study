# 6장 컨테이너 어댑터

C++는 std::stack, std::queue, std::priority_queue

- 기존 순차 컨테이너에 대한 간결한 인터페이스 제공
- 표준 템플릿 라이브러리에 있는 알고리즘에서 사용할 수 없음
- 클래스 템플릿, 데이터 타입과 컨테이너(std::vector, std::list, std::deque)를 매개변수로 지정
- 기본적으로 std::deque을 내부 순차 컨테이너로 사용

## 6.1 스택

- std::stack, LIFO(Last In First Out)
- push(), pop(), top()
- 상수 시간
- stack.cpp

## 6.2 큐

- std::queue, FIFO(First In First Out)
- push(), pop(), back(), front()
- 상수 시간
- queue.cpp

## 6.3 우선순위 큐

- std::priority_queue
- push(), pop(), top()
- 로그 시간
- priorityQueue.cpp
