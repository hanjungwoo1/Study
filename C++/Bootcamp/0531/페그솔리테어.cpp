#include <iostream>
#include <climits>

using namespace std;
#define MAXH (5)
#define MAXW (9)
char map[MAXH+2][MAXW+2];
int intMap[MAXH+2][MAXW+2];
int solremain, solmove;

void InputData(){
    for (int h=1; h<=MAXH; h++){
        cin >> &map[h][1];
    }
}

void makeMap(){
    for(int i=1; i<=MAXH; i++){
        for(int j=1; j<=MAXW; j++){
            if(map[i][j] == '#'){
                intMap[i][j] = 0;
            }

            if(map[i][j] == '.'){
                intMap[i][j] = 1;
            }

            if(map[i][j] == 'o'){
                intMap[i][j] = 2;
                solremain++;
            }
        }
    }
}

void printMap(){
    for(int i=1; i<=MAXH; i++){
        for(int j=1; j<=MAXW; j++){
            cout << intMap[i][j];
        }
        cout << endl;
    }
}

int xPos[4] = {0, 0, 1 ,-1};
int xFPos[4] = {0, 0, 2, -2};
int yPos[4] = {1, -1, 0, 0};
int yFPos[4] = {2, -2, 0, 0};

bool isInside(int nx, int ny, int fx, int fy){
    return (1<= nx && nx <= MAXH && 1<= ny && ny <= MAXW && 1<= fx && fx <= MAXH && 1<= fy && fy <= MAXW);
}

void dfs(int pinCnt, int moveCnt){

    // check Start
    int flag = 0;
    for(int i=1; i<=MAXH; i++){
        for(int j=1; j<=MAXW; j++){
            if (intMap[i][j] == 2){ // start

                for(int k=0; k<4; k++){ // 가능한 좌표 만들기
                    int nearX = i+xPos[k];
                    int nearY = j+yPos[k];
                    int farX = i+xFPos[k];
                    int farY = j+yFPos[k];

                    if(isInside(nearX, nearY, farX, farY) && intMap[nearX][nearY] == 2 && intMap[farX][farY] == 1){ // 옆에 갈 수 있으며, 다음칸이 비어 있다.
                        intMap[nearX][nearY] = 1;
                        intMap[i][j] = 1;
                        intMap[farX][farY] = 2;
                        flag = 1;
                        dfs(pinCnt-1, moveCnt+1);
                        intMap[nearX][nearY] = 2;
                        intMap[i][j] = 2;
                        intMap[farX][farY] = 1;
                    }
                }
            }
        }
    }

    if (flag == 0){
        if (pinCnt < solremain){ // 핀이 더 작아지면
            solremain = pinCnt;
            solmove = moveCnt;
        }

        if (pinCnt == solremain){
            solmove = min(solmove, moveCnt);
        }
        return;
        // cout << "MUST END" << endl;
        // printMap();
        // cout << "END" << endl;
    }
}


int main(){
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분
        solmove = INT_MAX;
        solremain = 0;
        makeMap();
        //printMap();
        dfs(solremain, 0);
        //여기서부터 작성

        cout << solremain << " " << solmove << endl;//출력하는 부분
    }
    return 0;
}