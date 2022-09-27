/**
 * @file avl.hpp
 * @author Mohamed El hadjaoui
 * @brief   implementing avl tree with all the needed functions
 * @version 0.1
 * @date 2022-09-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _AVL_HPP
#define _AVL_HPP

#include "node.hpp"

template <typename Content, typename Compare , typename Alloc>
class AVL
{
    private:
        typedef Content value_type;
        typedef Compare key_compare;
        typedef typename Alloc::template rebind<Node<value_type> >::other node_allocator;
        Node<value_type> *_PTN;
        node_allocator _alloc_node;
        key_compare _compre_key;

    private:
        Node<value_type>* newNode(Content content)
        {
            Node<value_type> *node = _alloc_node.allocate(sizeof(Node<value_type>));
            node = _alloc_node.construct(node, Node<value_type>(content, NULL));
            return(node);
        }
        int max(int a, int b)
        {
            return (a > b)? a : b;
        }
        int height(Node<value_type> *N)
        {
            if (N == NULL)
                return 0;
            return N->height;
        }
        int getBalance(Node *N)
        {
            if (N == NULL)
                return 0;
            return height(N->left) - height(N->right);
        }
        Node<value_type> * leaf_right_node(Node<value_type> * node) const // maximum node
        { 
            return !node->right ? node : leaf_right_node(node->right); 
        }
        Node<value_type> * leaf_left_node(Node<value_type> * node) const    // minimum node
        { 
            return !node->left ? node : leaf_left_node(node->left); 
        }
        Node<value_type> *rightRotate(Node *y)
        {
            Node *x = y->left;
            Node *T2 = x->right;
            x->right = y;
            y->left = T2;
            // parent_correction(y, x->parent);
            y->height = max(height(y->left), height(y->right)) + 1;
            x->height = max(height(x->left), height(x->right)) + 1;
            return x;
        }
        Node<value_type> *leftRotate(Node *x)
        {
            Node<value_type> *y = x->right;
            Node<value_type> *T2 = y->left;

            y->left = x;
            x->right = T2;
        //     parent_correction(y, x->parent);
            x->height = max(height(x->left), height(x->right)) + 1;
            y->height = max(height(y->left), height(y->right)) + 1;
            return y;
        }
        Node<value_type> *insert(Node<value_type> *node, Node<value_type> *parent, Content cnt) 
        {
          if (node == NULL)
            return newNode(cnt);
          if (_comp(item.first, (node->item->first)))
            node->left = insertNode(node->left, node, item);
          else if (_comp(node->item->first, item.first)) //(item > (node->item))
            node->right = insertNode(node->right, node, item);
          else
            return node;

          // Update the balance factor of each node
          // And, balance the tree
          node->height = 1 + max(height(node->left), height(node->right));
          int balanceFactor = getBalanceFactor(node);
          if (balanceFactor > 1)
          {
            if (_comp(item.first, node->left->item->first)) //(item < (node->left->item))
            {
              return rightRotate(node);
            }
            else if (_comp(node->left->item->first, item.first)) //(item > (node->left->item))
            {
              node->left = leftRotate(node->left);
              return rightRotate(node);
            }
          }
          if (balanceFactor < -1)
          {
            if (_comp(node->right->item->first, item.first)) //(item > (node->right->item))
            {
              return leftRotate(node);
            }
            else if (_comp(item.first, node->right->item->first)) //(item < (node->right->item))
            {
              node->right = rightRotate(node->right);
              return leftRotate(node);
            }
          }
          if (node->left)
            node->left->parent = node;
          if (node->right)
            node->right->parent = node;
          return node;
        }
    public :
        AVL() {_PTN = NULL; _size = 0;}


};

#endif