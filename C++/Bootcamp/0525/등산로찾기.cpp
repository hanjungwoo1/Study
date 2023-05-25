#include <iostream>
#include <deque>
#include <set>
#include <cmath>

using namespace std;

#define MAXN (102)
int N;//산크기
int eh, ew;//목적지 위치 세로, 가로
int map[MAXN][MAXN];
int visit[MAXN][MAXN];
int check[MAXN][MAXN];
set<pair<int, int>> candidate;

struct mount{
    int x;
    int y;
    int power;
};
deque<mount> queue;

void InputData(){
    cin >> N;
    cin >> eh >> ew;
    for (int h=1; h<=N; h++){
        for (int w=1; w<=N; w++){
            cin >> map[h][w];
        }
    }
}

bool IsInside(int nx, int ny) {
    return (0 < nx && 0 < ny && nx <= N && ny <= N);
}

void printMap(){
    cout << "PRINT MAP " << endl;
    for (int h=1; h<=N; h++){
        for (int w=1; w<=N; w++){
            cout << map[h][w] <<" ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "PRINT VISIT " << endl;
    for (int h=1; h<=N; h++){
        for (int w=1; w<=N; w++){
            cout << visit[h][w] <<" ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "PRINT Mount " << endl;
    for (int h=1; h<=N; h++){
        for (int w=1; w<=N; w++){
            cout << check[h][w] <<" ";
        }
        cout << endl;
    }
    cout << endl;
}

void makeStart(){
    for(int i= 1; i<N+1; i++){
        candidate.insert({1, i});
        candidate.insert({N, i});
        candidate.insert({i, 1});
        candidate.insert({i, N});
    }
}

void dfs(){
    for(auto it = candidate.begin(); it!=candidate.end(); it++){
        //cout << (*it).first << " " << (*it).second << endl;
        int putx = (*it).first;
        int puty = (*it).second;
        int putpower = map[putx][puty];
        queue.push_back({putx, puty, putpower*putpower});  
        //map[putx][puty] = putpower;
    }

    int xPos[4] = {0, 0, 1, -1};
    int yPos[4] = {1, -1, 0, 0};

    while(!queue.empty()){
        int nowX = queue.front().x;
        int nowY = queue.front().y;
        int nowPower = queue.front().power;
        queue.pop_front();
        //visit[nowX][nowY] = 1;
        
        //cout << "X : " << nowX << " Y : " << nowY << " Power : " << nowPower << endl;

        for(int i = 0; i<4; i++){
            int newX = nowX + xPos[i];
            int newY = nowY + yPos[i];
            int newPower;

            //if (visit[newX][newY] == 0 && IsInside(newX, newY)){
            if (IsInside(newX, newY)){    
                if (map[nowX][nowY] == map[newX][newY]){ // 평지 -> 힘 안듬
                    newPower = nowPower;
                }else if(map[newX][newY] > map[nowX][nowY]){ // 오르막 -> 높이 차의 제곱
                    int temp = abs(map[newX][newY] - map[nowX][nowY]);
                    newPower = nowPower + temp*temp;
                }else{ // 내리막 -> 높이 차
                    int temp = abs(map[newX][newY] - map[nowX][nowY]);
                    newPower = nowPower + temp;
                }
   
                if(check[newX][newY] == 0){
                    check[newX][newY] = newPower;
                    queue.push_back({newX, newY, newPower});
                }else{
                    if (check[newX][newY] > newPower){ // 업데이트 가능할때만 큐에 푸시
                        check[newX][newY] = newPower;
                        queue.push_back({newX, newY, newPower});
                    }
                }
            }
        }
    }
    //printMap();
}

int main(){
    int ans = -1;
    InputData();//입력 받는 부분
    makeStart();
    dfs();
    //여기서부터 작성

    cout << check[eh][ew] << endl;//출력하는 부분
    return 0;
}