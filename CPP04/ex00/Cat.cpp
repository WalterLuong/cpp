/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 04:02:20 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 03:21:38 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) {
	this->_type = "Cat";
	std::cout << "Default Cat constructor called !" << std::endl;
}

Cat::Cat( Cat const & src ) {
	this->_type = src._type;
	std::cout << "Copy Cat constructor called !" << std::endl;
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called !" << std::endl;
}

Cat &		Cat::operator=( Cat const & other ) {
	this->_type = other._type;
	return *this;
}

void	Cat::makeSound( void ) const {
	std::cout << "🐱 Meeeeeeeeeeow" << std::endl;
}