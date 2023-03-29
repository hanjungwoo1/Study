#include "ex3-5.h"
int Person::getAge()
{
	return age;
}
void Person::setAge(int data)
{
	age = data;
}
int Person::getGender()
{
	return gender;
}
void Person::setGender(int data)
{
	gender = data;
}
string Person::getName()
{
	return name;
}
void Person::setName(string data)
{
	name = data;
}
void Person::printInfo()
{
	cout << "[Person Info]\n";

	if(name.length() != 0)
		cout << "Name\t: " << name << " ";
	else
		cout << "Name\t: no data ";

	switch(gender)
	{
		case MAN:
			cout << " (MAN)\n";
			break;
		case WOMAN:
			cout << " (WOMAN)\n";
			break;
		default:
			cout << " (no data)\n";
			break;
	}
	if(age < 0)
		cout << "age\t: no data\n";
	else
		cout << "age\t: " << age << "\n";
}


