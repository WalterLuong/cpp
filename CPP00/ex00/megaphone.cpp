/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:59:36 by wluong            #+#    #+#             */
/*   Updated: 2021/12/24 06:13:53 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define RED "\033[5;1;31m"
#define NOR "\033[m"

int		main(int ac, char **av)
{
	int				i;
	size_t			j;
	std::string		word;

	if (ac == 1)
		std::cout << RED << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << NOR;
	else
	{
		for (i = 1; i < ac; i++)
		{
			word = av[i];
			for (j = 0; j < word.length(); j++)
				word.at(j) = toupper(word.at(j));
			std::cout << word;
			if (i != ac - 1)
				std::cout << " ";
		}
	}
		std::cout << std::endl;
	return (0);
}