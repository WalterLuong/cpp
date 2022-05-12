/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 20:31:01 by wluong            #+#    #+#             */
/*   Updated: 2021/12/26 23:19:56 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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

	(void)av;
	if (ac != 1)
	{
		std::cout << "Too many arguments !" << std::endl;
		return (1);
	}
	Zombie *z1 = newZombie("Glenn");
	Zombie *z2 = newZombie("Rick");

	randomChump("Carl");
	z1->announce();
	z2->announce();
	delete z1;
	delete z2;
}