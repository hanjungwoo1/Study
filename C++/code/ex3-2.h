#ifndef EX3_1_H_
#define EX3_1_H_

#include <iostream>
using namespace std;
#include <cstring>

class Student
{
public:
	Student();
	Student(int nAge);
	Student(const char * strName);
	Student(int nAge, const char * strName);
	~Student();

	int getAge() { return age; }
	void setAge(int data) { age = data; }
	char * getName() { return name; }
	void setName(const char * data);
	void printInfo();

private:
	int age;
	char * name;
};

#endif /* EX3_1_H_ */
