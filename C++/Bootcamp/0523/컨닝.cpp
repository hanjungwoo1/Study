#include <iostream>
#include <algorithm>


using namespace std;
#define MAXN ((int)1e5)
int N;//개수
int F[MAXN + 10];

void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> F[i];
	}
}

long long BinarySearch(){

    long long summation = 0;
    long long count;

    for(long long i = 0; i<N-1; i++){

        double base = F[i];
        double result;

        long long start = i+1;
        long long end = N;
        long long middle = end;
        long long ans = 0;

        while(start < end){
            middle = (start + end) /2;
            //cout << "start : " << start << " end : " << end << " middle : " << middle << endl;

            result = F[middle] * 0.9;
            if (base < result){
                end = middle;
                //cout << "okay" << endl;
                ans = middle;
            }else{
                start = middle +1;
                //cout << "fail" << endl;
            }
        }
        //cout << "Base : " << base << " Target index : " << middle << " Value : " << result << endl;
        //cout << "ANS : " << ans << endl;
        //cout << "Count : " << ans - i -1 << endl; 
        
        if (ans == 0){
            count = N-i-1;
        }else{
            count = ans -i -1;
        }
        //cout << "Count : " << count << endl; 
        
        summation += count;
    }
    return summation;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long ans = -1;

	InputData();// 입력받는 부분
    sort(F, F + N); // 정렬

    ans = BinarySearch();

	// 여기서부터 작성

	cout << ans << "\n";// 출력하는 부분
	return 0;
}