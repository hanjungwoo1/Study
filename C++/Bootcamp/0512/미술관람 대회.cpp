#include <iostream>
#include <deque>

using namespace std;
#define MAXN (100)
int N;//그림크기(정사각형)
char map[MAXN+10][MAXN+10];
char new_map[MAXN+10][MAXN+10];
int sol1, sol2;
int posX[4] = {-1, 0, 1, 0};
int posY[4] = {0, 1, 0, -1};
deque<pair<int, int>> queue;


void InputData(){
	cin >> N;
	for (int h=1; h<=N; h++){
		cin >> &map[h][1]; }
}

void copyMap(){

    for (int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if (map[i][j] =='B'){
                new_map[i][j] = 'B';
            }else{
                new_map[i][j] = 'R';
            }
        }
    }
}

bool IsInside(int ny, int nx) {
    return (0 < nx && 0 < ny && nx <= N && ny <= N);
}

void floodfill(int i,int j){
    queue.push_back({i, j});
    char key = map[i][j];

    //cout << "start Key : " << key << endl;

    while(!queue.empty()){

        int x = queue.front().first;
        int y = queue.front().second;

        queue.pop_front();
    
        for(int i = 0; i<4; i++){
			int nx = x + posX[i];
			int ny = y + posY[i];

			if (IsInside(nx, ny) && map[nx][ny]==key){
				queue.push_back({nx, ny});
                map[nx][ny] = '0';
			}
		}	
    }
}

void floodfill_red(int i,int j){
    queue.push_back({i, j});
    char key = new_map[i][j];

    //cout << "start Key : " << key << endl;

    while(!queue.empty()){

        int x = queue.front().first;
        int y = queue.front().second;

        queue.pop_front();
    
        for(int i = 0; i<4; i++){
			int nx = x + posX[i];
			int ny = y + posY[i];

			if (IsInside(nx, ny) && new_map[nx][ny]==key){
				queue.push_back({nx, ny});
                new_map[nx][ny] = '0';
			}
		}	
    }
}


void start(){
    int count1 = 0;
    int count2 = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if (map[i][j] != '0'){ // start
                floodfill(i, j);
                count1 += 1;
            }

            if (new_map[i][j] != '0'){ // start
                floodfill_red(i, j);
                count2 += 1;
            }
        }
    }
    sol1 = count1;
    sol2 = count2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();// 입력받는 부분
    copyMap();

    start();

	cout << sol1 << " " <<  sol2 << "\n";// 출력하는 부분
	return 0;
}