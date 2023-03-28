#include <iostream>
using namespace std;
class Test
{
	int a;
	int b;
public :
	void setData( int x, int y){
		a = x;
		b = y;
	}
	void show()	{
		cout << "a=" << a << '\t' << "b=" << b << endl;
	}
};
int main()
{
	Test obj;
	obj.setData( 10, 20 );
	obj.show();
	getchar();
	return 0;
}
