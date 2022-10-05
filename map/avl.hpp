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
  typedef typename value_type::first_type key_type;
	typedef typename value_type::second_type mapped_type;
  typedef Alloc allocate;
  typedef typename Alloc::template rebind<Node<value_type> >::other node_allocator;

  Node<value_type> *_root;
  node_allocator _alloc_node;
  allocate  _allocator;
  key_compare _compare_key;

public:
  AVL() { _root = NULL; }
  AVL(Node<value_type> *node) { _root = node; }
  void setRoot(Node<value_type> *node) {_root = node;}
  Node<value_type> *base() const {return _root;}
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
  // void _freePair(Content *c)
  // {
  //     _allocator.destroy(c);
  //     _allocator.deallocate(c, 1);
  // }
  void parent_correction(Node<value_type>*&n, Node<value_type> *p)
	{
		if (!n)
			return ;
		parent_correction(n->right, n);
		n->parent = p;
		parent_correction(n->left, n);
	}
  void _freeNode(Node<value_type> *node)
  {
      if (!node)
          return;
      // _freePair(node->cnt);
      _alloc_node.destroy(node);
      _alloc_node.deallocate(node, 1);
  }
  Node<value_type> *leaf_right_node(Node<value_type> *node) const // maximum node
  {
    if (!node) return NULL;
    return !node->right ? node : leaf_right_node(node->right);
  }
  Node<value_type> *leaf_left_node(Node<value_type> *node) const // minimum node
  {
    if (!node) return NULL;
    return !node->left ? node : leaf_left_node(node->left);
  }
  Node<value_type> *rightRotate(Node<value_type> *unbalanced_node)
  {
    Node<value_type> *A = unbalanced_node->left;
    Node<value_type> *B = A->right;
    A->right = unbalanced_node;
    unbalanced_node->left = B;
    // keep track of parent
    // A->parent = unbalanced_node->parent;
    // unbalanced_node->parent = A;
    parent_correction(unbalanced_node, A->parent);
    unbalanced_node->height = std::max(height(unbalanced_node->left), height(unbalanced_node->right)) + 1;
    A->height = std::max(height(A->left), height(A->right)) + 1;
    if (A->right)
				A->right->height = std::max(height(A->right->left), height(A->right->right)) + 1;
			if (A->left)
				A->left->height = std::max(height(A->left->left), height(A->left->right)) + 1;
    return A;
  }
  Node<value_type> *leftRotate(Node<value_type> *unbalanced_node)
  {
    Node<value_type> *A = unbalanced_node->right;
    Node<value_type> *B = A->left;

    A->left = unbalanced_node;
    unbalanced_node->right = B;
    // keep track of parent
    // A->parent = unbalanced_node->parent;
    // unbalanced_node->parent = A;
    // if (unbalanced_node->right)
    //   unbalanced_node->right->parent = unbalanced_node;
    parent_correction(A, unbalanced_node->parent);
    unbalanced_node->height = std::max(height(unbalanced_node->left), height(unbalanced_node->right)) + 1;
    A->height = std::max(height(A->left), height(A->right)) + 1;
    if (A->left)
				A->left->height = std::max(height(A->left->left), height(A->left->right)) + 1;
		if (A->right)
				A->right->height = std::max(height(A->right->left), height(A->right->right)) + 1;
    return A;
  }
  Node<value_type> *insert_node(Node<value_type> *node, const  Content &cnt, Node<value_type> *parent)
  {
    // std::cout << cnt.first << std::endl;
    if (!node)
    {
        node = _alloc_node.allocate(1);
        _alloc_node.construct(node, Node<value_type>(cnt));
        node->parent = parent;
        return (node);
     }
    else if (cnt.first == node->cnt.first)
      return NULL;
    else if (_compare_key(cnt.first, node->cnt.first)) // returns true if the first argument is considered to go before the second
      node->left = insert_node(node->left, cnt, node);
    else if (_compare_key(node->cnt.first, cnt.first))
      node->right = insert_node(node->right, cnt, node);
  
    node->height = 1 + std::max(height(node->left), height(node->right));
    int balanceFactor = getBalance(node);
    if (balanceFactor > 1 && node->left && _compare_key(cnt.first, node->left->cnt.first)) // left is dominant
    {
       // Left Left Case
      
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
         node =  rightRotate(node);
    }
    else if (balanceFactor > 1 && node->left && _compare_key(node->left->cnt.first , cnt.first)) // left is dominant
    {
       // Left right Case
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
        node =  rightRotate(node);
    }
    else if (balanceFactor < -1 && node->right && _compare_key(node->right->cnt.first , cnt.first)) // right is dominant
    {
      // Right Right Case
     
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
         node =  leftRotate(node);
    }
    else if (balanceFactor < -1 && node->right && _compare_key(cnt.first, node->right->cnt.first )) //right is dominant
    {
    // Right Left Case
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
         node =  leftRotate(node);
    }
    if (node->left)
      node->left->parent = node;
    if (node->right)
      node->right->parent = node;
    return node;
  }
  Node<value_type> *searchNode(Node<value_type> *node, const  key_type key) const
  {
    if (!node)
      return NULL;
    else if (node->cnt.first == key)
      return node;
    else if (_compare_key(key, node->cnt.first))
      return  searchNode(node->left, key);
    else
      return searchNode(node->right, key);
    return node;
  }
  
  Node<value_type> *deleteNode(Node<value_type> *root,  const key_type  &key)
  {
    if (root == NULL)
      return NULL;
    if (_compare_key(key, root->cnt.first))
      root->left = deleteNode(root->left, key);
    else if (_compare_key(root->cnt.first, key))
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
        if (temp == NULL)  // No child case
        {
          temp = root;
          root = NULL;
        }
        else // One child case
        {
          // temp->parent = root->parent;
          _alloc_node.construct(root, *temp);
          // root->parent = parent;
        } 

        _freeNode(temp);
      }
      else // two child case
      {
        Node<value_type> *temp = leaf_left_node(root->right); // node with two children: Get the inorder  successor (smallest in the right subtree)
        _allocator.construct(&(root->cnt), temp->cnt);
        // std::swap(root->cnt, temp->cnt);
        root->right = deleteNode(root->right, temp->cnt.first);
        // explanation
          /* The constructed AVL Tree would be
 
                9
               / \
deleted ->  (1)  10
             / \    \
            0   5    11           
           /   / \
         -1   2   6
         
             ||        replace just the key of node (1) by the key node (2) and remove (2)  
             VV

              9                                   
             / \
            2    10
           / \    \
          0   5    11
         /     \
       -1       6
        */
      }
    }

     // If the tree had only one node
    // then return
    if (root == NULL)
      return root;
    root->height = std::max(height(root->left), height(root->right)) + 1;
    int balanceFactor = getBalance(root);
    if (balanceFactor > 1)
    {
      if (getBalance(root->left) >= 0)
        return rightRotate(root);
      else
      {
        root->left = leftRotate(root->left);
        return rightRotate(root);
      }
    }
    if (balanceFactor < -1)
    {
      if (getBalance(root->right) <= 0)
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
  Node<value_type> *clear_tree(Node<value_type> *root)
  {
    if (!root)
      return NULL;
    clear_tree(root->left);
    clear_tree(root->right);
    if (root)
    {
      _alloc_node.destroy(root);
      _alloc_node.deallocate(root, sizeof(Node<value_type>));
    }
    return NULL;
  }
  void preOrder(Node<value_type> *root)
  {
  
        if (root == NULL)
        return;
 
    /* first print data of root */
        std::cout << root->cnt.first << " ";

 
    /* then recur on left subtree */
    preOrder(root->left);
    // std::cout << " / \n";
 
    /* now recur on right subtree */
    preOrder(root->right);
    // std::cout << " \\ \n";

  }
};

#endif