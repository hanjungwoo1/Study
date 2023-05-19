#include <iostream>
#include<algorithm>
using namespace std;

int N, C, M; // N은 마을 갯수, C는 가능한 수량
int S[10000+10];
int E[10000+10];
int NUM[2000+10];

struct Box{
    int start;
    int end;
    int amount;
};

Box route[10000+10];
int depart[10000+10];
int visit[10000+10];

void InputData(){
    cin >> N >> C;
    cin >> M;
    for (int i=1; i<M+1; i++){
        cin >> route[i].start >> route[i].end >> route[i].amount;
    }
} 

bool comp(const Box &a, const Box &b){
    if(a.end < b.end) {
        return true;
    } else if(a.end == b.end){
        if (a.start < b.start) {
            return true;
        } 
    }
    return false;
}

int solve(){
    int total = 0;
    int start;
    int end;
    int size;
    for(int i = 1; i< M+1; i++){
        start = route[i].start;
        end = route[i].end;
        size = route[i].amount;

        //cout << "from : " << start << " to : " << end << " size : " << size << endl;

		int max_truck= 0; // 지나갈 길에 최대 박스양 -> 남은 빈자리 구하기 위함
		for (int j = start; j < end; j++){
			max_truck = max(depart[j], max_truck);
		}
		int capacity = min(size,C-max_truck); // 넣을 수 있는 택배 구하기
		for (int j = start; j < end; j++) { // 출발에 넣어서 끝까지 하기 위함
			depart[j] += capacity;
		}
        // cout << "Depart : " ;
        // for(int x = 0; x<M+1; x++){
        //     cout << depart[x] << " ";
        // }
        // // cout << endl;
        cout << "Max_truck : " << max_truck << " capacity : " << capacity << endl;

		total += capacity; 

    }
    return total;
}


int main(){
    

    InputData();// 입력받는 부분

    sort(route+1, route+M+1, comp);

    int ans = solve();
    // 여기서부터 작성

    cout << ans << endl;// 출력하는 부분
    return 0;
}