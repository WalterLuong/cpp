/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 05:01:21 by wluong            #+#    #+#             */
/*   Updated: 2021/12/29 02:26:33 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

/*==========================================================
						CONSTRUCTORS
===========================================================*/

Fixed::Fixed ( void ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed ( const int n ) : _value(UNSCALE(n, this->_bytes)) {
	std::cout << "Int constructor called" << std::endl;
	
}

Fixed::Fixed( const float f ) : _value((int)(roundf(f * FIXED_POINT_ONE(this->_bytes)))) {
	std::cout << "Float constructor called" << std::endl;
}

/*==========================================================
						DESTRUCTORS
===========================================================*/

Fixed::~Fixed ( void ) {
	std::cout << "Destructor called" << std::endl;
}

/*==========================================================
						OVERLOADS
===========================================================*/

Fixed &		Fixed::operator=( Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = rhs.getRawBits();

	return *this;
}

/*==========================================================
					MEMEBR FUNCTIONS
===========================================================*/

int			Fixed::getRawBits( void ) const {
	return this->_value;
}

void		Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int			Fixed::toInt( void ) const {
	return SCALE(this->_value, this->_bytes);
}

float		Fixed::toFloat( void ) const {
	return static_cast<float>(_value) / FIXED_POINT_ONE(this->_bytes);
	
}

std::ostream &	operator<<( std::ostream &os, Fixed const & other ) {
	os << other.toFloat();
	return os;
}