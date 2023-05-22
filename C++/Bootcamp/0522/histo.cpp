#include <iostream>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;
int N;//히스토그램수
int H[100000+10];//히스토그램 높이
int flag = 1;

bool InputData() {
    cin >> N;
    if (N == 0) return false;
    
    for (int i=0; i<N; i++){
        cin >> H[i];
    }
    H[N] = -1;
    return true;
}


long long solve(){
    long long max_result = 0;
    stack<long long> st;
    long long width = 0;
    for(int i =0; i<=N; i++){
        while(!st.empty()&& H[st.top()] > H[i]){
            int index = st.top();
            st.pop();
            if(st.empty()){ // 지금 뽑은애가 제일 작다
                width = i;
                //cout << "empty width" << endl;
            }
            else{ // 0이 밑바닥은 여기
                width = i - st.top() - 1;  // 전체에서, 이전 놈 빼고 1 추가 더(현재 놈)
                //cout << "st.top : " << st.top() << endl; st.top -> 뽑고나서 그 다음에 !!!
            }

            //cout << "Height : " << H[index] << " Width : " << width << " index : " << i << endl;
            max_result = max(max_result, H[index] * width);
        }
        st.push(i);
    }
    return max_result;
}


int main() {
    long long ans = -1;
    while(InputData()){//입력받는 부분
        //여기서부터 작성
        ans = solve();
        cout << ans << "\n";//출력하는 부분
    }
    return 0;
}