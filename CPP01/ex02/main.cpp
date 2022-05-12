/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:48:44 by wluong            #+#    #+#             */
/*   Updated: 2021/12/27 00:07:50 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#define GR	"\033[1;4;32m"
#define YEL	"\033[33m"
#define NOR	"\033[m"

int		main(void) {

	std::string		brain = "HI THIS IS BRAIN";
	std::string		*stringPTR = &brain;
	std::string&	stringREF = brain;
	std::string		brain2 = "lol";


	std::cout << YEL << "======================================" << NOR << std::endl;
	std::cout << GR << "DISPLAY ADDRESSES" << NOR << std::endl << std::endl;
	std::cout << "The address of the string is :" << std::endl;
	std::cout << "\t" << &brain << std::endl << std::endl;
	std::cout << "The address of the string by pointer is :" << std::endl;
	std::cout << "\t" << stringPTR << std::endl << std::endl;
	std::cout << "The address of the string by reference is :" << std::endl;
	std::cout << "\t" << &stringREF << std::endl << std::endl;
	std::cout << YEL << "======================================" << NOR << std::endl;
	std::cout << "The message is :" << std::endl;
	std::cout << "\t" << brain << std::endl;
	std::cout << std::endl << "The message by pointer is :" << std::endl;
	std::cout << "\t" << *stringPTR << std::endl;
	std::cout << std::endl << "The message by reference is :" << std::endl;
	std::cout << "\t" << stringREF << std::endl;
}