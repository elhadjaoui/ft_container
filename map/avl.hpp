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

template <typename Content, typename Compare, typename Alloc>
class AVL
{
private:
  typedef Content value_type;
  typedef Compare key_compare;
  typedef typename Alloc::template rebind<Node<value_type>>::other node_allocator;

  Node<value_type> *_PTN;
  node_allocator _alloc_node;
  key_compare _compare_key;

private:
  Node<value_type> *newNode(Content content)
  {
    Node<value_type> *node = _alloc_node.allocate(sizeof(Node<value_type>));
    node = _alloc_node.construct(node, Node<value_type>(content, NULL));
    return (node);
  }
  int max(int a, int b)
  {
    return (a > b) ? a : b;
  }
  int height(Node<value_type> *N)
  {
    if (N == NULL)
      return 0;
    return N->height;
  }
  int getBalance(Node<value_type> *N)
  {
    if (N == NULL)
      return 0;
    return height(N->left) - height(N->right);
  }

  Node<value_type> *leaf_right_node(Node<value_type> *node) const // maximum node
  {
    return !node->right ? node : leaf_right_node(node->right);
  }
  Node<value_type> *leaf_left_node(Node<value_type> *node) const // minimum node
  {
    return !node->left ? node : leaf_left_node(node->left);
  }
  Node<value_type> *rightRotate(Node<value_type> *unbalanced_node)
  {
    Node<value_type> *A = unbalanced_node->left;
    Node<value_type> *B = A->right;
    A->right = unbalanced_node;
    unbalanced_node->left = B;
    // keep track of parent
    A->parent = unbalanced_node->parent;
    unbalanced_node->parent = A;
    if (unbalanced_node->left)
      unbalanced_node->left->parent = unbalanced_node;
    unbalanced_node->height = max(height(unbalanced_node->left), height(unbalanced_node->right)) + 1;
    A->height = max(height(A->left), height(A->right)) + 1;
    return A;
  }
  Node<value_type> *leftRotate(Node<value_type> *unbalanced_node)
  {
    Node<value_type> *A = unbalanced_node->right;
    Node<value_type> *B = A->left;

    A->left = unbalanced_node;
    unbalanced_node->right = B;
    // keep track of parent
    A->parent = unbalanced_node->parent;
    unbalanced_node->parent = A;
    if (unbalanced_node->right)
      unbalanced_node->right->parent = unbalanced_node;
    unbalanced_node->height = max(height(unbalanced_node->left), height(unbalanced_node->right)) + 1;
    A->height = max(height(A->left), height(A->right)) + 1;
    return A;
  }
  Node<value_type> *insert(Node<value_type> *node, Node<value_type> *parent, Content cnt)
  {
    if (node == NULL)
      return newNode(cnt);
    if (_compare_key(cnt.first, (node->cnt.first))) // returns true if the first argument is considered to go before the second
      node->left = insert(node->left, node, cnt);
    else if (_compare_key(node->cnt.first, cnt.first))
      node->right = insert(node->right, node, cnt);
    else
      return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1) // left is dominant
    {
      if (_compare_key(cnt.first, node->left->cnt.first)) // Left Left Case
      {
        /*
      we can check if is left left case by comparing the height(left and right) of the left child  node or comparing the key of the inserted node and the unbalced node
            10
            / \
           5   15
          / \
         3   9
        / \
       1   (4) -> inserted node
      */
        return rightRotate(node);
      }
      else if (_compare_key(node->left->cnt.first, cnt.first)) // Left Right Case
      {
        /*
        we can check if is left right case by comparing the height(left and right) of the left child node or comparing the key of the inserted node and the unbalced node
               10
              / \
             4  15
            / \
           2   6
              / \
             7   (9)-> inserted node
        */

        node->left = leftRotate(node->left);
        return rightRotate(node);
      }
    }
    if (balanceFactor < -1) // right is dominant
    {
      if (_compare_key(node->right->cnt.first, cnt.first)) // Right Right Case
      {
        /*
         we can check if is right right case by comparing the height(left and right) of the right child node or comparing the key of the inserted node and the unbalced node
                10
               / \
              4  15
                /  \
               11  17
                   / \
                  18 (20)-> inserted node
         */
        return leftRotate(node);
      }
      else if (_compare_key(cnt.first, node->right->cnt.first)) // Right Left Case
      {
        /*
      we can check if is right right case by comparing the height(left and right) of the right child node or comparing the key of the inserted node and the unbalced node
             10
            / \
           4  15
             /  \
           11   17
           / \
          18 (20)-> inserted node
      */
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
  Node<value_type> *searchNode(Node<value_type> *node, typename value_type::first_type key) const
  {
    if (!node)
      return NULL;
    if (node->cnt->first == key)
      return node;
    Node<value_type> *right = searchNode(node->right, key);
    if (right)
      return right;
    Node<value_type> *left = searchNode(node->left, key);
    return left;
  }
  Node<value_type> *deleteNode(Node<value_type> *root, typename value_type::first_type key)
  {
    if (root == NULL)
      return NULL;
    if (_compare_key(key, (root->key)->first))
      root->left = deleteNode(root->left, key);
    else if (_compare_key((root->key)->first, key))
      root->right = deleteNode(root->right, key);
    else
    {
      if ((root->left == NULL) || (root->right == NULL))
      {
        Node<value_type> *temp = NULL;
        if (temp == root->left)
          temp = root->right;
        else
          temp = root->left;
        if (temp == NULL)
        {
          temp = root;
          root = NULL;
        }
        else
          _allocater.construct(root, *temp);
      }
      else
      {
        Node<value_type> *temp = leaf_left_node(root->right);
        _allocater.construct(root->key, *temp->key);
        root->right = deleteNode(root->right, temp->key->first);
      }
    }
    if (root == NULL)
      return root;
    root->height = max(height(root->left), height(root->right)) + 1;
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1)
    {
      if (getBalanceFactor(root->left) >= 0)
        return rightRotate(root);
      else
      {
        root->left = leftRotate(root->left);
        return rightRotate(root);
      }
    }
    if (balanceFactor < -1)
    {
      if (getBalanceFactor(root->right) <= 0)
        return leftRotate(root);
      else
      {
        root->right = rightRotate(root->right);
        return leftRotate(root);
      }
    }
    if (root->left)
      root->left->parent = root;
    if (root->right)
      root->right->parent = root;
    return root;
  }
  Node<value_type> *clear( Node<value_type> *root)
  {
    if (!root)
      return NULL;
    clear(root->right);
    clear(root->left);
    if (root)
    {
      _allocater.destroy(root);
      _allocater.deallocate(root, sizeof(Node<value_type>));
    }
    return NULL;
  }
public:
  AVL() { _PTN = NULL; }
};

#endif