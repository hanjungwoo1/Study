#include <iostream>
#include <stdio.h>
#include <deque>
#include <algorithm>

using namespace std;
int N;//마을 수
int A[100000+10];//마을 위치
int B[100000+10];//잡힌 물고기 양
long long ans = 0;

void InputData(){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d %d", &A[i], &B[i]);
    }
}

int isPossible(int n) {
    long long remain = 0;
    int i;
    for (i = 0; i < N-1; i++) {
        remain += B[i] - n;
        if (remain >= 0 && (remain - (A[i + 1] - A[i])) <0){
        // 서로 보내줄 수 없음
            remain = 0;
        } 
        else{
            remain -= A[i + 1] - A[i];
        } 
         
    }
    // 마지막은 보내는거 계산 안해도 됨, 남은걸로 해결
    remain += (B[N - 1]- n);

    if (remain>=0) return 1; // 성공 Signal
    else return 0; // 실패 Signal
}


void binarySearch(){

    long long minFish = 0;
    long long maxFish = 1000000000;

    while (minFish <= maxFish){

        long long target = (minFish + maxFish) /2 ;


        int result = isPossible(target);

        //cout << "minFish : " << minFish << " maxFish : " << maxFish << " target : " << target << " result : " << result << endl;

        if (result == 0){
            maxFish = target - 1;
        }
        if (result == 1){
            minFish = target + 1;
            ans = max(target, ans);
        }
    }
}

int main(){
    InputData();//입력받는 부분

    binarySearch();

    cout << ans << endl;//출력하는 부분
    return 0;
}
