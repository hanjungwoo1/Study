#include "ex3-2.h"
#include "ex3-2-1.cpp"

int main( )
{
	Student st1;
	st1.printInfo();

	Student st2(20);
	st2.printInfo();

	Student st3("HongGD");
	st3.printInfo();

	Student st4(21, "LeeSS");
	st4.printInfo();

	Student * st5 = new Student(25, "student");
	st5->printInfo();

	cout << "\n=== end ===\n";

	delete st5;
	st4.setName("HGD");
	st4.printInfo();
	st1.setName("spiderMan");
	st1.printInfo();
	
    cout << "\n===free === \n";
	return 0;
}
