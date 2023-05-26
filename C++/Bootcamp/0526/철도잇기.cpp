#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

#define MAXN (50)
int N, M, K;//철도역수, 철도수, 추가로 연결시킬수있는 철도수
int S[MAXN + 10];
int E[MAXN + 10];
int map[MAXN + 10][MAXN + 10];
int visit[MAXN + 10];
deque<int> result;


void InputData() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> S[i] >> E[i];
        map[S[i]][E[i]] = 1;
        map[E[i]][S[i]] = 1;
    }
}

void printMap(){
    for(int i = 1; i<N+1; i++){
        for(int j =1; j<N+1; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}

void printVisit(){
    for(int i = 1; i<N+1; i++){
            cout << visit[i] << " ";
    }
    cout << endl;
}

void dfs(int start){

    deque<int> queue;
    queue.push_back(start);
    visit[start] = 1;
    int area = 1;

    while(!queue.empty()){
        int now = queue.front();
        queue.pop_front();

        for(int i=1; i<N+1; i++){
            int next = i;

            //cout << "NOW : " << now << " NEXT : " << next << endl;
            if (map[now][next] != 0 && visit[next] == 0){
                //cout << "NEW : " << next << endl; 
                visit[next] = 1;
                area += 1;
                queue.push_back(next);
            }
        }
    }
    // cout << "area : " << area << endl;
    // printVisit();
    result.push_back(area);
}

bool compare(int x, int y){
    return x>y;
}

void solve(){


    for(int i =1; i<N+1; i++){
        if (visit[i] == 0){
            dfs(i);
        }
    }

    sort(result.begin(), result.end(), compare);
    int ans = 0;

    for(int j=0; j<K+1; j++){
        ans += result[j];
    }
    cout << ans << endl;
}


int main() {

    InputData();//입력받는 부분
    //printMap();
    //printVisit();
    solve();

    return 0;
}