/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:15:53 by mel-hadj          #+#    #+#             */
/*   Updated: 2022/06/05 15:44:21 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

// #include <fstream>
// #include <iostream>
// #include <iterator>
// #include <map>
// #include <vector>
// #include <memory>
#include "random_access_iterator.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T>> 
    class vector
    {
        
        public:
            typedef T 											value_type;
            typedef Alloc										allocator_type;
            typedef typename allocator_type::reference			reference;
            typedef typename allocator_type::const_reference 	const_reference;
            typedef typename allocator_type::pointer			pointer;
            typedef typename allocator_type::const_pointer		const_pointer;
            typedef ptrdiff_t                                   difference_type;
            typedef size_t										size_type;
            typedef __wrap_iter<pointer>								iterator;
            typedef __wrap_iter<const_pointer>						const_iterator;
            // typedef reverse_iterator<const_iterator>	        const_reverse_iterator;
            // typedef reverse_iterator<iterator>					reverse_iterator;
    };
    
 
        
}


#endif
