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
            iterator_type _iter;

        public:
            reverse_iterator() : _iter() {}
            explicit reverse_iterator (iterator_type it)
            {
                // std::cout << "ues\n";
                _iter = it;
            }
            template <class T>
            reverse_iterator(const reverse_iterator<T> &rev_it) { _iter = rev_it.base(); }
            reverse_iterator &operator=(const reverse_iterator &copy) {_iter = copy._iter;return *this;}
            Iterator base(){return _iter;}
            // --it
            reverse_iterator operator--(){_iter++;return *this;}
            // it--
            reverse_iterator operator--(int) {reverse_iterator _tmp = *this;_iter++; return _tmp;}
            // ++it
            reverse_iterator operator++(){_iter--;return *this;}
            // it++
            reverse_iterator operator++(int){reverse_iterator _tmp = *this; _iter--; return _tmp;}
            reference operator*() const
            {
                Iterator tmp = _iter;
                --tmp; 
                return *(tmp);
            }
            pointer operator->() { return &(operator*()); }
            reverse_iterator operator+ (difference_type n)  { return reverse_iterator(_iter - n); }
            reverse_iterator operator- (difference_type n)  { return reverse_iterator(_iter + n); }
            reverse_iterator& operator+= (difference_type n){_iter -= n; return *this;}
            reverse_iterator& operator-= (difference_type n){_iter += n; return *this;}
            reference operator[](difference_type index) { return *(_iter + index - 1); }
            Iterator base() const {return _iter;}
    };


    template <class Iterator>
    reverse_iterator<Iterator> operator+( typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &it)
    {
        reverse_iterator<Iterator> A(it);
       for (int i = 0; i < n; i++)
			A++;
		return (A);
    }
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (std::distance(lhs.base() , rhs.base()));
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