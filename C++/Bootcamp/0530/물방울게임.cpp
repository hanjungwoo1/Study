#include <iostream>
#include <algorithm>
#include <climits>
 
using namespace std;
 
#define MAXN (100)
int A;
int N;
int W[MAXN+10];
int ans;
 
void InputData(){
    cin >> A >> N;
    for (int i=0; i<N; i++){
        cin >> W[i];
    }
}
 
void printDrops(){
    for (int i=0; i<N; i++){
        cout << W[i] << " ";
    }
    cout << endl;
}
 
void dfs(int index, int drops, int skill_count){
    //cout << "drops : " << drops << " Skill Count : " << skill_count << " INDEX: " << index <<" ANS : " << ans << endl;
    if (index == N||ans<=skill_count || skill_count > N){
        ans = min(ans, skill_count);
        return;
    }
     
    // 흡수 가능
    if (W[index] < drops) {
        dfs(index + 1, drops + W[index], skill_count); // 흡수
    }
    else{
    // 흡수 불가능
        dfs(index+1, drops, skill_count+1);    // Skill 2 -> 제거
        dfs(index, drops + drops-1, skill_count+1);    // Skill 1 -> 밑에 놈 흡수
    }
}
 
int main(){
    int t, T;
    cin >> T;
    for (t=1; t<=T; t++){
        InputData();//입력받는 부분
        ans = INT_MAX;
        //여기서부터 작성
        sort(W, W+N);
        dfs(0, A, 0);
 
        cout << "Case #" << t << ": " << ans << endl;//출력하는 부분
    }
    return 0;
}