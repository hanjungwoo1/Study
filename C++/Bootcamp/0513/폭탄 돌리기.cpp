#include <iostream>
using namespace std;
#define MAXN (100)
int K;//처음 폭탄을 가진 사람 번호
int N;//퀴즈 개수
int T[MAXN+10];//걸린 시간
char Z[MAXN+10];//정답 여부

void InputData(){
    cin >> K;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T[i] >> Z[i];
    }
}

int solve(){

    int time = 0;
    int count = 0;
    for(int i = 0; i<N; i++){

        time += T[i];

        if (time > 210){
            break;
        }

        if (Z[i] == 'T'){
            count += 1;
        }

        //cout << "Time : " << time << " Count : " << count << endl; 
    }

    count += K;
    count %= 8;

    if (count == 0){
        count = 8;
    }
    return count;
}



int main(){
    int ans = -1;
    InputData();//입력받는 부분

    ans = solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}