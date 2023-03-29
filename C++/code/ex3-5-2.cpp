#include "ex3-5.h"
#include "ex3-5-1.cpp"

int main( )
{
	Person *pPersonArray[PERSON_MAX];
	unsigned int nPersonCount = 0;
	char cContinue;
	do{
		cout << "[Person Info Input]\n";
		if(nPersonCount < PERSON_MAX)
		{
			int inputAge = -1;
			int inputGender = -1;
			string inputName = string("no data");
			cout << "input age : ";
			cin >> inputAge;
			cout << "input gender (man : 0, woman : 1) : ";
			cin >> inputGender;
			cout << "input name : ";
			cin.ignore();
			getline(cin, inputName);
			pPersonArray[nPersonCount] = new Person;
			pPersonArray[nPersonCount]->setName(inputName);
			pPersonArray[nPersonCount]->setAge(inputAge);
			pPersonArray[nPersonCount++]->setGender(inputGender);
		}
		else
		{
			cout << "person array full\n";
			break;
		}
		cout << "continue(y/n)? : ";
		cin >> cContinue;
	}while(cContinue=='y' || cContinue == 'Y');

	cout << "[ " << nPersonCount << " Person Info Print]\n";

	for(unsigned int i=0; i < nPersonCount; i++)
	{
		cout << "( " << i+1 << " ) ";
		Person &rPerson = *(pPersonArray[i]);
		rPerson.printInfo();
		delete pPersonArray[i];
	}

	getchar(); getchar();
	return 0;
}
