/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 04:04:34 by wluong            #+#    #+#             */
/*   Updated: 2022/01/06 04:04:34 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PRESIDENTIALPARDONFORM_HPP
# define	PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm : public Form
{

public:

	PresidentialPardonForm( void );
	PresidentialPardonForm( PresidentialPardonForm const & src );
	PresidentialPardonForm( std::string const & target );
	virtual ~PresidentialPardonForm( void );

	PresidentialPardonForm &	operator=( PresidentialPardonForm const & other );

	std::string		getTarget( void ) const;
	virtual void	execute( Bureaucrat const & executor ) const;

private:

	std::string		_target;

};

#endif