#include <iostream>
using namespace std;
#define MAXN (100)
int W, H;//블록의 가로, 세로 길이
int N;//상점 수
int Dir[MAXN+10];//상점및 동근이 위치한 방향(1:북, 2:남, 3:서, 4:동)
int Len[MAXN+10];//북남: 왼쪽에서 거리, 서동:위쪽에 거리
int Pos[MAXN+10];//좌상단에서의 거리
//0~N-1 상점, N:동근
int ABS(int x) { return (x<0) ? -x:x; }
int Solve(){
    //1.상점 및 동근이 좌상단에서의 거리 구하기
    for (int i=0; i<=N; i++){
        if (Dir[i] == 1) Pos[i] = Len[i];
        else if(Dir[i] == 2) Pos[i] = 2*W + H - Len[i];
        else if(Dir[i] == 3) Pos[i] = 2*W + 2*H - Len[i];
        else Pos[i] = W + Len[i];
    }
    //2.동근와 상점의 최단 거리 구해서 합하기(구한값은 시계방향이므로 절반보다 크면 반시계방향이 답)
    int total = 2*W + 2*H;//블록 총길이
    int half = total / 2;//최대 먼 길이
    int sum = 0;
    for (int i=0; i<N; i++){
        int dist = ABS(Pos[N] - Pos[i]);
        if (dist > half) dist = total - dist;//반시계방향이 더 짧음
        sum += dist;
    }
    return sum;
}
void InputData(){
    cin >> W >> H;
    cin >> N;
    for (int i=0; i<=N; i++){
        cin >> Dir[i] >> Len[i];
    }
}
int main(){
    InputData();
    int ans = Solve();
    cout << ans << endl;// 출력하는 부분
    return 0;
}