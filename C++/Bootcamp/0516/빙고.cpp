#include <iostream>
using namespace std;

int A[5+10][5+10];
int B[25+10];
int bingo_count;

void InputData(){
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cin >> A[i][j];
        }
    }
    for (int i=0; i<25; i++){
        cin >> B[i];
    }
}

void mapping(int target){

    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if (A[i][j]==target){
                A[i][j] = 0;
                return;
            }
        }
    }
}

void checkBingo(int index){

    int bingo = 0;

    //row
    int count = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if (A[i][j] == 0){
                count += 1;
            }
        }
        if (count == 5){
            bingo += 1;
        } 
        count = 0;
    }

    //col
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if (A[j][i] == 0){
                count += 1;
            }
        }
        if (count == 5){
            //cout << "bingo" << endl;
            bingo += 1;
        } 
        count = 0;
    }

    count = 0;
    //digonal
    for(int i=0; i<5; i++){
        if(A[i][i]==0){
            count += 1;
        }
        if(count == 5){
            bingo += 1;
        }
    }

    count = 0;
    for(int i=0; i<5; i++){
        if(A[4-i][i]==0){
            count += 1;
        }
        if(count == 5){
            bingo += 1;
        }
    }
    bingo_count = bingo;
    //cout << "bingo count : " << bingo << " index : " << index << endl;
}


void printMap(){

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << A[i][j] << " " ;
        }
        cout << endl;
    }

}

int solve(){

    for (int i=0; i<25; i++){
        mapping(B[i]);
        checkBingo(i);
        printMap();
        cout << endl;
        if (bingo_count >= 3){
            return i+1;
        }
    }
    return 25;
}



int main(){
    int ans = -1;
    InputData();// 입력받는 부분

    ans = solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}

/*

11 12 2 24 10
16 1 13 3 25
6 20 5 21 17
19 4 8 14 9
22 15 7 23 18
5 10 7 16 2
4 22 8 17 13
3 18 1 6 25
12 19 23 14 21
11 24 9 20 15

*/