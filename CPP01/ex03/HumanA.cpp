/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 00:17:00 by wluong            #+#    #+#             */
/*   Updated: 2021/12/27 02:56:18 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &obj ) : _myWeapon(obj) {
	 this->setName(name); 
	std::cout << BLUE << this->_name << NOR << " is created !" << std::endl;
}

HumanA::~HumanA ( void ) {
	std::cout << BLUE << this->_name << NOR << " is destroyed !" << std::endl;
}

void	HumanA::setName( std::string name ) {
	this->_name = name;
}

std::string		HumanA::getName( void ) const {
	return (this->_name);
}

void	HumanA::attack( void ) const {
	std::cout << BLUE << this->getName() << NOR << " attacks with his " << YEL << this->_myWeapon.getType() << NOR << std::endl;
}