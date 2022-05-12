/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:35:14 by wluong            #+#    #+#             */
/*   Updated: 2022/01/08 01:11:07 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

# define BLUE "\033[1;34m"
# define PUR "\033[1;35m"
# define BLUE2 "\033[1;36m"
# define YELL "\033[3;33m"
# define NOR "\033[m"
# define RED "\033[1;31m"

Form::Form( void ) : _title("Random Form"), _requiredGrade(150), _execGrade(150),_signed(false) {
	checkGrade();
	return ;
}

Form::Form( Form const & src ) : _title(src._title), _requiredGrade(src._requiredGrade), _execGrade(src._execGrade),_signed(false) {
	checkGrade();
	return ;
}

Form::Form( std::string const & title, int const & grade, int const & exec ) : _title(title), _requiredGrade(grade), _execGrade(exec), _signed(false) {
	checkGrade();
	return ;
}

Form::~Form( void ) {
	return ;
}

Form &	Form::operator=( Form const & other ) {
	this->_title = other._title;
	this->_requiredGrade = other._requiredGrade;
	this->_execGrade = other._execGrade;
	return *this;
}

std::string		Form::getTitle( void ) const {
	return this->_title;
}

int				Form::getRequiredGrade( void ) const {
	return this->_requiredGrade;
}

bool			Form::getSigned( void ) const {
	return this->_signed;
}

int				Form::getExecGrade( void ) const {
	return this->_execGrade;
}

void			Form::beSigned( Bureaucrat const & target ) {
	if (target.getGrade() <= this->_requiredGrade) {
		this->_signed = true;
	}
	else {
		throw Form::GradeTooLowException();
	}
}

void			Form::checkGrade( void ) const {
	if (this->_requiredGrade < 1 || this->_execGrade < 1) {
		throw Form::GradeTooHighException();
	}
	else if (this->_requiredGrade > 150 || this->_execGrade > 150) {
		throw Form::GradeTooLowException();
	}
	else {
		return ;
	}
}

std::ostream &		operator<<( std::ostream & os, Form const & src ) {
	os << BLUE2 << src.getTitle() << NOR << " is a form which need grade " << RED << src.getRequiredGrade() << NOR << " to be signed and grade "\
	<< RED << src.getExecGrade() << NOR << " to be executed";
	return os;
}