#include "ex3-2.h"
#include<iostream>
using namespace std;
Student::Student()
{
	cout << "(C) default constructor\n";
	age = -1;
	name = NULL;
}

Student::Student(int nAge)
{
	cout << "(C) Student(int nAge) constructor\n";
	age = nAge;
	name = NULL;
}

Student::Student(const char * strName)
{
	cout << "(C) Student(char * strName) constructor\n";
	age = -1;
	int len = strlen(strName)+1;
	name = new char[len];
	strncpy(name, strName, len);
}
Student::Student(int nAge, const char * strName)
{
	cout << "(C) Student(int nAge, char * strName) constructor\n";
	age = nAge;
	int len = strlen(strName)+1;
	name = new char[len];
	strncpy(name, strName, len);
}

Student::~Student()
{
	cout << "(D) default destructor\n";
	printInfo();
	if(name != NULL)
		delete [] name;
}

void Student::setName(const char * strName)	// 수정 필요
{
	if(name != NULL){
		delete[] name;
	}
	name = new char [strlen(strName) + 1];
	// strncpy(name, strName, strlen(strName)+1);
    strcpy(name, strName);
}
void Student::printInfo()
{
	cout << "[Student Info]\n";
	if(name != NULL)
		cout << "Name\t: " << getName() << "\n";
	else
		cout << "Name\t: no data\n";

	if(getAge() < 0)
		cout << "age\t: no data\n";
	else
		cout << "age\t: " << getAge() << "\n";
}
