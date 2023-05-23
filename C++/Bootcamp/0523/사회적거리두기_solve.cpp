#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
#define MAXNM ((int)1e5)
int N, M;//소마리수, 잔디구간 개수
long long A[MAXNM+10];//잔디 구간 시작
long long B[MAXNM+10];//잔디 구간 끝
long long ans = -1;

void InputData(){
	cin >> N >> M;
	for (int i=0 ; i<M ; i++){
		cin >> A[i] >> B[i];
	}
}

int isPossible(long long range){
    int cow = 1;
    long long start = A[0];
    long long wantPos;
    int index = 0;
    while(true){
        if (index >= M){
            break;
        }
        wantPos = start+range;
        if(A[index] <= wantPos && wantPos <= B[index]){
            cow += 1;
            start = wantPos;
        }else{ 
            index += 1;
            if (A[index] >= wantPos){
                cow += 1;
                start = A[index];
            }
        }
    }

    if (cow >= N){
        ans = max(ans, range);
        return 1;
    }
    return 0;
}

void binarySearch(){
    long long start = 1;
    long long end = pow(10, 18);
    long long middle;
    while (start <= end){
        middle = (start + end) /2;
        int result = isPossible(middle);

        if (result == 1){
            start = middle+1;
        }else{
            end = middle -1;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();// 입력받는 부분

    sort(A, A+M);
    sort(B, B+M);

    binarySearch();

    //isPossible(2);
	// 여기서부터 작성

	cout << ans << "\n";// 출력하는 부분
	return 0;
}


/*
6 4
0 2
4 6
8 8
9 11

2
*/


/*
5 3
0 2
4 7
9 9

2
*/