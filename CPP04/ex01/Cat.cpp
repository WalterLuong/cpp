/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 04:02:20 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 04:30:15 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) {
	this->_type = "Cat";
	this->_catBrain = new Brain;
	std::cout << "Default Cat constructor called !" << std::endl;
}

Cat::Cat( Cat const & src ) {
	this->_type = src._type;
	this->_catBrain = new Brain(*src._catBrain);
	std::cout << "Copy Cat constructor called !" << std::endl;
}

Cat::~Cat( void ) {
	delete this->_catBrain;
	std::cout << "Cat destructor called !" << std::endl;
}

Cat &		Cat::operator=( Cat const & other ) {
	this->_type = other._type;
	delete this->_catBrain;
	this->_catBrain = new Brain(*other._catBrain);
	return *this;
}

void	Cat::makeSound( void ) const {
	std::cout << "🐱 Meeeeeeeeeeow" << std::endl;
}

void		Cat::setNewIdea( int const & index, std::string const & idea ) {
	if (index < 100) {
		this->_catBrain->setNewIdea(index, idea);
	}
	else {
		std::cout << "Index > 100. This brain is not that big..." << std::endl;
	}
}

std::string	Cat::getIdea( int const & index ) const {
	return this->_catBrain->getIdea(index);
}