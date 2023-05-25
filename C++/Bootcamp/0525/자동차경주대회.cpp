#include <iostream>
#include <deque>
#include <climits>
#include <vector>
using namespace std;

#define MAXN (100)
int L;//정비를 받지 않고 갈수있는 최대거리
int N;//정비소 개수
int dist[MAXN+10];//정비소사이거리
int times[MAXN+10];//정비시간
int summation = 0;
int checkArray[MAXN+10];

struct car{
    int pos;
    int time;
    int fuel;
    vector<int> route;
};

deque<car> queue;

void InputData(){
    cin >> L;
    cin >> N;
    for (int i=1; i<=N+1; i++){
        cin >> dist[i];
        summation += dist[i];
        checkArray[i] = INT_MAX;
    }
    for (int i=1; i<=N; i++){
        cin >> times[i];
    }
}

void printCheck(){
    for (int i=1; i<=N+1; i++){
        cout << checkArray[i] << " ";
    }
    cout << endl;
}

void dfs(){

    int resultTime = INT_MAX;
    vector<int> resultRoute;

    queue.push_back({0, 0, L,{}});

    // 정비소마다 최소 값 업데이트, 이것보다 크면 skip!

    while(!queue.empty()){

        int nowPos = queue.front().pos;
        int nowTime = queue.front().time;
        int nowFuel = queue.front().fuel;
        vector<int> nowRoute = queue.front().route;
        queue.pop_front();

        int check = 0;
        for(int i=nowPos+1; i<=N+1; i++){
            check += dist[i]; // 현재에서 끝까지 가능한지
        }

        if (check <= nowFuel){ // 마지막까지 도착, 
            //cout << "ROUTE : " << nowRoute << " nowTime : " << nowTime << endl; 
            if (nowTime < resultTime){
                resultTime = nowTime;
                resultRoute = nowRoute;
                //cout << "UPDATE " << "ROUTE : " << nowRoute << " nowTime : " << nowTime << endl; 
            }
        }

        // 현재부터 갈수 있는곳
        for(int i=nowPos+1; i<N+1; i++){
            int newFuel = nowFuel-dist[i];
            int newTime = nowTime+times[i];
            vector<int> newRoute = nowRoute;

            //cout << "nowPos : " << nowPos << " nowFuel : " << nowFuel << " newPos : " << i <<" newFuel : " << newFuel << endl; 
            nowFuel = newFuel; // update Fuel
            if (newFuel >= 0 && checkArray[i] >= newTime){
                checkArray[i] = newTime;
                newRoute.push_back(i);
                queue.push_back({i, newTime, L, newRoute});
            }
        }
        //printCheck();
    }

    if (summation <= L){
        cout << "0" << endl;
    }else{
        cout << resultTime << endl;
        cout << resultRoute.size() << endl;
        for(int i=0; i<resultRoute.size(); i++){
            cout << resultRoute[i] << " ";
        }
    } 
}


int main(){
    InputData();//입력 받는 부분

    dfs();
    //여기서부터 작성

    return 0;
}