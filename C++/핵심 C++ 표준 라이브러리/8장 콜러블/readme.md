# 8장 콜러블

STL 알고리즘과 컨테이너느 콜러블 단위(callable unit), 간단히 줄여서 '콜러블'을 매개변수로 받을 수 있다.

## 8.1 함수

함수는 가장 간단한 형태의 콜러블

## 8.2 함수 오브젝트

```C++
struct sqaure{
    void operator()(int& i){i= i*i;}
}

std::vector<int> myVec{1,2,3,4,5,6,7,8,9,10};

std::for_each(myVec.begin(), myVec.end(), Square());

for(auto v: myVec) std:: cout << v << " "; // 1 4 9 16 25 36 49 64 81 100
```

### 8.2.1 미리 정의된 함수 오브젝트

C++는 미리 정의된 함수 오브젝트를 다양하게 제공, &lt;functional&gt;
- 컨테이너의 디폴트 동작을 변경하는 데 매우 유용
- std::less를 기준으로 정렬 되어 있음, std::greater로 가능


|함수 오브젝트 용도|형식|
|--------------|---|
|부정 연산|std::negate&lt;T&gt;()|
|산술 연산|std::plus&lt;T&gt;(), std::minux&lt;T&gt;(), std::multiplies&lt;T&gt;(), std:;divides&lt;T&gt;(), std::modulus&lt;T&gt;()|
|비교 연산|std::equal_to&lt;T&gt;(), std::not_equal_to&lt;T&gt;(), std::less&lt;T&gt;(), std::greater&lt;T&gt;(), std::less_equal&lt;T&gt;(), std::greater_equal&lt;T&gt;()|
|논리 연산|std::logical_not&lt;T&gt;(), std::logical_and&lt;T&gt;(), std::logical_or&lt;T&gt;()|
|비트 연산|std::bit_and&lt;T&gt;(), std::bit_or&lt;T&gt;(), std::bit_xor&lt;T&gt;()

## 8.3 람다 함수

원하는 기능이 필요한 시점에 함수를 즉시 만들어 사용