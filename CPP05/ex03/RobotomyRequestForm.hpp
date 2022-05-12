/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 04:04:38 by wluong            #+#    #+#             */
/*   Updated: 2022/01/07 03:32:27 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ROBOTOMYREQUESTFORM_HPP
# define	ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : public Form
{

public:

	RobotomyRequestForm( void );
	RobotomyRequestForm( RobotomyRequestForm const & src );
	RobotomyRequestForm( std::string const & target );
	virtual ~RobotomyRequestForm( void );

	RobotomyRequestForm &	operator=( RobotomyRequestForm const & other );

	std::string		getTarget( void ) const;
	virtual void	execute( Bureaucrat const & executor ) const;

private:

	std::string		_target;

};

int		random(int min, int max);

#endif