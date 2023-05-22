#include <iostream>
#include <stack>
#include <deque>

using namespace std;
#define MAXN ((int)5e5)
int N, K;
char str[MAXN + 10];
stack<char> st;
deque<char> queue;

void InputData() {
	cin >> N >> K;
	cin >> str;
}

void solve(){
    for (int i = 0; i < N; i++) {
        while (!st.empty() && st.top() < str[i] && K > 0) {
        st.pop();
        K--;
        }
        st.push(str[i]);
    }

    while (!st.empty() && K > 0) {
        st.pop();
        K--;
    }
}

int main() {
	InputData();//입력 받는 부분

    solve();

    while (!st.empty()) {
        char data =  st.top();
        st.pop();
        queue.push_back(data);
    }

    for(int i = queue.size()-1; i>=0; i--){
        cout << queue[i];
    }
    
	return 0;
}
