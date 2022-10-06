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
typedef std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> iter_def;
typedef ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ft_iter_def;
typedef std::pair<std::map<int, std::string>::const_iterator, std::map<int, std::string>::const_iterator> const_iter_def;
typedef ft::pair<ft::map<int, std::string>::const_iterator, ft::map<int, std::string>::const_iterator> ft_const_iter_def;
// int main()
// {
//             iter_def res;
//             ft_iter_def ft_res;

//             std::map<int, std::string> m;
//             ft::map<int, std::string> ft_m;
//             for (size_t i = 0; i < 1e6; ++i)
//             {
//                 m.insert(std::make_pair(i, "value"));
//                 ft_m.insert(ft::make_pair(i, "value"));
//             }
//             res = m.equal_range(1e5);
//             ft_res = ft_m.equal_range(1e5);
//             if  ((ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first))
//             {
//                 cout << "Done\n";
//             }

//   return 0;
// }

int main ()
{
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}

// system("leaks a.out");