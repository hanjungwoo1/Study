#include <iostream>
#include<deque>

using namespace std;
#define MAXN ((int)1e3)
int M, N;//상자의 가로, 세로 칸 수
int map[MAXN+10][MAXN+10];//토마토 정보
deque<pair<int,int>> rotten;
int max_value;


void InputData(){
	cin >> M >> N;
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			cin >> map[i][j];
		}
	}
}

bool IsInside(int ny, int nx) {
    return (0 <= nx && 0 <= ny && nx < M && ny < N);
}

void rotten_tomato(){
    for (int i=0; i<N; i++){
        for (int j =0; j<M; j++){
            if (map[i][j] == 1){
                rotten.push_back(make_pair(i,j));
            }
        }
    }
}

void show_map(){
    for (int i=0; i<N; i++){
        for (int j =0; j<M; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// any normal tomato return false
bool check_map(){
    for (int i=0; i<N; i++){
        for (int j =0; j<M; j++){
            if (map[i][j] == 0){
                return 0;
            }
        }
    }
    return 1;
}

void dfs(){

	int posX[4] = {-1, 0, 1, 0};
	int posY[4] = {0, 1, 0, -1};

    while(!rotten.empty()){

        int x = rotten.front().first;
    	int y = rotten.front().second;
        rotten.pop_front();

        for(int i = 0; i<4; i++){
            int nx = x + posX[i];
            int ny = y + posY[i];

            // cout << "candidate : " <<nx << ny << endl;
            if(IsInside(nx, ny) && map[nx][ny] >= 0){
                // cout << "result : " << nx << ny << endl;

                if (map[nx][ny] == 0){
                    map[nx][ny] = map[x][y] + 1;
                    if (map[nx][ny] > max_value){
                        max_value = map[nx][ny];
                    }
                    rotten.push_back(make_pair(nx,ny));
                }else if (map[nx][ny] > (map[x][y]+1)){
                    map[nx][ny] = map[x][y] + 1;

                    if (map[nx][ny] > max_value){
                        max_value = map[nx][ny];
                    }
                    rotten.push_back(make_pair(nx,ny));

                }
            }
        }
        show_map();
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	max_value = 0;
	InputData();//입력
    rotten_tomato();

    if(check_map()){
        cout << 0;
        return 0;
    }

    dfs();

    if(!check_map()){
        cout << -1;
        return 0;
    }


	cout << (max_value -1) << "\n";//출력
	return 0;
}



/*

6 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1

*/