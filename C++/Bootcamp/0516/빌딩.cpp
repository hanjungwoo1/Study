#include <iostream>
#include <cmath>
#include <deque>

using namespace std;
int N;//빌딩의 층수
int decimal;
deque<int> queue;


void InputData(){
    cin >> N;
}

void makeArray(){

    int number = N;
    int remain;
    int count = 0;
    while(number!=0){
        remain = number % 10; // 마지막 자리
        number = number / 10; // 마지막 수 버리기
        queue.push_back(remain);
        count += 1;
    }
    decimal = count;
}

int Cal(int deci){
    if(deci == 0){
        return 0;
    }
    if(deci == 1){
        return 1;
    }
    return (Cal(deci-1) *9 + pow(10, deci-1));
}

int getDiff(int deci){
    int diff = 0;
    if(queue[deci]<4){
        diff += Cal(deci) * queue[deci];
    }else{
        diff += Cal(deci) * (queue[deci] -1) + pow(10, deci);
    }
    return diff;
}

int Solve(){
    int diff = 0;
    while(--decimal >=0){
        diff += getDiff(decimal);
    }
    return N-diff;
}

int main(){
    int ans = -1;
    InputData();//입력받는 부분

    makeArray();
    ans = Solve();
    //여기서부터 작성

    cout << ans << endl;
    
    return 0;
}