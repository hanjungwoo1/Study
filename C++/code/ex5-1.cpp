#include <iostream>
using namespace std;

class CarEngine
{
private:
	int mEngine;
public:
	void setEngine( int n ){
		mEngine = n;
	}
	int getEngine()
	{
		return mEngine;
	}
};
class Car
{
private:
	int mAccel;
public:
	CarEngine engine;
};

int main()
{
	Car car;
	car.engine.setEngine( 10 );
	cout <<car.engine.getEngine() << endl;

	return 0;
}
