#include<iostream>

void foo(){std::cout <<"foo()" << std::endl;}
void foo(int a = 0) {std::cout << "foo(int)" << std::endl;}

int main(){
    foo();
    return 0;

}