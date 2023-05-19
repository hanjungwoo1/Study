#include <iostream>
using namespace std;

int N;
char A[20000+10];
void InputData(){
    cin >> N >> A;
}

void solve(){

    int count = 0;
    int flag = 0;
    for(int i = 0; i< 20000+10; i++){
        if (A[i] == '\0'){
            break;
        }
        //cout << "check : " <<A[i] << " " << endl;;

        if (A[i] == '<'){
            count += 1;
        }else if (A[i]== '>'){
            count -= 1;
        }

        if (count == N && isdigit(A[i])){
            cout << A[i];
            flag = 1;
        }

        if (count == N && A[i] == '<' && flag ==1){
            cout << " ";
            flag = 0;
        }
    }

}


int main (){
    InputData();// 입력받는 부분

    solve();

    // 여기서부터 작성

    return 0;
}