#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <climits>
#include <set>

using namespace std;

int S, E;//출발 정류장 번호, 도착 정류장 번호
deque<pair<int, int>> queue;
vector<int> candidate;
int visit[10000];

void InputData(){
    cin >> S >> E;
}

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

void makeCandidate(){
    for(int i=1000; i<=9999; i++){
        if (isPrime(i)){
            candidate.push_back(i);
            //cout << i << endl;
        }
    }
    //cout << "COUNT : " << candidate.size() << endl;
}

bool isOneMatched(int first, int second){

    int count =0;
    if(first < 1000 || second < 1000 || first > 9999 || second > 9999){
        //cout << "ERROR NUMBER : " << first << " " << second;
        return false;
    }

    while(first >0){
        int first_out = first % 10; // 1의 자리
        int second_out = second % 10;

        //cout << "FIRST : " << first << " SECOND : " << second << " FR : " << first_out << " SR : " << second_out << endl;
        if(first_out != second_out) count ++;

        first /= 10;
        second /= 10;
    }
    if (count == 1) return true;
    return false;
}

set<int> makeNum(int num){

    vector<int> each_num;
    set<int> candiSet;

    for(int i=0; i<candidate.size();i++){
        int check = candidate[i];

        if(isOneMatched(num, check) && visit[check] == 0){
            visit[check] = 1;
            candiSet.insert(check);
        }
    }
    return candiSet;
}

int dfs(){
    int ans = INT_MAX;
    int time = 0;
    queue.push_back({S, time});
    int flag = 1;

    while(!queue.empty() && flag == 1){
        int number = queue.front().first;
        int time = queue.front().second;
        queue.pop_front();

        set<int> item = makeNum(number);

        for(auto it = item.begin(); it!=item.end(); it++){
            int check = *it;
            int new_time = time+1;
            if (check == E){
                ans = min(ans, new_time);
                flag = 0;
                break;
            }
            queue.push_back({check, new_time});
        }
    }
    return ans;
}



int main(){
    int ans = -1;
    InputData();// 입력받는 부분
    makeCandidate();
    ans = dfs();
    cout << ans << endl;// 출력하는 부분
    return 0;
}
