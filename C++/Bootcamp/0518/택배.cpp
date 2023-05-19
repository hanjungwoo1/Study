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

    int start = 0;
    int index = 0;
    int size = C;
    int handleAmount;

    // 가까운거 위주로 계속 넣다가.
    // 새로운 (한번에 스킵)

    for(int i = 1; i< M+1; i++){
        index = route[i].start;

        if (visit[index] ==0){
            size += depart[index];
            visit[index] = 1;
        }

        // 움직이기 가능한 수량 계산
        if (route[i].amount <= size){ // 작거나 같으면 다 넣고
            handleAmount = route[i].amount;
        }else if(route[i].amount > size){ // 부분만 넣고
            handleAmount = size;
        }

        depart[route[i].end] += handleAmount;
        size -= handleAmount;

    }

    int total = 0;
    for(int i=1; i<N+1; i++){
        //cout << depart[i] << " " << endl;
        total += depart[i];
    }
    //cout << total<< endl;
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