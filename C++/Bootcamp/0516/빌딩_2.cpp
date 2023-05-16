#include <iostream>
#include <cmath>
using namespace std;

int N;//빌딩의 층수

void InputData(){
    cin >> N;
}

int fact(int n) {
   if (n == 0 || n == 1)
   return 1;
   else
   return n * fact(n - 1);
}

bool isContain(int number){

    int remain;
    while(number!=0){
        remain = number % 10; // 마지막 자리
        number = number / 10; // 마지막 수 버리기

        if (remain == 4){
            return 1;
        }
    }
    return 0;
}

int countSolve(){
    int count = 0;
    int index = 1;
    while(index <= N){
        
        if (isContain(index)){
            count += 1;
        }
        count +=1;
        index +=1;
    }
    return count;
}

// 자릿수 개수 구하기
int makeDecimal(int number){
    int count = 0;
    while(number >0){
        count += 1;
        number = number/10;
    }
    return count;
}


int combinations(int number){

    int result = pow(10, number);
    for(int i=1; i<=number; i++){
        int comb = fact(number) / (fact(i) * fact(number-i));
        int deci = pow(10, number-i);

        int temp = comb * deci * pow(-1, i+1);

        result += temp;
    }
    
    return result;
}


int main(){
    InputData();//입력받는 부분

    cout << countSolve() << endl;


    combinations(4);

    //cout << makeDecimal(N) << endl;

    return 0;
}
