/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 04:20:34 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 03:22:50 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) {
	this->_type = "WrongCat";
	std::cout << "Default WrongCat constructor called !" << std::endl;
}

WrongCat::WrongCat( WrongCat const & src ) {
	this->_type = src._type;
	std::cout << "Copy WrongCat constructor called !" << std::endl;
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called !" << std::endl;
}

WrongCat &		WrongCat::operator=( WrongCat const & other ) {
	this->_type = other._type;
	return *this;
}