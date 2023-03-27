#include<iostream>
#include<iomanip>	// setprecision, setw 사용을 위해 인클루드

using  namespace  std;
int main()
{
	int number = 12;
	cout << showbase;
	cout <<"cout Decimal : "<< number << endl;
	cout <<"cout Hexadecimal: "<< hex << number << endl;
	cout <<"cout octal: "<< oct << number << endl;

	double dnumber = 7.12345;
	cout << setprecision(3);
	cout << dnumber << endl;	// 기본 모드 - 유효숫자 3자리 출력
	cout << fixed;
	cout << dnumber << endl;	// fixed 모드 - 소수점 이하3자리 출력
	cout << scientific;
	cout << dnumber << endl;	// scientific 모드 - 소수점 이하 3자리 출력
	cout <<"|"<< setw(10) << number <<"|"<< setw(15) << dnumber <<"|"<< endl;

	cout << left;
	cout <<"|"<< setw(10) << number <<"|"<< setw(15) << dnumber <<"|"<< endl;

	cout << right;
	cout <<"|"<< setw(10) << number <<"|"<< setw(15) << dnumber <<"|"<< endl;

	return 0;
}
/* 조정자 해제 Tip
	cout.unsetf(ios_base::scientific);	// 실수값 출력 형태를 기본모드 형태로 되돌림
	cout<< noshowbase;                 	// 진법 접두어 출력 취소
	cout << setprecision(-1);           	// 유효숫자 및 소수점 이하 자리 수 지정 취소
*/

