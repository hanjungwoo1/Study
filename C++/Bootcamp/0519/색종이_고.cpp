#include <iostream>
#include <vector>
#include <set>

using namespace std;
int N;//색종이 수
int X[100+10];
int Y[100+10];
int ans = 0;

vector<int> row_vector;
vector<int> col_vector;
set<pair<int, int>> coord;

int mapArea[110][110];

void InputData() {
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> X[i] >> Y[i];
    }
}

void makeArea(){
    int row;
    int col;
    for(int i=0; i<N; i++){
        row = X[i];
        col = Y[i];
        for (int j = row; j<row+10; j++){
            for(int k=col; k<col+10; k++){
                //area.insert({j, k});   // 넓이 만들기     
                mapArea[j][k] = 1;   
            }
        }
    } 
}

void calArea(int start_x, int start_y, int end_x, int end_y){
    int row;
    int col;
    int count=0;
    
    for(int i = start_x; i < end_x; i++){
        for(int j = start_y; j< end_y; j++){

            if(mapArea[i][j] == 1){
                count += 1;
            }else{
                return;
            }
        }
    }
    ans = max(ans,count);
}

void solve(){
    
    // make coord candidate
    for (int i=0; i<N; i++){
        row_vector.push_back(X[i]);
        row_vector.push_back(X[i]+10);
        col_vector.push_back(Y[i]);
        col_vector.push_back(Y[i]+10);
    }

    // make coord
    int combi_x;
    int combi_y;
    for(int i=0; i<row_vector.size(); i++){
        combi_x = row_vector[i];
        for (int j = 0; j<col_vector.size(); j++){
            combi_y = col_vector[j];
            coord.insert({combi_x, combi_y});
        }
    }

    makeArea();

    int start_x;
    int start_y;
    int end_x;
    int end_y;
    for (auto it = coord.begin(); it != coord.end(); it++) {
	    
        start_x = (*it).first;
        start_y = (*it).second;
        for (auto it2 = coord.begin(); it2 != coord.end(); it2++) {
            end_x = (*it2).first;
            end_y = (*it2).second;

            if (start_x < end_x && start_y < end_y){
                calArea(start_x, start_y, end_x, end_y);
            }
        }
    }
}


int main() {
    InputData();//입력받는 부분

    solve();
    //여기서부터 작성
    
    cout << ans << endl;//출력하는 부분
    return 0;
}