#include <iostream>
using namespace std;
class BaseClass
{
public:
	BaseClass() { cout << "[BaseClass]\n\n"; }
	virtual ~BaseClass() { cout << "[BaseClass]\n\n"; }
};
class DerivedClass : public BaseClass
{
public:
	DerivedClass() { cout << "[DerivedClass]\n\n"; }
	~DerivedClass() { cout << "[DerivedClass]\n\n"; }
};

int main()
{
	BaseClass * base = new DerivedClass;
	delete base;
	cout << "--------------------------------------" << endl;
	//DerivedClass derive;  
	return 0;
}
