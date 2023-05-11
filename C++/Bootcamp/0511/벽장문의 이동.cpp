#include <iostream>
using namespace std;

#define MAXN (20)
#define INF (100000000)
int N;  // door counts
int sl, sr; // left, right index
int M; // to find doors counts
int seq[MAXN+10];
int result;




void InputData(){
	cin >> N;
	cin >> sl >> sr;
	cin >> M;
	for (int i=0; i<M; i++){
		cin >> seq[i];
	}
}

void dfs(int index, int count){
    /*
    index : where to find in array(seq)
    count : moved distance
    */

    // cout << "index : " << index << " count : " << count << endl;
    // cout << "sl sr :  " << sl <<" "<< sr << endl; 

    if (index == M){
        // cout << "result index : " << index << " count : " << count << endl;
        result = min(result, count);
        return;
    }
   
    // left to find
    int temp_count = count; // backup count, for right 
    int temp_sl = sl;  
    temp_count += abs(sl - seq[index]); // add abs distance
    sl = seq[index]; // set SL new Target
    dfs(index+1, temp_count);
    sl = temp_sl; // rebase SL to before
   
    // right to find
    temp_count = count;
    int temp_sr = sr;
    temp_count += abs(sr - seq[index]); // add abs distance
    sr = seq[index]; // set SR new Target
    dfs(index+1, temp_count);
    sr = temp_sr; // rebase SR to before
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	result = INF;

	InputData();//입력받는 부분

    dfs(0, 0);
	//여기서부터 작성

	cout << result << endl;//출력하는 부분
	return 0;
}