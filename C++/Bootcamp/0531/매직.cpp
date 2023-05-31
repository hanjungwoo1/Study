#include <iostream>
#include <vector>
using namespace std;
char map[5][10];
int numData[12];
int visit[13];

int numCount=0;

struct numList{
    int one;
    int two;
    int three;
    int four;
};

vector<pair<int,int>> locPair = {{0,4}, {1,1}, {1,3}, {1,5}, {1,7}, {2,2}, {2,6}, {3,1}, {3, 3}, {3, 5}, {3, 7}, {4, 4}};
vector<numList> locNumList = {{0, 2, 5, 7}, {0, 3, 6, 10}, {1, 2, 3, 4}, {3, 8, 9, 10}, {1, 5, 8, 11}, {4, 5, 9, 11}};

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

int *fillData(int *numArray){
    for(auto it=locNumList.begin(); it!=locNumList.end(); it++){
        int index = 0;
        int count = 0;

        if (numArray[(*it).one] == -1){
            count += 1;
            index = (*it).one;
        }

        if (numArray[(*it).two] == -1){
            count += 1;
            index = (*it).two;
        }

        if (numArray[(*it).three] == -1){
            count += 1;
            index = (*it).three;
        }

        if (numArray[(*it).four] == -1){
            count += 1;
            index = (*it).four;
        }

        if (count ==3){
            numArray[index] = 26 - (numArray[(*it).one] + numArray[(*it).two] + numArray[(*it).three] + numArray[(*it).four]) -1;
        } 
    }
    return numArray;
}


int isCorrect(int *numArray){

    for(auto it=locNumList.begin(); it!=locNumList.end(); it++){

        if (numArray[(*it).one] == -1 || numArray[(*it).two] == -1 || numArray[(*it).three] == -1 || numArray[(*it).four] == -1){
            continue;
        }else{
            int temp = numArray[(*it).one] + numArray[(*it).two] + numArray[(*it).three] + numArray[(*it).four];
            if (temp!=26){
                //cout << "FAIL" << endl;
                return 0;
            }
            //cout << "SUCCESS" << endl;
        }
        //cout << numArray[(*it).one] <<  numArray[(*it).two] << numArray[(*it).three] << numArray[(*it).four] << endl;
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

int *fillData(int *numArray){
    for(auto it=locNumList.begin(); it!=locNumList.end(); it++){
        int index = 0;
        int count = 0;

        if (numArray[(*it).one] == -1){
            count += 1;
            index = (*it).one;
        }

        if (numArray[(*it).two] == -1){
            count += 1;
            index = (*it).two;
        }

        if (numArray[(*it).three] == -1){
            count += 1;
            index = (*it).three;
        }

        if (numArray[(*it).four] == -1){
            count += 1;
            index = (*it).four;
        }

        if (count ==3){
            numArray[index] = 26 - (numArray[(*it).one] + numArray[(*it).two] + numArray[(*it).three] + numArray[(*it).four]) -1;
        } 
    }
    return numArray;
}


void dfs(int count){

    

    if(isCorrect(numData) == 0){
        return;
    }

    if (count == 12){ // check
        //showData();

        cout << "NUM" << endl;
        for(int i=0; i<12; i++){
            cout << numData[i] << " ";
        }
        cout << endl;

        return;
    }


    for(int i=0; i<12; i++){
        if (numData[i]==-1){
            for(int j=1; j<13; j++){
                if(visit[j]==0){
                    numData[i] = j;
                    visit[j] = 1;
                    dfs(count+1);
                    visit[j] = 0;
                    numData[i] = -1;
                }
            }
        }
    }
}




int main(){
	InputData();//입력받는 부분
    makeData();
    dfs(numCount);

	//OutputData();//출력하는 부분
	return 0;
}