/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 20:31:01 by wluong            #+#    #+#             */
/*   Updated: 2021/12/26 23:46:02 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

void	randomChump( std::string name ) {
	Zombie	new_z;

	new_z.setName(name);
	new_z.announce();
}

Zombie*		newZombie( std::string name )
{
	Zombie	*new_z = new Zombie();
	new_z->setName(name);
	return (new_z);
}

int		main(int ac, char **av) {

	Zombie	*horde;
	std::string	buff;
	int		nb;

	(void)av;
	if (ac != 1)
	{
		std::cout << "Too many arguments !" << std::endl;
		return (1);
	}
	std::cout << "How many zombies do you want : ";
	std::getline(std::cin, buff);
	for (size_t i(0); i < buff.length(); i++) {
		if (!isdigit(buff.at(i)))
		{
			std::cout << "You must type only positive argument !" << std::endl;
			return (1);
		}
	}
	nb = atoi(buff.c_str());
	horde = zombieHorde(nb, "Walker");
	for (int i(0); i < nb; i++) {
		horde[i].announce();
	}
	delete [] horde;
}