#include <iostream>
#include <map>
#include <vector>
using namespace std;

int K;
int A[6+10];
int B[6+10];
int min_area = 1;
int max_area = 1;

map<int, vector<int>> visit;

void InputData(){
    cin >> K;
    for (int i=0 ; i<6 ; i++){
        cin >> A[i] >> B[i];
    }
}

void solve(){

    // push 
    for(int i =0; i<6; i++){
        visit[A[i]].push_back(B[i]);
    }

    // 하나만 있으면 max_vertex
    for(int i =1; i<5; i++){
        auto temp = visit[i];
        if (temp.size() == 1){
            max_area *= temp[0];
        }
    }

    // 양사이드에 중복이면 가운데 놈이 min_vertex
    int count = 0;
    for(int j=1; j<9; j++){
        if (A[(j-1)%6] == A[(j+1)%6]){
            count += 1;
            if (count >2){
                break;
            }
            min_area *= B[j%6];
            // cout << B[j%6] << endl;
        } 
    }
}

int main(){
    int ans = -1;
    InputData();// 입력받는 부분

    solve();
    
    ans = (max_area - min_area) * K;

    cout << ans << endl;// 출력하는 부분
    return 0;
}