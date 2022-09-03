/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-31
 * 
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

using namespace std;
 
class Complex {
private:
    double real;
    double imag;
 
public:
    // Default constructor
   explicit Complex(double r = 0.0, double i = 0.0)
        : real(r)
        , imag(i)
    {
    }
 
    // magnitude : usual function style
    double mag() { return getMag(); }
 
    // magnitude : conversion operator
    operator double() { return getMag(); }
 
private:
    // class helper to get magnitude
    double getMag()
    {
        return sqrt(real * real + imag * imag);
    }
};


int main () {
  std::vector<int> myvector;
  for (int i=0; i<10; i++) myvector.push_back(i);
typedef std::vector<int>::iterator iter_type;
                                                         // ? 9 8 7 6 5 4 3 2 1 0 ?
  iter_type from (myvector.begin());                     //   ^
                                                         //         ------>
  iter_type until (myvector.end());                      //                       ^
                                                         //
  ft::reverse_iterator<iter_type> rev_until (from);     // ^
                                                         //         <------
  ft::reverse_iterator<iter_type> rev_from (until); 
//   ft::reverse_iterator<std::vector<int>::iterator> from,until;

//  until = from;

  std::cout << "myvector :" << rev_until[3] << ".\n";

  return 0;
}