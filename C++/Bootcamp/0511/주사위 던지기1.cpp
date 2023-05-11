#include <iostream>
using namespace std;
int N;//던진횟수
int M;//출력모양
int num[10];
bool visited[10];


void InputData(){
	cin >> N >> M;
}

void dfs(int count, int start){

    if (count > N){
        for (int i=1; i<N+1; i++){
            cout << num[i] << " ";
        }
        cout << endl;
        return;
    }

    if (M==1){
        for(int i = 1; i<=6; i++){
        num[count]=i; 
        dfs(count+1, 0);
        }
    }

    if (M==2){
        for(int i = start; i<=6; i++){
        num[count]=i; 
        dfs(count+1, i);
        }
    }
    
    if (M==3){
        for(int i = 1; i<=6; i++){
            if (!visited[i]){
                visited[i] = 1;
                num[count] = i;
                dfs(count+1, 0);
                visited[i] = 0;
            }
        }
    }

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력

	dfs(1, 1);

	return 0;
}