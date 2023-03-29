#include <iostream>
using namespace std;
class Data
{
public:
	Data() { x=0; y=0; }
	Data(int i, int j) { x=i; y=j; }
	void getData(int &i, int &j) { i=x; j=y; }
	Data operator+(const Data &obj);
	Data operator+(int);
	Data operator-(const Data &obj);
	bool operator==(const Data &obj);
	Data operator++();

private:
	int x, y;
	
};
Data Data::operator+(const Data &obj)
{
	Data temp;
	temp.x = x + obj.x;
	temp.y = y + obj.y;
	return temp;
}

Data Data::operator+(int n)
{
	Data temp;
	temp.x = x + n;
	temp.y = y + n;
	return temp;
}
Data Data::operator-(const Data &obj)
{
	Data temp;
	temp.x = x - obj.x;
	temp.y = y - obj.y;
	return temp;
}

bool Data::operator==(const Data &obj)
{
	if(x == obj.x && y == obj.y)
		return true;
	else
		return false;
}
Data Data::operator++()
{
	++x;
	++y;

	return *this;
}

int main()
{
	Data c1(1, 1), c2(2, 2), c3, c4(4, 4);
	int x,y;

	c3 = c1 + c2;
	//c3 = c1.operator+(c2);
	//c3.operator=(c1 + c2);
	//c3.operator=(c1.operator +(c2));

	c3.getData(x,y);
	cout << "(c1 + c2) X : " << x << ", Y : " << y << "\n";

	c3 = c1 - c2;
	c3.getData(x,y);
	cout << "(c1 - c2) X : " << x << ", Y : " << y << "\n";

	c3 = c1;
	c3.getData(x,y);
	cout << "(c3 = c1) X : " << x << ", Y : " << y << "\n";
	c3 = c1+100;
	c3.getData(x,y);
	cout << "(c3 = c1+100) X : " << x << ", Y : " << y << "\n\n";

	if(c1==c4)
		cout << "c1 == c4 is true" << "\n";
	else
		cout << "c1 == c4 is false" << "\n";

	if(c1==c2)
		cout << "c1 == c2 is true" << "\n\n";
	else
		cout << "c1 == c2 is false" << "\n\n";

	c4.getData(x,y);
	cout << "c4 X : " << x << " , Y : " << y << "\n";
	c4 = ++c4;
	c4.getData(x,y);
	cout << "++c4 X : " << x << " , Y : " << y << "\n" << "\n";
	
 
	return 0;
}


