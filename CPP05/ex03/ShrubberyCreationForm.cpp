/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 04:04:40 by wluong            #+#    #+#             */
/*   Updated: 2022/01/08 03:35:13 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("shrubbery creation", 145, 137) , _target("NOWHERE") {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : Form("shrubbery creation", 145, 137), _target(src._target) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ) : Form("shrubbery creation", 145, 137), _target(target) {
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	return ;
}

ShrubberyCreationForm &		ShrubberyCreationForm::operator=( ShrubberyCreationForm const & other ) {
	Form::operator=(other);
	this->_target = other._target;
	return *this;
}

std::string					ShrubberyCreationForm::getTarget( void ) const {
	return this->_target;
}

void						ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {
	if (!this->getSigned()) {
		throw Form::FormIsNotSigned();
		return ; 
	}
	if (this->getExecGrade() >= executor.getGrade()) {
		std::string		filename = executor.getName() + "_shrubbery";
		std::ofstream	ofs(filename.c_str());
		ofs << "WHERE : " << this->_target << std::endl;
		ofs << "                                        ." << std::endl;
		ofs << "                                  .         ;" << std::endl;
		ofs << "     .              .              ;%     ;;" << std::endl;
		ofs << "       ,           ,                :;%  %;" << std::endl;
		ofs << "        :         ;                   :;%;'     .," << std::endl;
    	ofs << ".        %;     %;            ;        %;'    ,;" << std::endl;
		ofs << " ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
		ofs << "  %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
		ofs << "   ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
		ofs << "    `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
		ofs << "     `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
		ofs << "        `:%;.  :;bd%;          %;@%;'" << std::endl;
		ofs << "          `@%:.  :;%.         ;@@%;'" << std::endl;
		ofs << "            `@%.  `;@%.      ;@@%;" << std::endl;
		ofs << "              `@%%. `@%%    ;@@%;" << std::endl;
		ofs << "                ;@%. :@%%  %@@%;" << std::endl;
		ofs << "                  %@bd%%%bd%%:;" << std::endl;
		ofs << "                    #@%%%%%:;;" << std::endl;
		ofs << "                    %@@%%%::;" << std::endl;
		ofs << "                    %@@@%(o);  . '" << std::endl;
		ofs << "                    %@@@o%;:(.,'" << std::endl;
		ofs << "                `.. %@@@o%::;" << std::endl;
		ofs << "                   `)@@@o%::;" << std::endl;
		ofs << "                    %@@(o)::;" << std::endl;
		ofs << "                   .%@@@@%::;" << std::endl;
		ofs << "                   ;%@@@@%::;." << std::endl;
		ofs << "                  ;%@@@@%%:;;;." << std::endl;
		ofs << "              ...;%@@@@@%%:;;;;,.." << std::endl;
	}
	else {
		throw Form::GradeTooLowException();
	}
}