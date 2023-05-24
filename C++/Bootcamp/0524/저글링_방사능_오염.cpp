#include <iostream>
#include <deque>

using namespace std;

#define MAXN (100)
int W, H;//지도의 가로 세로 크기
char map[MAXN+10][MAXN+10];//지도 정보('1':저글링, '0':빈곳)
int xPos[4] = {0, 0, 1, -1};
int yPos[4] = {1, -1, 0, 0};
int sw, sh;//시작위치 가로 세로 좌표
int ans = 0;

struct zergling{

    int x;
    int y;
    int time;
};

deque<zergling> queue;

void InputData(){
    cin >> W >> H;
    for (int i=1; i<=H; i++){
        cin >> &map[i][1];
    }
    cin >> sw >> sh;
}

void showMap(){
    for(int i =1; i<=W; i++){
        for (int j=1; j<=H; j++){
            cout << map[j][i];
        }
        cout << endl;
    }
}

int countMap(){
    int count = 0;     
    for(int i =1; i<=W; i++){
        for (int j=1; j<=H; j++){
            if (map[j][i] == '1') {
                count++;
            }
        }
    }
    //cout << "COUNT : " << count << endl;
    return count;
}


bool IsInside(int nx, int ny) {
    return (0 < nx && 0 < ny && nx <= W && ny <= H);
}

int BFS(){

    int time = 3;
    int ans = 2;
    zergling temp = {sw, sh, time};
    queue.push_back(temp);
    map[sh][sw] = '2';
    int count = 0;

    while(!queue.empty()){
        count += 1;

        int nowx = queue.front().x; // w
        int nowy = queue.front().y; // h
        int nowTime = queue.front().time;
        queue.pop_front();

        //cout << "BASE : "<< nowy << " " << nowx << " " << nowTime << endl; 

        for (int i = 0;i< 4;i++){

            int newX = nowx + xPos[i];
            int newY = nowy + yPos[i];
            int time = nowTime + 1;

            //cout << "Check : " << newY << " " << newX << endl;

            if (IsInside(newX, newY) && map[newY][newX] == '1'){
                //cout << "processing : " << newY << " " << newX << endl;
                map[newY][newX] = '2';
                zergling newTemp = {newX, newY, time};
                ans = max(ans, nowTime);
                queue.push_back(newTemp);
            }
        }
        //showMap();
        //cout << endl;
    }

    //cout << "ANS : " << ans << endl;
    return ans;
}



int main(){
    InputData();//입력 받는 부분
    int ans = 3;
    int left = -1;
    //showMap();
    ans = BFS();

    //showMap();
    left = countMap();

    cout << ans+1 << endl;
    cout << left << endl;

    return 0;
}
