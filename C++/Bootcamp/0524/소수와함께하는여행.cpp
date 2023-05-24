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


int dfs(){
    int ans = INT_MAX;
    int time = 0;
    queue.push_back({S, time});
    int flag = 1;

    while(!queue.empty() && flag == 1){
        int number = queue.front().first;
        int time = queue.front().second;
        queue.pop_front();

        for(int i=0; i<candidate.size();i++){
            int check = candidate[i];
            int new_time = time+1;
            
            if(isOneMatched(number, check)){
                if (check == E){
                    ans = min(ans, new_time);
                    flag = 0;
                    break;
                }
                queue.push_back({check, new_time});

                //cout << "CHECK : " << check << " TIME : " << new_time << endl;
            }
        }
    }
    //cout << ans << endl;
    return ans;
}

set<int> makeNum(int num){

    vector<int> each_num;
    set<int> candidate;

    while(num >0){
        int out_num = num % 10; // 1의 자리
        num /= 10;
        each_num.push_back(out_num);
    }

    for(int i = 1; i<10; i++){
        string result = to_string(i)+to_string(each_num[2])+to_string(each_num[1])+to_string(each_num[0]);
        int result_num =  stoi(result);
        if(isPrime(result_num) && num != result_num){
            candidate.insert(result_num);
        }
    }

    for(int i = 0; i<10; i++){
        string result = to_string(each_num[3])+to_string(i)+to_string(each_num[1])+to_string(each_num[0]);
        int result_num =  stoi(result);
        if(isPrime(result_num) && num != result_num){
            candidate.insert(result_num);
        }
    }

    for(int i = 0; i<10; i++){
        string result = to_string(each_num[3])+to_string(each_num[2])+to_string(i)+to_string(each_num[0]);
        int result_num =  stoi(result);
        if(isPrime(result_num) && num != result_num){
            candidate.insert(result_num);
        }
    }

    for(int i = 0; i<10; i++){
        string result = to_string(each_num[3])+to_string(each_num[2])+to_string(each_num[1])+to_string(i);
        int result_num =  stoi(result);
        if(isPrime(result_num) && num != result_num){
            candidate.insert(result_num);
        }
    }


    return candidate;
}

int main(){
    int ans = -1;
    //InputData();// 입력받는 부분
    //makeCandidate();
    //ans = dfs();
    // set<int> item = makeNum(1033);

    // for(auto it = item.begin(); it != item.end(); it++){
    //     cout << *it << endl;
    // }


    //cout << isOneMatched(3734, 1733) << endl;
    cout << ans << endl;// 출력하는 부분
    return 0;
}
