/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 04:42:09 by wluong            #+#    #+#             */
/*   Updated: 2022/01/08 01:25:37 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

# define BLUE "\033[1;34m"
# define YELL "\033[3;33m"
# define NOR "\033[m"

int		main() {

	try {
		std::cout << BLUE << "============ FIRST TEST ==========" << NOR << std::endl;
		std::cout << YELL << "=== SHRUBBERY ===" << NOR << std::endl;
		Bureaucrat	A("Albert", 146);
		Bureaucrat	B("Bogoss", 140);
		Bureaucrat	C("Cazzo", 132);
		ShrubberyCreationForm	F("maison");
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << C << std::endl;
		std::cout << F << std::endl;
		A.executeForm(F);
		B.executeForm(F);
		C.executeForm(F);
		A.signForm(F);
		B.signForm(F);
		C.signForm(F);
		A.executeForm(F);
		B.executeForm(F);
		C.executeForm(F);
	}
	catch(const std::exception& e) { std::cout << e.what() << std::endl; }
	try {
		std::cout << BLUE << "============ SECOND TEST ==========" << NOR << std::endl;
		std::cout << YELL << "=== ROBOTOMY ===" << NOR << std::endl;
		Bureaucrat	D("Denis", 79);
		Bureaucrat	E("Edouard", 50);
		Bureaucrat	F("Firmin", 37);
		Bureaucrat	G("Gaston", 29);
		Bureaucrat	H("Hercules", 8);
		Bureaucrat	I("Ines", 14);
		RobotomyRequestForm	M("hospital");
		std::cout << D << std::endl;
		std::cout << E << std::endl;
		std::cout << F << std::endl;
		std::cout << G << std::endl;
		std::cout << H << std::endl;
		std::cout << I << std::endl;
		std::cout << M << std::endl;
		D.executeForm(M);
		E.executeForm(M);
		F.executeForm(M);
		D.signForm(M);
		E.signForm(M);
		F.signForm(M);
		D.executeForm(M);
		E.executeForm(M);
		F.executeForm(M);
		G.executeForm(M);
		H.executeForm(M);
		I.executeForm(M);
	}
	catch(const std::exception& e) { std::cout << e.what() << std::endl; }
		try {
		std::cout << BLUE << "============ THIRD TEST ==========" << NOR << std::endl;
		std::cout << YELL << "=== PRESIDENTIAL PARDON ===" << NOR << std::endl;
		Bureaucrat	J("Joelle", 30);
		Bureaucrat	K("Kenny", 20);
		Bureaucrat	L("Laurent", 1);
		PresidentialPardonForm	P("galaxy");
		std::cout << J << std::endl;
		std::cout << K << std::endl;
		std::cout << L << std::endl;
		std::cout << P << std::endl;
		J.executeForm(P);
		K.executeForm(P);
		L.executeForm(P);
		J.signForm(P);
		K.signForm(P);
		L.signForm(P);
		J.executeForm(P	);
		K.executeForm(P	);
		L.executeForm(P	);
	}
	catch(const std::exception& e) { std::cout << e.what() << std::endl; }

}