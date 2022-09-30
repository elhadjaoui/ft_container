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
#include "./stack/stack.hpp"
#include "./map/pair.hpp"
#include "./map/make_pair.hpp"
// #include "./map/map.hpp"


using namespace std;
// map::begin/end
#include <iostream>
#include <map>

 
// Driver Code
int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;
   mymap.insert(std::pair<char,int>('a',20));
   mymap.insert(std::pair<char,int>('b',20));
   mymap.insert(std::pair<char,int>('c',30));
   mymap.insert(std::pair<char,int>('d',40));
   mymap.insert(std::pair<char,int>('e',50));
   mymap.insert(std::pair<char,int>('f',60));

//   it=mymap.find('b');
//   mymap.erase (it);                   // erasing by iterator

//   mymap.erase ('c');                  // erasing by key

//   it=mymap.find ('e');
//   mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}