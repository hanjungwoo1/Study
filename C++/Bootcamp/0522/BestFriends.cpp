#include <iostream>
#include <string>
#include <deque>

using namespace std;

#define MAX_N (300000)

int N, K;
string name[MAX_N + 10];
int check[MAX_N + 10];
deque<int> queue;

void Input_Data(void) {
	string str;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> name[i];
	}
}



long long solve(){
    long long result = 0;
    int count = 0;
    for(int i = 0; i<N; i++){
        
        int index = name[i].size();
        result += check[index];

        if (queue.size() == K){
            check[queue.front()] -=1;
            queue.pop_front();
        }
    
        queue.push_back(index);
        check[index] += 1;
    }
    return result;
}



int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long sol = -1;

	// 입력 받는 부분
	Input_Data();

	// 여기서부터 작성
	sol = solve();

	// 출력하는 부분
	cout << sol << '\n';

	return 0;
}