/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 06:32:45 by wluong            #+#    #+#             */
/*   Updated: 2022/01/05 03:36:53 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

AMateria::AMateria( void ) : _type("NONE") {
	return ;
}

AMateria::AMateria( AMateria const & src ) : _type(src._type) {
	return ;
}

AMateria::AMateria( std::string const & type ) : _type(type) {
	return ;
}

AMateria::~AMateria( void ) {
	return ;
}

AMateria &		AMateria::operator=( AMateria const & other ) {
	(void) other;
	return *this;
}

std::string const &		AMateria::getType( void ) const {
	return this->_type;
}

void					AMateria::use( ICharacter & target ) {
	(void) target;
	std::cout << "You should not be able to print this !" << std::endl;
}