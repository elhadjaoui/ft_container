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
#include "./vector/is_integral.hpp"
#include "./vector/enable_if.hpp"
#include "./vector/vector.hpp"


using namespace std;

// inserting into a vector
#include <iostream>
#include <vector>

int main ()
{
  ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  ft::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}