#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N;
int grids[500+10][500+10];
int visit[500+10][500+10];
int maxStride = 0;
int maxInt = 0;

struct trackter{
    int nx;
    int ny;
};

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> grids[i][j];
            maxInt = max(grids[i][j] , maxInt);
        }
    }
}

// void printMap(){
//     for(int i = 0; i<N; i++){
//         for(int j =0; j<N; j++){
//             cout << grids[i][j];
//         }
//         cout << endl;
//     }
// }

bool isInside(int nx, int ny){
    return (0<= nx && 0<= ny && nx < N && ny < N);
}

int bfs(int startx, int starty, int power){
    deque<trackter> queue;
    queue.push_back({startx, starty});
    visit[startx][starty] = 1;
    int area = 1;
    int check = 0;
    int xPos[4] = {1, 0, 0, -1};
    int yPos[4] = {0, 1, -1, 0};

    while(!queue.empty()){
        int nowX = queue.front().nx;
        int nowY = queue.front().ny;
        queue.pop_front();

        for(int i=0; i<4; i++){
            int newX = nowX + xPos[i];
            int newY = nowY + yPos[i];

            if(isInside(newX, newY) && visit[newX][newY] == 0 && abs(grids[newX][newY] - grids[nowX][nowY])<=power){
                visit[newX][newY] = 1;
                area += 1;
                queue.push_back({newX, newY});    
            }

            if (area >= maxStride){
                return area;
            }
        }
    }
    return 0;
}

void binarySearch(){
    int start = 0;
    int end = maxInt;
    int middle;
    int answer;
    while(start < end){

        int middle = (start+end)/2;
        int maxResult = 0;
        fill(visit[0], visit[510], 0);
        for(int i=0;i<N; i++){
            for(int j=0; j<N; j++){
                int result = bfs(i, j, middle);
                maxResult = max(result, maxResult);
            } 
        }

        if (maxStride <= maxResult){ //correct
            end = middle;
            answer = middle;
        }else{ // more middle
            start = middle+1;
        }
    }

    cout << answer << endl;
}


int getResult(){
    int mapSize = N*N;
    if (mapSize%2==1){
        return (mapSize/2) + 1;
    }
    return mapSize/2;
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분
    //printMap();
    maxStride = getResult();
    binarySearch();
    // dfs(0, 0, 1);

    // 여기서부터 작성
    //cout << maxStride << endl;
    // cout << ans << endl;// 출력하는 부분
    return 0;
}