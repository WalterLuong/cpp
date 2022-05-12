/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 05:13:47 by wluong            #+#    #+#             */
/*   Updated: 2021/12/27 20:17:57 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int		main(int ac, char **av)
{
	std::string		buff;

	(void) av;
	if (ac != 1) {
		std::cout << "Error: Too many arguments." << std::endl;
		return (1);
	}
	else {
		Karen			myKaren;
		std::cout << std::endl << "Choose the level of complaining :" << std::endl;
		std::cout << YEL << "\t[DEBUG] [INFO] [WARNING] [ERROR]" << NOR << std::endl;
		std::cout << GR << "↪ " << NOR;
		std::getline(std::cin, buff);
		std::cout << std::endl;
		myKaren.complain(buff);
		return (0);
	}
}