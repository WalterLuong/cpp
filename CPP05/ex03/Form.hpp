/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:23:01 by wluong            #+#    #+#             */
/*   Updated: 2022/01/08 03:24:52 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FORM_HPP
# define	FORM_HPP

class Form;

# include"Bureaucrat.hpp"

class Form
{

public:

	Form( void );
	Form( Form const & src );
	Form( std::string const & title, int const & grade, int const & exec );
	virtual ~Form( void );

	Form &	operator=( Form const & other );

	class	GradeTooHighException : public std::exception
	{
		public :
			virtual const char* what() const throw() { return "Grade is too high !" ;}
	};

	class	GradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw() { return "Grade is too Low !" ;}
	};

	class	FormIsNotSigned : public std::exception
	{
		public :
			virtual const char* what() const throw() { return "Form is not signed !" ;}
	};

	std::string		getTitle( void ) const;
	int				getRequiredGrade( void ) const;
	int				getExecGrade( void ) const;
	bool			getSigned( void ) const;
	void			checkGrade( void ) const;
	void			beSigned( Bureaucrat const & target );
	virtual void	execute( Bureaucrat const & executor ) const = 0;

private:

	std::string	_title;
	int			_requiredGrade;
	int			_execGrade;
	bool		_signed;
	
};

std::ostream &		operator<<( std::ostream & os, Form const & src );

#endif