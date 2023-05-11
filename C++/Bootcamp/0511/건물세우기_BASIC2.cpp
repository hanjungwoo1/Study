#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
#define MAXN (10)
int N;//빌딩개수(장소개수)
int A[MAXN+10][MAXN+10];//[빌딩][장소]=비용
int visited[11];
int num[11];
deque<int> result;

void InputData(){
	cin >> N;
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			cin >> A[i][j];
		}
	}
}

void dfs(int index){

    // success combinations
    if (index > N){

        int temp = 0;
        for (int i=1; i<N+1; i++){
            // cout << A[i][num[i]] << " ";
            temp += A[i][num[i]];
        }
        // cout << endl;
        
        result.push_back(temp);
        return;
    }
    
    for(int i = 1; i<=N; i++){
        if (!visited[i]){
            visited[i] = 1;
            num[index] = i;
            dfs(index+1);
            visited[i] = 0;
        }
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력

    dfs(1);
	//여기서부터 작성

    // for(int i=0; i<result.size(); i++){
    //     cout << result[i] << " ";
    // }
    // cout << endl;

    sort(result.begin(), result.end());

    // for(int i=0; i<result.size(); i++){
    //     cout << result[i] << " ";
    // }

	cout << result[0] << "\n";//출력
	return 0;
}