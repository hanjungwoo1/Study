#ifndef EX3_4_H_
#define EX3_4_H_

#include <iostream>
using namespace std;
#include <string>
#define PERSON_MAX 100
class Person
{
	enum {MAN, WOMAN};

public:
	int getAge();
	void setAge(int data);
	int getGender();
	void setGender(int data);
	string getName();
	void setName(string data);
	void printInfo();
private:
	int age;
	int gender;
	string name;
};

#endif /* EX3_4_H_ */
