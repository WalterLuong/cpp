/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 03:13:00 by wluong            #+#    #+#             */
/*   Updated: 2022/01/08 03:26:03 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void ) {
	return ;
}

Intern::Intern( Intern const & src ) {
	*this = src;
	return ;
}

Intern::~Intern( void ) {
	return ;
}

Intern &	Intern::operator=( Intern const & other ) {
	(void) other;
	return *this;
}

Form*		Intern::makeForm(std::string const & type, std::string const & target ) {
	std::string		typeform[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form	*newF;
	int		ret = -1;

	for (int i(0); i < 3; i++) {
		if (type == typeform[i]) {
			ret = i;
		}
	}
	switch (ret)
	{
	case 0:
		newF = new ShrubberyCreationForm(target);
		return (newF);
		break;
	case 1:
		newF = new RobotomyRequestForm(target);
		return (newF);
		break;
	case 2:
		newF = new PresidentialPardonForm(target);
		return (newF);
		break;
	default:
		throw Intern::NoForm();
		return (NULL);
		break;
	}
}