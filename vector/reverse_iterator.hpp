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
            // reverse_iterator(Iterator it) : _iter(it) {}
            reverse_iterator() : _iter() {}
            explicit reverse_iterator (iterator_type it):_iter(it){ }
            template <class T>
            reverse_iterator(const reverse_iterator<T> &rev_it) { _iter = rev_it._iter; }
            reverse_iterator &operator=(const reverse_iterator &copy) {_iter = copy._iter;return *this;}
            // --it
            reverse_iterator operator--(){_iter++;return *this;}
            // it--
            reverse_iterator operator--(int) {reverse_iterator _tmp = *this;_iter++; return _tmp;}
            // ++it
            reverse_iterator operator++(){_iter--;return *this;}
            // it++
            reverse_iterator operator++(int){reverse_iterator _tmp = *this; _iter--; return _tmp;}
            bool operator==(const reverse_iterator &other) { return (_iter == other._iter); }
            bool operator!=(const reverse_iterator &other) { return !operator==(other); }
            reference operator*() const{Iterator tmp = _iter;--tmp; return *(tmp);}
            pointer operator->() { return &(operator*()); }
            reverse_iterator operator+ (difference_type n) const { return reverse_iterator(_iter - n); }
            reverse_iterator operator- (difference_type n) const { return reverse_iterator(_iter + n); }
            reverse_iterator& operator+= (difference_type n){_iter -= n; return *this;}
            reverse_iterator& operator-= (difference_type n){_iter += n; return *this;}
            bool operator<(const reverse_iterator &other) { return !(_iter < other._iter); }
            bool operator>(const reverse_iterator &other) { return !(_iter > other._iter); }
            bool operator<=(const reverse_iterator &other) { return other._iter <= _iter; }
            bool operator>=(const reverse_iterator &other) { return other._iter >= _iter; }
            reference operator[](int index) { return *(_iter + index); }
            Iterator base() const {return _iter;}
    };


    template <class Iterator>
    reverse_iterator<Iterator> operator+( typename reverse_iterator<Iterator>::difference_type a, const reverse_iterator<Iterator> &it)
    {
        return reverse_iterator<Iterator>(it.base() + a);
    }
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() - rhs.base);
    }
    template <class Iterator>
    bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return !operator==(lhs,rhs);
    }
    template <class Iterator>
    bool operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator>
    bool operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator>
    bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
};


#endif