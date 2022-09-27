/**
 * @file map.hpp
 * @author Mohamed El Hadjaoui
 * @brief 
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _MAP_HPP
#define _MAP_HPP

#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <memory>                      
#include <functional>
#include "pair.hpp"
#include "bidirectional_iterator.hpp"
#include "../vector/reverse_iterator.hpp" 



namespace ft
{

  template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
    class map
    {
  public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef size_t size_type;

        typedef bidirectional<value_type> iterator;
        typedef bidirectional<const value_type> const_iterator;

        typedef reverse_iterator<iterator> reverse_iterator;
        typedef reverse_iterator<const_iterator> const_reverse_iterator;
        class value_compare : public binary_function<value_type,value_type,bool> 
        {
            friend class map;
            protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {}
            public:
            bool operator()(const value_type& x, const value_type& y) const {
            return comp(x.first, y.first);
        }
        };

    private:
        typedef typename Alloc::template rebind<Node<value_type> >::other node_allocator;
        typedef Node<value_type> *node_pointer;
        typedef Node<const value_type> *const_node_pointer;

    private:
        key_compare _ft_cmp;
        allocator_type _allocator;
        node_pointer _root_;
        size_type _size_;
        node_allocator _node_allocator;

       
    };
}
// template <class Key, class T, class Compare, class Alloc>
// void swap(ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y)
// {
//     x.swap(y);
// }

// template <class Key, class T, class Compare, class Alloc>
// bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
// {
//     return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
// }

// template <class Key, class T, class Compare, class Alloc>
// bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
// {
//     return !(lhs == rhs);
// }

// template <class Key, class T, class Compare, class Alloc>
// bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
// {
//     return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
// }

// template <class Key, class T, class Compare, class Alloc>
// bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
// {
//     return lhs == rhs || lhs < rhs;
// }

// template <class Key, class T, class Compare, class Alloc>
// bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
// {
//     return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
// }

// template <class Key, class T, class Compare, class Alloc>
// bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
// {
//     return lhs == rhs || lhs > rhs;
// }

#endif