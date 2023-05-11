#include <iostream>
using namespace std;
#define MAXN (100)
int N, M;//지하철역수, 목적역
int S[MAXN+2][MAXN+2];//[s][e]=시간

void InputData(){
	cin >> N >> M;
	for (int s=1; s<=N; s++){
		for (int e=1; e<=N; e++){
			cin >> S[s][e];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력

	//여기서부터 작성
	return 0;
}