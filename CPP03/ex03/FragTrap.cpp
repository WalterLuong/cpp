/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:23:53 by wluong            #+#    #+#             */
/*   Updated: 2022/01/03 01:49:26 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*==================================================================*
*			CONSTRUCTOR AND DESTRUCTORS								*
*===================================================================*/

FragTrap::FragTrap( void ) {
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDmg = 30;
	std::cout << "Default FragTrap constructor called !" << std::endl;
	std::cout << "\tNAME :" << this->_name << std::endl;
	std::cout << "\tHP :" << this->_energyPoint << std::endl;
	std::cout << "\tACTION POINTS :" << this->_hitPoint << std::endl;
	std::cout << "\tATTACK DAMAGE :" << this->_attackDmg << std::endl << std::endl;
}

FragTrap::FragTrap( FragTrap const & src ) {
	this->_name = src._name;
	this->_hitPoint = src._hitPoint;
	this->_energyPoint = src._energyPoint;
	this->_attackDmg = src._attackDmg;
	std::cout << "Copy FragTrap constructor called !" << std::endl;
	std::cout << "\tNAME :" << this->_name << std::endl;
	std::cout << "\tHP :" << this->_energyPoint << std::endl;
	std::cout << "\tACTION POINTS :" << this->_hitPoint << std::endl;
	std::cout << "\tATTACK DAMAGE :" << this->_attackDmg << std::endl << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	this->_name = name;
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDmg = 30;
	std::cout << "Paramteric FragTrap constructor called !" << std::endl;
	std::cout << "\tNAME :" << this->_name << std::endl;
	std::cout << "\tHP :" << this->_energyPoint << std::endl;
	std::cout << "\tACTION POINTS :" << this->_hitPoint << std::endl;
	std::cout << "\tATTACK DAMAGE :" << this->_attackDmg << std::endl << std::endl;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called !" << std::endl;
}

/*==================================================================*
*			OVERLOAD												*
*===================================================================*/

FragTrap &		FragTrap::operator=( FragTrap const & other ) {
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDmg = other._attackDmg;
	return *this;
}

/*==================================================================*
*			MEMEBER FUNCTION										*
*===================================================================*/

void			FragTrap::highFivesGuys( void ) {
	std::cout << YELL << "\t[HIGH FIVE]" << std::endl;
	if (this->_energyPoint && this->_hitPoint) {
		std::cout << BLUE << this->getName() << NOR << " boosts the team with some " << YELL << "HIGH FIVES." << NOR << std::endl << std::endl;
		this->_hitPoint--;
	}
	else if (!this->_energyPoint) {
		std::cout << BLUE << this->getName() << NOR << " can't High five. This player is dead." << std::endl << std::endl;
	}
	else if (!this->_hitPoint) {
		std::cout << "You don't have enough PM..." << std::endl << std::endl;
	}
}

void			FragTrap::attack( std::string const & target ) {
	if (this->_hitPoint > 0) {
		std::cout << "🤖 " << BLUE << this->getName() << NOR << " using FragTrap attack " << BLUE << target << NOR \
		<< " causing " << RED << this->_attackDmg << NOR << " points of damage ! 💥" << std::endl;
		this->_hitPoint-= 5;
	}
	else {
		std::cout << "You don't have enough PM..." << std::endl << std::endl;
	}
}

void			FragTrap::attack( ClapTrap & target ) {
	std::cout << RED << "\t[ATTACK]" << NOR <<std::endl;
	if ( this->_hitPoint > 0 && target.getEnergyPoint() > 0 && this->_energyPoint) {
		std::cout << "🤖 " << BLUE << this->getName() << NOR << " using FragTrap attack " << BLUE << target.getName() << NOR \
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