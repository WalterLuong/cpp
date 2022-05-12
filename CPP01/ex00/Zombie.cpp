/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 20:36:38 by wluong            #+#    #+#             */
/*   Updated: 2021/12/26 23:46:10 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (void) {
	this->_name = "NONE";
}

Zombie::~Zombie ( void ) {
	std::cout << "🪦  " << this->_name << " is finally dead... RIP " << this->_name << std::endl;
}

void	Zombie::setName( std::string name ) {
	this->_name = name;
	std::cout << "🧟 " << this->_name << " comes back from the deads !" << std::endl;
}



void	Zombie::announce( void ) const {
	std::cout << this->_name;
	std::cout << " BraiiiiiiinnnzzzZ... 🧠" << std::endl;
}