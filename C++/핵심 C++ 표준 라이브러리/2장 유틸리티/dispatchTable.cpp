#include <cmath>
#include <functional>
#include <iostream>
#include <map>

int main(){

  std::cout << std::endl;

  // dispatch table
  std::map< const char , std::function<double(double, double)> > dispTable;
  dispTable.insert( std::make_pair('+', [](double a, double b){ return a + b;}));
  dispTable.insert( std::make_pair('-', [](double a, double b){ return a - b;}));
  dispTable.insert( std::make_pair('*', [](double a, double b){ return a * b;}));
  dispTable.insert( std::make_pair('/', [](double a, double b){ return a / b;}));

  // do the math
  std::cout << "3.5 + 4.5= " << dispTable['+'](3.5, 4.5) << std::endl;
  std::cout << "3.5 - 4.5= " << dispTable['-'](3.5, 4.5) << std::endl;
  std::cout << "3.5 * 4.5= " << dispTable['*'](3.5, 4.5) << std::endl;
  std::cout << "3.5 / 4.5= " << dispTable['/'](3.5, 4.5) << std::endl;

  // add a new operation
  dispTable.insert( std::make_pair('^', [](double a, double b){ return std::pow(a, b); }));
  std::cout << "3.5 ^ 4.5= " << dispTable['^'](3.5, 4.5) << std::endl;

  std::cout << std::endl;

};