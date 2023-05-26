#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX (100)
int M, N, K;//세로크기, 가로크기, 직사각형 개수
int sx[MAX+10];
int sy[MAX+10];
int ex[MAX+10];
int ey[MAX+10];

int paperMap[MAX+10][MAX+10];

int sol[MAX * MAX];//각 영역 넓이 저장용
void InputData(){
    cin >> M >> N >> K;
    for (int i=0; i<K; i++){
        cin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
    }
}

void makeData(){
    for (int i=0; i<K; i++){
        //cout << sx[i] << sy[i] << ex[i] << ey[i] << endl;  // 왼쪽아래 좌표, 
        
        for(int j=sx[i]; j < ex[i]; j++){
            for(int k=sy[i]; k <ey[i]; k++){
                paperMap[j][k] = 1;
            }
        }
    }
}

void printMap(){

    cout << "PRINTMAP" << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << paperMap[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool IsInside(int nx, int ny) {
    return (0 <= nx && 0 <= ny && nx < N && ny < M);
}

int dfs(int x, int y){

    deque<pair<int, int>> queue;
    queue.push_back({x, y});
    paperMap[x][y] = 2;

    int xPos[4]= {0, 0, 1, -1};
    int yPos[4]= {1, -1, 0, 0};
    int area = 1;

    while (!queue.empty()){
        int nowX = queue.front().first;
        int nowY = queue.front().second;
        queue.pop_front();

        for(int i =0; i<4; i++){
            int newX = nowX + xPos[i];
            int newY = nowY + yPos[i];

            if(IsInside(newX, newY) && paperMap[newX][newY] == 0){
                area += 1;
                paperMap[newX][newY] = 2;
                queue.push_back({newX, newY});
            }
        }
    }
    return area;
}

void solve(){

    int idx = 0;
    vector<int> Result;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if (paperMap[i][j] == 0){
                int areaResult = dfs(i, j);
                //printMap();
                //cout << "INDEX : " << idx << " AREA : " << areaResult << endl;
                //sol[idx] = areaResult;
                Result.push_back(areaResult);
                idx += 1;
            }
        }
    }

    sort(Result.begin(), Result.end());
    cout << idx<<endl;
    for(int i=0; i<Result.size(); i++){
        cout << Result[i] <<" ";
    }

}

void OutputData(int ans){
    cout << ans << endl;
    for (int i=0; i<ans; i++){
        cout << sol[i] << " ";
    }
    cout << endl;
}

int main(void){
    int ans = -1;
    InputData();//입력받는 부분
    //cout << "PREPROCESS " << endl;
    makeData();
    //printMap();
    solve();
    //여기서부터 작성

    //OutputData(ans);//출력하는 부분
    return 0;
}