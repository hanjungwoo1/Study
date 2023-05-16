#include <iostream>
#include <deque>
using namespace std;

#define MAXN ((int)1e3)
int N;
deque<int> queue;

void InputData(){
    cin >> N;
}

int check(int num){
    for(int i=0; i<queue.size(); i++){
        if (queue[i] == num){
            return 1;
        }
    }
    return 0;
}

int make_sqaure(int num){

    int result = 0;
    string str_data = to_string(num);

    for(auto data : str_data){
        int num = data-'0';
        result += num*num;
    }   
    return result;
}

void is_happy(int num){

    int start_num = num;
    while(start_num!=1){
        // loop
        if(check(start_num)==1){
            //cout << "broke loop " << endl;
            //cout << endl;
            num -= 1;
            start_num = num;
            queue.erase(queue.begin(), queue.end());
        }
        queue.push_back(start_num);
        start_num = make_sqaure(start_num);
        //cout << "num : " << start_num << endl;
    }
}


int main(){
    int ans = -1;
    InputData();//입력받는 부분

    is_happy(N);

    for(int i=0; i<queue.size(); i++){
        if (queue[i] > ans && queue[i] <= N){
            ans = queue[i];
        }
    }

    cout << ans << endl;//출력하는 부분
    return 0;
}