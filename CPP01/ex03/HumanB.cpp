/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 00:17:18 by wluong            #+#    #+#             */
/*   Updated: 2021/12/27 02:52:55 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name) {
	this->setName(name);
//	this->_myWeapon = NULL;
	std::cout << RED << this->_name << NOR << " is created !" << std::endl;
}

HumanB::~HumanB( void ) {
	std::cout << RED << this->_name << NOR << " is destroyed !" << std::endl;
}

void	HumanB::setName( std::string name) {
	this->_name = name;
}

std::string		HumanB::getName( void ) const {
	return (this->_name);
}

void			HumanB::setWeapon( Weapon &obj ) {
	this->_myWeapon = &obj;
}

void			HumanB::attack( void ) const {
	std::cout << RED << this->getName() << NOR << " attacks with his " << YEL << this->_myWeapon->getType() << NOR << std::endl;
}