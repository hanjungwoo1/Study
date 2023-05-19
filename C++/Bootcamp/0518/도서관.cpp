#include <iostream>
#include <vector>
#include <utility>
#include<algorithm>

using namespace std;

int N;
int S[10000+10];
int E[10000+10];
int present = 0;
int absent = 0;

vector<pair<int, int>> myVec;

void InputData(void){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> S[i] >> E[i];

        myVec.push_back({S[i], E[i]});
    }
}

bool comp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second < b.second) return true;
    return false;
}

void solve(){

    int start = myVec[0].first;
    int end = myVec[0].second;
    //cout << "start func" << endl;

    for (int i =1; i<myVec.size(); i++){
        //cout << myVec[i].first << " " << myVec[i].second << endl;

        if (myVec[i].first <= end){
            end = max(end, myVec[i].second);
            present = max(present, end-start);
        }else{
            absent = max(absent, myVec[i].first-end);
            start = myVec[i].first;
            end = myVec[i].second;
        }

        //cout << start << " " << end << endl; 
    }
}

int main(void){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    sort(myVec.begin(), myVec.end());

    solve();


    cout << present << " " << absent << endl;// 출력하는 부분
    return 0;
}