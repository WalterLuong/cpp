/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:53:30 by wluong            #+#    #+#             */
/*   Updated: 2021/12/26 23:37:00 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie*		zombieHorde( int N, std::string name ) {

	Zombie	*horde = new Zombie[N];
	std::string	new_name;
	std::string nbr;
	for (int i(0); i < N; i++) {
		std::stringstream	ss;
		ss << i + 1;
		ss >> nbr;
		new_name = name + " " + nbr;
		horde[i].setName(new_name);
	}
	return (horde);
}