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
#include "make_pair.hpp"
#include "bidirectional_iterator.hpp"
#include "../vector/reverse_iterator.hpp"
#include "../vector/lexicographical_compare.hpp"
#include "../vector/equal.hpp"

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
    typedef ft::reverse_iterator<iterator> reverse_iterator;
    typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef Node<const value_type> *const_node_pointer; // this type just for casting to const_iterator
    class value_compare : public std::binary_function<value_type, value_type, bool>
    {
      friend class map;

    protected:
      Compare comp;
      value_compare(Compare c) : comp(c) {}

    public:
      bool operator()(const value_type &x, const value_type &y) const
      {
        return comp(x.first, y.first);
      }
    };

  private:
    AVL<value_type, key_compare, allocator_type> _my_tree;
    size_type _size;
    allocator_type _allocator;
    key_compare _comare_key;

  public:
    explicit map(const Compare &comp = Compare(), const allocator_type & = allocator_type()) : _my_tree(NULL),_size(0), _comare_key(comp) {}
    template <class InputIterator>
    map(InputIterator first, InputIterator last, const Compare &comp = Compare(), const allocator_type & = allocator_type()) :  _my_tree(NULL), _size(0), _comare_key(comp)
    {
      insert(first, last);
    }
    void print_tree()
    {
      _my_tree.preOrder(_my_tree.base());
    }
    map(const map<Key, T, Compare, allocator_type> &x) : _my_tree(NULL),_size(0)
    {
      insert(x.begin(), x.end());
    }
    ~map()
    {
      clear();
    }
    map<Key, T, Compare, allocator_type> &operator=(const map<Key, T, Compare, allocator_type> &x)
    {
      clear();
      insert(x.begin(), x.end());
      return *this;
    }
    // iterators:
    iterator begin()
    {
      return iterator(_my_tree.leaf_left_node(_my_tree.base()));
    }
    const_iterator begin() const
    {
      return const_iterator((const_node_pointer)_my_tree.leaf_left_node(_my_tree.base()));
    }
    iterator end()
    {
      iterator it = iterator(NULL,_my_tree.leaf_right_node(_my_tree.base()));
      // iterator it = iterator((_my_tree.leaf_right_node(_my_tree.base())));
      return (it);
    }
    const_iterator end() const
    {
      return const_iterator(NULL);
    }
    reverse_iterator rbegin()
    {
      return reverse_iterator(end());
    }
    const_reverse_iterator rbegin() const
    {
      return const_reverse_iterator(end());
    }
    reverse_iterator rend()
    {
      return reverse_iterator(begin());
    }
    const_reverse_iterator rend() const
    {
      return const_reverse_iterator(begin());
    }

    // capacity:
    bool empty() const { return !(_size > 0); }
    size_type size() const { return _size; }
    size_type max_size() const { return _allocator.max_size(); }

    // 23.3.1.2 element access:
    mapped_type &operator[](const key_type &x)
    {
      return (*((this->insert(ft::make_pair(x, mapped_type()))).first)).second;
    }
    // modifiers:
    pair<iterator, bool> insert(const value_type &x)
    {
      Node<value_type> *node = _my_tree.insert_node(_my_tree.base(), x, NULL);
      if (node)
      {
        _size++;
        _my_tree.setRoot(node);
        return (ft::make_pair(find(x.first), true));
      }
      return (ft::make_pair(find(x.first), false));
    }
    iterator insert(iterator position, const value_type &x)
    {
      (void)position;
      return insert(x).first;
    }
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last)
    {
      for (; first != last; first++)
        insert(*first);
    }
    void erase(iterator position)
    {
      erase(position->first);
    }
    size_type erase(const key_type &x)
    {
      if (_size)
      {
        if (find(x) == end())
        {
          _size--;
          return 0;
        }
        _size--;
        _my_tree.setRoot(_my_tree.deleteNode(_my_tree.base(), x));
        return 1;
      }
      return 0;
    }
    void erase(iterator first, iterator last)
    {
      if (_size)
      {
        if (first != last)
        {
          iterator it = first;
          erase(++first, last);
          erase(it->first);
        }
      }
    }
    void swap(map<Key, T, Compare, Alloc> &x)
    {
      std::swap(x._size, this->_size);
      std::swap(x._my_tree, this->_my_tree);
    }
    void clear()
    {
      _my_tree.setRoot(_my_tree.clear_tree(_my_tree.base()));
      _size = 0;
    }
    // observers:
    key_compare key_comp() const
    {
      return _comare_key;
    }
    value_compare value_comp() const
    {
      return value_compare(_comare_key);
    }

    iterator find(const key_type &x)
    {
      Node<value_type> *node = _my_tree.searchNode(_my_tree.base(), x); 
      if (node)
        return (iterator(node));
      return end();
    }
    const_iterator find(const key_type &x) const
    {
      Node<value_type> *node = _my_tree.searchNode(_my_tree.base(), x); 
      if (node)
        return (const_iterator((const_node_pointer)node));
       return end();
    }
    size_type count(const key_type &x) const
    {
      if (find(x) != end())
        return 1;
      return 0;
    }
    iterator lower_bound(const key_type &x)
    {
      iterator first = begin();
      iterator last = end();
      while (first != last)
      {
        if (_comare_key(first->first, x) == false)
          break;
        ++first;
      }
      return (first);
    }
    const_iterator lower_bound(const key_type &x) const
    {
      const_iterator first = begin();
      const_iterator last = end();
      while (first != last)
      {
        if (_comare_key(first->first, x) == false)
          break;
        ++first;
      }
      return (first);
    }
    iterator upper_bound(const key_type &x)
    {
      iterator first = begin();
      iterator last = end();
      while (first != last)
      {
        if (_comare_key(x, first->first) == true)
          break;
        ++first;
      }
      return (first);
    }
    const_iterator upper_bound(const key_type &x) const
    {
      const_iterator first = begin();
      const_iterator last = end();
      while (first != last)
      {
        if (_comare_key(x, first->first) == true)
          break;
        ++first;
      }
      return (first);
    }
    pair<iterator, iterator> equal_range(const key_type &x)
    {
      return ft::make_pair(lower_bound(x), upper_bound(x));
    }
    pair<const_iterator, const_iterator> equal_range(const key_type &x) const
    {
      return ft::make_pair(lower_bound(x), upper_bound(x));
    }
    allocator_type get_allocator() const
    {
      return _allocator;
    }
  };
}
template <class Key, class T, class Compare, class Alloc>
void swap(ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y)
{
  x.swap(y);
}

template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
  return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
  return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
  return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
  return lhs == rhs || lhs < rhs;
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
  return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
  return lhs == rhs || lhs > rhs;
}

#endif