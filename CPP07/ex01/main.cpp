/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:36:36 by wluong            #+#    #+#             */
/*   Updated: 2022/01/18 15:59:41 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int		main() {
	int a[3] = {37, 42, -5};
	std::string	b[4] = {"Salut", "les", "amis", "!"};
	bool	c[4] = {true, true ,false, true};
	float	f[6] = {1.2f, 3.4f, 5.6f, 7.8f, 9.11f, 10.12f};
	std::cout << "\033[1;32m=== FIRST TEST : INT ===\033[m" << std::endl;
	std::cout << "\033[1;3;33mint	a[3] = {37, 42, -5}\033[m" << std::endl;
	std::cout << "PRINT :" << std::endl;
	iter(a, 3, print);
	iter(a, 3, increase);
	std::cout << std::endl;
	std::cout << "INCREASE THEN PRINT :" << std::endl;
	iter(a, 3, print);
	std::cout << std::endl;
	std::cout << "\033[1;32m=== SECOND TEST : STRING ===\033[m" << std::endl;
	std::cout << "\033[1;3;33mstd::string	b[4] = {\"Salut\", \"les\", \"amis\", \"!\"}\033[m" << std::endl;
	iter(b, 4, print);
	iter(b, 4, increase);
	std::cout << std::endl;
	std::cout << "\033[1;32m=== THIRD TEST : BOOL ===\033[m" << std::endl;
	std::cout << "\033[1;3;33mbool	c[4] = {true, true ,false, true}\033[m" << std::endl;
	iter(c, 4, print);
	std::cout << std::endl;
	std::cout << "\033[1;32m=== FOURTH TEST : FLOAT ===\033[m" << std::endl;
	std::cout << "\033[1;3;33mfloat	f[6] = {1.2f, 3.4f, 5.6f, 7.8f, 9.11f, 10.12f}\033[m" << std::endl;
	std::cout << "PRINT :" << std::endl;
	iter(f, 6, print);
	iter(f, 6, increase);
	std::cout << std::endl;
	std::cout << "INCREASE THEN PRINT :" << std::endl;
	iter(f, 6, print);

}