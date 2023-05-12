#include <iostream>
#include <deque>

using namespace std;
#define MAXN ((int)1e4)
int N;
int X[MAXN+10];
int Y[MAXN+10];
int map[110][110];
int posX[4] = {-1, 0, 1, 0};
int posY[4] = {0, 1, 0, -1};
int result;

deque<pair<int,int>> queue;

void InputData(){
	cin >> N;
	for (int i=0 ; i<N ; i++){
		cin >> X[i] >> Y[i];
	}
}

bool IsInside(int ny, int nx) {
    return (0 <= nx && 0 <= ny && nx <= 101 && ny <= 101);
}

void makeMap(){
    for(int i =0; i<N; i++){
        map[X[i]][Y[i]] = 1;
    }
}

void printMap(){
    // print
    for(int i =1; i<101; i++){
        for (int j = 1; j<101; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}

void floodfill(int x,int y){ 

    if (map[x][y] == 1) {
		result++;
		return;
	}
    else if (map[x][y] == 0) {
		for (int i = 0; i < 4; i++) {
        
            int nx = x+posX[i];
            int ny = y+posY[i];

            //밖으로 나갔을 때 무시
			if (!IsInside(nx, ny)) {
                continue;
            }
            map[x][y] = 2;
			floodfill(nx, ny);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();// 입력받는 부분
    makeMap();
    floodfill(0, 0);
	cout << result << "\n";// 출력하는 부분
	return 0;
}