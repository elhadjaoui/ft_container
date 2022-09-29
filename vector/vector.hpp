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
#include "reverse_iterator.hpp" 

namespace ft
{
    template < class T, class Alloc = std::allocator<T> > 
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
            typedef reverse_iterator<const_iterator>	        const_reverse_iterator;
            typedef reverse_iterator<iterator>					reverse_iterator;

         private:
		    allocator_type	_allocator;
		    pointer			_buffer;
		    size_type		_capacity;
		    size_type		_size;

        public :
		    explicit vector(const allocator_type &alloc = allocator_type()): _allocator(alloc), _buffer(), _capacity(0), _size(0) {}
            explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()): _allocator(alloc), _capacity(n), _size(n)
		    {
		    	_buffer = _allocator.allocate(_size);
		    	for (size_type i = 0; i < _size; i++)
                    _allocator.construct(_buffer + i, val);
            }
            template <class InputIterator>
		    vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value, bool>::type x = true): _allocator(alloc), _buffer(),_capacity(0), _size(0)
		    {
				for(; first != last; first++)
					push_back(*first);
		    }
            vector(const vector &x): _allocator(x.get_allocator()), _capacity(x._size), _size(x._size)
			{
				_buffer = _allocator.allocate(_size);
				for (size_type i = 0; i < _size; i++)
               		_allocator.construct((&_buffer[i]), x[i]);
			}

        	iterator begin() { return iterator(_buffer); }
			const_iterator begin() const { return const_iterator(_buffer); }

        	iterator end() { return iterator(_buffer + _size); }
			const_iterator end() const { return iterator(_buffer + _size); }

			reverse_iterator rbegin() {return reverse_iterator(end());}
			const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}

			reverse_iterator rend() {return reverse_iterator(begin());}
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

			size_type size() const { return _size; }
			size_type max_size() const {return _allocator.max_size();}
    		size_type capacity() const { return _capacity; }
	    	bool empty() const { return _size ? false : true; }

			void reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
				if (n > _capacity)
				{
					pointer tmp = _allocator.allocate(n);;
					for (size_type i = 0; i < _size; i++)
        	            _allocator.construct(&(tmp[i]), _buffer[i]);
					for (size_type i = 0; i < _size; i++)
						_allocator.destroy(_buffer + i);
					_allocator.deallocate(_buffer, _capacity);
					_capacity	= n;
					_buffer		= tmp;
				}
			}
        	void resize(size_type n, value_type val = value_type())
			{
				if (n > _capacity)
				{
					reserve(n);
					for (; _size < n; _size++)
						_allocator.construct(_buffer + _size, val);
				}
				else
				{
					if (n < size())
						while (n < size())
							pop_back();
					else
						for (; _size < n; _size++)
							_allocator.construct(_buffer + _size, val);
				}
			}
        	reference at(size_type n)
        	{
	    	    if (n >= _size)
			        throw std::out_of_range("ft::vector");
	    	    return *(begin() + n);
        	}
        	const_reference at(size_type n) const
        	{
	    	    if (n >= _size)
			        throw std::out_of_range("ft::vector");
	    	    return *(begin() + n);
        	}

        	reference operator[](size_type n) { return *(begin() + n); }
        	const_reference operator[](size_type n) const { return *(begin() + n); }
	
        	reference front() {return *begin();}
        	const_reference front() const {return *begin();}

        	reference back() {return *(end()-1);}
        	const_reference back() const { return *(end() - 1); }

        	void push_back(const value_type &val) { resize(_size + 1, val); }
        	void pop_back() { _allocator.destroy(_buffer + (--_size)); }

        	void clear() { while (_size) pop_back(); }

        	iterator erase(iterator position)
        	{
	    	    iterator copy = position;    

	    	    for (; position != (end() - 1); position++)
	    	    {
	    	    	_allocator.destroy(&(*position));
        	        _allocator.construct(&(*position), (*(position + 1)));
	    	    }
	    	    _size--;
	    	    return copy;
        	}
        	iterator erase(iterator first, iterator last)
        	{
        		iterator tmp = first;
        		size_type n = 0;
        		for (; tmp != last; tmp++)
        			n++;
        		tmp = first;
        		for (; tmp != last; tmp++)
        			_allocator.destroy(&(*tmp));
        		tmp = first;
        		for (; last != end(); last++)
        		{
        			*first = *last;
        			_allocator.destroy(&(*last));
        			first++;
        		}
        		_size -= n;
        		return tmp;
        	}
        	allocator_type get_allocator() const { return _allocator; }

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, bool>::type x = true)
			{
				clear();
				size_type n = 0;
				InputIterator tmp = first;
				for (; tmp != last; tmp++)
					n++;
				if (n > _capacity)
					reserve(n);
				while (first != last)
					push_back(*first++);
			}
			void assign(size_type n, const value_type &val)
			{
				clear();
				if (n > _capacity)
					reserve(n);
				while (_size < n)
					push_back(val);
			}
			iterator insert(iterator position, const value_type &val)
			{
				difference_type diff = position -  begin();
				if (diff < 0 )
					diff = 0;
				if ( diff > (difference_type)_size)
					diff = (difference_type)_size;
				push_back(val);
				position = begin();
				while(diff--)
					position++;
				iterator it = end() - 1;
				for (; it != position; it--)
				{
					_allocator.destroy(&(*it));
			        _allocator.construct(&(*it), *(it - 1));
			    }
				_allocator.destroy(&(*it));
			    _allocator.construct(&(*it), val);
			    return position;
			}
			void insert(iterator position, size_type n, const value_type &val)
			{
				difference_type diff = position -  begin();
				if (diff < 0 )
					diff = 0;
				if ( diff > (difference_type)_size)
					diff = (difference_type)_size;
				resize(_size + n);
				position = begin();
				while (diff--)
					position++;
				iterator last = end() - 1;
				iterator mid = end() - 1 - n;
				
			    for (; mid != position - 1; mid--)
				{
					_allocator.destroy(&(*last));
			        _allocator.construct(&(*last), *mid);
					last--;
				}
				for (; last != position - 1; last--)
				{
					_allocator.destroy(&(*last));
			        _allocator.construct(&(*last), val);
			    }
			}
			
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, bool>::type = false)

			{
        	    difference_type diff = (position - begin());
        	    difference_type cap = (last - first) + _size;
        	    if (diff < 0 )
				diff = 0;
				if ( diff > (difference_type)_size)
					diff = (difference_type)_size;
        	   	reserve(cap);
        	    insert(begin() + diff, last - first, value_type());
        	    for (InputIterator it = first; it != last; it++)
        	    {
        	        position = begin() + diff;
        	        _allocator.destroy(&(*position));
        	        _allocator.construct(&(*position), *it);
        	        diff++;
        	    }
			}
			void swap(vector &x)
			{
				std::swap(_buffer, x._buffer);
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
				std::swap(_allocator, x._allocator);
			}
		};

		template <class T, class Alloc>
		bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}
		template <class T, class Alloc>
		bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return !(lhs == rhs);
		}
		template <class T, class Alloc>
		bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
		template <class T, class Alloc>
		bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return lhs == rhs || lhs < rhs;
		}
		template <class T, class Alloc>
		bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
		}
		template <class T, class Alloc>
		bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return lhs == rhs || lhs > rhs;
		}
		template <class T, class Alloc>
		void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
		{
			x.swap(y);
		}

};

#endif 
