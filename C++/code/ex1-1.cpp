#include<iostream>
using  namespace std;
void my_flush();
int main()
{
	int intNumber;
	double doubleNumber;
	char ch;
	char str[100];

	cout <<"INSERT INT: ";
	cin >> intNumber;
	cout <<"INSERT FLOAT: ";
	cin >> doubleNumber;
	cout <<"INSERT CHAR: ";
	cin >> ch;
	cout <<"INSERT STRING: ";
	cin >> str;
	cout <<"intNumber = "<< intNumber << endl;
	cout <<"doubleNumber = "<< doubleNumber << endl;
	cout <<"ch = "<< ch << endl;
	cout <<"str = "<< str << endl;
	my_flush();

	cout <<"INSERT STRING WITH WHITE SPACE : " ;
	cin.getline(str, sizeof(str));
	cout <<"INSERTED STRING : "<< str << endl;
	cout <<"INSERT WHITE SPACE(space, tab, enter) : " ;
	ch=cin.get();       //get()은 오버로딩된 멤버함수로 어떤 문자든 한 문자 읽어들임
	cout <<"ASCII CODE : "<< (int)ch << endl;
	return 0;             // ? 생략가능

}
void my_flush() // 사용자가 만든 cin 입력 버퍼 지우기 함수
{ 
	while(cin.get()!='\n') ; 
}

