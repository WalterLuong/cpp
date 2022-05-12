/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 07:35:21 by wluong            #+#    #+#             */
/*   Updated: 2022/01/05 02:56:38 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name("UNKNOW"), _space(0) {
	for (int i(0); i < 4; i++) {
		this->_stuff[i] = NULL;
	}
	return ;
}

Character::Character( Character const & src ) : _name(src._name), _space(src._space) {
	for (int i(0); i < src._space; i++) {
		this->_stuff[i] = src._stuff[i]->clone();
	}
	for (int i(src._space); i < 4; i++) {
		this->_stuff[i] = NULL;
	}
}

Character::Character( std::string const & name ) : _name(name), _space(0) {
	for (int i(0); i < 4; i++) {
		this->_stuff[i] = NULL;
	}
	return;
}


Character::~Character( void ) {
	for (int i(0); i < 4; i++) {
		delete _stuff[i];
	}
}

Character &		Character::operator=( Character const & other ) {
	this->_name = other._name;
	for (int i(0); i < 4; i++) {
		delete this->_stuff[i];
	}
	for (int i(0); i < other._space; i++) {
		this->_stuff[i] = other._stuff[i]->clone();
	}
	for (int i(other._space); i < 4; i++) {
		this->_stuff[i] = NULL;
	}
	this->_space = other._space;
	return *this;
}

std::string const & 	Character::getName( void ) const {
	return this->_name;
}

void 			Character::equip( AMateria* m ) {
	if (this->_space < 3) {
		this->_stuff[_space] = m;
		this->_space++;
	}
}

void 			Character::unequip( int idx ) {
	if (idx < this->_space && idx >= 0) {
		_stuff[idx] = NULL;
		for (int i(idx); i < this->_space; i++) {
			_stuff[i] = _stuff[i + 1];
		}
		_stuff[this->_space] = NULL;
		_space--;
	}
	else if (idx == this->_space) {
		_stuff[idx] = NULL;
		_space--;
	}
	else {
		std::cout << "Bad Index." <<std::endl;
	}
}

void 			Character::use( int idx, ICharacter& target ) {
	if (idx >= 0 && idx < this->_space && this->_stuff[idx] != NULL) {
		this->_stuff[idx]->use(target);
	}
	else {
		std::cout << "Bad Index." << std::endl;
	}
}
