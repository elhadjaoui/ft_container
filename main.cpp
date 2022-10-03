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

int main ()
{
         ft::map<int, std::string> ft_m;
            for (size_t i = 0; i < 1e6; ++i)
            {
                ft_m.insert(ft::make_pair(i, "value"));
            }

  return 0;
}
  // system("leaks a.out");