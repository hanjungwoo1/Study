#include <iostream>
using namespace std;
class Test{
public:
	Test(int a, int b){
		x = a; y = b;
	}
	Test(const Test& r){
		cout << "copy cons. call" << endl;
		this->x = r.x;
		this->y = r.y;
	}
private:
	int x;
	int y;
};
Test fn( Test t)
{
	cout << "fn call" << endl;
	return t;
}
int main()
{
	Test obj(10,20);
	Test obj1 = obj;
	fn( obj );

	return 0;
}
