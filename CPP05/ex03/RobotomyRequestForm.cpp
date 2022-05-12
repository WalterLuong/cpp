/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 04:04:36 by wluong            #+#    #+#             */
/*   Updated: 2022/01/08 03:34:15 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("robotomy request", 72, 45) , _target("NOWHERE") {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : Form("robotomy request", 72, 45), _target(src._target) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const & target ) : Form("robotomy request", 72, 45), _target(target) {
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	return ;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & other ) {
	Form::operator=(other);
	this->_target = other._target;
	return *this;
}

std::string				RobotomyRequestForm::getTarget( void ) const {
	return this->_target;
}

void					RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	if (!this->getSigned()) {
		throw Form::FormIsNotSigned();
		return ; 
	}
	if (this->getExecGrade() >= executor.getGrade()) {
			std::cout << "BZRZRZRZRZRZRZRZRZRZRZRZRZRZRZZR *drill noise*" << std::endl;
			int		rand = random(1, 2);
			switch (rand)
			{
			case 1:
				std::cout << executor.getName() << " has been robotomized with success at " << this->getTarget() << std::endl;
				break;
			case 2:
				std::cout << executor.getName() << " has not been robotomizesd. It is a failure..." << std::endl;
				break;
			default:
				break;
			}
	}
	else {
		throw Form::GradeTooLowException();
	}
}

int		random(int min, int max)
{
	static bool first = true;
	if (first) {
		srand( time(NULL) );
		first = false;
	}
	return min + rand() % (( max + 1 ) - min);
}
