/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 07:17:39 by wluong            #+#    #+#             */
/*   Updated: 2022/01/05 03:31:22 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _learned(0) {
	for (int i(0); i < 4; i++) {
		_stuff[i] = NULL;
	}
	return ;
}

MateriaSource::MateriaSource( MateriaSource const & src ) {
	for (int i(0); i < src._learned; i++) {
		_stuff[i] = src._stuff[i]->clone();
	}
	for (int i(src._learned); i < 4; i++) {
		_stuff[i] = NULL;
	}
	_learned = src._learned;
}

MateriaSource::~MateriaSource( void ) {
	for (int i(0); i < 4; i++) {
		delete _stuff[i];
	}
	return ;
}

MateriaSource &		MateriaSource::operator=( MateriaSource const & other ) {
	for (int i(0); i < other._learned; i++) {
		_stuff[i] = other._stuff[i]->clone();
	}
	for (int i(other._learned); i < 4; i++) {
		_stuff[i] = NULL;
	}
	_learned = other._learned;
	return *this;
}

void		MateriaSource::learnMateria( AMateria* newMateria ) {
	if (_learned < 4) {
		_stuff[_learned] = newMateria;
		_learned++;
	}
	else {
		delete newMateria;
		std::cout << "You can't learn more than 4 Materias." << std::endl;
	}
}

AMateria*	MateriaSource::createMateria( std::string const & type ) {
	for (int i(0); i < _learned; i++) {
		if (_stuff[i]->getType() == type) {
			return _stuff[i]->clone();
		}
	}
	return NULL;
}