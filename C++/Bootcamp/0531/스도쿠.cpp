#include <iostream>
#include <vector>

using namespace std;

#define MAXN (9)
int sudoku[MAXN][MAXN];
vector<pair<int,int>> candidate;
int maxLength;


void InputData(){
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            cin >> sudoku[r][c];
            if (sudoku[r][c] == 0){
                candidate.push_back({r,c});
            }
        }
    }
}

void OutputData(){
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            cout << sudoku[r][c] << " ";
        }
        cout << endl;
    }
}

int checkRow(int x){
    int visit[10] = {0,};
    for(int i=0; i<9; i++){ // 0부터 9까지 탐색, X고정
        if (sudoku[x][i] == 0){
            continue;
        }
        if (visit[sudoku[x][i]] == 0){ // 방문안했고, 0이 아니다 -> 숫자다 -> 판단 가능
            visit[sudoku[x][i]] = 1; // 방문 처리
        }else if (visit[sudoku[x][i]] == 1){
            return 0;
        }
    } 
    return 1;
}

int checkCol(int y){
    //OutputData();
    int visit[10] = {0,};
    for(int i=0; i<9; i++){ // 0부터 9까지 탐색, X고정
        if (sudoku[i][y] == 0){
            continue;
        }
        if (visit[sudoku[i][y]] == 0){ // 방문안했고, 0이 아니다 -> 숫자다 -> 판단 가능
            visit[sudoku[i][y]] = 1; // 방문 처리
        }else if (visit[sudoku[i][y]] == 1){
            return 0;
        }
    } 
    return 1;
}

int checkRange(int x, int y){

    int startx, endx;
    int starty, endy;

    if (0<=x && x<3){ // 0~2
        startx = 0;
        endx = 2;
    }
    if (3<=x && x<6){ // 3~5
        startx = 3;
        endx = 5;
    }
    if (6<=x && x<9){
        startx = 6;
        endx = 8;
    }
    if (0<=y && y<3){ // 0~2
        starty = 0;
        endy = 2;
    }

    if (3<=y && y<6){ // 3~5
        starty = 3;
        endy = 5;
    }
    if (6<=y && y<9){
        starty = 6;
        endy = 8;
    }

    int visit[10] = {0,};
    for(int i=startx;i<=endx; i++){
        for(int j=starty; j<=endy; j++){
            if(sudoku[i][j] == 0) continue;
            if (visit[sudoku[i][j]] == 0){ // 방문안했고, 0이 아니다 -> 숫자다 -> 판단 가능
                visit[sudoku[i][j]] = 1; // 방문 처리
            }else if (visit[sudoku[i][j]] == 1){
                return 0;
            }
        }
    }
    return 1;
}

int flag = 0;
void dfs(int index){

    if (flag == 1) return;

    if (maxLength == index){     // 종료 조건
        flag = 1;
        OutputData();
        return;
    }

    int putX = candidate[index].first;
    int putY = candidate[index].second;

    for(int i=1; i<10; i++){ // 넣을 숫자 1에서 9까지
        sudoku[putX][putY] = i;
        if (checkRow(putX) && checkCol(putY) && checkRange(putX, putY)){
            dfs(index+1);
        }
        sudoku[putX][putY] = 0;
    }
}

int main(){
    InputData();//입력받는 부분
    maxLength = candidate.size();
    dfs(0);
    return 0;
}