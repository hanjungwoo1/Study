#include <iostream>
#include <string>
#include<deque>


using namespace std;

#define MAXN ((int)1e4)
int M, T, N;//배에태울수있는수, 배이동시간, 손님수
int AT[MAXN + 10];
string SIDE[MAXN + 10];

deque<pair<int, int>> Left_side;
deque<pair<int, int>> Right_side;

int arrived[MAXN + 10];
int flag = 0; // 0-> LEFT, 1-> RIGHT
int now_time = 0;
int arrived_N = 0;

void InputData() {
	cin >> M >> T >> N;
	for (int i = 0; i < N; i++) {
		cin >> AT[i] >> SIDE[i];
	}

    for (int i=0; i<N; i++){
        if (SIDE[i] == "left"){
            Left_side.push_back({AT[i], i});
        }else{
            Right_side.push_back({AT[i], i});
        }
    }
}

void OutputData() {
	for (int i = 0; i < N; i++) {
		cout << arrived[i] << "\n";
	}
}

int getInFerry(){
    // return 0 -> 잘 태웠음
    // return 1 -> 그냥 아무것도 못하고 기다림
    // return 2 -> 아무도 못태웠는데 반대에서 기다림
    // return 3 -> 다 태웠음 최대까지

    int getIn = 0;
    int arrived_time;
    if (flag==0){
        while(!Left_side.empty() && getIn < M){ // 왼쪽에 있을때 왼쪽에 기다리는놈 태우기
            int arrived_time = Left_side[0].first;
            int idx = Left_side[0].second;
            if (now_time >= arrived_time){
                Left_side.pop_front(); // 왼쪽에서 태우기
                arrived[idx] = now_time+ T;
                getIn += 1; // 탔음
                arrived_N += 1;
                continue;
            }

            if (getIn > 0){ // 태운사람이 있다면 반대쪽으로 넘어가기
                now_time += T;
                flag = 1;
                return 0;
            }

            // 태운 사람이 없는 경우, 반대 검사
            int arrive_time = Right_side[0].first;
            if (now_time >= arrive_time){ 
                now_time += T;
                flag = 1;
                return 2;
            }

            // 태운 사람도 없고, 반대에도 없음
            return 1; // -> 시간 +=1
        } 

        // 왼쪽이 비어 있던가, 다 찼을 때
        if (getIn >= M){ // 다 찼으면, 우선 그냥 반대로 가야함
            now_time += T;
            flag = 1;
            return 3;
        }
       
        // 아예 비어 있는 경우
        int arrive_time = Right_side[0].first;
        if (now_time >= arrive_time){ 
            now_time += T;
            flag = 1;
            return 2;
        }

        return 1;
    }else{
        while(!Right_side.empty() && getIn < M){ // 오른쪽에 있을 때 기다리고 있는 애 태우기
            int arrived_time = Right_side[0].first;
            int idx = Right_side[0].second;
            if (now_time >= arrived_time){
                Right_side.pop_front(); // 왼쪽에서 태우기
                arrived[idx] = now_time+ T;
                getIn += 1; // 누군가라도 탔음
                idx += 1;
                arrived_N += 1;
                continue;
            }

            if (getIn > 0){
                now_time += T;
                flag = 0;
                return 0;
            }

            int arrive_time = Left_side[0].first;
            if (now_time >= arrive_time){
                now_time += T;
                flag = 0;
                return 2;
            }

            return 1;
        }
        if (getIn >= M){ // 다 찼으면, 우선 그냥 반대로 가야함
            now_time += T;
            flag = 0;
            return 3;
        }
        int arrive_time = Left_side[0].first; // 아예 비어 있는 경우
        if (now_time >= arrive_time){
            now_time += T;
            flag = 0;
            return 2;
        }
        return 1;
    }
    return 1;
}

bool checkCusmtomer(){
    if (Left_side.empty() && Right_side.empty()) return true;
    return false;
}

void checkState(){

    cout << endl;
    cout << "- Check Start -" << endl;

    cout << "Left : ";
    for(int i=0; i<Left_side.size(); i++){
        cout << Left_side[i].first << " ";
    }
    cout << endl;

    cout << "Right : ";
    for(int i=0; i<Right_side.size(); i++){
        cout << Right_side[i].first << " ";
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
		cout << arrived[i] << " ";
	}
    cout << endl;

    cout << "Flag : " << flag << " Now_time : " << now_time << endl;

    cout << "- Check Finish - " << endl;
    cout << endl;
}


void solve(){

    int count = 0;

    while(true){

        // // End StateMent
        // if (checkCusmtomer()){
        //     //cout << "break by empty State" << endl;
        //     break;
        // }
        if (arrived_N >= N){
            break;
        }

        int result = getInFerry(); // 무조건 기다려서 태우고, flag를 바꾼다.
        //cout << "result : " << result << endl;; 
        if (result == 1){
            now_time += 1;
        }
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	InputData();//입력받는 부분
	solve();
	OutputData();//출력하는 부분
	return 0;
}