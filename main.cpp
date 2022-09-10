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

int main ()
{
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
  std::vector<int> myvector (fifth.begin(),fifth.end());
  std::vector<int>::iterator it;

  it = myvector.begin()  ;
  // it = myvector.insert ( it , 200 );
  // std::cout << ' ' << *it;
  myvector.insert (it,-2,300);

//   // "it" no longer valid, get a new one:
//   it = myvector.begin();

//   std::vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
// system("leaks a.out");
  return 0;
}