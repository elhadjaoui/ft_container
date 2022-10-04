/**
 * @file node.hpp
 * @author El hadjaoui Mohamed
 * @brief 
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _NODE_HPP
#define _NODE_HPP
#include <memory>
  
template <class Content,  class Alloc = std::allocator<Content> >
class Node
{
    private :
        typedef Alloc allocator_type;
        allocator_type _allocator;

    public:
        Content cnt;
        Node<Content> *parent;
        Node<Content> *left;
        Node<Content> *right;
        int height;

  Node(Content cnt) : cnt(cnt), parent(NULL), left(NULL),  right(NULL), height(1)
  {
  
  }
  Node() : cnt(0), height(1), left(NULL), parent(NULL), right(NULL) {}
};


#endif