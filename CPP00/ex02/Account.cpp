/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 01:54:21 by wluong            #+#    #+#             */
/*   Updated: 2021/12/24 05:58:13 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
//#include <chrono>
#include <iomanip>

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;


/********************
 * CONST & DEST		*
 * *****************/

Account::Account( int initial_deposit ) : _amount(initial_deposit) {
	this->_accountIndex = this->_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
}

Account::~Account( void ) {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

/********************
 *		GETTER		*
********************/


int		Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int		Account::getTotalAmount( void ) {
	return _totalAmount;
}

int		Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int		Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

/********************
 *	MEMBER FUNC		*
********************/

void	Account::makeDeposit( int deposit ) {
	this->_totalAmount += deposit;
	this->_nbDeposits += 1;
	this->_totalNbDeposits++;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:1" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (this->_amount >= withdrawal){
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		this->_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << this->_amount << ";";
		this->_amount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:1" << std::endl;
		return true;
	}
	else {
		this->_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << this->_amount << ";";
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

/********************
 *		DISPLAY		*
********************/

void	Account::_displayTimestamp( void ) {
	time_t	curr_time;
	curr_time = time(NULL);

	tm now_tm = *localtime(&curr_time);
	std::cout << std::setfill('0') << "[" << now_tm.tm_year + 1900;
	std::cout << std::setw(2) << now_tm.tm_mon + 1;
	std::cout << std::setw(2) << now_tm.tm_mday << "_";
	std::cout << std::setw(2) << now_tm.tm_hour;
	std::cout << std::setw(2) << now_tm.tm_min;
	std::cout << std::setw(2) << now_tm.tm_sec << "] ";
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

