/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:35:35 by wluong            #+#    #+#             */
/*   Updated: 2022/01/03 01:36:46 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*==================================================================*
*			CONSTRUCTOR AND DESTRUCTORS								*
*===================================================================*/

ScavTrap::ScavTrap( void ) {
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDmg = 20;
	std::cout << "Default ScavTrap constructor called !" << std::endl;
	std::cout << "\tNAME :" << this->_name << std::endl;
	std::cout << "\tHP :" << this->_energyPoint << std::endl;
	std::cout << "\tACTION POINTS :" << this->_hitPoint << std::endl;
	std::cout << "\tATTACK DAMAGE :" << this->_attackDmg << std::endl << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src ) {
	this->_name = src._name;
	this->_hitPoint = src._hitPoint;
	this->_energyPoint = src._energyPoint;
	this->_attackDmg = src._attackDmg;
	std::cout << "Copy ScavTrap constructor called !" << std::endl;
	std::cout << "\tNAME :" << this->_name << std::endl;
	std::cout << "\tHP :" << this->_energyPoint << std::endl;
	std::cout << "\tACTION POINTS :" << this->_hitPoint << std::endl;
	std::cout << "\tATTACK DAMAGE :" << this->_attackDmg << std::endl << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	this->_name = ClapTrap::_name;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDmg = 20;
	std::cout << "Parametric ScavTrap constructor called !" << std::endl;
	std::cout << "\tNAME :" << this->_name << std::endl;
	std::cout << "\tHP :" << this->_energyPoint << std::endl;
	std::cout << "\tACTION POINTS :" << this->_hitPoint << std::endl;
	std::cout << "\tATTACK DAMAGE :" << this->_attackDmg << std::endl << std::endl;
}

ScavTrap::~ScavTrap ( void ) {
	std::cout << "ScavTrap destructor called !" << std::endl;
}

/*==================================================================*
*			OVERLOAD												*
*===================================================================*/

ScavTrap &		ScavTrap::operator=( ScavTrap const & other ) {
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDmg = other._attackDmg;
	return *this;
}

/*==================================================================*
*			MEMEBER FUNCTION										*
*===================================================================*/

void			ScavTrap::guardGate( void ) {
	std::cout << YELL << "\t[GATE KEEPER MODE]" << std::endl;
	if (this->_energyPoint && this->_hitPoint) {
		std::cout << BLUE << this->getName() << NOR << " have enterred in " << YELL << "Gate keeper mode." << NOR << std::endl << std::endl;
		this->_hitPoint--;
	}
	else if (!this->_energyPoint) {
		std::cout << BLUE << this->getName() << NOR << " can't enter in guard keeper mode. This player is dead." << std::endl << std::endl;
	}
	else if (!this->_hitPoint) {
		std::cout << "You don't have enough PM..." << std::endl << std::endl;
	}
}

void			ScavTrap::attack( std::string const & target ) {
	if (this->_hitPoint > 0) {
		std::cout << "🤖 " << BLUE << this->getName() << NOR << " using ScavTrap attack " << BLUE << target << NOR \
		<< " causing " << RED << this->_attackDmg << NOR << " points of damage ! 💥" << std::endl;
		this->_hitPoint-= 5;
	}
	else {
		std::cout << "You don't have enough PM..." << std::endl << std::endl;
	}
}

void			ScavTrap::attack( ClapTrap & target ) {
	std::cout << RED << "\t[ATTACK]" << NOR <<std::endl;
	if ( this->_hitPoint > 0 && target.getEnergyPoint() > 0 && this->_energyPoint) {
		std::cout << "🤖 " << BLUE << this->getName() << NOR << " using ScavTrap attack " << BLUE << target.getName() << NOR \
		<< " causing " << RED << this->_attackDmg << NOR << " points of damage ! 💥" << std::endl;
		target.takeDamage(*this);
		this->_hitPoint--;
	}
	else if ( this->_hitPoint == 0) {
		std::cout << "You don't have enough PM..." << std::endl << std::endl;
	}
	else if (!target.getEnergyPoint()) {
		std::cout << "Ennemy " << BLUE << target.getName() << NOR << " is already dead." << std::endl << std::endl;
	}
	else if (!this->_energyPoint) {
		std::cout << BLUE << this->getName() << NOR << " can't attack. This player is dead." << std::endl << std::endl;
	}
}