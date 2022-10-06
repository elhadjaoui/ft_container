#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

// CPP Program to demonstrate Conversion Operators
#include <cmath>
#include <memory>
#include "../vector/random_access_iterator.hpp"
#include "../vector/reverse_iterator.hpp"
#include "../vector/equal.hpp"
#include "../vector/lexicographical_compare.hpp"
#include "../vector/is_integral.hpp"
#include "../vector/enable_if.hpp"
#include "../vector/vector.hpp"
#include "../stack/stack.hpp"
#include "../map/pair.hpp"
#include "../map/make_pair.hpp"
#include "../map/map.hpp"
using namespace std;



int main ()
{
   /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string1");
        std::vector<std::string> v2(20, "string2");
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string1");
        ft::vector<std::string> ft_v2(20, "string2");
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

//  system("leaks container");
  return 0;
}