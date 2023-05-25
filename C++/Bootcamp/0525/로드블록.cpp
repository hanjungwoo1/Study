#include <iostream>
#include <deque>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int A[10000 + 10];
int B[10000 + 10];
int L[10000 + 10];
int route[105][105];
int visit[105][105];
int ans;

struct path{
    int pos;
    int dist;
    vector<pair<int, int>> pathVector;
};

void InputData(){
    cin >> N >> M;
    for (int i = 0; i<M; i++){
        cin >> A[i] >> B[i] >> L[i];
    }
}

void makeRoute(){
    for(int i =0; i<M; i++){
        route[A[i]][B[i]] = L[i];
        route[B[i]][A[i]] = L[i];
    }
}

// recursion 가능
int changeMap(int nx, int ny){
    route[nx][ny] = route[nx][ny] *2;
    route[ny][nx] = route[ny][nx] *2;

    fill(visit[0], visit[105], INT_MAX);
    int resultDistance = INT_MAX;
    deque<path> farmer;
    farmer.push_back({1,0, {}});

    while(!farmer.empty()){
        int nowPos = farmer.front().pos;
        int nowDistance = farmer.front().dist;
        farmer.pop_front();

        if (nowPos == N && nowDistance < resultDistance){
            resultDistance = nowDistance;   
            continue;
        }

        for(int i=1; i<101; i++){
            int newPos = i;
            int newDistance = nowDistance + route[nowPos][i];
            if (route[nowPos][i] !=0 && visit[nowPos][i] > newDistance){
                farmer.push_back({newPos, newDistance, {}});
                visit[nowPos][i] = newDistance;
            }
        }
    }
    route[nx][ny] = route[nx][ny]/2;
    route[ny][nx] = route[ny][nx]/2;
    return resultDistance;
}


void dfs(){
    fill(visit[0], visit[105], INT_MAX);
    int resultDistance = INT_MAX;
    vector<pair<int, int>> resultVector;
    deque<path> farmer;
    farmer.push_back({1,0, {}});

    while(!farmer.empty()){
        int nowPos = farmer.front().pos;
        int nowDistance = farmer.front().dist;
        vector<pair<int, int>> nowVector = farmer.front().pathVector;
        farmer.pop_front();

        if (nowPos == N && nowDistance < resultDistance){
            //cout << "END : " << nowDistance << endl;
            resultDistance = nowDistance;
            resultVector = nowVector;    
            continue;
        }

        for(int i=1; i<101; i++){
            int newPos = i;
            int newDistance = nowDistance + route[nowPos][i];
            vector<pair<int, int>> newVector = nowVector;
            if (route[nowPos][i] !=0 && visit[nowPos][i] > newDistance){
                //cout << "GO : " << i << " DIS : "<< route[nowPos][i] << endl;
                newVector.push_back({nowPos, i});
                farmer.push_back({newPos, newDistance, newVector});
                visit[nowPos][i] = newDistance;
            }
        }
    }

    for(int i = 0; i<resultVector.size(); i++){
        //cout << resultVector[i].first << " " << resultVector[i].second << endl;
        int result = changeMap(resultVector[i].first, resultVector[i].second);
        //cout << "INCREASE : " << result << endl; 
        ans = max(ans, result - resultDistance);
    }
}


int main(){
    InputData();// 입력받는 부분
    makeRoute();

    dfs();

    cout << ans << endl;// 출력하는 부분
    return 0;
}

/*

5 7
2 1 5
1 3 1
3 2 8
3 5 7
3 4 3
2 4 7
4 5 2
*/