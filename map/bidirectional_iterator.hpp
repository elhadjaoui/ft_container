/**
 * @file bidirectional_iterator.hpp
 * @author Mohamed El Hadjaoui
 * @brief 
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _BIDIRECTIONAL_ITERATOR_HPP_
#define _BIDIRECTIONAL_ITERATOR_HPP_
#include "node.hpp"

namespace ft
{
template <class T>
class bidirectional
{

public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef size_t difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;

private:
    Node<value_type> *_current;
    Node<value_type> *_previous;


    Node<value_type> *leaf_right_node(Node<value_type> *node) const 
    { 
        return !node->right ? node : leaf_right_node(node->right); 
    }

    Node<value_type> *leaf_left_node(Node<value_type> *node) const
    { 
        return !node->left ? node : leaf_left_node(node->left); 
    }

    Node<value_type> *_parent(Node<value_type> *node)
    {
        if (!node)
            return NULL;
        return node->parent;
    }


    void backward()
    {  
        if (!_current)
        {
            _current = _previous;
            return ;
        }
        Node<value_type> *left = _left_node(_current);
        if (left)
            _current = leaf_right_node(left);
        else
            while (1)
            {
                Node<value_type> *parent = _parent(_current);
                if (!parent || _right_node(parent) == _current)
                {
                    _current = parent;
                    break;
                }
                _current = parent;
            }
    }
    void forward()
    {
        Node<value_type> *right = _right_node(_current);
        if (right)
            _current = leaf_left_node(right);
        else
            while (1)
            {
                Node<value_type> *parent = _parent(_current);
                if (!parent || _left_node(parent) == _current)
                {
                    _current = parent;
                    break;
                }
                _current = parent;
            }
    }

public:
    Node<value_type> *current() const { return _current; }
    Node<value_type> *previous() const { return _current; }

    bidirectional(Node<value_type> *curr) { _current = curr; }

    template<class T>
    operator bidirectional<const T>()
    {
        const_Node<value_type> *curr = (const_Node<value_type>)*_current;
        return bidirectional<const T>(curr);
    }

    bidirectional() {}

    template <class T1>
    bidirectional(const bidirectional<T1> &copy): _current((Node<value_type> *)copy.current()), _previous((Node<value_type> *)copy.previous()){}

    template <class T1>
    bidirectional &operator=(bidirectional<T1> &copy)
    {
        _current = (Node<value_type> *)copy._current;
        _previous = (Node<value_type> *)copy._previous;
        return *this;
    }

    bidirectional operator--()
    {
        backward();
        return *this;
    }

    bidirectional operator--(int)
    {
        bidirectional _tmp = *this;
        operator--();
        return _tmp;
    }

    bidirectional operator++()
    {
        forward();
        return *this;
    }

    bidirectional operator++(int)
    {
        bidirectional _tmp = *this;
        operator++();
        return _tmp;
    }

    pointer operator->() const { return _current->content; }

    reference operator*() const { return *(operator->()); }

    bool operator==(const bidirectional lhs) { return _current == lhs._current; }

    bool operator!=(const bidirectional lhs) { return _current != lhs._current; }
};
}

#endif