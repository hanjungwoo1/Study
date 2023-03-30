#include<iostream>
using namespace std;
class A
{
  private:
	int a;
  protected :
	int aa;
  public :
     A(int n1=0, int n2=0) 
      : a(n1), aa(n2) {}
     void prnA(){
	 cout <<a<<' '<<aa<<endl;
	}
};
class B : public A
{
 private:
    int b;
 protected :
    int bb;
 public :
    B(int n1=0,int n2=0,int n3=0,int n4=0) 
        : A(n1, n2), b(n3), bb(n4) {}
    void prnB(){
	  cout << b << ' ' << bb << endl;
    }
};
class C : public B
{
  private:
     int c;
  protected :
	int cc;
  public :
	C(int n1=0, int n2=0, int n3=0,  
       int n4=0, int n5=0, int n6=0)
	 :B(n1,n2,n3,n4), c(n5), cc(n6) 
       {}
	void prnC(){
		cout << c <<' '<< cc <<endl;
	}
	void setData(){
		aa = 77;
		bb = 88;
		cc = 99;
	}
};
int main()
{
	C ob(1,2,3,4,5,6);
	ob.prnA();
	ob.prnB();
	ob.prnC();

	ob.setData();

	ob.prnA();
	ob.prnB();
	ob.prnC();

	getchar();
	return 0;
}

