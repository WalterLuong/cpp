/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 00:16:42 by wluong            #+#    #+#             */
/*   Updated: 2021/12/27 02:13:38 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string name) {
	setType(name);
}

Weapon::~Weapon( void ) {
	return ;
}

void	Weapon::setType( std::string name ) {
	this->_type = name;
}

std::string		Weapon::getType( void ) const {
	return (this->_type);
}