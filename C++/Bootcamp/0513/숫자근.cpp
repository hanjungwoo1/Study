#include <iostream>
#include <string> 
#include <deque>
#include <algorithm>

using namespace std;
#define MAXN ((int)1e3)

int N;//정수개수
int A[MAXN + 10];//입력 정수
deque<pair<int,int>> queue;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
}

int makeNum(int num){
    while(1){

        string start_str = to_string(num);
        int sum=0;

        for(const auto data : start_str){
            sum += data - '0';
        }

        // cout << "Num : " << num << " sum : " << sum << endl;

        num = sum;

        if (to_string(num).size() == 1){
            break;
        }

    }
    return num;
}


bool comp(pair<int, int> left, pair<int, int> right)
{
    if (left.first > right.first)
    {
        return true;
    }    
    else
    {
        if (left.first == right.first && left.second < right.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
        
}

void solve(){
    for(int i=0; i<N; i++){
        int result = makeNum(A[i]);
        queue.push_back({result, A[i]});
    }
}


int main(){
    int ans = -1;
    InputData();//입력 받는 부분

    solve();

    // for(int i=0; i<queue.size(); i++){
    //     cout << queue[i].first << " " << queue[i].second << endl;
    // }

    sort(queue.begin(), queue.end(), comp);
    // cout << "sorting ~" << endl;


    // for(int i=0; i<queue.size(); i++){
    //     cout << queue[i].first << " " << queue[i].second << endl;
    // }

    cout << queue[0].second << endl;//출력하는 부분
    return 0;
}