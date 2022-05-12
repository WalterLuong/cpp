/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 04:09:56 by wluong            #+#    #+#             */
/*   Updated: 2022/01/07 03:32:41 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SHRUBBERYCREATIONFORM_HPP
# define	SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{

public:

	ShrubberyCreationForm( void );
	ShrubberyCreationForm( ShrubberyCreationForm const & src );
	ShrubberyCreationForm( std::string const & target );
	virtual ~ShrubberyCreationForm( void );

	ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & other );

	std::string		getTarget( void ) const;
	virtual void	execute( Bureaucrat const & executor ) const;

private:

	std::string		_target;

};

#endif