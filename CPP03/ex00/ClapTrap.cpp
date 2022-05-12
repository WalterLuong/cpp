/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 06:07:06 by wluong            #+#    #+#             */
/*   Updated: 2022/01/02 00:33:03 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("NONE"), _hitPoint(10), _energyPoint(10), _attackDmg(0) {
	std::cout << "Default ClapTrap constructor called !" << std::endl;
	std::cout << "\tNAME :" << this->_name << std::endl;
	std::cout << "\tHP :" << this->_energyPoint << std::endl;
	std::cout << "\tACTION POINTS :" << this->_hitPoint << std::endl;
	std::cout << "\tATTACK DAMAGE :" << this->_attackDmg << std::endl << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const & src ) : _hitPoint(src._hitPoint), _energyPoint(src._hitPoint), _attackDmg(src._attackDmg) {
	std::cout << "Copy ClapTrap constructor called !" << std::endl;
	std::cout << "\tNAME :" << this->_name << std::endl;
	std::cout << "\tHP :" << this->_energyPoint << std::endl;
	std::cout << "\tACTION POINTS :" << this->_hitPoint << std::endl;
	std::cout << "\tATTACK DAMAGE :" << this->_attackDmg << std::endl << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoint(10), _energyPoint(10), _attackDmg(0) {
	std::cout << "Parametric ClapTrap constructor called !" << std::endl;
	std::cout << "\tNAME :" << this->_name << std::endl;
	std::cout << "\tHP :" << this->_energyPoint << std::endl;
	std::cout << "\tACTION POINTS :" << this->_hitPoint << std::endl;
	std::cout << "\tATTACK DAMAGE :" << this->_attackDmg << std::endl << std::endl;
	return ;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap destructor called !" << std::endl;
	return ;
}

ClapTrap &		ClapTrap::operator=( ClapTrap const & other ) {
	this->_name = other._name;
	this->_attackDmg = other._attackDmg;
	this->_energyPoint = other._energyPoint;
	this->_hitPoint = other._hitPoint;
	return *this;
}

std::string		ClapTrap::getName( void ) const {
	return this->_name;
}

unsigned int	ClapTrap::getAttackDmg( void ) const {
	return this->_attackDmg;
}

unsigned int	ClapTrap::getEnergyPoint( void ) const {
	return this->_energyPoint;
}

void			ClapTrap::attack( std::string const & target ) {
	if (this->_hitPoint > 0) {
		std::cout << "🤖 ClapTrap " << BLUE << this->getName() << NOR << " attack " << BLUE << target << NOR \
		<< " causing " << RED << this->_attackDmg << NOR << " points of damage ! 💥" << std::endl;
		this->_hitPoint-= 5;
	}
	else {
		std::cout << "You don't have enough PM..." << std::endl << std::endl;
	}
}

void			ClapTrap::attack( ClapTrap & target ) {
	if ( this->_hitPoint > 0) {
		std::cout << "🤖 ClapTrap " << BLUE << this->getName() << NOR << " attack " << BLUE << target.getName() << NOR \
		<< " causing " << RED << this->_attackDmg << NOR << " points of damage ! 💥" << std::endl;
		target.takeDamage(*this);
		this->_hitPoint--;
	}
	else {
		std::cout << "You don't have enough PM..." << std::endl << std::endl;
	}
}

void			ClapTrap::takeDamage( unsigned int amount ) {
	std::cout << "🤖 ClapTrap " << BLUE << this->getName() << NOR << " receive " << YELL << amount << NOR \
	<< " points of damage !" << std::endl;
	if (amount > this->_energyPoint) {
		this->_energyPoint = 0;
	}
	else {
		this->_energyPoint -= amount;
	}
	std::cout << "❤️  Vie restante de " << BLUE <<  this->_name << NOR << " : " << GREEN << this->getEnergyPoint() << NOR << std::endl << std::endl;
}

void			ClapTrap::takeDamage( ClapTrap const & attacker ) {
	std::cout << "🤖 ClapTrap " << BLUE << this->getName() << NOR << " receive " << YELL << attacker.getAttackDmg() << NOR \
	<< " points of damage !" << std::endl;
	this->_energyPoint -= attacker.getAttackDmg();
	std::cout << "❤️  Vie restante de " << BLUE << this->_name << NOR << " : " << GREEN << this->getEnergyPoint() << NOR << std::endl << std::endl;
}

void			ClapTrap::beRepaired( unsigned int amount ) {
	std::cout << "ClapTrap " << BLUE << this->getName() << NOR 	<< " repaired " << YELL << amount << NOR\
	<< " Energy points !" << std::endl;
	this->_energyPoint += amount;
	std::cout << "Vie restante de " << this->_name << " : " << GREEN << this->getEnergyPoint() << NOR << std::endl << std::endl;
}