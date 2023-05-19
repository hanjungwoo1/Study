#include <iostream>
using namespace std;

char str[100000+10];
int global_size; 
int flag;

void InputData(){
    cin >> str;
}

void getSize(){
    int count = 0;
    for(int i = 0; i<100000+10 ; i++){
        if (str[i] == '(' || str[i] == ')'){
            count += 1;
        }else{
            break;
        }
    }
    global_size = count;
}

int isCorrect(){
    int count = 0;
    for(int i = 0; i<global_size; i++){
        if (count <0){
            //cout << "fail~ negative" << endl;
            return -1; // 음수 에러
        }
        if (str[i] == '('){
            count += 1;
            continue;
        } 
        if (str[i] == ')'){
            count -= 1;
            continue;
        }
    }
    if (count == 0){
        //cout << "correcto~!" << endl;
        return 1;
    }else if (count > 0){
        //cout << "fail~ positive" << endl;
        return 0; // 양수 에러
    }else{
        //cout << "fail~ negative" << endl;
        return -1; // 음수 에러
    }
}

int solve(){

    int count = 0;
    for(int i = 0; i<global_size; i++){
        //cout << str[i] << endl; 
        if (str[i] == '(' && flag == 1){
            str[i] = ')';
            if(isCorrect()==1) count += 1;
            str[i] = '(';
        }else if (str[i] == ')' && flag == -1){
            str[i] = '(';
            if(isCorrect()==1) count += 1;
            str[i] = ')';
        }
    }
    //cout << "count : " << count << endl;

    return count;
}


int main(){
    int ans = -1;

    InputData();// 입력받는 부분
    getSize();
    flag= isCorrect(); // 1 is correct, 0, -1 is fail
    //cout << "Flag : " << flag << endl;
    if (flag == 1){
        cout << 0 << endl;
    }else{
        ans = solve();
        cout << "Size : " << global_size << endl;
        cout << ans << endl;// 출력하는 부분
    
    }

    return 0;
}

/*

()
(())
()(()())

*/