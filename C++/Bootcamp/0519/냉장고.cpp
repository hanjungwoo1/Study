#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

struct Temp{
    int start;
    int end;
};

int N;
int X[100+10];
int Y[100+10];
Temp datas[110];

deque<pair<int,int>> queue;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> datas[i].start >> datas[i].end;
    }
}

bool comp(Temp &a,Temp &b){
    if (a.start < b.start) return true;
    if (a.start == b.start){
        if (a.end < b.end) {
            return true;
        }
    }
    return false;
} 

void solve(){

    int total = 1;
    queue.push_back({datas[0].start, datas[0].end});
    int start;
    int end;

    for(int i = 1; i<N; i++){
        //cout << "start : " << X[i] << " end : " << Y[i] << endl;

        int size = queue.size();
        for(int j = 0; j<queue.size(); j++){
            
            start = queue[0].first;
            end = queue[0].second;
            queue.pop_front();
            //cout << "checking : " << start << "  "  << end << endl;

            //update
            if (end >= datas[i].start){
                int new_start = max(datas[i].start, start);
                int new_end = min(datas[i].end, end);
                //cout << "update push ! : " << new_start << " " << new_end << endl;
                queue.push_back({new_start, new_end});
                break;
            }
            //not update, push origin
            queue.push_back({start, end});

            //noting to do, so push new_data
            if (j == size-1){
                //cout << " new one " << endl;
                queue.push_back({datas[i].start, datas[i].end});
                break;
            }
        }
    }
}

int main(){
    InputData();// 입력받는 부분

    sort(datas, datas+N, comp);

    solve();
    cout << queue.size() << endl;// 출력하는 부분
    return 0;
}
