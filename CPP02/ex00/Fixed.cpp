/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 05:01:21 by wluong            #+#    #+#             */
/*   Updated: 2021/12/28 05:16:56 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

Fixed::Fixed ( void ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed ( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &		Fixed::operator=( Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = rhs.getRawBits();

	return *this;
}

int			Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void		Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}