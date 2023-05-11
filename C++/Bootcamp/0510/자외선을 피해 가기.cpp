#include <iostream>
#include <deque>

using namespace std;
#define MAXN (100)
#define INF (1<<30)

int N;//가로, 세로 크기
char map[MAXN+10][MAXN+10];//지도정보
int dp[MAXN+10][MAXN+10];//지도정보
deque<pair<int,int>> path;
int result;


void InputData(){
	cin >> N;
	for (int i=1; i<=N; i++){
		cin >> &map[i][1];
	}
}

bool IsInside(int ny, int nx) {
    return (0 < nx && 0 < ny && nx <= N && ny <= N);
}

void show_map(){
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            cout << map[i][j];
        }
        cout << endl;
	}
}

void show_dp(){

    cout << endl;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            cout << dp[i][j];
        }
        cout << endl;
	}
    cout << endl;
}

void dfs(){
	int posX[4] = {-1, 0, 1, 0};
	int posY[4] = {0, 1, 0, -1};

    path.push_back(make_pair(1,1));
    dp[1][1] = map[1][1]-'0';

    while(!path.empty()){

        int x = path.front().first;
    	int y = path.front().second;
        path.pop_front();

        for(int i = 0; i<4; i++){
            int nx = x + posX[i];
            int ny = y + posY[i];

            if(IsInside(nx, ny)){
                //cout << nx << ny << endl;

                // when dp is empty -> update
                if (dp[nx][ny] == 0){
                    dp[nx][ny] = dp[x][y] + map[nx][ny]-'0';
                    path.push_back(make_pair(nx, ny));
                }else{
                    int temp = dp[x][y] + map[nx][ny]-'0';

                    if (temp < dp[nx][ny]){
                        dp[nx][ny] = temp;
                        path.push_back(make_pair(nx, ny));
                    }
                }
            }            
        }    
        //show_dp();
    }
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	result = INF;
	InputData();//입력

    dfs();

	cout << dp[N][N] << "\n";//출력
	return 0;
}


/*

3
041
253
620

*/