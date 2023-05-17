# 10장 수학

## 10.1 무작위 수

무작위수(random number)(난수) 는 소프트웨어 테스트, 암호 키 생성, 컴퓨터 게임 등 다양한 분야에서 사용

### 10.1.1 무작위수 생성기

```C++
#include <random>

std::random_device seed;
std::mt19937 generator(seed());
```

- Generator::result_type : 생성된 무작위수의 데이터 타입
- gen() : 무작위수를 리턴
- gen.min() : gen이 리턴할 수 있는 무작위수 중에서 최솟값을 리턴
- gen.max() : gen이 리턴할 수 있는 무작위수 중에서 최댓값을 리턴

### 10.1.2 무작위수 분포

```C++
#include <random>

std::random_device seed;
std::mt19937 gen(sedd());
std::uniform_int_distribution<> unDis(0, 20);
unDis(gen);
```

- random.cpp


## c에서 물려받은 수학 함수

&lt;cmath&gt;에 정의된 함수
|pow|sin|tanh|asinh|fabs|
|exp|cos|asin|aconsh|fmod|
|sqrt|tan|acos|atanh|frexp|
|log|sinh|atan|ceil|ldexp|
|log10|cosh|atan2|floor|modf|


&lt;cstdlib&gt;에 정의된 함수

|abs|llabs|ldiv|srand|
|labs|div|lldiv|rand|

- mathFuctions.cpp





