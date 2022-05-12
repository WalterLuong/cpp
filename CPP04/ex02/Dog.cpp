/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 03:53:38 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 04:30:19 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) {
	this->_type = "Dog";
	this->_dogBrain = new Brain;
	std::cout << "Default Dog constructor called !" << std::endl;
}

Dog::Dog( Dog const & src ) {
	this->_type = src._type;
	this->_dogBrain = new Brain(*src._dogBrain);
	std::cout << "Copy Dog constructor called !" << std::endl;
}

Dog::~Dog( void ) {
	delete this->_dogBrain;
	std::cout << "Dog destructor called !" << std::endl;
}

Dog &		Dog::operator=( Dog const & other ) {
	this->_type = other._type;
	delete this->_dogBrain;
	this->_dogBrain = new Brain(*other._dogBrain);
	return *this;
}

void	Dog::makeSound( void ) const {
	std::cout << "🐶 OUAF OUAF OUAF" << std::endl;
}

void		Dog::setNewIdea( int const & index, std::string const & idea ) {
	if (index < 100) {
		this->_dogBrain->setNewIdea(index, idea);
	}
	else {
		std::cout << "Index > 100. This brain is not that big..." << std::endl;
	}
}

std::string	Dog::getIdea( int const & index ) const {
	return this->_dogBrain->getIdea(index);
}

std::string*	Dog::getAddress( void ) const {
	return this->_dogBrain->getAddress();
}