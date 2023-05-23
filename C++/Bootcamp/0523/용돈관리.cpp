#include <iostream>
#include <climits>

using namespace std;

#define MAX_N (100000)

int N, M;
int need[MAX_N];
int binaryMin = 1;
int binaryMax = 100000;
int ans = MAX_N;
int now_remain = MAX_N;

void Input_Data(void) {
	cin >> N >> M;
	for (int i = 0; i < N;i++) {
		cin >> need[i];
	}
}

// O(N)
void getMinMax(){
	int summation = 0;
	for(int i = 0; i< N; i++){
		binaryMin = min(need[i], binaryMin);
		summation += need[i];
	}
	binaryMax = summation;
}

int calAccount(int withdraw){
	int now_money = 0;
	int count = 0;
	for(int i = 0; i<N; i++){

		if (withdraw < need[i]){
			return 1;
		}
		
		if (now_money < need[i]){
			count += 1;
			now_money = withdraw;
			now_money -= need[i];
		}else{
			now_money -= need[i];
		}
		//cout << "Need : " << need[i] << " Count : " << count << " Now : " << now_money << endl;
	}
	// now_money 를 기준으로 추가 조건 해줘야 할 지도
	if (count > M){
		return 1; // 인출량 초과, 낮춰야함
	}else 
		return 0;
}

void binarySearch(){
	if (binaryMax - binaryMin < 0){
		return ;
	}
	int middle = (binaryMin + binaryMax) / 2;
	int result = calAccount(middle);
	//cout << "MIN : " << binaryMin << " MAX : " << binaryMax << " Target : " << middle << " Result : " << result << endl;

	if(result == 1){
		binaryMin = middle+1;
		binarySearch();
	}else{
		ans = min(ans, middle);
		binaryMax = middle-1;
		binarySearch();
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio();
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 입력 받는 부분
	Input_Data();
	//getMinMax();
	// calAccount(600); // 미달
	// calAccount(501); // 미달
	// calAccount(500); // 적정
	// calAccount(499); // 초과
	// calAccount(400); // 초과

	//cout << "MIN : " << binaryMin << endl;
	//cout << "MAX : " << binaryMax << endl;
	binarySearch();

	// 여기서부터 작성

	// 출력하는 부분
	cout << ans << '\n';

	return 0;
}