#include <iostream>
#include <deque>

using namespace std;
#define MAXN (50)
int R, C;//지도 세로, 가로 크기
char map[MAXN+10][MAXN+10];

void InputData(){
    cin >> R >> C;
    for (int i=0; i<R; i++){
        cin >> map[i];
    }
}

bool IsInside(int nx, int ny) {
    return (0 <= nx && 0 <= ny && nx < R && ny < C);
}

void printMap(){

    cout << "PRINT MAP " << endl;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}




int dfs(){


    deque<pair<int, int>> artist;
    deque<pair<int, int>> flood;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if (map[i][j] == 'S'){
                artist.push_back({i, j});
            }
            if (map[i][j] == '*'){
                flood.push_back({i, j});
            }
        }
    }

    deque<pair<int, int>> artist_temp;
    deque<pair<int, int>> flood_temp;

    int xPos[4] = {0, 0, 1, -1};
    int yPos[4] = {1, -1, 0, 0};
    int flag = 1;

    while(flag>0){

        // 홍수 진행
        while(!flood.empty()){
            int fx = flood.front().first;
            int fy = flood.front().second;
            flood.pop_front();

            for(int i = 0; i<4; i++){
                int nfx = fx + xPos[i];
                int nfy = fy + yPos[i];
                if(IsInside(nfx, nfy) && map[nfx][nfy] == '.'){
                    map[nfx][nfy] = '*';
                    flood_temp.push_back({nfx, nfy});
                }
            }
        }

        // 다음 홍수 준비, 리셋
        flood = flood_temp;
        flood_temp.clear();

        // 화가 탐색 진행
        while(!artist.empty()){
            int ax = artist.front().first;
            int ay = artist.front().second;
            artist.pop_front();
            map[ax][ay] = 'v';

            for(int i = 0; i<4; i++){
                int nax = ax + xPos[i];
                int nay = ay + yPos[i];

                if (map[nax][nay] == 'D'){
                    return flag;
                }

                if(IsInside(nax, nay) && map[nax][nay] == '.' && map[nax][nay] != 'v'){
                    map[nax][nay] = 'v';
                    artist_temp.push_back({nax, nay});
                }
            }
        }

        // 다음 화가 준비, 리셋
        artist = artist_temp;
        artist_temp.clear();

        if (artist.empty()){
            cout << "KAK" << endl;
            return -1;
        }

        flag += 1;
        //printMap();
    }




    return 0;
}


int main(){
    int T, ans = -1;
    scanf("%d", &T);
    for (int t=1; t<=T; t++){
        InputData();//입력 받는 부분
        // 여기서부터 작성 
        ans = dfs();
        if (ans == -1) cout << "KAKTUS" << endl;//출력 하는 부분
        else cout << ans << endl;
    }
    return 0;
}