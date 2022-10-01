/**
 * @file bidirectional_iterator.hpp
 * @author Mohamed El Hadjaoui
 * @brief  check this link https://www.cs.odu.edu/~zeil/cs361/latest/Public/treetraversal/index.html
 * @version 0.1
 * @date 2022-09-24
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
    Node<value_type> *_root;
    Node<value_type> *_last_root_position;
    Node<value_type> *leaf_right_node(Node<value_type> *node) const 
    { 
        if (!node) return NULL;
        return !node->right ? node : leaf_right_node(node->right); 
    }
    Node<value_type> *leaf_left_node(Node<value_type> *node) const
    { 
        if (!node) return NULL;
        return !node->left ? node : leaf_left_node(node->left); 
    }
    void previous_position()
    {  
        if (!_root)
        {
            _root = _last_root_position; // if root == end() back to its last position
            return ;
        }
        Node<value_type> *left = _root->left; //(*) check the explanation below
        if (left)
            _root = leaf_right_node(left); //(*) check the explanation below
        else
        {                                                   
            Node<value_type> *parent = _root->parent; 
            while (parent && parent->left == _root) 
            {
                _root = parent;
                parent = parent->parent;
            }
            _root = parent;
        }

        /* explanation

        root-> (9)    root-- == node(6) ==> (*) Take a step down to the left Then run down to the right as far as possible 
               / \
              1   10
             / \    \
            0   5    11           
           /   / \
         -1   2   6
         

                9         root-- == end()
               / \
              1   10
             / \    \
            0   5    11           
           /   / \
root ->  (-1) 2   6
         


                9         root-- == node(5)
               / \
              1   10
             / \    \
            0   5    11           
           /   / \
         -1   2  (6)  <- root 
         

        */
    }
    void next_position()
    {
        if (!_root) return;
        _last_root_position = _root;
        Node<value_type> *right = _root->right; //(*) check the explanation below
        if (right)
            _root = leaf_left_node(right); //(*)  check the explanation below
        else // root has no right child
        {
            Node<value_type> *parent = _root->parent;
            while (parent && parent->right == _root)
            {
                _root = parent;
                parent = parent->parent;
            }
            _root = parent;
            
        }
        // explanation  
        /*
        
        root ->(9)         root++ == node(10) ==> (*) Take a step down to the right Then run down to the left as far as possible
               / \
              1   20
             /   /  \
            0   12   33           
           /   / \
         -1   10 16


         + if the root has no right child and located at the right child of its parent

                9          
               / \
              1   20
             /   /  \
            0   12  (33) <- root     root++ == end() == null       
           /   /  \
         -1   10  16



          + if the root has no right child and located at the left child of its parent

                9          
               / \
              1   20
             /   /  \
            0   12  (33)           
           /   /  \
         -1  (10)  16
               ^
               |__ root   root++ == node(12)
        */
    }
public:
    bidirectional(Node<value_type> *node) { _root = node; }
    bidirectional(): _root(NULL), _last_root_position(NULL) {}
    template <class T1>
    bidirectional(const bidirectional<T1> &copy): _root((Node<value_type> *)copy._root), _last_root_position((Node<value_type> *)copy._last_root_position){}
    template <class T1>
    bidirectional &operator=(bidirectional<T1> &copy)
    {
        _root = (Node<value_type> *)copy._root;
        _last_root_position = (Node<value_type> *)copy._last_root_position;
        return *this;
    }
    bidirectional operator--()
    {
        previous_position();
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
        next_position();
        return *this;
    }
    bidirectional operator++(int)
    {
        bidirectional _tmp = *this;
        operator++();
        return _tmp;
    }
    pointer operator->() const { return _root->cnt; }
    reference operator*() const { return *(operator->()); }
    bool operator==(const bidirectional lhs) { return _root == lhs._root; }
    bool operator!=(const bidirectional lhs) { return _root != lhs._root; }
};
}

#endif