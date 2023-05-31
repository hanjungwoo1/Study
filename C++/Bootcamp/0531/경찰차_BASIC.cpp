#include <iostream>
#include <climits>
using namespace std;
#define MAXW (20)
int N;//도로의 개수
int W;//사건의 개수
struct POS{
	int r, c;//세로, 가로
};
POS pos[MAXW+10];//사건 좌표

int FirstX=1;
int FirstY=1;
int SecondX;
int SecondY;
int Result = INT_MAX;

void InputData() {
	cin >> N;
	cin >> W;
	for (int i=0; i<W; i++){
		cin >> pos[i].r >> pos[i].c;
	}
}

void dfs(int index, int distance, string path){

    if( Result < distance){
        return;
    }

    if (index == W){
        //cout << "DIST : " << distance << " PATH : " << path << endl;
        Result = min(Result, distance);
        return ;
    }

    int newDistance;

    // First;
    int fxTemp = FirstX;
    int fyTemp = FirstY;
    FirstX = pos[index].r;
    FirstY = pos[index].c;
    newDistance = abs(fxTemp - FirstX) + abs(fyTemp - FirstY);
    dfs(index+1, distance+newDistance, path + "F");
    FirstX = fxTemp;
    FirstY = fyTemp;

    // Second;
    int sxTemp = SecondX;
    int syTemp = SecondY;
    SecondX = pos[index].r;
    SecondY = pos[index].c;
    newDistance = abs(sxTemp - SecondX) + abs(syTemp - SecondY);
    dfs(index+1, distance+newDistance, path + "S");
    SecondX = sxTemp;
    SecondY = syTemp;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력받는 부분

	//여기서부터 작성
    SecondX = N;
    SecondY = N;

    dfs(0, 0, "");


	cout << Result << "\n";//출력하는 부분
	return 0;
}