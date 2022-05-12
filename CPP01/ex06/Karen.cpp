/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 05:13:54 by wluong            #+#    #+#             */
/*   Updated: 2021/12/27 20:16:32 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen( void ) {
	std::cout << "Oh no ! Karen is here 😰" << std::endl << std::endl;
}

Karen::~Karen( void ) {
	std::cout << std::endl << "Karen finally get away 😖" << std::endl;
}

void	Karen::_debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << IT << "👩 -(I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!)" << NOR << std::endl;
}

void	Karen::_info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << IT << "👩 -(I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!)" << NOR << std::endl;
}

void	Karen::_warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << IT << "👩 -(I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.)" << NOR << std::endl;
}

void	Karen::_error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << IT << "👩 -(This is unacceptable, I want to speak to the manager now.)" << NOR << std::endl;
}

int		Karen::complain( std::string level ) {
	std::string		strtab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
//	void	(Karen::*fptr[4]) (void) = {&Karen::_debug, &Karen::_info, &Karen::_warning, &Karen::_error};

	for (int i(0); i < 4; i++) {
		if (!strtab[i].compare(level))
			return(i);
	}
	return (-1);
}

void	Karen::filter( std::string level ) {
	int		lvl;

	lvl = this->complain( level ) + 1;
	switch (lvl)
	{

		case 1:
			this->_debug();
			break;
		case 2:
			this->_info();
			break;
		case 3:
			this->_warning();
			break;
		case 4:
			this->_error();
			break;
		default:
			std::cout << "👩 [ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}