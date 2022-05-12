/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 04:42:09 by wluong            #+#    #+#             */
/*   Updated: 2022/01/06 03:26:24 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

# define BLUE "\033[1;34m"
# define YELL "\033[3;33m"
# define NOR "\033[m"

int		main() {

try {
	std::cout << BLUE << "============ FIRST TEST ==========" << NOR << std::endl;
	std::cout << YELL << "Bureaucrat B(\"Baptiste\", 5)" << NOR << std::endl;
	Bureaucrat B("Baptiste", 5);
	std::cout << B << std::endl;
	Form	F("Demande de bourse", 7, 3);
	std::cout << F << std::endl;
	Form	G("Contrat de travail chez Monoprix rayon animaux", 2, 2);
	std::cout << G << std::endl;
	B.signForm(F);
	B.signForm(G);
	B.upGrade();
	std::cout << B << std::endl;
	B.upGrade();
	std::cout << B << std::endl;
	B.upGrade();
	std::cout << B << std::endl;
	B.signForm(G);
	Form	I("very low form", 151, 12);
	Form	H("very high form", 0, 0);
}
	catch(const std::exception& e) { std::cout << e.what() << std::endl; }
}