#include <iostream>
using namespace std;
#define MAXN (100)
int N, M;//재료종류수, 가진돈
int X[MAXN + 10];//1인분당 필요한 양
int Y[MAXN + 10];//주방에 있는 양
int Sm[MAXN + 10];//작은 포장 재료 양
int Pm[MAXN + 10];//작은 포장 가격
int Sv[MAXN + 10];//큰포장 재료 양
int Pv[MAXN + 10];//큰포장 가격

int answer = 0;

void InputData() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i] >> Sm[i] >> Pm[i] >> Sv[i] >> Pv[i];
	}
}

// int buy_item(int money, int item[]){

//     for (int i=0; i<N; i++){ // 현재 아이템 확인

//         int money_Pm = money - Pm[i];
//         int money_Pv = money - Pv[i];

//         if (money_Pm <= 0 || money_Pv <=0){
//             int temp = 1000;
//             for(int i = 0; i < N; i++){
//                 int size = item[i] / X[i];
                
//                 if (size < temp){ // 제일 작은 것
//                     temp = size;
//                 }

//             }       
//             if (answer < temp){  // 제일 큰 것
//                 answer = temp;
//             }  
//             return 0; 
//         }

//         item[i] = item[i] + Sm[i];
//         buy_item(money_Pm, item);
//         item[i] = item[i] - Sm[i]; // 원상복귀

//         item[i] = item[i] + Pv[i];
//         buy_item(money_Pv, item);
//         item[i] = item[i] - Pv[i]; // 원상복귀
//     }
    
//     return 0;
// }


int get_minimum_index(){
    int temp = 100000;
    int temp_index = 0;

    for(int i = 0; i<N; i++){
        int count = Y[i] / X[i];
        if (count < temp){
            temp = count;
            temp_index = i;
        }

    }
    return temp_index;
}


int buy_item(){

    while (M > 0){

    }



    return 0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	InputData();//입력 받는 부분
	
    int item[N];

    for(int i=0; i<N; i++){
        item[i] = Y[i];
    }

    buy_item();

	cout << answer << "\n";//출력 하는 부분
	return 0;
}