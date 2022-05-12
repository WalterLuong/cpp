/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 03:32:33 by wluong            #+#    #+#             */
/*   Updated: 2021/12/30 05:02:28 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {
	return ;
}

Point::Point( Point const & src ) : _x(src._x), _y(src._y) {
	return ;
}

Point::Point( Fixed const & a, Fixed const & b) : _x(a), _y(b) {
	return ;
}

Point::~Point( void ) {
	return ;
}

Point &		Point::operator=( Point const & rhs ) {
	(void) rhs;
	return *this;
}

float		Point::getX( void ) const {
	return (this->_x.toFloat());
}

float		Point::getY( void ) const {
	return (this->_y.toFloat());
}