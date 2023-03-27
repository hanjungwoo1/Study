#include<iostream>
using  namespace std;
void my_flush(); 
int main() 
{ 
    int num; 
    cin >> num; 
    while(cin.fail()) {    // cin자체 flag를 검사해서 입력이 실패하면 true값을 리턴
         my_flush();       // cin 입력버퍼에 들어 있는 불필요한 데이터를 지워 줌
         cin >>num;       // 다시 입력을 시도 함. 
    } 
    cout <<"num="<< num << endl; 
    return 0; 
} 
void my_flush() // 사용자가 만든 cin입력버퍼 지우기함수
{ 
    cin.clear();     // cin의 자체flag값을 0으로 만듬- 이 부분이 빠지면 cin 입력 시도를 
                          // 하지 않고 무조건 실패로 인식되어 무한loop에 빠짐
    while(cin.get()!='\n') ; // cin입력 버퍼내의 모든 데이터 삭제
} 

