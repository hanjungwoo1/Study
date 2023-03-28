#include <iostream>
#include <list>
#include <functional>

using namespace std;
#define MAXN (100)
int N, M;//재료종류수, 가진돈
int X[MAXN + 10];//1인분당 필요한 양
int Y[MAXN + 10];//주방에 있는 양
int Sm[MAXN + 10];//작은 포장 재료 양
int Pm[MAXN + 10];//작은 포장 가격
int Sv[MAXN + 10];//큰포장 재료 양
int Pv[MAXN + 10];//큰포장 가격

struct item{
    int num;
    int supply;
    int price;
};

struct item item_list;

void InputData() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i] >> Sm[i] >> Pm[i] >> Sv[i] >> Pv[i];
        item temp1;
        item_list[i*2].num = i*2;
        temp1.supply = Sm[i*2];
        temp1.price = Pm[i*2];
        item_list.push_back(temp1);

        item temp2;
        temp2.num = i*2 + 1;
        temp2.supply = Sv[i*2 +1];
        temp2.price = Pv[i*2 + 1];

	}
}


// void brute_force(int num, int total){



// }


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int ans = -1;
	InputData();//입력 받는 부분
	
    for(auto loop : item_list)
    {
        std::cout << loop.num << loop.supply << loop.price << std::endl;
    }


    cout << item_list[0] << endl;

	cout << ans << "\n";//출력 하는 부분
	return 0;
}