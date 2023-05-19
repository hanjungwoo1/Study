#include <iostream>
#include<algorithm>

using namespace std;
#define MAXN ((int)1e5)
int N;//영화수
struct DATA{
    int s, e;
};
DATA A[MAXN + 10];

bool comp(const DATA &a, const DATA &b){
    if(a.e < b.e) return true;
    if(a.e == b.e){
        if(a.s > b.s) return true;
    }
    return false;
}

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i].s >> A[i].e;
    }
}

int solve(){

    int index = 0;
    for(int i = 0; i<N; i++){
        if (A[i].e - A[i].s >= 2){
            index = i;
            break;
        }
    }

    int start = A[index].s;
    int end = A[index].e;
    int count = 1;
    for(int i =1; i<N; i++){
        //cout << A[i].s  << " " << A[i].e << endl;

        if (A[i].e - A[i].s < 2){
            continue;
        }

        // 볼 수 있음
        if(end <= A[i].s){
            count += 1;
            end = A[i].e;
            //cout << "watch : " << start << " " << end << endl;
        }

    }
    return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InputData();//입력받는 부분
	sort(A, A+N, comp);
    int ans = solve();

	cout << ans << "\n";//출력하는 부분
	return 0;
} 


/*
5
7 8
1 2
18 20
1 3
13 15

3
*/