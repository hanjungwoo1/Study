#include <iostream>
#include <set>

using namespace std;

int N;
int A[100+10];
int B[100+10];
int map[105][105];

set<pair<int, int>> area;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i] >> B[i];
    }
}

void printMap(){

    for (int x = 0; x < 103; x++) {
        for (int y = 0; y < 103; y++){
                
                cout << map[x][y];
            }
            cout << endl;
        }
}

// int posx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
// int posy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int posx[4] = {1, 0, -1, 0};
int posy[4] = {0, 1, 0, -1};

int countMap(){

    int count = 0;
    for (int x = 0; x < 103; x++) {
        for (int y = 0; y < 103; y++){
                
            if(map[x][y]==1){
                
                for(int i=0; i<4; i++){
                    int nx = x+posx[i];
                    int ny = y+posy[i];

                    if (map[nx][ny] == 0 || nx<0 || ny<0){
                        count += 1;
                        map[x][y] = 2;
                        continue;
                    }

                }
            }         
        }   
    }
    return count;
}

int solve(){

    for(int i = 0; i<N; i++){
        // cout << "Square : " << A[i] << " " << B[i] << endl;;

        for (int x = A[i]; x < A[i] + 10; x++) {
            for (int y = B[i]; y < B[i]+10; y++){
                // cout << x << "," << y << endl;
                // area.insert({x,y});
                map[x][y] = 1;
            }
            // cout << endl;
        }
    }
    //printMap();
    int result = countMap();
    //cout << "result : " << result << endl;
    //printMap();
    return result;
}




int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    ans = solve();
    // 여기서부터 작성

    cout << ans << endl;// 출력하는 부분
    return 0;
}