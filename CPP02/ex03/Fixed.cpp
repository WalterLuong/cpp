/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 05:01:21 by wluong            #+#    #+#             */
/*   Updated: 2021/12/30 03:26:28 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

/*==========================================================
						CONSTRUCTORS
===========================================================*/

Fixed::Fixed ( void ) : _value(0) {
	return;
}

Fixed::Fixed ( Fixed const & src) {
	*this = src;
	return ;
}

Fixed::Fixed ( const int n ) : _value(UNSCALE(n, this->_bytes)) {
	return ;
}

Fixed::Fixed( const float f ) : _value((int)(roundf(f * FIXED_POINT_ONE(this->_bytes)))) {
	return ;
}

/*==========================================================
						DESTRUCTORS
===========================================================*/

Fixed::~Fixed ( void ) {
	return ;
}

/*==========================================================
						OVERLOADS
===========================================================*/

Fixed &		Fixed::operator=( Fixed const & rhs) {
	this->_value = rhs.getRawBits();

	return *this;
}

bool		Fixed::operator>( Fixed const & other ) const {
	return this->_value > other._value;
}

bool		Fixed::operator<( Fixed const & other ) const {
	return this->_value < other._value;
}

bool		Fixed::operator>=( Fixed const & other ) const {
	return this->_value >= other._value;
}

bool		Fixed::operator<=( Fixed const & other ) const {
	return this->_value <= other._value;
}

bool		Fixed::operator==( Fixed const & other ) const {
	return this->_value == other._value;
}

bool		Fixed::operator!=( Fixed const & other ) const {
	return this->_value != other._value;
}

Fixed		Fixed::operator+( Fixed const & other ) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed		Fixed::operator-( Fixed const & other ) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed		Fixed::operator*( Fixed const & other ) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed		Fixed::operator/( Fixed const & other ) const {
	if (other.toFloat() != 0) {
		return Fixed(this->toFloat() / other.toFloat());
	}
	else
		throw std::runtime_error("Error: Divsion by 0.");
}

Fixed&		Fixed::operator++( void ) {
	this->_value++;
	return *this;
}

Fixed		Fixed::operator++( int e ) {
	(void) e;
	Fixed tmp = (*this);
	++(*this);
	return (tmp);
}

Fixed		Fixed::operator--( int e ) {
	(void) e;
	Fixed tmp = (*this);
	++(*this);
	return (tmp);
}

/*==========================================================
					MEMEBR FUNCTIONS
===========================================================*/

int			Fixed::getRawBits( void ) const {
	return this->_value;
}

void		Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

int			Fixed::toInt( void ) const {
	return SCALE(this->_value, this->_bytes);
}

float		Fixed::toFloat( void ) const {
	return static_cast<float>(_value) / FIXED_POINT_ONE(this->_bytes);
	
}

const Fixed &		Fixed::max( Fixed const & a, Fixed const & b) {
	if (a > b) {
		return a;
	}
	return b;
}

const Fixed &		Fixed::min( Fixed const & a, Fixed const & b) {
	if (a > b) {
		return b;
	}
	return a;
}

Fixed &		Fixed::max( Fixed & a, Fixed & b) {
	if (a > b) {
		return a;
	}
	return b;
}

Fixed &		Fixed::min( Fixed & a, Fixed & b) {
	if (a < b) {
		return a;
	}
	return b;
}

std::ostream &	operator<<( std::ostream &os, Fixed const & other ) {
	os << other.toFloat();
	return os;
}