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

void leaks()
{
    cout << endl
         << endl;
    system("leaks container");
}

int main()
{
    {
          cout << "************************ STD Constructors **********************\n";
          std::map<char,int> first;

          first['a']=10;
          first['b']=30;
          first['c']=50;
          first['d']=70;

          std::map<char,int> second (first.begin(),first.end());

          std::map<char,int> third (second);

          std::map<char,int,classcomp> fourth;                 // class as Compare

          bool(*fn_pt)(char,char) = fncomp;
          std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
    } {
          cout << "************************ FT Constructors **********************\n";
          ft::map<char,int> first;

          first['a']=10;
          first['b']=30;
          first['c']=50;
          first['d']=70;

          ft::map<char,int> second (first.begin(),first.end());

          ft::map<char,int> third (second);

          ft::map<char,int,classcomp> fourth;                 // class as Compare

          bool(*fn_pt)(char,char) = fncomp;
          ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
         leaks();
    } {
          cout << "************************ STD Begin **********************\n";
          std::map<char,int> mymap;

          mymap['b'] = 100;
          mymap['a'] = 200;
          mymap['c'] = 300;

          // show content:
          for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    } {
          cout << "************************ FT Begin **********************\n";
          ft::map<char,int> mymap;

          mymap['b'] = 100;
          mymap['a'] = 200;
          mymap['c'] = 300;

          // show content:
          for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
         leaks();
    } {
        cout << "************************ STD Clear **********************\n";
        std::map<char, int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        std::cout << "mymap contains:\n";
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';

        mymap.clear();
        mymap['a'] = 1101;
        mymap['b'] = 2202;

        std::cout << "mymap contains:\n";
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';
    } {
        cout << "************************ FT Clear **********************\n";
        ft::map<char, int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        cout << "mymap contains:\n";
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';

        mymap.clear();
        mymap['a'] = 1101;
        mymap['b'] = 2202;

        std::cout << "mymap contains:\n";
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';
        leaks();
    } {
        cout << "************************ STD Count **********************\n";
        std::map<char, int> mymap;
        char c;

        mymap['a'] = 101;
        mymap['c'] = 202;
        mymap['f'] = 303;

        for (c = 'a'; c < 'h'; c++)
        {
          std::cout << c;
          if (mymap.count(c) > 0)
            std::cout << " is an element of mymap.\n";
          else
            std::cout << " is not an element of mymap.\n";
        }
    } {
        cout << "************************ FT Count **********************\n";
        ft::map<char, int> mymap;
        char c;

        mymap['a'] = 101;
        mymap['c'] = 202;
        mymap['f'] = 303;

        for (c = 'a'; c < 'h'; c++)
        {
          std::cout << c;
          if (mymap.count(c) > 0)
            std::cout << " is an element of mymap.\n";
          else
            std::cout << " is not an element of mymap.\n";
        }
        leaks();
    } {
        cout << "************************ STD empty **********************\n";

        std::map<char, int> mymap;

        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;

        while (!mymap.empty())
        {
          std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
          mymap.erase(mymap.begin());
        }
    } {
        cout << "************************ FT empty **********************\n";
        ft::map<char, int> mymap;
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;

        while (!mymap.empty())
        {
          std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
          mymap.erase(mymap.begin());
        }
        leaks();
    } {
        cout << "************************ STD end **********************\n";
        std::map<char, int> mymap;

        mymap['b'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;

        // show content:
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';
    } {
        cout << "************************ FT end **********************\n";
        ft::map<char, int> mymap;

        mymap['b'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;

        // show content:
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';
         leaks();
    } {
        cout << "************************ STD equal range **********************\n";
        std::map<char, int> mymap;

        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;

        std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> ret;
        ret = mymap.equal_range('b');

        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';

        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';
    } {
        cout << "************************ FT equal range **********************\n";
        ft::map<char, int> mymap;

        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;

        ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
        ret = mymap.equal_range('b');

        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';

        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';
        leaks();
    } {
        cout << "************************ STD erase **********************\n";
        std::map<char, int> mymap;
        std::map<char, int>::iterator it;
        // insert some values:
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;
        mymap['d'] = 40;
        mymap['e'] = 50;
        mymap['f'] = 60;

        it = mymap.find('b');
        mymap.erase(it); // erasing by iterator

        mymap.erase('c'); // erasing by key

        it = mymap.find('e');
        mymap.erase(it, mymap.end()); // erasing by range

        // show content:
        for (it = mymap.begin(); it != mymap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';
    } {
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
         leaks();
    } {
        cout << "************************ STD find **********************\n";
        std::map<char, int> mymap;
        std::map<char, int>::iterator it;

        mymap['a'] = 50;
        mymap['b'] = 100;
        mymap['c'] = 150;
        mymap['d'] = 200;

        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase(it);

        // print content:
        std::cout << "elements in mymap:" << '\n';
        std::cout << "a => " << mymap.find('a')->second << '\n';
        std::cout << "c => " << mymap.find('c')->second << '\n';
        std::cout << "d => " << mymap.find('d')->second << '\n';
    } {
        cout << "************************ FT find **********************\n";
        ft::map<char, int> mymap;
        ft::map<char, int>::iterator it;

        mymap['a'] = 50;
        mymap['b'] = 100;
        mymap['c'] = 150;
        mymap['d'] = 200;

        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase(it);

        // print content:
        std::cout << "elements in mymap:" << '\n';
        std::cout << "a => " << mymap.find('a')->second << '\n';
        std::cout << "c => " << mymap.find('c')->second << '\n';
        std::cout << "d => " << mymap.find('d')->second << '\n';
        leaks();
    } {
        cout << "************************ STD get_allocator **********************\n";
        int psize;
        std::map<char, int> mymap;
        std::pair<const char, int> *p;

        // allocate an array of 5 elements using mymap's allocator:
        p = mymap.get_allocator().allocate(5);

        // assign some values to array
        psize = sizeof(std::map<char, int>::value_type) * 5;

        std::cout << "The allocated array has a size of " << psize << " bytes.\n";

        mymap.get_allocator().deallocate(p, 5);
    } {
        cout << "************************ FT get_allocator **********************\n";
        int psize;
        ft::map<char, int> mymap;
        ft::pair<const char, int> *p;

        // allocate an array of 5 elements using mymap's allocator:
        p = mymap.get_allocator().allocate(5);

        // assign some values to array
        psize = sizeof(ft::map<char, int>::value_type) * 5;

        std::cout << "The allocated array has a size of " << psize << " bytes.\n";

        mymap.get_allocator().deallocate(p, 5);
        leaks();
    } {
        cout << "************************ STD insert **********************\n";
        std::map<char, int> mymap;

        // first insert function version (single parameter):
        mymap.insert(std::pair<char, int>('a', 100));
        mymap.insert(std::pair<char, int>('z', 200));

        std::pair<std::map<char, int>::iterator, bool> ret;
        ret = mymap.insert(std::pair<char, int>('z', 500));
        if (ret.second == false)
        {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }

        // second insert function version (with hint position):
        std::map<char, int>::iterator it = mymap.begin();
        mymap.insert(it, std::pair<char, int>('b', 300)); // max efficiency inserting
        mymap.insert(it, std::pair<char, int>('c', 400)); // no max efficiency inserting

        // third insert function version (range insertion):
        std::map<char, int> anothermap;
        anothermap.insert(mymap.begin(), mymap.find('c'));

        // showing contents:
        std::cout << "mymap contains:\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "anothermap contains:\n";
        for (it = anothermap.begin(); it != anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    } {
        cout << "************************ FT insert **********************\n";
        ft::map<char, int> mymap;

        // first insert function version (single parameter):
        mymap.insert(ft::pair<char, int>('a', 100));
        mymap.insert(ft::pair<char, int>('z', 200));

        ft::pair<ft::map<char, int>::iterator, bool> ret;
        ret = mymap.insert(ft::pair<char, int>('z', 500));
        if (ret.second == false)
        {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }

        // second insert function version (with hint position):
        ft::map<char, int>::iterator it = mymap.begin();
        mymap.insert(it, ft::pair<char, int>('b', 300)); // max efficiency inserting
        mymap.insert(it, ft::pair<char, int>('c', 400)); // no max efficiency inserting

        // third insert function version (range insertion):
        ft::map<char, int> anothermap;
        anothermap.insert(mymap.begin(), mymap.find('c'));

        // showing contents:
        std::cout << "mymap contains:\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "anothermap contains:\n";
        for (it = anothermap.begin(); it != anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        leaks();
    } {
        cout << "************************ STD key_compare **********************\n";
        std::map<char, int> mymap;

        std::map<char, int>::key_compare mycomp = mymap.key_comp();

        mymap['a'] = 100;
        mymap['b'] = 200;
        mymap['c'] = 300;

        std::cout << "mymap contains:\n";

        char highest = mymap.rbegin()->first; // key value of last element

        std::map<char, int>::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mycomp((*it++).first, highest));
    } {
        cout << "************************ FT key_compare **********************\n";
        ft::map<char, int> mymap;

        ft::map<char, int>::key_compare mycomp = mymap.key_comp();

        mymap['a'] = 100;
        mymap['b'] = 200;
        mymap['c'] = 300;

        std::cout << "mymap contains:\n";

        char highest = mymap.rbegin()->first; // key value of last element

        ft::map<char, int>::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mycomp((*it++).first, highest));
        leaks();
    }
     {
        cout << "************************ STD lower_bound **********************\n";
        std::map<char, int> mymap;
        std::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;

        itlow = mymap.lower_bound('b'); // itlow points to b
        itup = mymap.upper_bound('d');  // itup points to e (not d!)

        mymap.erase(itlow, itup); // erases [itlow,itup)

        // print content:
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        cout << "************************ FT lower_bound **********************\n";
        ft::map<char, int> mymap;
        ft::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;

        itlow = mymap.lower_bound('b'); // itlow points to b
        itup = mymap.upper_bound('d');  // itup points to e (not d!)

        mymap.erase(itlow, itup); // erases [itlow,itup)

        // print content:
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        leaks();
    }
    {
        cout << "************************ STD upper_bound **********************\n";
        std::map<char, int> mymap;
        std::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;

        itlow = mymap.lower_bound('b'); // itlow points to b
        itup = mymap.upper_bound('d');  // itup points to e (not d!)

        mymap.erase(itlow, itup); // erases [itlow,itup)

        // print content:
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        cout << "************************ FT upper_bound **********************\n";
        ft::map<char, int> mymap;
        ft::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;

        itlow = mymap.lower_bound('b'); // itlow points to b
        itup = mymap.upper_bound('d');  // itup points to e (not d!)

        mymap.erase(itlow, itup); // erases [itlow,itup)

        // print content:
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        leaks();
    }
    {
        cout << "************************ STD max_size **********************\n";

        int i;
        std::map<int, int> mymap;

        if (mymap.max_size() > 1000)
        {
            for (i = 0; i < 1000; i++)
                mymap[i] = 0;
            std::cout << "The map contains 1000 elements.\n";
        }
        else
            std::cout << "The map could not hold 1000 elements.\n";
    }
    {
        cout << "************************ FT max_size **********************\n";

        int i;
        ft::map<int, int> mymap;

        if (mymap.max_size() > 1000)
        {
            for (i = 0; i < 1000; i++)
                mymap[i] = 0;
            std::cout << "The map contains 1000 elements.\n";
        }
        else
            std::cout << "The map could not hold 1000 elements.\n";
            leaks();
    }
    {
        cout << "************************ STD  operator[] **********************\n";

        std::map<char, std::string> mymap;

        mymap['a'] = "an element";
        mymap['b'] = "another element";
        mymap['c'] = mymap['b'];

        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';

        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    }
    {
        cout << "************************ FT  operator[] **********************\n";

        ft::map<char, std::string> mymap;

        mymap['a'] = "an element";
        mymap['b'] = "another element";
        mymap['c'] = mymap['b'];

        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';

        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
        leaks();
    }

    {
        cout << "************************ STD  rbegin **********************\n";
        std::map<char, int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        // show content:
        std::map<char, int>::reverse_iterator rit;
        for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
    }
    {
        cout << "************************ FT  rbegin **********************\n";
        ft::map<char, int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        // show content:
        ft::map<char, int>::reverse_iterator rit;
        for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
        leaks();
    }
    {
        cout << "************************ STD  rend **********************\n";
        std::map<char, int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        // show content:
        std::map<char, int>::reverse_iterator rit;
        for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
    }
    {
        cout << "************************ FT  rend **********************\n";
        ft::map<char, int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        // show content:
        ft::map<char, int>::reverse_iterator rit;
        for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
        leaks();
    }
    {
        cout << "************************ STD  size **********************\n";
        std::map<char, int> mymap;
        mymap['a'] = 101;
        mymap['b'] = 202;
        mymap['c'] = 302;

        std::cout << "mymap.size() is " << mymap.size() << '\n';
    }
    {
        cout << "************************ FT  size **********************\n";
        ft::map<char, int> mymap;
        mymap['a'] = 101;
        mymap['b'] = 202;
        mymap['c'] = 302;

        std::cout << "mymap.size() is " << mymap.size() << '\n';
        leaks();
    }
    {
        cout << "************************ STD  swap **********************\n";
        std::map<char, int> foo, bar;

        foo['x'] = 100;
        foo['y'] = 200;

        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;

        foo.swap(bar);

        std::cout << "foo contains:\n";
        for (std::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "bar contains:\n";
        for (std::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        cout << "************************ FT  swap **********************\n";
        ft::map<char, int> foo, bar;

        foo['x'] = 100;
        foo['y'] = 200;

        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;

        foo.swap(bar);

        std::cout << "foo contains:\n";
        for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "bar contains:\n";
        for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        leaks();
    }
    {
        cout << "************************ STD  value_comp **********************\n";
        std::map<char, int> mymap;

        mymap['x'] = 1001;
        mymap['y'] = 2002;
        mymap['z'] = 3003;

        std::cout << "mymap contains:\n";

        std::pair<char, int> highest = *mymap.rbegin(); // last element

        std::map<char, int>::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mymap.value_comp()(*it++, highest));
    }
    {
        cout << "************************ FT  value_comp **********************\n";
        ft::map<char, int> mymap;

        mymap['x'] = 1001;
        mymap['y'] = 2002;
        mymap['z'] = 3003;

        std::cout << "mymap contains:\n";

        ft::pair<char, int> highest = *mymap.rbegin(); // last element

        ft::map<char, int>::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mymap.value_comp()(*it++, highest));
        leaks();
    }
    {
        cout << "************************ STD  relational operators  **********************\n";
        std::map<char, int> foo, bar;
        foo['a'] = 100;
        foo['b'] = 200;
        bar['a'] = 10;
        bar['z'] = 1000;

        // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
        if (foo == bar)
            std::cout << "foo and bar are equal\n";
        if (foo != bar)
            std::cout << "foo and bar are not equal\n";
        if (foo < bar)
            std::cout << "foo is less than bar\n";
        if (foo > bar)
            std::cout << "foo is greater than bar\n";
        if (foo <= bar)
            std::cout << "foo is less than or equal to bar\n";
        if (foo >= bar)
            std::cout << "foo is greater than or equal to bar\n";
    }
    {
        cout << "************************ FT  relational operators  **********************\n";
        ft::map<char, int> foo, bar;
        foo['a'] = 100;
        foo['b'] = 200;
        bar['a'] = 10;
        bar['z'] = 1000;

        // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
        if (foo == bar)
            std::cout << "foo and bar are equal\n";
        if (foo != bar)
            std::cout << "foo and bar are not equal\n";
        if (foo < bar)
            std::cout << "foo is less than bar\n";
        if (foo > bar)
            std::cout << "foo is greater than bar\n";
        if (foo <= bar)
            std::cout << "foo is less than or equal to bar\n";
        if (foo >= bar)
            std::cout << "foo is greater than or equal to bar\n";
        leaks();
    }
    {
        cout << "************************ STD  swap  **********************\n";

        std::map<char, int> foo, bar;

        foo['x'] = 100;
        foo['y'] = 200;

        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;

        swap(foo, bar);

        std::cout << "foo contains:\n";
        for (std::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "bar contains:\n";
        for (std::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        cout << "************************ FT  swap  **********************\n";

        ft::map<char, int> foo, bar;

        foo['x'] = 100;
        foo['y'] = 200;

        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;

        swap(foo, bar);

        std::cout << "foo contains:\n";
        for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "bar contains:\n";
        for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        leaks();
    }
    return 0;
}