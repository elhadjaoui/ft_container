/**
 * @file make_pair.hpp
 * @author Mohamed El Hadjaoui
 * @brief 
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _MAKE_PAIR_HPP
#define _MAKE_PAIR_HPP


#include "pair.hpp"

namespace ft 
{
    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
      return ( pair<T1,T2>(x,y) );
    }
}

#endif

