#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

#define MAXN (100)
int N;
char map[MAXN+10][MAXN+10];
int posX[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int posY[8] = {0, 1, 0, -1, -1, -1, 1, 1};

deque<pair<int, int>> queue;

void InputData(){
	cin >> N;
	for (int i=1; i<=N; i++){
		cin >> &map[i][1];
	}
}

bool IsInside(int ny, int nx) {
    return (0 < nx && 0 < ny && nx <= N && ny <= N);
}

void floodfill(int i,int j){
    queue.push_back({i, j});
    map[i][j] = '2';

    while(!queue.empty()){

        int x = queue.front().first;
        int y = queue.front().second;

        queue.pop_front();
    
        for(int i = 0; i<8; i++){
			int nx = x + posX[i];
			int ny = y + posY[i];

			if (IsInside(nx, ny) && map[nx][ny]=='1'){
				queue.push_back({nx, ny});
                map[nx][ny] = '2';
			}
		}	
    }
}

int start(){
    int count = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if (map[i][j] == '1'){ // start
                floodfill(i, j);
                count += 1;
            }
        }
    }
    return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력

    int result;
    result = start();
    cout << result << endl;
}