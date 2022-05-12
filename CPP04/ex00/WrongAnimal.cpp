/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 04:18:34 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 03:22:34 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("UNDEFINED") {
	std::cout << "Default WrongAnimal constructor called !" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src ) : _type(src._type) {
	std::cout << "Copy WrongAnimal constructor called !" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called !" << std::endl;
}

WrongAnimal &		WrongAnimal::operator=( WrongAnimal const & other ) {
	this->_type = other._type;
	return *this;
}

std::string 	WrongAnimal::getType( void ) const {
	return this->_type;
}

void			WrongAnimal::makeSound( void ) const {
	std::cout << "Hello I am a WrongAnimal !" << std::endl;
}