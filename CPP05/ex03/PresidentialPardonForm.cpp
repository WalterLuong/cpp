/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 04:04:32 by wluong            #+#    #+#             */
/*   Updated: 2022/01/08 01:05:57 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("presidential pardon", 25, 5) , _target("NOWHERE") {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : Form("presidential pardon", 25, 5), _target(src._target) {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const & target ) : Form("presidential pardon", 25, 5), _target(target) {
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	return ;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & other ) {
	Form::operator=(other);
	this->_target = other._target;
	return *this;
}

std::string		PresidentialPardonForm::getTarget( void ) const {
	return this->_target;
}

void			PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	if (!this->getSigned()) {
		throw Form::FormIsNotSigned();
		return ; 
	}
	if (this->getExecGrade() >= executor.getGrade()) {
			std::cout << executor.getName() << " has been forigven by Zafod Beeblerox at " << this->getTarget() << ". He might not die today." << std::endl;
	}
	else {
		throw Form::GradeTooLowException();
	}
}