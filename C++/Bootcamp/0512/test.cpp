#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
 
int N;
int map[100 + 10][100 + 10];
int sol{ 0 };
 
void input() {
	cin >> N;
	int tempx;
	int tempy;
	for (int i = 0; i < N; i++) {
		cin >> tempx >> tempy;
		map[tempy][tempx] = 1;
	}
}
 
void floodFill(int i, int j) {
 
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1,-1,0,0 };
    
    // 건초를 발견하면 갯수 +1 해주고 돌아감.
	if (map[i][j] == 1) {
		sol++;
		return;
	}
    
    // 방문 안하고, 비어있는 0일 때
	else if (map[i][j] == 0) {
 
		//4방향 반복
		for (int ii = 0; ii < 4; ii++) {
        
            //밖으로 나갔을 때 무시
			if (((i + dy[ii]) == -1) or (i + dy[ii] == 102)
				or (j + dx[ii] == -1) or (j + dx[ii] == 102)) continue;
 
            // 0일 때 확산 해야 하므로, 방문표시는 다른 숫자인 2로 해준다.
			map[i][j] = 2;
            
            //들렀다는 방문 표시 후 추가 확산
			floodFill(i + dy[ii], j + dx[ii]);
		}
	}
 
}
 
int main() {
	input();
    memset(map,0,sizeof(map));
 
    // 0,0은 무조건 빈 부분이므로 여기서부터 시작
	floodFill(0, 0);
 
	cout << sol;
 
	return 0;
}