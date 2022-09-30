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
#include "../vector/reverse_iterator.hpp" 

#include "avl.hpp"

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
        typedef reverse_iterator<iterator> reverse_it;
        typedef reverse_iterator<const_iterator> const_reverse_iterator;
        class value_compare : public std::binary_function<value_type,value_type,bool> 
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
        AVL<value_type, key_compare, allocator_type> _my_tree;
        size_type _size;
        allocator_type _allocator;
        key_compare _comare_key;

        explicit map(const Compare& comp = Compare(),const allocator_type& = allocator_type()) : _size(0), _my_tree(NULL) {}
        template <class InputIterator>
        map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const allocator_type& = allocator_type());
        map(const map<Key,T,Compare,allocator_type>& x);
        ~map();
        map<Key,T,Compare,allocator_type>&operator=(const map<Key,T,Compare,allocator_type>& x)
        {
          clear();
          insert(x.begin(), x.end());
          return *this;
        }
        // iterators:
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_it rbegin();
        const_reverse_iterator rbegin() const;
        reverse_it rend();
        const_reverse_iterator rend() const;
        // capacity:
        bool empty() const;
        size_type size() const;
        size_type max_size() const;
        // 23.3.1.2 element access:
        T& operator[](const key_type& x);
        // modifiers:
        pair<iterator, bool> insert(const value_type& x)
        {
          
        }
        iterator insert(iterator position, const value_type& x)
        {

        }
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last);
        void erase(iterator position);
        size_type erase(const key_type& x);
        void erase(iterator first, iterator last);
        void swap(map<Key,T,Compare,allocator_type>&);
        void clear();
        // observers:
        key_compare key_comp() const;
        value_compare value_comp() const;

        iterator find(const key_type& x)
        {
          return (iterator(_my_tree.searchNode(_my_tree.base(), x)));
        }
        const_iterator find(const key_type& x) const
        {
          
        }
        size_type count(const key_type& x) const;
        iterator lower_bound(const key_type& x);
        const_iterator lower_bound(const key_type& x) const;
        iterator upper_bound(const key_type& x);
        const_iterator upper_bound(const key_type& x) const;
        pair<iterator,iterator>
        equal_range(const key_type& x);
        pair<const_iterator,const_iterator>
        equal_range(const key_type& x) const;

       
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