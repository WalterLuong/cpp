/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 06:45:26 by wluong            #+#    #+#             */
/*   Updated: 2022/01/02 00:25:52 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int		main(int ac, char **av) {

	(void) av;
	if (ac == 1) {
	std::string		buff;

	std::cout << "Donnez un nom au premier ClapTrap : " << BLUE;
	std::getline(std::cin, buff);
	std::cout << NOR;
	
	ClapTrap	C1(buff);
	
	std::cout << "Donnez un nom au deuxieme ClapTrap : " << BLUE;
	std::getline(std::cin, buff);
	std::cout << NOR;

	ClapTrap	C2(buff);


	C1.attack(C2);
	C2.attack(C1);
	C1.beRepaired(5);
	C2.beRepaired(5);
	C1.attack(C2);
	C2.attack(C1);
	return 0;
	}
	std::cout << "Too much arguments." << std::endl;
	return 0;
}