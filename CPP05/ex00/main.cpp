/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 04:42:09 by wluong            #+#    #+#             */
/*   Updated: 2022/01/05 05:19:12 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

# define BLUE "\033[1;34m"
# define YELL "\033[3;33m"
# define NOR "\033[m"

int		main() {

	std::cout << BLUE << "============ FIRST TEST ==========" << NOR << std::endl;
	std::cout << YELL << "Bureaucrat B(\"Baptiste\", 0)" << NOR << std::endl;
	try { Bureaucrat	B("Baptiste", 0); }
	catch(const std::exception& e) { std::cout << e.what() << std::endl; }
	std::cout << BLUE << "============ SECOND TEST ==========" << NOR << std::endl;
	std::cout << YELL << "Bureaucrat H(\"Harry\", 154)" << NOR << std::endl;
	try { Bureaucrat	H("Harry", 154); }
	catch(const std::exception& e) { std::cout << e.what() << std::endl; }
	std::cout << BLUE << "============ THIRD TEST ==========" << NOR << std::endl;
	std::cout << YELL << "Bureaucrat C(\"Charles\", 2) + 2 upgrade" << NOR << std::endl;
	try { 
		Bureaucrat	C("Charles", 2);
		std::cout << C << std::endl;
		C.upGrade();
		std::cout << C << std::endl;
		C.upGrade();
		std::cout << C << std::endl;

	}
	catch(const std::exception& e) { std::cout << e.what() << std::endl; }
	std::cout << BLUE << "============ FOURTH TEST ==========" << NOR << std::endl;
	std::cout << YELL << "Bureaucrat A(\"Alphonse\", 149) + 4 downgrade & 1 upgrade" << NOR << std::endl;
	try { 
		Bureaucrat	A("Alphonse", 149);
		std::cout << A << std::endl;
		A.downGrade();
		std::cout << A << std::endl;
		A.upGrade();
		std::cout << A << std::endl;
		A.downGrade();
		std::cout << A << std::endl;
		A.downGrade();
		std::cout << A << std::endl;
		A.downGrade();
		std::cout << A << std::endl;

	}
	catch(const std::exception& e) { std::cout << e.what() << std::endl; }
}