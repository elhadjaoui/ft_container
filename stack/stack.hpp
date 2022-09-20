/**
 * @file stack.hpp
 * @author Mohamed El hadjaoui
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _STACK_HPP
#define _STACK_HPP

#include "../vector/vector.hpp"
namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
	{
    public:
        typedef T           value_type;
        typedef Container   container_type;
        typedef size_t      size_type;

    private:
        container_type _c_type;

    public:
        explicit stack(const container_type &ctnr = container_type()) : _c_type(ctnr) {}
        bool empty() const {return _c_type.empty();}
        size_type size() const{return _c_type.size();}
        value_type &top() { return _c_type.back(); }
        const value_type &top() const { return _c_type.back(); }
        void push(const value_type &val) { return _c_type.push_back(val); }
        void pop() { return _c_type.pop_back(); }
    };

    template <class T, class Container>
    bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs){ return lhs.c == rhs.c; }

    template <class T, class Container>
    bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs){ return lhs.c < rhs.c; }

    template <class T, class Container>
    bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs){ return lhs.c != rhs.c; }

    template <class T, class Container>
    bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs){ return lhs.c <= rhs.c; }

    template <class T, class Container>
    bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs){ return lhs.c > rhs.c; }

    template <class T, class Container>
    bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs){ return lhs.c >= rhs.c; }

}
#endif