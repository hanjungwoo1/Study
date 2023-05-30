/*
탐색하면서 더하고
자리올림이 더하지 않는 소들의 최대 수를 확인해라.
*/


#include <iostream>
using namespace std;

int N;
int W[20];
int min_ans = -1;
void InputData(){
    cin >> N;
    for (int i=0 ; i<N ; i++){
        cin >> W[i];
    }
}

int isRoundUp(int left, int right){

    int smaller = min(left, right);
    int bigger = max(left, right);

    while (smaller!=0){

        int smaller_digit = smaller%10;
        int bigger_digit = bigger%10;

        //cout << smaller << " " << bigger << endl;
        //cout << smaller_digit << " " << bigger_digit << endl;
        if (smaller_digit + bigger_digit >= 10){
            return 0;
        }
        smaller /= 10;
        bigger /= 10;
    }

    return 1;
}

void dfs(int index, int before, int after, int count){

    if (!isRoundUp(before, after)){
        return ;
    }

    if (index==N){
        //cout << before << " " << after << " count : " << count << endl;
        min_ans = max(min_ans, count);
        return ;
    }

    if(index < N){
            // not add
            dfs(index+1, before+after, 0, count);
            // add
            dfs(index+1, before+after, W[index], count + 1);
    }
}


int main(){

    InputData();// 입력받는 부분
    dfs(0, 0, 0, 0);
    // cout << isRoundUp(7311, 19) << endl;
    // 여기서부터 작성

    cout << min_ans << endl;//출력하는 부분
    return 0;
}