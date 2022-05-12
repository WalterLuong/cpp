/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 06:45:26 by wluong            #+#    #+#             */
/*   Updated: 2022/01/03 02:15:14 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int		main(int ac, char **av) {

	(void) av;
	if (ac != 1) {
		std::cout << "Too much arguments." << std::endl;
		return 1;
	}

	FragTrap	FT("Onizuka");
	ScavTrap	ST("Hercules");
	ClapTrap	CT("Nemo");
	DiamondTrap	DT("Jerry");

	CT.attack(FT);
	FT.highFivesGuys();
	ST.guardGate();
	DT.whoAmI();
	DT.attack(ST);
	DT.beRepaired(100);
	DT.guardGate();
	DT.highFivesGuys();
	CT.beRepaired(10);
	FT.beRepaired(10);
	ST.beRepaired(10);
	ST.attack(CT);
	FT.attack(ST);
	return 0;
}