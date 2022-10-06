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

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
  bool operator()(const char &lhs, const char &rhs) const
  {
    return lhs < rhs;
  }
};

int main()
{
  {
      //   cout << "************************ STD Constructors **********************\n";
      //   std::map<char,int> first;

      //   first['a']=10;
      //   first['b']=30;
      //   first['c']=50;
      //   first['d']=70;

      //   std::map<char,int> second (first.begin(),first.end());

      //   std::map<char,int> third (second);

      //   std::map<char,int,classcomp> fourth;                 // class as Compare

      //   bool(*fn_pt)(char,char) = fncomp;
      //   std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
  } {
      //   cout << "************************ FT Constructors **********************\n";
      //   ft::map<char,int> first;

      //   first['a']=10;
      //   first['b']=30;
      //   first['c']=50;
      //   first['d']=70;

      //   ft::map<char,int> second (first.begin(),first.end());

      //   ft::map<char,int> third (second);

      //   ft::map<char,int,classcomp> fourth;                 // class as Compare

      //   bool(*fn_pt)(char,char) = fncomp;
      //   ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
      //   system("leaks container");
  } {
      //   cout << "************************ STD Begin **********************\n";
      //   std::map<char,int> mymap;

      //   mymap['b'] = 100;
      //   mymap['a'] = 200;
      //   mymap['c'] = 300;

      //   // show content:
      //   for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
      //     std::cout << it->first << " => " << it->second << '\n';
  } {
      //   cout << "************************ FT Begin **********************\n";
      //   ft::map<char,int> mymap;

      //   mymap['b'] = 100;
      //   mymap['a'] = 200;
      //   mymap['c'] = 300;

      //   // show content:
      //   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
      //     std::cout << it->first << " => " << it->second << '\n';
      //   system("leaks container");
  } {
      // cout << "************************ STD Clear **********************\n";
      // std::map<char, int> mymap;

      // mymap['x'] = 100;
      // mymap['y'] = 200;
      // mymap['z'] = 300;

      // std::cout << "mymap contains:\n";
      // for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
      //   std::cout << it->first << " => " << it->second << '\n';

      // mymap.clear();
      // mymap['a'] = 1101;
      // mymap['b'] = 2202;

      // std::cout << "mymap contains:\n";
      // for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
      //   std::cout << it->first << " => " << it->second << '\n';
  } {
      // cout << "************************ FT Clear **********************\n";
      // ft::map<char, int> mymap;

      // mymap['x'] = 100;
      // mymap['y'] = 200;
      // mymap['z'] = 300;

      // cout << "mymap contains:\n";
      // for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
      //   std::cout << it->first << " => " << it->second << '\n';

      // mymap.clear();
      // mymap['a'] = 1101;
      // mymap['b'] = 2202;

      // std::cout << "mymap contains:\n";
      // for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
      //   std::cout << it->first << " => " << it->second << '\n';
      // system("leaks container");
  } {
      // cout << "************************ STD Count **********************\n";
      // std::map<char, int> mymap;
      // char c;

      // mymap['a'] = 101;
      // mymap['c'] = 202;
      // mymap['f'] = 303;

      // for (c = 'a'; c < 'h'; c++)
      // {
      //   std::cout << c;
      //   if (mymap.count(c) > 0)
      //     std::cout << " is an element of mymap.\n";
      //   else
      //     std::cout << " is not an element of mymap.\n";
      // }
  } {
      // cout << "************************ FT Count **********************\n";
      // ft::map<char, int> mymap;
      // char c;

      // mymap['a'] = 101;
      // mymap['c'] = 202;
      // mymap['f'] = 303;

      // for (c = 'a'; c < 'h'; c++)
      // {
      //   std::cout << c;
      //   if (mymap.count(c) > 0)
      //     std::cout << " is an element of mymap.\n";
      //   else
      //     std::cout << " is not an element of mymap.\n";
      // }
      // system("leaks container");
  } {
      // cout << "************************ STD empty **********************\n";

      // std::map<char, int> mymap;

      // mymap['a'] = 10;
      // mymap['b'] = 20;
      // mymap['c'] = 30;

      // while (!mymap.empty())
      // {
      //   std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
      //   mymap.erase(mymap.begin());
      // }
  } {
      // cout << "************************ FT empty **********************\n";
      // ft::map<char, int> mymap;
      // mymap['a'] = 10;
      // mymap['b'] = 20;
      // mymap['c'] = 30;

      // while (!mymap.empty())
      // {
      //   std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
      //   mymap.erase(mymap.begin());
      // }
      //  system("leaks container");
  } {
      // cout << "************************ STD end **********************\n";
      // std::map<char, int> mymap;

      // mymap['b'] = 100;
      // mymap['a'] = 200;
      // mymap['c'] = 300;

      // // show content:
      // for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
      //   std::cout << it->first << " => " << it->second << '\n';
  } {
      // cout << "************************ FT end **********************\n";
      // ft::map<char, int> mymap;

      // mymap['b'] = 100;
      // mymap['a'] = 200;
      // mymap['c'] = 300;

      // // show content:
      // for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
      //   std::cout << it->first << " => " << it->second << '\n';
      //   system("leaks container");
  } {
      // cout << "************************ STD equal range **********************\n";
      // std::map<char, int> mymap;

      // mymap['a'] = 10;
      // mymap['b'] = 20;
      // mymap['c'] = 30;

      // std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> ret;
      // ret = mymap.equal_range('b');

      // std::cout << "lower bound points to: ";
      // std::cout << ret.first->first << " => " << ret.first->second << '\n';

      // std::cout << "upper bound points to: ";
      // std::cout << ret.second->first << " => " << ret.second->second << '\n';
  } {
      // cout << "************************ FT equal range **********************\n";
      // ft::map<char, int> mymap;

      // mymap['a'] = 10;
      // mymap['b'] = 20;
      // mymap['c'] = 30;

      // ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
      // ret = mymap.equal_range('b');

      // std::cout << "lower bound points to: ";
      // std::cout << ret.first->first << " => " << ret.first->second << '\n';

      // std::cout << "upper bound points to: ";
      // std::cout << ret.second->first << " => " << ret.second->second << '\n';
      // system("leaks container");
  } {
    // cout << "************************ STD erase **********************\n";
    // std::map<char, int> mymap;
    // std::map<char, int>::iterator it;
    // // insert some values:
    // mymap['a'] = 10;
    // mymap['b'] = 20;
    // mymap['c'] = 30;
    // mymap['d'] = 40;
    // mymap['e'] = 50;
    // mymap['f'] = 60;

    // it = mymap.find('b');
    // mymap.erase(it); // erasing by iterator

    // mymap.erase('c'); // erasing by key

    // it = mymap.find('e');
    // mymap.erase(it, mymap.end()); // erasing by range

    // // show content:
    // for (it = mymap.begin(); it != mymap.end(); ++it)
    //   std::cout << it->first << " => " << it->second << '\n';
  }
  {
    cout << "************************ FT erase **********************\n";
    ft::map<char, int> mymap;
    ft::map<char, int>::iterator it;
    // insert some values:
    mymap['a'] = 10;
    mymap['b'] = 20;
    mymap['c'] = 30;
    mymap['d'] = 40;
    mymap['e'] = 50;
    mymap['f'] = 60;
    // mymap.print_tree();
    it = mymap.find('b');
    mymap.erase(it); // erasing by iterator

    mymap.erase('c'); // erasing by key

    it = mymap.find('e');
    mymap.erase(it, mymap.end()); // erasing by range

    // show content:
    for (it = mymap.begin(); it != mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
      system("leaks container");
  }
  return 0;
}