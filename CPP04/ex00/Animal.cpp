/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 03:42:51 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 03:21:30 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type("UNDEFINED") {
	std::cout << "Default Animal constructor called !" << std::endl;
	return ;
}

Animal::Animal( Animal const & src ) : _type(src._type) {
	std::cout << "Copy Animal constructor called !" << std::endl;
	return ;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called !" << std::endl;
}

Animal &		Animal::operator=( Animal const & other ) {
	this->_type = other._type;
	return *this;
}

std::string 	Animal::getType( void ) const {
	return this->_type;
}

void			Animal::makeSound( void ) const {
	std::cout << "Hello I am an animal !" << std::endl;
}