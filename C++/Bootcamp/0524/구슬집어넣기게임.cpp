#include <iostream>
#include <deque>

using namespace std;
#define MAXN (15)
int R, C;//게임판 행(세로), 열(가로) 크기
char map[MAXN+5][MAXN+5];//게임판('#':벽, '.':빈공간, 'R':빨간구슬, 'B':파란구슬, 'H':목표구멍)

int hx;
int hy;

struct marbles{
    int rx; // redx
    int ry; // redy
    int bx; // bluex
    int by; // bluey
    int time;
};

void InputData(){
	cin >> R >> C;
	for (int i=0; i<R; i++){
		cin >> map[i];
	}
}

void printMap(){

    cout << "PRINT MAP" << endl;

    for(int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

marbles findMarbles(){

    int redX;
    int redY;
    int blueX;
    int blueY;

    for(int i =0; i<R; i++){
        for(int j=0; j<C; j++){
            if (map[i][j] == 'R'){
                redX = i;
                redY = j;
            }

            if (map[i][j]=='B'){
                blueX = i;
                blueY = j;
            }

            if (map[i][j]=='H'){
                hx = i;
                hy = j;
            }
        }
    }
    //cout << "RED : " << redX << " " << redY << " BLUE : " << blueX << " " << blueY << endl;
    marbles temp = {redX, redY, blueX, blueY};
    return temp;
}

int xPos[4] = {0, 0, 1, -1};
int yPos[4] = {1, -1, 0, 0};

int BFS(marbles &startMarbles){

    deque<marbles> queue;
    int ans = 99;
    queue.push_back(startMarbles);

    while(!queue.empty()){

        marbles now = queue.front();
        queue.pop_front();

        //cout <<"RED : "  << now.rx << " " << now.ry << " BLUE : " << now.bx << " " << now.by << " " << " TIME : " << now.time << endl;

        for(int i =0; i<4;i++){
            int newrx = now.rx+xPos[i];
            int newry = now.ry+yPos[i];
            int newbx = now.bx+xPos[i];
            int newby = now.by+yPos[i]; 
            int newTime = now.time + 1;

            if (newTime > 10){
                continue; // skip when over 10 times, 0~9 is true
            }

            if (newbx == hx && newby == hy){ // BLUE HOLE
                continue;
            }

            if (newrx == newbx && newry == newby){ // encounter each marbles
                continue; 
            }

            if (newrx == hx && newry == hy){ // RED HOLE
                //cout << "SUCCESS!" << endl;
                ans = min(ans, newTime);
                continue;
            }

            if (map[newrx][newry]=='#'){ // RED encounter wall, stay
                newrx = now.rx;
                newry = now.ry;
                //cout << "WALL" << endl;
            }
            if (map[newbx][newby]=='#'){ // BLUE encounter wall, stay
                newbx = now.bx;
                newby = now.by;
                //cout << "WALL" << endl;
            }

            marbles temp = {newrx, newry, newbx, newby, newTime};
            queue.push_back(temp);
        }

    }
    //cout << "ANS : " << ans << endl;
    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, ans=-10;
	cin >> T;
	for (int i=0; i<T; i++){
		InputData();//입력

        //printMap();
        marbles startItem = findMarbles();
        ans = BFS(startItem);
        if (ans == 99) ans = -1;
		//여기서부터 작성

		cout << ans << "\n";//출력
	}
	return 0;
}