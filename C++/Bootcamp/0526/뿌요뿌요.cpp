#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
#define MAXH (12)
#define MAXW (6)
char map[MAXH+2][MAXW+2];
int visit[13][7];
deque<pair<int, int>> clearQueue;

void InputData(){
    for (int i=1; i<=MAXH; i++){
        cin >> &map[i][1];
    }
}

void printMap(){
    cout << "PRINTMAP" << endl;
    for (int i=1; i<=MAXH; i++){
        for(int j=1; j<=MAXW; j++){
            cout<< map[i][j];
        }
        cout << endl;
    }

    cout << "PRINTMAP" << endl;
    for (int i=1; i<=MAXH; i++){
        for(int j=1; j<=MAXW; j++){
            cout<< map[i][j];
        }
        cout << endl;
    }
}

bool IsInside(int nx, int ny) {
    return (0 < nx && 0 < ny && nx <= MAXW && ny <= MAXH);
}

int dfs(int y, int x){
    deque<pair<int,int>> queue;
    queue.push_back({y, x});
    visit[y][x] = 2;
    int area = 1;
    char check = map[y][x];
    int xPos[4]= {0, 0, 1, -1};
    int yPos[4]= {1, -1, 0, 0};
    int flag = 0;

    while(!queue.empty()){
        int nowY = queue.front().first;
        int nowX = queue.front().second;
        queue.pop_front();

        for(int i =0; i<4; i++){
            int newY = nowY + yPos[i];
            int newX = nowX + xPos[i];

            if(IsInside(newX, newY) && visit[newY][newX] == 0 && map[newY][newX] == check){
                area += 1;
                visit[newY][newX] = 2;
                queue.push_back({newY, newX});
            }
        }
    }

    if (area>=4){ // Z로 맵핑
        flag = 1;
        for (int i=1; i<=MAXH; i++){
            for(int j=1; j<=MAXW; j++){
                if (visit[i][j] == 2){
                    visit[i][j] = 1;
                    map[i][j] = 'Z';
                    clearQueue.push_back({i, j});
                }
            }
        }
    }else{
        for (int i=1; i<=MAXH; i++){
            for(int j=1; j<=MAXW; j++){
                if (visit[i][j] == 2){
                    visit[i][j] = 1;
                }
            }
        }
    }
    return flag;
}

void renewMap(){
    for(int i = 1; i<=6; i++){

        deque<char> remainQueue;
        for(int j = 12; j>=0; j--){
            if (map[j][i] == 'Z' || map[j][i] =='.'){
                continue;
            }else{
                remainQueue.push_back(map[j][i]);
            }
        }

        for(int j = 12; j>0; j--){
            map[j][i] = '.';
        }
        int index = 12;
        for(int k=0; k<remainQueue.size()-1; k++){
            map[index][i] = remainQueue[k];
            index--;
        }
    }
}

void solve(){

    int ans = 0;
    while(1){

        int result = 0;
        int temp_result = 0; 
        fill(visit[0], visit[13], 0);

        for (int i=1; i<=MAXH; i++){
            for(int j=1; j<=MAXW; j++){
                if(map[i][j] != '.' && map[i][j] != 'Z' && visit[i][j] == 0){
                    temp_result = dfs(i, j); // 0, 1 이 나오고
                    result = max(temp_result, result);
                }
            }
        }

        if (result !=0){
            ans += 1;
            renewMap();
        }else{
            break;
        }
    }
    cout << ans << endl;
}


int main(){
    int T, t, ans = -1;
    cin >> T;
    for (t=1; t<=T; t++){
        InputData();//입력받는 부분
        solve();
    }
    return 0;
}