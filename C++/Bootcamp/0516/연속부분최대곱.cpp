#include <iostream>
#include <stdio.h>
#include <deque>
#include <algorithm>

using namespace std;

int N;
double D[10000+10];
deque<double> queue;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> D[i];
    }
}

void solve(){
    queue.push_back(D[0]);
    for(int i=1; i<N; i++){
        double result = max({D[i], queue[i-1] * D[i]});
        // cout << "result : " << result << endl;
        queue.push_back(result);
    }
}

int main(){
    double ans = -1;

    InputData();// 입력받는 부분

    solve();
    sort(queue.begin(), queue.end());

    printf("%.3lf\n", queue[queue.size()-1]);// 출력하는 부분
    return 0;
}