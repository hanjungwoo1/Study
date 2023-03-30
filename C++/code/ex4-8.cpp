#include <iostream>
using namespace std;
#include <Cstring>
class CString
{
private:
	char* m_str;
	int m_length;
public:
	CString();
	CString(const char* str);
	CString(const CString &r); 
	~CString();
	CString operator+(CString &r);
	CString operator+(const char* str);
	CString operator=(const CString &r); 
	bool operator==(CString &r);
	bool operator==(char* str);
	friend ostream& operator<<(ostream& os, CString &r);
	friend istream& operator >>(istream &is, CString &r);
};

CString::CString():m_length(0)
{
	m_str = new char[m_length + 1];
}
CString::CString(const char* str) 
{
	m_length=strlen(str);
	m_str = new char[m_length + 1];
	strcpy(m_str, str);
}
CString::CString(const CString & r) : m_length(r.m_length)
{
	m_str = new char[m_length + 1];
	strcpy(m_str, r.m_str);
}
CString::~CString()
{
	delete[] m_str;
}
CString CString::operator+(CString& r)
{
	char* temp;
	temp = new char[m_length + r.m_length+1];
	strcpy(temp, m_str);
	strcat(temp, r.m_str);
	CString tob(temp);
	delete[] temp;
	return tob;
}
CString CString::operator+(const char* str)
{
	char* temp;
	temp = new char[m_length + strlen(str)+1];
	strcpy(temp, m_str);
	strcat(temp, str);
	CString tob(temp);
	delete[] temp;
	return tob;
}
CString CString::operator=(const CString& r)
{
	if (this == &r) { 	return *this;	}  // 나에게 나를 대입하려고 할때는 바로 리턴
	delete[] m_str;  // m_str의 기존메모리 해제(Memory leak 방지)
	m_length = r.m_length;
	m_str = new char[m_length + 1];
	strcpy(m_str, r.m_str);
	return *this;
}
bool CString::operator==(CString& r)
{
	if (strcmp(m_str, r.m_str) == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool CString::operator==(char* str)
{
	if (strcmp(m_str, str) == 0) {
		return true;
	}
	else {
		return false;
	}
}
ostream& operator<<(ostream& os, CString& r)
{
	cout << r.m_str << "(" << r.m_length << ")" << endl;
	return os;
}
istream& operator >>(istream& is, CString& r)
{
	char temp[1000];  // 문자열입력 배열은 크게 잡아 줌
	cin >> temp;
	r.m_length = strlen(temp);
	delete[] r.m_str;  // m_str의 기존메모리 해제(Memory leak 방지)
	r.m_str = new char[r.m_length + 1];
	strcpy(r.m_str, temp);
	return is;
}


int main()
{
	CString str1("abcdefg");
	CString str2 = "abcdefg";
	cout << "str1=" << str1 << endl;
	cout << "str2=" << str2 << endl;
	str2 = str1;
	CString str3 = str1;
	cout << "str1=" << str1 << endl;
	cout << "str2=" << str2 << endl;
	cout << "str3=" << str3 << endl;
	str1 = str2 + str3;
	cout << "str1 = str2 + str3 : " << str1 << endl;


	str1 = str2 + "rh";
	cout << "str2 + rh : " << str1 << endl;

	CString str4("tbcdefg");
	if (str1 == str4)
		cout << "equal(==)" << endl;
	else
		cout << "not equal(!=)" << endl;

	CString str5("last"), str6;
	cin >> str5;
	cout << str5;
	cin >> str6;
	cout << str6;
 
	return 0;
}

