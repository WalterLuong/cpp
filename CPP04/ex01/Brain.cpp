/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 01:07:21 by wluong            #+#    #+#             */
/*   Updated: 2022/01/04 04:11:08 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <stdlib.h>
#include <sstream>

Brain::Brain( void ) {
	for (int i(0); i < 100; i++) {
		this->_ideas[i] = "I'm dumb";
	}
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain( Brain const & src ) {
	for (int i(0); i < 100; i++) {
	this->_ideas[i] =src._ideas[i];
	}
	std::cout << "Copy Brain constructor called" << std::endl;
}

Brain::Brain( std::string const & idea ) {
	std::stringstream	s;
	for (int i(0); i < 100; i++) {
		s << i;
		this->_ideas[i] = idea + " " + s.str();
	}
	std::cout << "Parametric Brain constructor called" << std::endl;
}

Brain::~Brain( void ) {
	std::cout << "Brain destructor called !" << std::endl;
}

Brain &		Brain::operator=( Brain const & other ) {
	for (int i(0); i < 100; i++) {
	this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

void		Brain::setNewIdea( int const & index, std::string const & idea ) {
	if (index < 100) {
		this->_ideas[index] = idea;
	}
	else {
		std::cout << "Index > 100. This brain is not that big..." << std::endl;
	}
}

std::string	Brain::getIdea( int const & index ) const {
	return this->_ideas[index];
}

std::string*	Brain::getAddress( void ) {
	return &this->_ideas[0];
}