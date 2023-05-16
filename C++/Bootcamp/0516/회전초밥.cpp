#include <iostream>
#include<algorithm>
#include<deque>


using namespace std;

int N, D, K, C;
int A[3000000+10];
int visited[3010];
int flag = 0; // 쿠폰초밥 없으면 0, count를 1올려
deque<int> queue;

void InputData(){
    cin >> N >> D >> K >> C;
    for (int i=0; i<N ; i++){
        cin >> A[i];
    }
}

void checkFlag(){
    for(int i=0; i<N; i++){
        if (A[i] == C){
            flag = 1;
            return;
        } 
    }
}

void printDeque(){
    for(int i=0; i<queue.size(); i++){
        cout << queue[i] << " ";
    }
    cout << endl;
}

int insertVisit(int count, int number){

    if (visited[number] == 0){
        count += 1;
    }
    visited[number] += 1;
    return count;
}

int extractVisit(int count, int number){

    visited[number] -=1;
    if (visited[number] == 0){
        count -= 1;
    }

    return count;
}

int checkQueue(){
    for(int i=0; i<queue.size(); i++){
        if (queue[i] == C){
            return 1;
        }
    }
    return 0;
}

int solve(){
    int input_num;
    int output_num;
    int result = 0;
    int count = 0;
    for(int i=0; i<N+K; i++){
        input_num = A[i%N];

        queue.push_back(input_num);
        count = insertVisit(count, input_num);
   
        if(queue.size()==K){
            
            if(visited[C] == 0){
                result = max(result, count+1);
            }else{
                result = max(result, count);
            }
            output_num = queue[0];
            queue.pop_front();
            count = extractVisit(count, output_num);
        }
    }
    return result;
}


int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    ans = solve();

    cout <<  ans << endl;// 출력하는 부분
    return 0;
}