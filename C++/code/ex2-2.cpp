#include<iostream>
using namespace std;
#include<string.h>
void prn(char *&ptr);              // 참조 포인터 변수
void prn(char (&chr)[10]);         // 참조 1차원 배열
void prn(int (&array)[3][4]);      // 참조 2차원 배열
int main()
{
	char str[10]="Star";
	int ary[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	char *cp = str;

	prn(cp);
	prn(str);
	cout << "Before : " << ary[2][3] << endl;
	prn(ary);
	cout << "After : " << ary[2][3] << endl;

	return 0;
}
void prn(char *&rPtr)
{
	cout << rPtr << endl;
	cout << "rPtr Size : " << sizeof(rPtr) << endl;
}
void prn(char (&chr)[10])
{
	cout << chr << endl;
	cout << "chr Size : " << sizeof(chr) << endl;
	strcpy(chr, "Dream");
}
void prn(int (&array)[3][4])
{
	cout << "array Size : " << sizeof(array) << endl;
	array[2][3]=20;
}
