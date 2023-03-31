#include <iostream>
using namespace std;

class BaseClass
{
public:
	void setData(int i=0) { x = i; }
	int getData() { return x; }
private:
	int x;
};

class DerivedClass : public BaseClass
{
public:
	void setData(int i=0) { y = i; }
	int getData() { return y; }
	DerivedClass(){ y = 5; }
private:
	int y;
};
int main()
{
	BaseClass *pBaseObj;
	BaseClass BaseObj;
	DerivedClass DerivedObj;

	pBaseObj = &BaseObj;
	pBaseObj->setData(10); 	// x = 10

	pBaseObj = &DerivedObj;
	pBaseObj->setData(99);		// ?

	cout << "BaseClass object x : " << BaseObj.getData() << endl;
	cout << "DerivedClass object y : " << DerivedObj.getData() << endl;

	return 0;
}
