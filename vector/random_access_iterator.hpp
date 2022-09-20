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
        __wrap_iter(const __wrap_iter<T> &copy) : _i(copy._i) {}
        template <class T>
        __wrap_iter &operator=(const __wrap_iter<T> &copy)
        {
            _i = copy._i;
            return *this;
        }
        __wrap_iter operator--()
        {
            _i--;
            return *this;
        }
        // a--
        __wrap_iter operator--(int)
        {
            __wrap_iter _old = *this;
            _i--;
            return _old;
        }
        // ++a
        __wrap_iter operator++()
        {
            _i++;
            return *this;
        }
        // a++
        __wrap_iter operator++(int)
        {
            __wrap_iter _old = *this;
            _i++;
            return _old;
        }

        template <class T>
        bool operator==(const __wrap_iter<T> &other)
        {
            return (_i == other._i);
        }

        template <class T>
        bool operator!=(const __wrap_iter<T> &other)
        {
            return !operator==(other);
        }

        reference operator*() const { return *_i; }

        pointer operator->() { return _i; }

        __wrap_iter operator+(int a) { return _i + a; }

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
        template<class T>
        __wrap_iter<T> operator+(int a,__wrap_iter<T> it) 
        { 
            __wrap_iter<T> _tmp = it; 
            return _tmp + a;
        }
    };

}

#endif

/*
namespace ft{

template <class Iter>
class myIter
{
public:
    typedef typename iterator_traits<Iter>::reference           reference;
    typedef typename iterator_traits<Iter>::pointer             pointer;
    typedef typename iterator_traits<Iter>::value_type          value_type;
    typedef typename iterator_traits<Iter>::difference_type     difference_type;
    typedef typename iterator_traits<Iter>::iterator_category   iterator_category;

private:
    pointer _base;

public:
    myIter(pointer base)
    : _base(base)
    {}

    myIter()
    : _base()
    {}

    template <class T>
    myIter(const myIter<T> &copy)
    : _base(copy.base())
    {}

    template <class T>
    myIter &operator=(const myIter<T> &copy) { _base = copy.base(); return *this;}
    // --it
    myIter operator--() { _base--; return *this; }
    // it--
    myIter operator--(int) { myIter _tmp = *this; _base--; return _tmp; }
    // ++it
    myIter operator++() { _base++; return *this; }
    // it++
    myIter operator++(int) { myIter _tmp = *this; _base++; return _tmp; }

    template <class T>
    bool operator==(const myIter<T> &other) { return (_base == other.base()); }

    template <class T>
    bool operator!=(const myIter<T> &other) { return !operator==(other); }

    reference operator*() const  { return *_base; }

    pointer operator->() { return _base; }

    myIter operator+(int a) { return _base + a; }

    myIter operator-(int a) { return myIter(_base - a); }

    void operator-=(int a) { _base -= a; }

    void operator+=(int a) { _base += a;}

    template <class T>
    difference_type operator-(myIter<T> other) { return _base - other.base(); }

    template <class T>
    bool operator<(const myIter<T> &other) { return _base < other._base; }

    template <class T>
    bool operator>(const myIter<T> &other) { return _base > other._base; }

    template <class T>
    bool operator<=(const myIter<T> &other) { return _base <= other._base; }

    template <class T>
    bool operator>=(const myIter<T> &other) { return _base >= other._base; }

    reference operator[](int index) { return *(_base + index);}

    pointer base() const {return _base;}
};

template<class T>
myIter<T> operator+(int a,myIter<T> it) { myIter<T> _tmp = it; return _tmp + a; }
};

#endif
*/