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
#include "./map/map.hpp"

using namespace std;
// map::begin/end
#include <iostream>
#include <map>
#include <ctime>
#include <iostream>

#include <iostream>
#include <map>

int main()
{
  std::map<int, std::string> m1;
  ft::map<int, std::string> ft_m1;
  for (size_t i = 0; i < 10; i++)
  {
    m1.insert(std::make_pair(i, "string2"));
    ft_m1.insert(ft::make_pair(i, "string2"));
  }
  std::map<int, std::string> const m2(m1.rbegin(), m1.rend());
  ft::map<int, std::string> const ft_m2(ft_m1.rbegin(), ft_m1.rend());
  cout << m2.rend()->first << endl;
  cout << ft_m2.rend()->first;
  // std::string res, ft_res, c_res, c_ft_res;

  // for (std::map<int, std::string>::reverse_iterator it = m1.rbegin(); it != m1.rend(); ++it) // fill res from m1
  //   res += it->second;
  // for (std::map<int, std::string>::const_reverse_iterator rit = m2.rbegin(); rit != m2.rend(); ++rit) // fill c_res from const m1
  //   c_res += rit->second;

  // for (ft::map<int, std::string>::reverse_iterator it = ft_m1.rbegin(); it != ft_m1.rend(); ++it) // fill ft_res from ft_m1
  //   ft_res += it->second;
  // for (ft::map<int, std::string>::const_reverse_iterator rit = ft_m2.rbegin(); rit != ft_m2.rend(); ++rit) // fill c_ft_res from const ft_m1
  //   c_ft_res += rit->second;

  return 0;
}

// system("leaks a.out");