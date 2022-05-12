/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:46:41 by wluong            #+#    #+#             */
/*   Updated: 2022/01/19 02:19:22 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <string>
#include <stdlib.h>

int		random(int min, int max) //range : [min, max]
{
	static bool first = true;
	if (first) {
		srand( time(NULL) );
		first = false;
	}
	return min + rand() % (( max + 1 ) - min);
}


int		main()
{
	std::cout << "\033[1;32m====== LITTLE VECTOR ======\033[m" << std::endl << std::endl;
	std::vector<int>	vec;
	int		i = 2;
	int		j = 7;
	for (int k(0); k < 6; k++) { vec.push_back(k); }
	std::cout << "\033[3;33mVector contains : { ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "}\033[m" << std::endl;
	std::cout << "\033[1;34mi = " << i << "\033[m" << std::endl;
	std::cout << "\033[1;34mj = " << j << "\033[m" <<std::endl;
	try { easyfind(vec, i); }
	catch(const std::exception& e) { std::cerr << i << e.what() << '\n'; }
	try { easyfind(vec, j); }
	catch(const std::exception& e) { std::cerr << j << e.what() << '\n'; }
	std::cout << std::endl;
	std::cout << "\033[1;32m====== RANDOM VECTOR ======\033[m" << std::endl << std::endl;
	std::vector<int>	vec2;
	int		m = random(0,50);
	for (int l(0); l < 20; l++) { vec2.push_back(random(0, 50)); }
	std::cout << "\033[3;33mVector contains : { ";
	for (std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "}\033[m" << std::endl;
	std::cout << "\033[1;34mm = " << m << "\033[m" << std::endl;
	try { easyfind(vec2, m); }
	catch(const std::exception& e) { std::cerr << m << e.what() << '\n'; }
}