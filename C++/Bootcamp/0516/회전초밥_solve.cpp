#include <iostream>
#include<algorithm>
#include<deque>


using namespace std;

int N, D, K, C;
int A[3000000+10];
int visited[3001];

void InputData(){
    cin >> N >> D >> K >> C;
    for (int i=0; i<N ; i++){
        cin >> A[i];
    }
}

int solve(){

    int flag;
    int coupon;
    int result = 0;
    for(int i =0; i<N; i++){
        flag = 0; // 중복
        coupon = 1;
        for(int j=i; j<i+K; j++){
            //cout << A[j%N] << " ";
            if(visited[A[j%N]]==1){
                // 중복 체크
                flag++;
            }else{
                // 방문 체크
                visited[A[j%N]]=1;
            }
        }

        if(visited[C] == 1){
            coupon = 0;
        }

        result = max(result, K - flag + coupon);
 
        for(int j=i; j<i+K; j++){
            visited[A[j%N]]=0;    
        }
    }

    return result;
}


int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    ans = solve();

    cout <<  ans << endl;// 출력하는 부분
    return 0;
}