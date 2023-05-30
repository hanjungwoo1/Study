#include <iostream>
#include <climits>

using namespace std;
#define MAXN (20)
int N, B; // 소의 수, 책꽂이 높이
int H[MAXN + 10]; // 소 키들의 높이
int result;


void InputData(){
    cin >> N >> B;
    for (int i=0; i<N; i++){
        cin >> H[i];
    }
}

/*
소의 조합 중, B보다 높지만 최소 값을 B빼고 출력
*/

void dfs(int index, int summation, string path){

    if (index == N){
        //cout << path << " SUM : " << summation << endl;
        if (summation >= B){
            result = min(result, summation);
        }

        return;
    }

    // non add
    dfs(index + 1, summation, path);
    // add
    dfs(index + 1, summation += H[index], path + to_string(index));
}

int main(){
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        result = INT_MAX;
        InputData();
        dfs(0, 0, "");
        cout << result - B << endl;
    }
    return 0;
}