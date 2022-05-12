/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:04:34 by wluong            #+#    #+#             */
/*   Updated: 2022/01/18 12:27:46 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "Array.hpp"

int		random(int min, int max) //range : [min, max]
{
	static bool first = true;
	if (first) {
		srand( time(NULL) );
		first = false;
	}
	return min + rand() % (( max + 1 ) - min);
}


int		main() {
	std::cout << "======= TEST DEFAULT INT ARRAY =======" << std::endl;
	Array<int>	tab(5);
	try {
		for (unsigned int i(0); i < tab.size(); i++) {
			std::cout << tab[i] << std::endl;
		}
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "======= TEST RANDOM VALUE INT ARRAY =======" << std::endl;
	Array<int>	tab2(10);
	try {
		for (unsigned int i(0); i < tab2.size(); i++) {
			tab2[i] = random(1, 100);
		}
		for (unsigned int i(0); i < tab2.size(); i++) {
			std::cout << tab2[i] << std::endl;
		}
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "======= TEST COPY CONSTRUCTOR INT ARRAY =======" << std::endl;
	Array<int>	tab3(tab2);
	try {
		for (unsigned int i(0); i < tab3.size(); i++) {
			std::cout << tab3[i] << std::endl;
		}
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "======= TEST OVERLOAD ASSIGNATION INT ARRAY =======" << std::endl;
	Array<int>	tab4 = tab3;
	try {
		for (unsigned int i(0); i < tab4.size(); i++) {
			std::cout << tab4[i] << std::endl;
		}
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "======= TEST OUT OF RANGE =======" << std::endl;
	try {
		for (unsigned int i(0); i < 10; i++) {
			std::cout << tab[i] << std::endl;
		}
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "======= TEST RANDOM VALUE STRING ARRAY =======" << std::endl;
	Array<std::string>	tabs(5);
	std::string		truc[10]= {"Bonjour", "Hello", "Hola", "Guten tag", "Buongiorno", "Ohayō gozaimasu", "Bom dia", "God morgon", "Namaste", "Boker tov"};
	try {
		for (unsigned int i(0); i < tabs.size(); i++) {
			tabs[i] = truc[random(0, 9)];
		}
		for (unsigned int i(0); i < tabs.size(); i++) {
			std::cout << tabs[i] << std::endl;
		}
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}