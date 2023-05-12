#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

#define MAXN (25)
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

void printMap(){
    cout << "print Map " << endl;
    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            cout << map[i][j] << " " ;
        } 
        cout << endl;    
    }
}


void FloodFill(int x, int y){
    if (map[x][y] != '1'){
        return;
    }
 
    map[x][y]='2';
 
    for (int i=0; i<8; i++){
        FloodFill(x+posX[i], y+posY[i]);
    }
}

int start(){
    int count = 0;
    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            if (map[i][j] == '1'){ // start
                FloodFill(i, j);
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

    int result = start();
    cout << result << endl;

	return 0;
}