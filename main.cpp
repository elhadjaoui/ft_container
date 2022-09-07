/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief c++ -std=c++98 main.cpp ; ./a.out
 * 
 * @version 0.1
 * @date 2022-08-31
 * @copyright Copyright (c) 2022
 * 
 */


#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

// CPP Program to demonstrate Conversion Operators     
#include <cmath>
#include <memory>
#include "./vector/random_access_iterator.hpp"
#include "./vector/reverse_iterator.hpp"
#include "./vector/equal.hpp"
#include "./vector/lexicographical_compare.hpp"

using namespace std;
 
class base {
public:
    virtual void print()
    {
        cout << "print base class\n";
    }
  
    void show()
    {
        cout << "show base class\n";
    }
};
  
class derived : public base {
public:
    void print()
    {
        cout << "print derived class\n";
    }
  
    void show()
    {
        cout << "show derived class\n";
    }
};
  
// is_integral example
#include <iostream>
#include <type_traits>

bool mypredicate (int i, int j) {
  return (i==j);
}

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

int main () {
  char foo[]="Apple";
  char bar[]="apartment";

  std::cout << std::boolalpha;

  std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

  std::cout << "Using default comparison (operator<): ";
  std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
  std::cout << '\n';

  std::cout << "Using mycomp as comparison object: ";
  std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
  std::cout << '\n';

  return 0;
}