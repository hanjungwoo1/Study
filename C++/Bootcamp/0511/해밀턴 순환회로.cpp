#include <iostream>

using namespace std;
#define MAXN (12)
#define INF (100000000)
int N;//대회수
int A[MAXN+10][MAXN+10];//[출발][도착]=항공료
int visited[MAXN+10];
int num[MAXN+10];
int result;


void InputData(){
	cin >> N;
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			cin >> A[i][j];
		}
	}
}

void dfs(int index){

    if (index > N){

        // cout << "path : ";
        // for(int i=0; i<N+2; i++){
        //     cout << num[i] << " ";
        // }
        // cout << endl;

        int temp=0;
        for (int i=1; i<N+1; i++){
            if (A[num[i]][num[i+1]] == 0){
                return;
            }
            temp += A[num[i]][num[i+1]];
        }

        if (temp < result){
            result = temp;
        }
        return;
    }

    for(int i = 2; i<=N; i++){
        if (!visited[i] && A[num[index-1]][i]!=0){ // not visited, not 0 distance
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

    result = INF;

	InputData();//입력

    num[1] = 1;
    num[N+1] = 1;

    dfs(2);

	cout << result<< "\n";//출력
	return 0;
}

/*

4
0 59 0 59 
83 0 24 89 
83 43 0 19 
19 0 19 0 

*/