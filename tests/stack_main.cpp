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

void leaks()
{
  cout << endl
       << endl;
  system("leaks container");
}
int main()
{
  // {
  //   cout << "************************ STD Constructors **********************\n";
  //  std::deque<int> mydeque (3,100);          // deque with 3 elements
  // std::vector<int> myvector (2,200);        // vector with 2 elements

  // std::stack<int> first;                    // empty stack
  // std::stack<int, std::deque<int> > second;         // stack initialized to copy of deque

  // std::stack<int,std::vector<int> > third;  // empty stack using vector
  // std::stack<int,std::vector<int> > fourth (myvector);

  // std::cout << "size of first: " << first.size() << '\n';
  // std::cout << "size of second: " << second.size() << '\n';
  // std::cout << "size of third: " << third.size() << '\n';
  // std::cout << "size of fourth: " << fourth.size() << '\n';
  // }
  // {
  //   cout << "************************ FT Constructors **********************\n";
  //   std::deque<int> mydeque (3,100);          // deque with 3 elements
  // ft::vector<int> myvector (2,200);        // vector with 2 elements

  // ft::stack<int> first;                    // empty stack
  // ft::stack<int , std::deque<int> > second ;         // stack initialized to copy of deque

  // ft::stack<int,ft::vector<int> > third;  // empty stack using vector
  // ft::stack<int,ft::vector<int> > fourth (myvector);

  // std::cout << "size of first: " << first.size() << '\n';
  // std::cout << "size of second: " << second.size() << '\n';
  // std::cout << "size of third: " << third.size() << '\n';
  // std::cout << "size of fourth: " << fourth.size() << '\n';
  //   leaks();
  // }
  // {
  //   cout << "************************ STD empty **********************\n";

  //   std::stack<int> mystack;
  //   int sum(0);

  //   for (int i = 1; i <= 10; i++)
  //     mystack.push(i);

  //   while (!mystack.empty())
  //   {
  //     sum += mystack.top();
  //     mystack.pop();
  //   }

  //   std::cout << "total: " << sum << '\n';
  // }
  // {
  //   cout << "************************ FT empty **********************\n";

  //   ft::stack<int> mystack;
  //   int sum(0);

  //   for (int i = 1; i <= 10; i++)
  //     mystack.push(i);

  //   while (!mystack.empty())
  //   {
  //     sum += mystack.top();
  //     mystack.pop();
  //   }

  //   std::cout << "total: " << sum << '\n';
  //   leaks();
  // }
  // {
  //   cout << "************************ STD pop **********************\n";
  //   std::stack<int> mystack;

  //   for (int i = 0; i < 5; ++i)
  //     mystack.push(i);

  //   std::cout << "Popping out elements...";
  //   while (!mystack.empty())
  //   {
  //     std::cout << ' ' << mystack.top();
  //     mystack.pop();
  //   }
  //   std::cout << '\n';
  // }
  // {
  //   cout << "************************ FT pop **********************\n";
  //   ft::stack<int> mystack;

  //   for (int i = 0; i < 5; ++i)
  //     mystack.push(i);

  //   std::cout << "Popping out elements...";
  //   while (!mystack.empty())
  //   {
  //     std::cout << ' ' << mystack.top();
  //     mystack.pop();
  //   }
  //   std::cout << '\n';
  //   leaks();
  // }
  // {
  //   cout << "************************ STD push **********************\n";
  //   std::stack<int> mystack;

  //   for (int i = 0; i < 5; ++i)
  //     mystack.push(i);

  //   std::cout << "Popping out elements...";
  //   while (!mystack.empty())
  //   {
  //     std::cout << ' ' << mystack.top();
  //     mystack.pop();
  //   }
  //   std::cout << '\n';
  // }
  // {
  //   cout << "************************ FT push **********************\n";
  //   ft::stack<int> mystack;

  //   for (int i = 0; i < 5; ++i)
  //     mystack.push(i);

  //   std::cout << "Popping out elements...";
  //   while (!mystack.empty())
  //   {
  //     std::cout << ' ' << mystack.top();
  //     mystack.pop();
  //   }
  //   std::cout << '\n';
  //   leaks();
  // }
  // {
  //   cout << "************************ STD size **********************\n";
  //   std::stack<int> myints;
  //   std::cout << "0. size: " << myints.size() << '\n';

  //   for (int i = 0; i < 5; i++)
  //     myints.push(i);
  //   std::cout << "1. size: " << myints.size() << '\n';

  //   myints.pop();
  //   std::cout << "2. size: " << myints.size() << '\n';
  // }
  // {
  //   cout << "************************ FT size **********************\n";
  //   std::stack<int> myints;
  //   std::cout << "0. size: " << myints.size() << '\n';

  //   for (int i = 0; i < 5; i++)
  //     myints.push(i);
  //   std::cout << "1. size: " << myints.size() << '\n';

  //   myints.pop();
  //   std::cout << "2. size: " << myints.size() << '\n';
  //   leaks();
  // }
  // {
  //   cout << "************************ STD size **********************\n";
  //   std::stack<int> mystack;

  //   mystack.push(10);
  //   mystack.push(20);

  //   mystack.top() -= 5;

  //   std::cout << "mystack.top() is now " << mystack.top() << '\n';
  // }
  // {
  //   cout << "************************ FT size **********************\n";
  //   ft::stack<int> mystack;

  //   mystack.push(10);
  //   mystack.push(20);

  //   mystack.top() -= 5;

  //   std::cout << "mystack.top() is now " << mystack.top() << '\n';
  //   leaks();
  // }
  {
    cout << "************************ STD :relational operators **********************\n";
    std::stack<int> mystack;
    std::stack<int> mystack1;

    mystack.push(10);
    mystack.push(20);

    mystack1.push(10);
    mystack1.push(20);
    if (mystack1 == mystack)
      cout << "Equal\n";
    if (mystack1 != mystack)
      cout << "Not Equal\n";
    if (mystack1 < mystack)
      cout << "Less\n";
    if (mystack1 <= mystack)
      cout << "Less than or Equal\n";
    if (mystack1 > mystack)
      cout << "Greater\n";
    if (mystack1 >= mystack)
      cout << "Greater than or Equal\n";
  }
  {
    cout << "************************ STD :relational operators **********************\n";
    ft::stack<int> mystack;
    ft::stack<int> mystack1;

    mystack.push(10);
    mystack.push(20);

    mystack1.push(10);
    mystack1.push(20);
    if (mystack1 == mystack)
      cout << "Equal\n";
    if (mystack1 != mystack)
      cout << "Not Equal\n";
    if (mystack1 < mystack)
      cout << "Less\n";
    if (mystack1 <= mystack)
      cout << "Less than or Equal\n";
    if (mystack1 > mystack)
      cout << "Greater\n";
    if (mystack1 >= mystack)
      cout << "Greater than or Equal\n";
    leaks();
  }
  return 0;
}