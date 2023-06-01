#include <iostream>
#include <deque>

using namespace std;
#define MAXN (100)
int N;
int K;
int R[MAXN+10];
int C[MAXN+10];
int L;
int X[MAXN+10];
char CMD[MAXN+10];
int snakeMap[MAXN][MAXN];
deque<pair<int, int>> snake;
int snake_dir=0;

void InputData(){
    cin >> N;
    cin >> K;
    for (int i=0; i<K; i++){
        cin >> R[i] >> C[i];
    }
    cin >> L;
    for (int i=0; i<L; i++){
        cin >> X[i] >> CMD[i];
    }
}

void makeMap(){
    for(int i=0; i<K; i++){
        snakeMap[R[i]][C[i]] = 1; // apple
    }
}

void printMap(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << snakeMap[i][j];
        }
        cout<< endl;
    }
}

int check(int nx, int ny){
    /*
    사과 만났을 때 = 1
    밖으로 나갔을 때 = 2
    내몸에 부딪혔을 때 = 3
    아무이상 없을 때 = 0
    */
    if (snakeMap[nx][ny] == 1){
        snakeMap[nx][ny] = 0;
        return 1; // apple
    }
    if (nx <1 || nx>N || ny <1 || ny>N){
        return 2; // outside
    } 
    for(int i=0; i<snake.size(); i++){// crash
        if (nx == snake[i].first && ny == snake[i].second){
            return 3;
        }
    }
    return 0;
}

// snake_dir = 0 -> 오른쪽
// snake_dir = 3 -> 위쪽
// snake_dir = 2 -> 왼쪽
// snake_dir = 1 -> 아래쪽
int xPos[4] = {0, 1, 0, -1};
int yPos[4] = {1, 0, -1, 0};

int solve(){

    snake.push_back({1,1});

    int index = 0;
    int L_index = 0;
    while(true){
        index += 1;

        int nowX = snake.front().first;
        int nowY = snake.front().second;

        int newX = nowX + xPos[snake_dir];
        int newY = nowY + yPos[snake_dir];
        
        //cout << "NOW X:" << nowX << " " << nowY << " TIME : " << index << endl;
        //cout << "NEW X:" << newX << " " << newY << " DIR : " << snake_dir << " SIZE : " << snake.size() << endl;

        int result = check(newX, newY);
        if (result == 1){
            snake.push_front({newX, newY});
        }else if(result == 2){
            return index;
        }else if(result == 3){
            return index;
        }else{
            snake.push_front({newX, newY});
            snake.pop_back();
        }

        /*
        L = -1, D = +1
        snake_dir = 0 -> 오른쪽
        snake_dir = 3 -> 위쪽
        snake_dir = 2 -> 왼쪽
        snake_dir = 1 -> 아래쪽
        */
        if(index == X[L_index]){ // 방향바꾸기 시간이 맞다면
            if(CMD[L_index] == 'D'){
                snake_dir += 1;
            }else{
                snake_dir -= 1;
            }
            snake_dir += 4;
            snake_dir = snake_dir %4;
            L_index += 1;
        }
    }

    return index;
}


int main(){
    int ans = -1;

    InputData();//입력받는 부분
    makeMap();
    //printMap();
    ans = solve();
    //여기서부터 작성

    cout << ans << endl;//출력하는 부분
    return 0;
}