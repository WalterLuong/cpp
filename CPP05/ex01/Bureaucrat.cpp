/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 04:29:54 by wluong            #+#    #+#             */
/*   Updated: 2022/01/06 03:30:29 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

# define BLUE "\033[1;34m"
# define PUR "\033[1;35m"
# define BLUE2 "\033[1;36m"
# define YELL "\033[3;33m"
# define NOR "\033[m"

Bureaucrat::Bureaucrat( void ) : _name("Lambda guy"), _grade(150) {
	checkGrade();
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name(src._name), _grade(src._grade) {
	checkGrade();
	return ;
}

Bureaucrat::Bureaucrat( std::string const & name, unsigned int grade ) : _name(name), _grade(grade) {
	checkGrade();
	return ;
}

Bureaucrat::~Bureaucrat( void ) {
	return ;
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & other ) {
	this->_grade = other._grade;
	return *this;
}

std::string		Bureaucrat::getName( void ) const {
	return this->_name;
}

int				Bureaucrat::getGrade( void ) const {
	return this->_grade;
}

void			Bureaucrat::upGrade( void ) {
	this->_grade--;
	checkGrade();
	return ;
}

void			Bureaucrat::downGrade( void ) {
	this->_grade++;
	checkGrade();
	return ;
}

void			Bureaucrat::checkGrade( void ) {
	if (this->_grade > 150) {
		throw GradeTooLowException();
	}
	else if (this->_grade < 1) {
		throw GradeTooHighException();
	}
	return;
}

void			Bureaucrat::signForm( Form & form ) {
	try {
		form.beSigned(*this);
		std::cout << PUR << this->getName() << NOR << " signs " << BLUE2 << form.getTitle() << NOR << " !" << std::endl; 
	}
	catch(const std::exception& e) {
		std::cerr << PUR << this->getName() << NOR << " cannot sign " \
		<< BLUE2 << form.getTitle() << NOR << " because his " << e.what() << std::endl;
	}
	
}

std::ostream &		operator<<( std::ostream & os, Bureaucrat const & src ) {
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return os;
}