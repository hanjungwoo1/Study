#include <iostream>
#include <vector>
using namespace std;
char map[5][10];
int numData[12];
int visit[13];
int ResultNum[12];

int numCount=0;
int flag =0;
char resultmap[5][10];

struct numList{
    int one;
    int two;
    int three;
    int four;
};

vector<pair<int,int>> locPair = {{0,4}, {1,1}, {1,3}, {1,5}, {1,7}, {2,2}, {2,6}, {3,1}, {3, 3}, {3, 5}, {3, 7}, {4, 4}};
vector<numList> locNumList = {{0, 2, 5, 7}, {0, 3, 6, 10}, {1, 2, 3, 4}, {7, 8, 9, 10}, {1, 5, 8, 11}, {4, 6, 9, 11}};

void InputData(){
	for (int h=0; h<5; h++){
		cin >> map[h];
	}
}

void OutputData(){
	for (int h=0; h<5; h++){
		cout << map[h] << endl;
	}
}

int isCorrect(int *numArray){

    // if (numArray[0] == 6 && numArray[4] == 12 && numArray[5] ==8 && numArray[6]==5){
    //     cout << endl;
    //     for(int i=0; i<12; i++){
    //         cout << numArray[i] << " ";
    //     }
      
    // }

    for(auto it=locNumList.begin(); it!=locNumList.end(); it++){
        int temp = numArray[(*it).one] + numArray[(*it).two] + numArray[(*it).three] + numArray[(*it).four];
        if (temp!=26)
            return 0;
    }
    return 1;
}

void makeData(){
    int index = 0;
    for(auto it = locPair.begin(); it!=locPair.end(); it++){
        if (map[(*it).first][(*it).second] == 'x'){
            numData[index] = -1;
        }else{
            numData[index] = map[(*it).first][(*it).second]-'0' - 16;
            visit[map[(*it).first][(*it).second]-'0' - 16] = 1;
            numCount++;
        }
        index ++;
    }
}

void dfs(int *numArray, int *visitArray, int index){

    //numArray=fillData(numArray);
    if (flag) return;

    int tempNum[12];
    int tempVisit[13];
    copy(numArray, numArray+12, tempNum);
    copy(visitArray, visitArray+13, tempVisit);

    if (index == 12){ // check

        if (isCorrect(tempNum)){
            //cout << "SUC" << endl;
            copy(numArray, numArray+12, ResultNum);
            flag = 1;
        }
        return;
    }

    if(numArray[index]!=-1){
        dfs(numArray, visitArray, index+1);
        return;
    }

    for(int j=1; j<13; j++){
        if(tempVisit[j]==0){
            tempNum[index] = j;
            tempVisit[j] = 1;
            dfs(tempNum, tempVisit, index+1);
            tempVisit[j] = 0;
            tempNum[index] = -1;
        }
    }   
}


int main(){
	InputData();//입력받는 부분
    makeData();
    dfs(numData, visit, 0);

    int index = 0;
    for(auto it = locPair.begin(); it!=locPair.end(); it++){
        map[(*it).first][(*it).second] = ResultNum[index]+16+'0';
        index ++;
    }
    OutputData();
	return 0;
}