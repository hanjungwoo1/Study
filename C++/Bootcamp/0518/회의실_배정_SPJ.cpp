#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int ID[500+10];
int S[500+10];
int E[500+10];
int sol[500+10];

struct node{

    int start;
    int end;
    int num;

    node(int x, int y, int z){
        start = x;
        end = y;
        num = z;
    }
};

bool cmp(const node & a, const node & b)
{
    if (a.end < b.end) return true; 
    return false;
}

int idx = 1;
int cnt = 1;
vector<node> myVec;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> ID[i] >> S[i] >> E[i];
    }
}

void OutputData(int ans){
    cout << ans << endl;
    for (int i=0; i<ans; i++){
        cout << sol[i] << " ";
    }
    cout << endl;
}

void makeSet(){
    for(int i =0; i<N; i++){
        myVec.push_back(node(S[i], E[i], ID[i]));
    }
}

void solve(){

    sort(myVec.begin(), myVec.end(), cmp);


    int time = myVec[0].end;
    sol[0] = myVec[0].num;

    for(int i=1; i<myVec.size(); i++){
//        cout << myVec[i].start << " " << myVec[i].end << " " << myVec[i].num << " " << endl;
        if(myVec[i].start >= time){
            time = myVec[i].end;
            sol[idx] = myVec[i].num;
            idx += 1;
            cnt += 1;
        }
    }
}

int main(){
    InputData();// 입력받는 부분
    makeSet();

    solve();  

    OutputData(cnt);// 출력하는 부분
    return 0;
}