#include <iostream>
using namespace std;
void prn(char *);
void prn(const char *);
void prn(const char *, int);
void prn(char, int);

int main()
{
	char str[]="Star";
	const char cStr[]="Const Star";

	prn(str); 
	prn(cStr); 
	prn("Moon");  
	prn("Gogumi", 3); 
	prn('#', 7); 
	
     return 0;
}
void prn(char *p)
{
	cout << "prn(char *) : " << p << endl;
}
void prn(const char *p)
{
	cout << "prn(const char *) : " << p << endl;
}
void prn(const char *p, int rc)
{
	cout << "prn(char *, int) : ";
	for(int i=0; i<rc; i++)  cout << p << " ";
	cout << endl;
}
void prn(char ch, int rc)
{
	cout << "prn(char, int) : ";
	for(int i=0; i<rc; i++)  cout << ch;
	cout << endl;
}

