#include <iostream>
#include <cstring>
using namespace std;

class Student {
	char *name; // 이름
	int number;
public:
	Student(const char *p, int n) {
		cout << "메모리 할당" << endl;
		name = new char[strlen(p)+1];
		strcpy(name, p);
		number = n;
	}
	~Student() {
		cout << "메모리 소멸" << endl;
		delete [] name;
	}
};
int main()
{
	Student s1("hello", 1234567);
	Student s2(s1);		// 복사 생성자 호출

	return 0;
}
