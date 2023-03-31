#include<iostream>
using namespace std;

class Human
{
public:
	virtual void show()
	{
		cout << "man.\n";
	}
};

class Woman : public Human
{
public:
	void show()
	{
		cout << "girl.\n";
	}
};
int main()
{
	Human h_ob;

	Woman w_ob;
	h_ob.show();
	w_ob.show();

	Human * h_ptr;
	h_ptr = &h_ob;
	h_ptr->show();
	h_ptr = &w_ob; // up-casting
	h_ptr->show();

	return 0;
}
