#include <iostream>
#include <map>
#include <deque>
#include <climits>

using namespace std;

int P;
char N1[10000+10];
char N2[10000+10];
int L[10000+10];
char farm;
int sol;

int route[55][55];
int visit[55][55];

struct cow{
    int name;
    int pos;
    int distance;
};

deque<cow> cow_queue; // 위치, 시간

void InputData(){
    cin >> P;
    for (int i=0; i<P; i++){
        cin >> N1[i] >> N2[i] >> L[i];
    }
}

void makeRoute(){

    for(int i=0; i<P; i++){
        int left =N1[i];
        int right = N2[i];
        // a-z
        if (97<=left && left <=122){
            left -= 97;
            //cout << N1[i] << " " << left << endl;
        }
        // A-Z, COW
        if (65<=left && left <= 90){
            left -=39;
            if (left!=51) cow_queue.push_back({left, left, 0});
            //cout << N1[i] << " " << left << endl;
        }
        // a-z
        if (97<=right && right <=122){
            right -= 97;
            //cout << N2[i] << " " << right << endl;
        }
        // A-Z, COW
        if (65<=right && right <= 90){
            right -=39;
            if (right!=51) cow_queue.push_back({right, right, 0});
            //cout << N2[i] << " " << right << endl;
        }
        // make route map

        if (route[left][right] == 0){
            route[left][right] = L[i];
            route[right][left] = L[i];
        }else{
            route[left][right] = min(L[i], route[left][right]);
            route[right][left] = min(L[i], route[left][right]);
        }
        
    }
}

void dfs(){
    int resultDistance = INT_MAX;
    int resultName;

    while(!cow_queue.empty()){
        int nowName = cow_queue.front().name;
        int nowPos = cow_queue.front().pos;
        int nowDistance = cow_queue.front().distance;
        cow_queue.pop_front();
        //cout << "NAME : " << nowName << " POS : " << nowPos << " DIS : " << nowDistance << endl;

        if (nowDistance > resultDistance) continue;

        if (nowPos == 51 && resultDistance > nowDistance){
            //cout << " SUCCESS : " << nowDistance  << endl;
            resultName = nowName;
            resultDistance = nowDistance;
            continue;
        }

        for(int i = 0; i<52; i++){
            int newPos = i;
            int newDistance = nowDistance + route[nowPos][i];
            if (route[nowPos][i]!=0 && visit[nowPos][i] > newDistance){
                visit[nowPos][newPos] = newDistance; 
                cow_queue.push_back({nowName, newPos, newDistance});
            }
        }
    }

    if (26<=resultName && resultName <= 50){
        resultName += 39;
    }
    char answer = resultName;
    farm = resultName;
    sol = resultDistance;

    //cout << answer << " " << resultDistance;
}

int main(){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    makeRoute();

    fill(visit[0], visit[55], INT_MAX);
    dfs();

    cout << farm << " " << sol << endl;// 출력하는 부분
    return 0;
}

/*
5
A d 6
B d 3
C e 9
d Z 8
e Z 3
*/