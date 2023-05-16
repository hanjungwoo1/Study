#include <iostream>
#include <deque>

using namespace std;

int N, P;
deque<int> queue;

void InputData(){
    cin >> N >> P;
}

int check(int num){
    for(int i=0; i<queue.size(); i++){
        if (queue[i] == num){
            return i+1;
        }
    }
    return 0;
}

int solve(){
    int temp = N;
    int index = 0;
    while(1){
        temp = temp * N;
        temp %= P;
        //cout << "Temp : " << temp << endl;
        index = check(temp);

        if (index!=0){
            break;
        }
        queue.push_back(temp);
    }
    return index;
}

int main(){
    InputData();// 입력받는 부분

    int index = solve();

    cout << queue.size() - index + 1 << endl;// 출력하는 부분
    return 0;
}