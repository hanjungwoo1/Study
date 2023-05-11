#include <iostream>
using namespace std;
#define MAXN (20)
int N, K;//자연수 개수, 만들수
int A[MAXN+10];//자연수 값
string msg[] = {"NO", "YES"};
int flag;

void InputData(){
	cin >> N >> K;
	for (int i=1; i<=N; i++){
		cin >> A[i];
	}
}

void dfs(int result, int index){

    if (index > N){
        //cout << "result : " << result << endl;
        if (result == K){
            flag = 1;
        }
        return;
    }

    // none add
    dfs(result, index+1);

    // add
    dfs(result+=A[index], index+1);
        
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for(int t=1; t<=T; t++){
		InputData();//입력
        flag=0;

		dfs(0, 1);
		cout << msg[flag] << "\n";//출력
	}
	return 0;
}