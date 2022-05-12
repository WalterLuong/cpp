/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 02:10:53 by wluong            #+#    #+#             */
/*   Updated: 2022/01/05 03:07:24 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {

	return;
}


Ice::Ice( Ice const & src ) : AMateria(src) {
	return ;
}
	
Ice::~Ice( void ) {
	return ;
}

Ice &		Ice::operator=( Ice const & other ) {
	(void) other;
	return *this;
}

AMateria*	Ice::clone( void ) const {
	Ice*	newC = new Ice(*this);
	return (newC);
}

void		Ice::use( ICharacter & target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}