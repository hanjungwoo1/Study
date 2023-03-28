#include <iostream>
using namespace  std;

int sqr(int &num);
int main()
{
	int res;
	res = sqr(10+20); //	¢¸ error
	cout << res << endl;
	return 0;
}				
int sqr(int &num) 
{
	return num * num;
}

