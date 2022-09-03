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
 
int main()
{
    vector<int> d;
    // a Complex object
    Complex com(3.0, 4.0);
 
    // print magnitude
    cout << com.mag() << endl;
    // same can be done like this
    cout << com << endl;
}