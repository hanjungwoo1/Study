#include <iostream>
#include <deque>

using namespace std;

int A, B, C, D;

deque <pair<pair<int, int>, int>> candidate;
int visit[1010][1010];
int ans = -2;

void InputData() {
	cin >> A >> B >> C >> D;
}

void bfs(){

    candidate.push_back({{0, 0}, 0});
    visit[0][0] = 1;

    int index = 0;
    while(!candidate.empty()){
        int now_Left = candidate.front().first.first;
        int now_Right = candidate.front().first.second;
        int now_count = candidate.front().second;
        candidate.pop_front();

        if (now_Left == C && now_Right == D){
            //cout << "END COUNT : " << now_count << endl;
            ans = now_count;
            return;
        }
        //cout << "LEFT : " << now_Left_now << " " << now_Left_max << " RIGHT : " << temp_right_now << " " << temp_right_max << " COUNT : " << now_count << endl;

        //F(LEFT)
        if (visit[A][now_Right] == 0){// 왼쪽 MAX
            candidate.push_back({{A, now_Right}, now_count+1});
            visit[A][now_Right] = 1;
        }
        //F(RIGHT)
        if (visit[now_Left][B] == 0){// 오른쪽 MAX
            candidate.push_back({{now_Left, B}, now_count+1});
            visit[now_Left][B] = 1;
        }

        //E(LEFT)
        if (visit[0][now_Right] == 0){// 왼쪽 0
            candidate.push_back({{0, now_Right}, now_count+1});
            visit[0][now_Right] = 1;
        }

        //E(RIGHT)
        if (visit[now_Left][0] == 0){// 오른쪽 0
            candidate.push_back({{now_Left, 0}, now_count+1});
            visit[now_Left][0] = 1;
        }

        //M(LEFT, RIGHT)
        if (now_Left + now_Right <= B){ // 왼쪽에서 오른쪽 다 줄 수 있음.
            if (visit[0][now_Left+now_Right] == 0){
            candidate.push_back({{0, now_Left+now_Right}, now_count+1});
            visit[0][now_Left+now_Right] = 1;
            }
        }
        else{ // 다 주기엔 넘침   
            if (visit[now_Left - (B-now_Right)][B] == 0){
            candidate.push_back({{now_Left - (B-now_Right), B}, now_count+1});
            visit[now_Left - (B-now_Right)][B] = 1;
            }
        }
        
        //M(RIGHT, LEFT)
        if(now_Left + now_Right <= A){
            if (visit[now_Left+now_Right][0] == 0){
            candidate.push_back({{now_Left+now_Right, 0}, now_count+1});
            visit[now_Left+now_Right][0] = 1;
            }
        }
        else{
            if (visit[A][now_Right - (A- now_Left)] == 0){
            candidate.push_back({{A, now_Right - (A- now_Left)}, now_count+1});
            visit[A][now_Right - (A- now_Left)] = 1;
            }
        }
    }
    ans = -1;
    
}

int main() {
	
	InputData();//입력받는 부분
	bfs();
	// 여기서부터 작성

	cout << ans << "\n";// 출력하는 부분
	return 0;
}
