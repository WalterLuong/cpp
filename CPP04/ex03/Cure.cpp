/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 01:55:17 by wluong            #+#    #+#             */
/*   Updated: 2022/01/05 03:07:58 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {
	return;
}


Cure::Cure( Cure const & src ) : AMateria(src) {
	return ;
}

Cure::~Cure( void ) {
	return ;
}

Cure &		Cure::operator=( Cure const & other ) {
	(void) other;
	return *this;
}

AMateria*	Cure::clone( void ) const {
	Cure*	newC = new Cure(*this);
	return (newC);
}

void		Cure::use( ICharacter & target ) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}