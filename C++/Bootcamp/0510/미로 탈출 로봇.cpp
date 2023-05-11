#include<iostream>
#include<vector>
#include<deque>
#include<utility>

using namespace std;

#define MAXN (100)
int W, H;//가로, 세로 크기
int sw, sh, ew, eh;//출발 가로세로, 도착 가로세로 좌표
char map[MAXN+10][MAXN+10];//지도정보
int visit[MAXN+10][MAXN+10];

void InputData(){
	cin >> W >> H;
	cin >> sw >> sh >> ew >> eh;
	for (int i=1; i<=H; i++){
		cin >> &map[i][1];
	}
}

bool IsInside(int ny, int nx) {
    return (0 < nx && 0 < ny && nx <= W && ny <= H);
}

void bfs(){
	deque< pair<int, int>> queue;
	int posX[4] = {-1, 0, 1, 0};
	int posY[4] = {0, 1, 0, -1};

	queue.push_back(make_pair(sh, sw));

	while (!queue.empty()){
		int x = queue.front().first;
		int y = queue.front().second;
		queue.pop_front();

		int cost = visit[x][y];

		for(int i = 0; i<4; i++){
			int nx = x + posX[i];
			int ny = y + posY[i];

			if (IsInside(nx, ny) && map[nx][ny]=='0' && visit[nx][ny] == 0){
				visit[nx][ny] = cost + 1;
				queue.push_back(make_pair(nx, ny));
			}
		}	
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력

	visit[sh][sw] = 1;
	bfs();

	// for (int i = 1; i < 10; i++){
	// 	for (int j = 1; j < 10; j++)
	// 	{
	// 		cout << map[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }


	// for (int i = 1; i < 10; i++){
	// 	for (int j = 1; j < 10; j++)
	// 	{
	// 		cout << visit[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	ans = visit[eh][ew]-1;
	cout << ans;
	return 0;
}

/*

8 7
1 2 7 5
11111111
00000111
10110011
10111001
10111101
10000001
11111111

*/
