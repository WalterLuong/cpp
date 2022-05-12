/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 03:42:51 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 06:23:22 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal( void ) : _type("UNDEFINED") {
	std::cout << "Default Animal constructor called !" << std::endl;
	return ;
}

AAnimal::AAnimal( AAnimal const & src ) : _type(src._type) {
	std::cout << "Copy Animal constructor called !" << std::endl;
	return ;
}

AAnimal::~AAnimal( void ) {
	std::cout << "Animal destructor called !" << std::endl;
}

AAnimal &		AAnimal::operator=( AAnimal const & other ) {
	this->_type = other._type;
	return *this;
}

std::string 	AAnimal::getType( void ) const {
	return this->_type;
}