#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, D, K, C;
int A[3000001];
int start, cnt, answer;
unordered_map<int, int> m;

void InputData(){
    cin >> N >> D >> K >> C;
    for (int i=0; i<N ; i++){
        cin >> A[i];
    }
}

void solve(){

for (int i = 0; i < K - 1; i++) { // k 4면 0 1 2 
		m[A[i]]++;
	} // k -1개 넣어두고 시작

	int fin = K - 1;
	for(int i = 0 ; i < N ; i++){ // 회전초밥이므로 한 바퀴 돌자
		int del = A[start];
		int cur = A[fin%N];
		m[cur]++;
		int num = m.size();
		if (m.find(C) == m.end()) { // 쿠폰용 초밥이 없다면 +1
			answer = max(answer,num + 1);
		}
		else {
			answer = max(answer, num);
		}
		m[del]--;
		if (m[del] == 0) // 갯수가 0이라면 map에서 아예 지우자
			m.erase(m.find(del));
		start++;
		fin++;
	}
}


int main(){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    solve();

    cout << answer << endl;// 출력하는 부분
    return 0;
}