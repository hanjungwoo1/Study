#include <iostream>
using namespace std;

void init_int(int& n)
{
    n = 9;
}

int main()
{
     int age;
     init_int(age);

     cout << age << endl;

	return 0;
}
