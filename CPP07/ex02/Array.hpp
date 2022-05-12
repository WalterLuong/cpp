/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:02:50 by wluong            #+#    #+#             */
/*   Updated: 2022/01/18 12:31:37 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ARRAY_HPP
# define	ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{

public:

	Array( void ) : _array(new T[0]), _size(0) {};
	Array( Array const & src ) : _array(new T[src._size]), _size(src._size) {
		for (unsigned int i(0); i < src._size; i++) {
			this->_array[i] = src._array[i];
		}
	}
	Array( unsigned int n ) : _array(new T[n]), _size(n) {};
	~Array( void ) { delete [] this->_array; }
	
	Array &		operator=( Array const & other ) {
		delete [] this->_array;
		_array = new T[other._size];
		for (int i(0); i < other._size; i++) {
			this->_array[i] = other._array[i];
		}
		this->_size = other._size;
		return *this;
	}

	T &		operator[]( unsigned int i ) {
		if (i >= this->_size)
			throw Array::OutOfRange();
		else
			return this->_array[i];
	}

	unsigned int		size( void ) const { return this->_size; }

	class OutOfRange : public std::exception
	{
		public :
			virtual const char* what() const throw() { return "Out of limits !" ;}
	};

private:

	T *				_array;
	unsigned int	_size;
};

#endif