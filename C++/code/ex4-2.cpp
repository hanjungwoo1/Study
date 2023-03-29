#include <iostream>
using namespace std;
class Test{
private:
	int a;
	int b;
public:
	Test( int n=0, int m=0 ): a(n), b(m){ }
	void SetData( int x, int y ){
		a = x;
		b = y;
	}
	void Show(){
		cout << "a=" << a << " b=" << b << endl;
	}
	Test& operator=( const Test& r ){
		this->a = r.a;
		this->b = r.b;
		return *this;
	}
};
int main()
{
	Test tt(10, 20);
	Test ss;
	ss = tt; 		 // Test ss = tt; 와의 차이점은?
	ss.Show();

	return 0;
}
