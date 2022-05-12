/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 04:07:34 by wluong            #+#    #+#             */
/*   Updated: 2022/01/06 03:04:27 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP

class Bureaucrat;

# include <iostream>
# include <string>
# include "Form.hpp"

class Bureaucrat
{

public:

	Bureaucrat( void );
	Bureaucrat( Bureaucrat const & src );
	Bureaucrat( std::string const & name, unsigned int grade );
	~Bureaucrat( void );

	Bureaucrat &	operator=( Bureaucrat const & other );

	class	GradeTooHighException : public std::exception
	{
		public :
			virtual const char* what() const throw() { return "Grade too high !" ;}
	};

	class	GradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw() { return "Grade too Low !" ;}
	};

	std::string		getName( void ) const;
	int				getGrade( void ) const;
	void			upGrade( void );
	void			downGrade( void );
	void			checkGrade(void);
	void			signForm( Form & form );

private:

	const std::string	_name;
	unsigned int		_grade;

};

std::ostream &		operator<<( std::ostream & os, Bureaucrat const & src );

#endif