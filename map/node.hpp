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

template <class Content>
class Node
{
    public:
        Content *key;
        Node *parent;
        Node *left;
        Node *right;
        int height;
};

#endif