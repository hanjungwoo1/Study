#include <iostream>
#include <climits>
using namespace std;

#define MAXN (10)
int N;
int cost[MAXN+10][MAXN+10];
int solpath[MAXN+10];//답 경로
int visit[MAXN+10];
int result = INT_MAX;
string result_path;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> cost[i][j];
        }
    }
}



void OutputData(){
    cout << result << endl;
    cout << result_path << endl;
    // for (int i=0; i<N; i++){
    //     cout << solpath[i] << " ";
    // }
    // cout << endl;
}

// index 높이
void dfs(int index, int summation, string path){

    if (summation > result){
        return;
    }

    if (index==N){
        //cout << "SUM : " << summation << " path : " << path << endl; 
        if (summation < result){
            result = summation;
            result_path = path;
        }
        return;
    }
      
    for(int i=0; i<N; i++){
        if (visit[i] == 0){
            visit[i] = 1;
            dfs(index+1, summation + cost[index][i], path +to_string(i+1)+ " ");
            visit[i] = 0;
        }
    }
}

int main(){
    int ans = -1;

    InputData();//입력받는 부분

    dfs(0, 0, "");

    OutputData();//출력하는 부분
    return 0;
}