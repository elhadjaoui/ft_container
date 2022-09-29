
#ifndef _ITERATOR_TRAITS_HPP_
#define _ITERATOR_TRAITS_HPP_

#include <iterator>
// #include <stddef.h>

// class template specialization

namespace ft
{
    template <class T>
    class iterator_traits
    {
    public:
        typedef typename T::value_type value_type;
        typedef typename T::reference reference;
        typedef typename T::pointer pointer;
        typedef typename T::difference_type difference_type;
        typedef typename T::iterator_category iterator_category;
    };

    template <class T>
    class iterator_traits<T *>
    {
    public:
        typedef T value_type;
        typedef T &reference;
        typedef T *pointer;
        typedef ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <class T>
    class iterator_traits<const T *>
    {
    public:
        typedef const T value_type;
        typedef std::random_access_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
        typedef const T *pointer;
        typedef const T &reference;
    };
};

#endif