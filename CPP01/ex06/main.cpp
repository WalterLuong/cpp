/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 05:13:47 by wluong            #+#    #+#             */
/*   Updated: 2021/12/27 20:17:20 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int		main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "YOu must have one argument." << std::endl;
		return (1);
	}
	else {
		Karen			myKaren;
		myKaren.filter(av[1]);
		return (0);
	}
}