/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:35:14 by wluong            #+#    #+#             */
/*   Updated: 2022/01/06 03:27:54 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	os << src.getTitle() << " is a form which need grade " << src.getRequiredGrade() << " to be signed and grade "\
	<< src.getExecGrade() << " to be executed";
	return os;
}