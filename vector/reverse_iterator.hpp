/**
 * @file reverse_iterator.hpp
 * @author Mohamed El hadjaoui
 * @brief implementing reverse_iterator
 * @version 0.1
 * @date 2022-09-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _REVERSE_ITERATOR_HPP_
#define _REVERSE_ITERATOR_HPP_

#include "iterator_traits.hpp"
namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
    public:
        typedef Iterator iterator_type;
        typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
        typedef typename iterator_traits<iterator_type>::value_type value_type;
        typedef typename iterator_traits<iterator_type>::difference_type difference_type;
        typedef typename iterator_traits<iterator_type>::pointer pointer;
        typedef typename iterator_traits<iterator_type>::reference reference;

    private:
        Iterator _iter;

    public:
        reverse_iterator(Iter base) : _iter(base) {}

        reverse_iterator() : _iter() {}

        template <class T>
        reverse_iterator(const reverse_iterator<T> &copy) { _iter = copy._iter; }

        reverse_iterator &operator=(const reverse_iterator &copy)
        {
            _iter = copy._iter;
            return *this;
        }
        // --it
        reverse_iterator operator--()
        {
            _iter++;
            return *this;
        }
        // it--
        reverse_iterator operator--(int)
        {
            reverse_iterator _tmp = *this;
            _iter++;
            return _tmp;
        }
        // ++it
        reverse_iterator operator++()
        {
            _iter--;
            return *this;
        }
        // it++
        reverse_iterator operator++(int)
        {
            reverse_iterator _tmp = *this;
            _iter--;
            return _tmp;
        }

        bool operator==(const reverse_iterator &other) { return (_iter == other._iter); }

        bool operator!=(const reverse_iterator &other) { return !operator==(other); }

        reference operator*() const
        {
            Iterator tmp = _iter;
            --tmp;
            return *(tmp);
        }

        pointer operator->() { return &(operator*()); }

        reverse_iterator operator+(int a) { return _iter - a; }

        reverse_iterator operator-(int a) { return _iter + a; }

        void operator-=(int a) { _iter += a; }

        void operator+=(int a) { _iter -= a; }

        difference_type operator-(reverse_iterator &other) { return other._iter - _iter; }

        bool operator<(const reverse_iterator &other) { return !(_iter < other._iter); }

        bool operator>(const reverse_iterator &other) { return !(_iter > other._iter); }

        bool operator<=(const reverse_iterator &other) { return other._iter <= _iter; }

        bool operator>=(const reverse_iterator &other) { return other._iter >= _iter; }

        reference operator[](int index) { return *(_iter + index - 1); }

    };

    template <class T>
    reverse_iterator<T> operator+(int a, reverse_iterator<T> &it)
    {
        return _tmp + a;
    }

};


#endif