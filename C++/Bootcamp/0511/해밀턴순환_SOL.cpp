#include <iostream>
using namespace std;
#define MAXN (12)
int N;//대회수
int A[MAXN+10][MAXN+10];//[출발][도착]=항공료
 
#define INF (1<<30)
bool used[MAXN + 10];
int sol;
void DFS(int s, int n, int sum){
    int e;
    if (sol <= sum) return;
    if (n >= N){//종료조건
        if (A[s][1] != 0){//마지막 도시에서 출발도시(1)에 갈수있어야 함
            if (sol > sum + A[s][1]) sol = sum + A[s][1];
        }
        return;
    }
    for (e = 2; e <= N; e++){
        if (A[s][e] == 0) continue;//경로없음
        if (used[e]) continue;
        used[e] = true;
        DFS(e, n+1, sum+A[s][e]);
        used[e] = false;
    }
}
int Solve(){
    sol = INF;
    DFS(1, 1, 0);//출발도시, 들린도시수, 총비용
    return sol;
}
 
void InputData(){
    cin >> N;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            cin >> A[i][j];
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData();//입력
 
    ans = Solve();//여기서부터 작성
 
    cout << ans << "\n";//출력
    return 0;
}