#include <iostream>
using namespace std;

char str[100000+10];
int global_size; 
int flag;
int ans;


void InputData(){
    cin >> str;
}

int solve(){
    int count = 0;
    int left = 0;
    int right = 0;
    for(int i = 0; i<100000+10 ; i++){
        if (str[i] == '(' || str[i] == ')'){
            count += 1;
        }else{
            break;
        }
    }
    global_size = count;

    int left_count = 0;
    int right_count = 0;
    for(int i =0; i<global_size; i++){
        if (str[i] == '(') left++;
        else {
            left--;
            left_count ++;
        }

        if (str[global_size-i-1] == ')') right++;
        else{
            right --;
            right_count ++;
        }    

        if (left<0) return left_count;
        if (right<0) return right_count;
    }

    return 0;
}

int main(){

    InputData();// 입력받는 부분
    ans = solve();
    cout << ans << endl;

    return 0;
}

/*

()
(())
()(()())

*/