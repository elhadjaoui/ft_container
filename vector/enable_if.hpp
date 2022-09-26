/**
 * @file enable_if.hpp
 * @author Mohamed El hadjaoui
 * @brief The enable_if family of templates is a set of tools to allow a function template or a class template specialization to include or exclude itself from a set of matching functions or specializations based on properties of its template arguments. For example, one can define function templates that are only enabled for, and thus only match, an arbitrary set of types defined by a traits class. The enable_if templates can also be applied to enable class template specializations
 * @version 0.1
 * @date 2022-09-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _ENABLE_IF_HPP_
#define _ENABLE_IF_HPP_

namespace ft
{
    template <bool Cond, class T = void>
    struct enable_if
    {
    };

    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };
}

#endif