/**
 * @file random_access_iterator.hpp
 * @author Mohamed El hadjaoui (you@domain.com)
 * @brief random access iterator      
 * @version 0.1
 * @date 2022-09-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _RANDOM_ACCESS_ITERATOR_HPP_
#define _RANDOM_ACCESS_ITERATOR_HPP_

#include "iterator_traits.hpp"

namespace ft
{

    template <class _Iter>
    class __wrap_iter
    {
    public:
        typedef _Iter iterator_type;
        typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
        typedef typename iterator_traits<iterator_type>::value_type value_type;
        typedef typename iterator_traits<iterator_type>::difference_type difference_type;
        typedef typename iterator_traits<iterator_type>::pointer pointer;
        typedef typename iterator_traits<iterator_type>::reference reference;

    private:
        pointer _i;

    public:
        __wrap_iter() : _i() {}
        template <class T>
        __wrap_iter(const __wrap_iter<T> &copy) : _i(copy.base()) {}
        __wrap_iter(pointer _new_i):_i(_new_i){}
        pointer base() const  {return _i;};
        template <class T>
        __wrap_iter &operator=(const __wrap_iter<T> &copy){ _i = copy.base();  return *this;}
        __wrap_iter operator--(){ _i--; return *this;}
        // a--
        __wrap_iter operator--(int){ __wrap_iter _old = *this; _i--; return _old;}
        // ++a
        __wrap_iter operator++(){_i++; return *this;}
        // a++
        __wrap_iter operator++(int){ __wrap_iter _old = *this; _i++; return _old;}

        template <class T>
        bool operator==(const __wrap_iter<T> &other){ return (_i == other._i);}

        template <class T>
        bool operator!=(const __wrap_iter<T> &other){ return !operator==(other);}

        reference operator*() const { return *_i; }

        pointer operator->() const { return _i; }

        __wrap_iter operator+(int a) { return __wrap_iter(_i + a); }

        __wrap_iter operator-(int a) { return __wrap_iter(_i - a); }

        void operator-=(int a) { _i -= a; }

        void operator+=(int a) { _i += a; }

        template <class T>
        difference_type operator-(__wrap_iter<T> other) { return _i - other._i; }

        template <class T>
        bool operator<(const __wrap_iter<T> &other) { return _i < other._i; }

        template <class T>
        bool operator>(const __wrap_iter<T> &other) { return _i > other._i; }

        template <class T>
        bool operator<=(const __wrap_iter<T> &other) { return _i <= other._i; }

        template <class T>
        bool operator>=(const __wrap_iter<T> &other) { return _i >= other._i; }

        reference operator[](int index) { return *(_i + index); }
    };
        template<class T>
        __wrap_iter<T> operator+(int a,__wrap_iter<T> it) 
        { 
            return it + a;
        }

}

#endif

