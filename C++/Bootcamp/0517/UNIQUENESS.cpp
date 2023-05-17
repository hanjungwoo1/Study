#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <set>
#include <unordered_set>

using namespace std;
int N;
char S[10000+10][20+10];
unordered_map<string, set<int>> result;
vector<string> name;
set<string> checker;

void InputData(){
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> S[i];
    }
}

void solve(){

    string data;
    for (int i=1; i<=N; i++){
        data = S[i];
        name.push_back(data);
        result[data].insert(i);
    }
}

int check(){

    for(auto it = result.begin(); it != result.end(); ++it )
	{
        auto temp = it->second;
        if (temp.size() > 1){
            return 1; // 
        }
	}
    return 0;
}

void printResult(){

    for(int i = 0; i<name.size(); i++){
        auto temp = name[i];
        if (checker.find(temp) != checker.end() || result[temp].size() == 1){ // 있으면
            continue;
        }else{ // 없으면
            checker.insert(temp);
            auto iter = result[temp];
            cout << temp << " ";
            for (auto sit = iter.begin(); sit != iter.end(); ++sit){
                cout << *sit << " ";
            }
            cout << endl;
        }
    }
}

int main(){
    InputData();// 입력받는 부분

    solve();

    if (check() == 1){
        printResult();
    }else{
        cout << "unique" << endl;
    }

    return 0;
}