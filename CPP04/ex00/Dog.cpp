/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 03:53:38 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 03:21:46 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) {
	this->_type = "Dog";
	std::cout << "Default Dog constructor called !" << std::endl;
}

Dog::Dog( Dog const & src ) {
	this->_type = src._type;
	std::cout << "Copy Dog constructor called !" << std::endl;
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called !" << std::endl;
}

Dog &		Dog::operator=( Dog const & other ) {
	this->_type = other._type;
	return *this;
}

void	Dog::makeSound( void ) const {
	std::cout << "🐶 OUAF OUAF OUAF" << std::endl;
}