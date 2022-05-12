/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 06:45:26 by wluong            #+#    #+#             */
/*   Updated: 2022/01/03 00:00:02 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int		main(int ac, char **av) {

	(void) av;
	if (ac != 1) {
		std::cout << "Too much arguments." << std::endl;
		return 1;
	}

	FragTrap	FT("Onizuka");
	ScavTrap	ST("Hercules");
	ClapTrap	CT("Nemo");

	CT.attack(FT);
	FT.highFivesGuys();
	ST.guardGate();
	CT.beRepaired(10);
	FT.beRepaired(10);
	ST.beRepaired(10);
	FT.attack(ST);
	ST.attack(FT);
	return 0;
}