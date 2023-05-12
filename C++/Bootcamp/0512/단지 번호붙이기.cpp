#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

#define MAXN (25)
int N;
char map[MAXN+10][MAXN+10];
int check[MAXN+10][MAXN+10];
int posX[4] = {-1, 0, 1, 0};
int posY[4] = {0, 1, 0, -1};

deque<int> houses;
deque<pair<int, int>> queue;


void InputData(){
	cin >> N;
	for (int i=1; i<=N; i++){
		cin >> &map[i][1];
	}
}

void makeMap(){
    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
                check[i][j] = 0;
        }     
    }
}

bool IsInside(int ny, int nx) {
    return (0 < nx && 0 < ny && nx <= N && ny <= N);
}

void printMap(){

    cout << "print Map " << endl;
    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            cout << check[i][j] << " " ;
        } 
        cout << endl;    
    }
}

void floodfill(int i,int j){
    queue.push_back({i, j});
    check[i][j] = 1;
    
    int count =0;
    while(!queue.empty()){
        
        count +=1;

        int x = queue.front().first;
        int y = queue.front().second;

        //cout << "processing : " << x << " " << y << endl;

        queue.pop_front();
    
        for(int i = 0; i<4; i++){
			int nx = x + posX[i];
			int ny = y + posY[i];

			if (IsInside(nx, ny) && map[nx][ny]=='1' && check[nx][ny] == 0){
				queue.push_back({nx, ny});
                check[nx][ny] = 1;
			}
		}	
    }

    houses.push_back(count);

    //cout << "housed : " << count << endl;
}

int start(){
    int count = 0;
    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            if (map[i][j] == '1' && check[i][j] == 0){ // start

                //cout << " i, j : " << i << j << " start"<< endl;
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

    int result = start();
    cout << result << endl;

    sort(houses.begin(), houses.end());

    for(const auto data: houses){
        cout << data << endl;
    }
	return 0;
}