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
    
    H[0] = 0;
    for (int i=1; i<N+1; i++){
        cin >> H[i];

        if (H[i] == 0) flag = 0;
    }
    return true;
}


long long solve(){
    long long max_result = 0;
    stack<long long> st;
    st.push(0);
    for(long long i =1; i<N+1; i++){
        while(!st.empty()&& H[st.top()] > H[i]){
            long long index = st.top();
            st.pop();
            max_result = max(max_result, H[index] * (i-st.top()-1));
            //cout << "index : " << i << " max_result : " << max_result << endl;
        }
        st.push(i);
    }

    long long height;
    long long width;
    while(!st.empty()){
        int index = st.top();
        st.pop();
        height = H[index];
        width = (N-index+1);
        max_result = max(max_result, height * width);
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