#include <iostream>
#include <deque>
using namespace std;

char str[100000+10];
deque<char> queue;

void InputData(){
    cin >> str;
}

int solve(){

    int count = 0;
    for(int i=0; i<100000+10; i++){
        char temp = str[i];
        if (temp =='\0'){
            break;
        }
    
        if (temp == '('){ // (
            queue.push_back(temp);
            //cout << "push left " << endl;
        }else{  // )
            
            if (queue.size() >0 && queue[queue.size()-1] == '(') {
                // 큐에 있으며 합이 맞을때
                queue.pop_back();

                //cout << "pop equal " << endl;
            }else{
                //cout << "count !" << endl;
                // 비어 있을 때
                count += 1;
                queue.push_back('(');
            }
        }
    }
//    cout << "count : " << count << endl;

    // for(int j = 0; j<queue.size(); j++){
    //     cout << queue[j] << " ";
    // }

    return count + (queue.size() /2);
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성

    ans = solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}