/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 01:38:36 by wluong            #+#    #+#             */
/*   Updated: 2022/01/03 02:08:59 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*==================================================================*
*			CONSTRUCTOR AND DESTRUCTORS								*
*===================================================================*/

DiamondTrap::DiamondTrap( void ) : ClapTrap("DEFAULT_clap_name") {
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDmg = FragTrap::_attackDmg;
	std::cout << "Default DIamondTrap constructor called !" << std::endl;
	std::cout << "\tNAME :" << this->_name << std::endl;
	std::cout << "\tHP :" << this->_energyPoint << std::endl;
	std::cout << "\tACTION POINTS :" << this->_hitPoint << std::endl;
	std::cout << "\tATTACK DAMAGE :" << this->_attackDmg << std::endl << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) {
	this->_name = src._name;
	this->_hitPoint = src._hitPoint;
	this->_energyPoint = src._energyPoint;
	this->_attackDmg = src._attackDmg;
	std::cout << "Copy DiamondTrap constructor called !" << std::endl;
	std::cout << "\tNAME :" << this->_name << std::endl;
	std::cout << "\tHP :" << this->_energyPoint << std::endl;
	std::cout << "\tACTION POINTS :" << this->_hitPoint << std::endl;
	std::cout << "\tATTACK DAMAGE :" << this->_attackDmg << std::endl << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name") {
	
	this->_name = name;
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDmg = FragTrap::_attackDmg;
	std::cout << "Parametric DiamondTrap constructor called !" << std::endl;
	std::cout << "\tNAME :" << this->_name << std::endl;
	std::cout << "\tHP :" << this->_energyPoint << std::endl;
	std::cout << "\tACTION POINTS :" << this->_hitPoint << std::endl;
	std::cout << "\tATTACK DAMAGE :" << this->_attackDmg << std::endl << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap destructor called !" << std::endl;
}

/*==================================================================*
*			OVERLOAD												*
*===================================================================*/

DiamondTrap &		DiamondTrap::operator=( DiamondTrap const & other ) {
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDmg = other._attackDmg;
	return *this;
}

/*==================================================================*
*			MEMEBER FUNCTION										*
*===================================================================*/

void				DiamondTrap::attack( std::string const & target ){
	ScavTrap::attack(target);
}
void				DiamondTrap::attack( ClapTrap & target ) {
	ScavTrap::attack(target);
}

void				DiamondTrap::whoAmI( void ) {
	std::cout << YELL << "\t[WHO AM I]" << NOR << std::endl;
	if (this->_energyPoint && this->_hitPoint) {
		std::cout << "Hello ! My name is " << BLUE << this->getName() << NOR << ", I'm a DiamondTrap and my ClapTrap name is " \
		<< BLUE << ClapTrap::getName() << NOR << " !" << std::endl << std::endl;
		this->_hitPoint--;
	}
	else if (!this->_energyPoint) {
		std::cout << BLUE << this->getName() << NOR << " can't present himself. This player is dead." << std::endl << std::endl;
	}
	else if (!this->_hitPoint) {
		std::cout << "You don't have enough PM..." << std::endl << std::endl;
	}
}

std::string			DiamondTrap::getName( void ) {
	return this->_name;
}

