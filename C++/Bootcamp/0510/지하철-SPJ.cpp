#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
#define MAXN (100)
#define INF (1e9)
 
int N, M;
int S[MAXN+2][MAXN+2];
int dist[MAXN+2]; 
int pre[MAXN+2]; 
 
void InputData(){
    cin >> N >> M;
    for (int s=1; s<=N; s++){
        for (int e=1; e<=N; e++){
            cin >> S[s][e];
        }
    }
}
 
void dfs(int start){
    vector<int> visit(N+1, 0); 
    fill(dist, dist+N+1, INF); 
    fill(pre, pre+N+1, 0); 
    dist[start] = 0; 
 
    for (int i=1; i<=N; i++){
        int u = 0;
        for (int j=1; j<=N; j++){
            if (!visit[j] && (u == 0 || dist[u] > dist[j])) 
                u = j;
        }
         
        visit[u] = 1;
 
        for (int v=1; v<=N; v++){
            if (dist[v] > dist[u] + S[u][v]){ 
                dist[v] = dist[u] + S[u][v];
                pre[v] = u;
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData();
 
    dfs(1); 
 
    cout << dist[M] << '\n';
    vector<int> path; 
    int p = M;
    while (p != 0){
        path.push_back(p);
        p = pre[p];
    }
 
    reverse(path.begin(), path.end()); 
     
    for (int i=0; i<path.size(); i++){
        cout << path[i] << ' ';
    }
    cout << '\n';
    return 0;
}